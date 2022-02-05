#include<bits/stdc++.h>
#include<stdio.h>
#include<fstream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define endl "\n"
#define int long long
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define all(a) a.begin(),a.end()
#define MAXN 10000005
#define BLOCK 555
#define pii pair<int,int>
 
void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}

#include <bits/stdc++.h>
using namespace std;

void run()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    run();
    //inputs
    int n,i=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;

    deque <int> q(k);

    //processing first k elements..max element is at front..
    for(i=0;i<k;i++){
        while(!q.empty() && a[i]>=a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    //processing remaining elements
    for(;i<n;i++){
        cout<<a[q.front()]<<" ";

        //check if element lies in window
        while(!q.empty() && a[q.front()]<=i-k){
            q.pop_front();
        } 

        //removing useless elements
        while(!q.empty() && a[i]>=a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    cout<<a[q.front()];
    return 0;

}
