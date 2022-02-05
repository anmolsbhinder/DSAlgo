#include <bits/stdc++.h>
using namespace std;

void run()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

class Node{
public:
      int data;
      Node* left;
      Node* right;

      Node(int d){
            data=d;
            left=NULL;
            right=NULL;
      }
};

Node* insert(Node* root,int x)
{
      if(root==NULL)
      return new Node(x);

      if(x<root->data)
      root->left = insert(root->left,x);

      else
      root->right = insert(root->right,x);
      
      return root;
}

void printInorder(Node* root)
{
      if(root==NULL)
      return;

      printInorder(root->left);
      cout<<root->data<<" ";
      printInorder(root->right);
}

bool search(Node* root, int x)
{
      if(root==NULL)
      return false;

      if(root->data==x)
      return true;

      if(x<root->data)
      return search(root->left,x);

      return search(root->right,x);
}

Node* findmin(Node* root)
{
      while(root->left!=NULL)
      root=root->left;

      return root;
}

Node* remove(Node* root, int x)
{
      if(root==NULL)
      return NULL;

      else if(x<root->data)
      root->left = remove(root->left,x);

      else if(x>root->data)
      root->right = remove(root->right,x);

      else
      {
            if(root->left==NULL && root->right==NULL)
            {
                  delete root;
                  root=NULL;
            }

            else if(root->left==NULL)
            {
                  Node* temp= root;
                  root = root->right;
                  delete temp;
            }

            else if(root->right==NULL)
            {
                  Node* temp= root;
                  root = root->left;
                  delete temp;
            }

            else
            {
                  Node* temp= findmin(root->right);
                  root->data = temp->data;
                  root->right = remove(root->right, temp->data);
            }
      }

      return root;
}

void printinrange(Node* root, int k1, int k2)
{
      if(root==NULL)
      return;

      if(root->data >= k1 && root->data <= k2)
      {
            printinrange(root->left,k1,k2);
            cout<<root->data<<" ";
            printinrange(root->right,k1,k2);
      }

      else if(root->data >=k2)
      printinrange(root->left,k1,k2);

      else
      printinrange(root->right,k1,k2);
}

void printleafpaths(Node* root, vector<int> &path)
{
      if(root==NULL)
      return;

      if(root->left == NULL && root->right== NULL)
      {
            for(int x: path)
            cout<<x<<" ";

            cout<<root->data<<endl;
            return;
      }

      path.push_back(root->data);
      printleafpaths(root->left, path);
      printleafpaths(root->right, path);

      path.pop_back();
      return;
}

Node* minbst(Node* root, int s, int e, vector<int> v)
{
      if(s>e)
      return root;

      int mid= (s+e)/2;
      int x= v[mid];

      root=insert(root,x);
      minbst(root,s,mid-1,v);
      minbst(root,mid+1,e,v);

      return root;
}

void levelorderprint(Node* root)
{
    queue<Node*> q;  
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp= q.front();
        if(temp==NULL)
        {
            cout<<endl;
            q.pop();

            if(!q.empty())
            q.push(NULL);
        }

        else
        {
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
    }
}

int flag=0;
Node* temp;
    
    void find(Node *root, Node *x)
    {
        if(root==NULL)
        return;
        
        find(root->left,x);
        
        if(flag==1)
        {
            temp=root;
            flag=2;
            return;
        }
        
        if(root==x)
        flag=1;
        
        find(root->right,x);
    }
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        if(root==NULL)
        return root;
        
        find(root,x);
        return temp;
    }

int main() 
{
      run();

      Node* root = NULL;
      int arr[] = {8,3,10,1,6,14,4,7,13};

      for(int x:arr)
      root = insert(root,x);
      
      //cout<<search(root,11);
      printInorder(root);
      cout<<endl;

      printinrange(root,5,12);
      cout<<endl;

      vector<int> path;
      printleafpaths(root,path);
      cout<<endl;

      root=NULL;
      vector<int> v= {1,2,3,4,5,6,7};
      root=minbst(root,0,v.size()-1,v);

      levelorderprint(root);
      cout<<endl;

      Node* t= inOrderSuccessor(root,x);

      // root= remove(root,14);
      // printInorder(root);
}