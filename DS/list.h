#include<iostream>
using namespace std;

class List;

class Node
{
		
public: 
	int data;
	Node *next;
	Node(int d):data(d),next(NULL){}

	int getdata()
	{
		return data;
	}

	~Node()
	{
		if(next!=NULL)
		delete next;
	}
	friend class List;
};

class List
{
	Node* head;
	Node* tail;

public:
	List():head(NULL),tail(NULL){}

	Node* begin()
	{
		return head;
	}

	Node* end()
	{
		return tail;
	}

	void update(Node* h)
	{
		head=h;
	}

	void push_front(int data)
	{
		if(head==NULL)
		{
			Node *n= new Node(data);
			head = tail = n;
		}

		else
		{
			Node *n= new Node(data);
			n->next= head;               //if n is an object then to access a class variable we type n.data while if n is a pointer i.e it has the address then we can type (*n).data or n->data
			head= n;
		}
	}

	void push_back(int data)
	{
		if(head==NULL)
		{
			Node *n= new Node(data);
			head = tail = n;
		}

		else
		{
			Node *n= new Node(data);
			tail->next= n;
			tail= n;
		}
	}

	void insert(int data, int pos)
	{
		if(pos==0)
		{
			push_front(data);
			return;
		}

		Node *temp= head;
		while(--pos)
		temp=temp->next;

		Node *n= new Node(data);
		n->next=temp->next;
		temp->next= n;
	}

	void pll()
	{
		Node* curr=head;
    	while(curr!=NULL)
    	{
       	 cout<<curr->data<<"->";
       	 curr= curr->next;
    	}
    	cout<<"NULL"<<endl;
	} 

	int search(int key)
	{
		Node *temp= head;
		int idx=0;
		while(temp!=NULL)
		{
			if(temp->data==key)
			return idx;
			idx++;
			temp=temp->next;
		}
		return -1;
	}  

	int id=0;
	int searchrec(Node* h,int key)
	{
		if(h==NULL)
		return -1;

		if(h->data==key)
		{
			return id;
		}
		
		else
		{
			id++;
			return searchrec(h->next,key);
		}
	}  

	void pop_front()
	{
		Node* temp= head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}

	void recrev(Node* curr,Node *prev)
	{
		if(curr==NULL)
		{
			head= prev;
			return;
		}

		
		Node *temp=curr->next;
		curr->next=prev;

		recrev(temp,curr);
	}

	void reverse()
	{
		Node *temp=head;
		Node *curr=head;
		Node *prev=NULL;

		while(curr)
		{
			temp=curr->next;
			curr->next=prev;
			prev=curr;
			curr=temp;
		} 

		head=prev;
	}

	Node* krev(Node* head,int k)
	{
		if(head==NULL)
		return NULL;

		Node *temp=head;
		Node *curr=head;
		Node *prev=NULL;
		int cnt=1;

		while(curr && cnt<=k)
		{
			temp=curr->next;
			curr->next=prev;
			prev=curr;
			curr=temp;
			cnt++;
		} 	

		head->next=krev(curr,k);	

		return prev;
	}


	~List()
	{
		if(head!=NULL)
		{
			delete head;
			head=NULL;
		}
	}
};