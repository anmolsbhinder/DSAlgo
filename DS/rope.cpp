#include<bits/stdc++.h>
#include<stdio.h>
#include<queue>
#include<fstream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define vi vector<int>
#define all(output) output.begin(),output.end()

void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}


int main() 
{
    run();
    int n;
    cin>>n;

    vector<int> rope(n);
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<n;i++)
    {
        cin>>rope[i];
        pq.push(rope[i]);
    }

    int score=0;
    while(pq.size()>1)
    {   
        int a= pq.top();
        score+= a;
        pq.pop();

        int b= pq.top();
        score+= b;
        pq.pop();

        pq.push(a+b);
    }

    cout<<score<<endl;

    return 0;
}
