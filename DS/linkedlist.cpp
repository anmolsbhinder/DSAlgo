#include<iostream>
#include "list.h"
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
List l,l2,l3;

        

Node * merge(Node* h1, Node* h2) 
{
    
    if(h1==NULL)
    return h2;

    if(h2==NULL)
    return h1;

    Node *c;
    if(h1->data < h2->data)
    {
        c=h1;
        c->next= merge(h1->next, h2);
    }

    else
    {
        c=h2;
        c->next= merge(h1, h2->next);
    }

    return c;
}

Node* midpoint(Node* h)
{
    Node* slow=h;
    Node* fast= h->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

Node* mergesort(Node* h)
{
    if(h==NULL || h->next==NULL)
    return h;
    
    Node* mid= midpoint(h);

    Node* a=h;
    Node* b=mid->next;
    mid->next=NULL;

    a=mergesort(a);
    b=mergesort(b);

    return merge(a,b);
}

int main() 
{
    run();
    
    
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);
    l.insert(10,0);

    l.pll();

    Node *h= l.begin();
    cout<<endl<<l.search(2);
    cout<<endl<<l.searchrec(h,4)<<endl<<endl;

    
    Node *hed= l.begin();
    hed=l.krev(hed,3);
    l.update(hed);

    l.pll();

    l2.push_back(1);
    l2.push_back(5);
    l2.push_back(7);
    l2.push_back(10);

    l3.push_back(2);
    l3.push_back(3);
    l3.push_back(6);

    l2.pll();
    l3.pll();

    Node* h1= l2.begin();
    Node* h2= l3.begin();

    Node* f= merge(h1,h2);
    l2.update(f);

    l2.pll();

    Node* fu=mergesort(l.begin());
    l.update(fu);

    l.pll();

    

    return 0;
}
