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
    string name;
    list<string> nbrs;

    Node(string name)
    {
        this->name=name;
    }
};

class Graph
{
    unordered_map<string,Node*> m;

public:
    Graph(vector<string> cities)
    {
        for(auto city: cities)
        m[city]= new Node(city);
    }

    void addEdge(string i,string j,bool undir=false)
    {
         m[i]->nbrs.push_back(j);
         if(undir)
         {
            m[j]->nbrs.push_back(i); 
         }
    }

    void printAdjList()
    {
        for(auto cp:m)
        {
            auto city= cp.first;
            Node* addr= cp.second;

            cout<<city<<"--> ";
            for(auto nbr: addr->nbrs)
            {
                cout<<nbr<<", ";
            }

            cout<<endl;
        }
    }
};


int main()
{
    run();
    vector<string> cities ={"Delhi", "Paris","London", "New York"};
    Graph g(cities);
    g.addEdge("Delhi","London");
    g.addEdge("New York","London",true);
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");
    
    g.printAdjList();
    return 0;
}