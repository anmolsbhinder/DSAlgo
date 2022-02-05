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

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V=v;
        l= new list<int>[V];
    }

    void addEdge(int i,int j,bool undir=true)
    {
         l[i].push_back(j);
         if(undir)
         {
            l[j].push_back(i); 
         }
    }

    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"--> ";
            for(auto data:l[i])
            {
                cout<<data<<", ";
            }

            cout<<endl;
        }
    }
};

int main()
{
    run();
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printAdjList();
    return 0;
}