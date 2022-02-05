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

    void bfs(int source)
    {
        queue<int> q;
        bool *visited= new bool[V]{0};

        q.push(source);
        visited[source]=true;

        while(!q.empty())
        {
            int f=q.front();
            cout<<f<<" ";
            q.pop();

            for(auto nbr: l[f])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr ]=true;
                }
            }
        }
    }
};

int main()
{
    run();
    Graph g(7);
    g.addEdge(5,1);
    g.addEdge(1,2);
    g.addEdge(2,6);
    g.addEdge(5,6);
    g.addEdge(2,5);

    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs(1);
    cout<<endl<<endl;
    g.printAdjList();
    return 0;
}