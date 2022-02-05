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
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int v)
    {
        V=v;
        l= new list<int>[V];
        adj.resize(V);
    }

    void addEdge(int i,int j,bool undir=true)
    {
         l[i].push_back(j);
         if(undir)
         {
            l[j].push_back(i); 
         }
    }

    void addEdge(int i,int j, int wt)
    {
         adj[i].push_back({j,wt});
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

    void dfshelper(int v, bool* visited)
    {
        visited[v]=true;
        cout << v << " ";
  
        for (auto nbr: l[v])
        if (!visited[nbr])
        dfshelper(nbr, visited);
    }

    void dfs (int v)
    {   
        bool *visited= new bool[V]{0};
        dfshelper(v,visited);
    }

    queue<int> topological()
    {
        vector<int> indegree(V,0);

        for(int i=0; i<V; i++)
        {
            for(auto nbr: l[i])
            indegree[nbr]++;
        }

        queue<int> q;

        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }

        queue<int> sorted;

        while(!q.empty())
        {
            int node = q.front();
            // cout<< node<<" ";
            sorted.push(node);
            q.pop();

            for(auto nbr: l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                q.push(nbr);
            }
        }

        return sorted;
    }

    bool cyclehelper(int node, bool* visited, int parent)
    {
        visited[node]=true;

        for(auto nbr: l[node])
        {
            if(!visited[nbr])       
            {
                if(cyclehelper(nbr,visited,node))
                return true;
            }

            else if(nbr!=parent)
            return true;
        }

        return false;
    }

    bool cycle_dfs_und()
    {
        bool* visited= new bool[V]{0};
        return cyclehelper(0,visited,-1);
    }

    bool checkCycle(int node, int vis[], int dfsVis[]) 
    {
        vis[node] = 1; 
        dfsVis[node] = 1; 

        for(auto nbr : l[node]) 
        {
            if(!vis[nbr]) 
            {
                if(checkCycle(nbr, vis, dfsVis)) 
                return true;
            } 

            else if(dfsVis[nbr]) 
            {
                return true; 
            }
        }

        dfsVis[node] = 0; 
        return false;
    }

    bool cycle_dfs_dir(int N)
    {
        int vis[N], dfsVis[N]; 
        memset(vis, 0, sizeof vis); 
        memset(dfsVis, 0, sizeof dfsVis); 

        for(int i = 1;i<=N;i++) 
        {
           if(!vis[i]) 
           { 
               if(checkCycle(i, vis, dfsVis)) 
               {
                   return true; 
               }
           }
       }
       return false; 
    }

    bool cycle_bfs_und(int source)
    {
        queue<pair<int,int>> q;
        bool *visited= new bool[V]{0};

        q.push({source,-1});
        visited[source]=true;

        while(!q.empty())
        {
            int f=q.front().first;
            int p=q.front().second;

            q.pop();

            for(auto nbr: l[f])
            {
                if(!visited[nbr])
                {
                    q.push({nbr,f});
                    visited[nbr]=true;
                }

                else if(nbr!=p)
                return true;
            }
        }
        return false;
    }

    bool bipartite_bfs(int source)
    {
        queue<int> q;
        vector<int> color(V,-1);

        q.push(source);
        color[source]=0;

        while(!q.empty())
        {
            int f=q.front();
            q.pop();

            for(auto nbr: l[f])
            {
                if(color[nbr]==-1)
                {
                    q.push(nbr);
                    color[nbr]= 1-color[f];
                }

                else if(color[nbr]== color[f])
                return false;
            }
        }

        return true;
    }

    bool helper(int v, int color[])
    {
        for (auto nbr: l[v])
        {
        if (color[nbr]==-1)
        {
            color[nbr] = 1 - color[v];
            if(!helper(nbr, color)) 
            {
                return false; 
            }
        } 
        else if(color[nbr] == color[v]) return false; 
    }
    return true; 

    }

    bool bipartite_dfs (int source, int n)
    {   
        int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!helper(i, color)) {
                return false;
            }
        } 
    }
    return true; 
    }


    void path_und(int N, int src) 
    { 
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
        queue<int>  q;
    
        dist[src] = 0;
        q.push(src); 

        while(q.empty()==false) 
        { 
           int node = q.front(); 
           q.pop();
         
            for(auto it: l[node])
            {
               if(dist[node] + 1 < dist[it])
                {
                    dist[it]=dist[node]+1;
                    q.push(it);
                }   
            } 
        } 

        for(int i = 0;i<N;i++) 
        cout << dist[i] << endl; 
    } 

    void path_dir(int src) 
    { 
        queue<int> topo = topological();
        topo.pop();

        vector<int> dist(V,INT_MAX);
    
        dist[src] = 0;

        while(topo.empty()==false) 
        { 
           int node = topo.front(); 
           topo.pop();
         
         if(dist[node]<INT_MAX)
            for(auto it: adj[node])
            {
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first]=dist[node]+it.second;

                }   
            } 
        } 

        for(int i = 1;i<V;i++) 
        cout << dist[i] << endl; 
    } 

};

int main()
{
    run();
    Graph g(10);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,5);
    // g.addEdge(5,6);
    // g.addEdge(4,5);
    // g.addEdge(0,4); 
    // g.addEdge(3,4);
    // g.bfs(1);
    // cout<<endl<<endl;
    // g.dfs(2);
    // cout<<endl<<endl;
    // g.printAdjList();
    // cout<<endl<<endl;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    // g.addEdge(4,5);
    // g.addEdge(6,5);
    // g.addEdge(7,2);
    // g.addEdge(7,8);
    // g.addEdge(8,9);
    // g.addEdge(9,7);
    // g.topological();
    // cout<<g.bipartite_dfs(1,5);
    //  g.printAdjList();
    // g.path_und(6,1);

    Graph g1(6);
    g1.addEdge(1,2,1);
    g1.addEdge(2,3,1);
    g1.addEdge(3,4,1);
    g1.addEdge(4,5,1);
    // g1.addEdge(5,1,1);
    // g1.addEdge(3,4,1);
    // g1.addEdge(4,5,1);
    // g1.addEdge(1,5,1);

    g1.path_dir(1);
    return 0;
}