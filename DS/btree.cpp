#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 
void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

Node* buildtree()
{
   int d;
   cin>>d;

   if(d==-1)
   return NULL;

   Node* n= new Node(d);
   n->left= buildtree();
   n->right= buildtree();
   return n; 
}

void preorderprint(Node* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}

void inorderprint(Node* root)
{
    if(root==NULL)
    return;

    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

void postorderprint(Node* root)
{
    if(root==NULL)
    return;

    postorderprint(root->left);
    postorderprint(root->right);
    cout<<root->data<<" ";
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

Node* levelorderbuild()
{
    queue<Node*> q;
    int root;
    cin>>root;
    Node* n= new Node(root);
    q.push(n);

    while(!q.empty())
    {
        Node* curr= q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1)
        {
            curr->left= new Node(c1);
            q.push(curr->left);
        }

        if(c2!=-1)
        {
            curr->right= new Node(c2);
            q.push(curr->right);
        }
    }
    return n;
}

int height(Node* root)
{

    if(root==NULL)
    return 0;

    cout<<root->data<<" ";

    int h1= height(root->left);
    int h2= height(root->right);

    return max(h1,h2)+1;
}

bool heightb(Node* root)
{
    if(root==NULL)
    return 0;

    int h1= height(root->left);
    int h2= height(root->right);

    if(abs(h1-h2)<=1)
    return true;

    else return false;
    
}

int sum(Node* root)
{
    if(root->left==NULL && root->right==NULL)
    return root->data;
    
    int n=root->data,s1=0,s2=0;

    if(root->left)
    s1= sum(root->left);

    if(root->right)
    s2= sum(root->right);

    root->data=s1+s2;

    return n+root->data;
}


int diameter(Node* root)
{
    if(root==NULL)
    return 0;
    
    int D1= height(root->left)+height(root->right);
    int D2= diameter(root->left);
    int D3= diameter(root->right);

    return max(D1,max(D2,D3));
}

pair<int,bool> isbalanced(Node* root)
{
    pair<int,bool> p, Left, Right;

    if(root==NULL)
    {
        p.first=0;
        p.second=true;
        return p;
    }

    Left= isbalanced(root->left);
    Right= isbalanced(root->right);

    int height= max(Left.first, Right.first)+1;

    if(abs(Left.first- Right.first)<=1 and Left.second and Right.second)
    return make_pair(height,true);

    else
    return make_pair(height,false);
}

class hdpair
{
public:
    int height;
    int diameter;
};

hdpair optdiameter(Node* root)
{
    hdpair p;

    if(root==NULL)
    {
        p.height=p.diameter=0;
        return p;
    }

    hdpair left= optdiameter(root->left);
    hdpair right= optdiameter(root->right);

    p.height= max(left.height, right.height)+1;

    int D1= left.height+right.height;
    int D2= left.diameter;
    int D3= right.diameter;

    p.diameter= max(D1, max(D2,D3));
    return p;
}

int exc(Node*);

int inc(Node* root)
{
    if(root==NULL)
    return 0;

    int ans= root->data+ exc(root->left)+exc(root->right);
    return ans;
}

int exc(Node* root)
{
    if(root==NULL)
    return 0;

    int ans= max(inc(root->left),exc(root->left))+max(inc(root->right),exc(root->right));
    return ans;
}

int msum(Node* root)
{
    if(root==NULL)
    return 0;

    int i= inc(root);
    int e= exc(root);

    return max(i,e);
}

class Pair
{
public:
    int inc;
    int exc;
};

Pair subsum(Node* root)
{
    Pair p;
    if(root==NULL)
    {
        p.inc=0;
        p.exc=0;
        return p;
    }

    Pair Left= subsum(root->left);
    Pair Right= subsum(root->right);

    p.inc= root->data+ Left.exc+Right.exc;
    p.exc= max(Left.inc,Left.exc)+max(Right.inc,Right.exc);

    return p;
}

void klevel(Node* root, int k)
{
    if(root==NULL)
    return;

    if(k==0)
    cout<<root->data;

    klevel(root->left,k-1);
    klevel(root->right,k-1);
}

void knode(Node* root, int k)
{
    if(root==NULL)
    return;

    
}

map<int,vector<int>> mp;

void vertical(Node* root, int key)
{
    if(root==NULL)
    return;

    mp[key].push_back(root->data);
    vertical(root->left,key-1);
    vertical(root->right,key+1);
}

map<int,int> mp2;

void topview(Node* root, int key)
{
    if(root==NULL)
    return;
    
    if(mp2.count(key)==0)
    mp2[key]=root->data;

    topview(root->left,key-1);
    topview(root->right,key+1);
}

int main()
{
    run();
    //Node* root= buildtree();
    Node* root= levelorderbuild();
    // preorderprint(root);
    // cout<<endl;
    // inorderprint(root);
    // cout<<endl;
    // postorderprint(root);
    // cout<<endl;
    // levelorderprint(root);
    // cout<<endl<<height(root)<<endl<<diameter(root)<<endl<<optdiameter(root).diameter;
    // sum(root);
    // cout<<endl<<endl;
    // levelorderprint(root);
    // pair<int,bool> p= isbalanced(root);
    // if(p.second) cout<<"YES";
    // else cout<<"NO";
    // cout<<heightb(root)<<endl<<msum(root);

    // cout<<msum(root)<<endl;
    // Pair p= subsum(root);

    // cout<<max(p.inc,p.exc)<<endl;

    // klevel(root,2);

    vertical(root,0);
    for(auto x: mp)
    {
        for(int i=0;i<x.second.size();i++)
        {
            cout<<x.second[i]<<" ";
        }

        cout<<endl;
    }

    topview(root,0);
    for(auto x: mp2)
    {
        cout<<x.second<<" ";
    }

}