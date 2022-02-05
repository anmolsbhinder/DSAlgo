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
        for(int i=1;i<V;i++)
        {
            cout<<i<<"--> ";
            for(auto data:l[i])
            {
                cout<<data<<", ";
            }

            cout<<endl;
        }
    }
    
    int bfs(int source, bool* visited ,int x)
    {
        queue<int> q;
        

        q.push(source);
        visited[source]=true;

        while(!q.empty())
        {
            int f=q.front();
            x++;
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
        
        return x;
    }

    pair<int,int> help(int N)
    {
        bool *visited= new bool[V]{0};
        int count=0;
        int capt=1;
        
        for(int i = 1;i<=N;i++) 
        {
           if(!visited[i]) 
           { 
               count++;
               int cnt= bfs(i,visited,0);
               capt*=cnt;
           }
       }
       
       pair<int,int>p;
       p.first=count;
       p.second= capt;
       
       return p; 
    }
    
};

int main()
{
    run();
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        Graph g(n+1);
        
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            g.addEdge(a,b,true);
        }
        
        // g.printAdjList();
        pair<int,int>p;
        p=g.help(n);
        
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}