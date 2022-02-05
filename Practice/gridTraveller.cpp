#include<bits/stdc++.h>
#include<stdio.h>
#include<fstream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define int long long
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
 
void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

unordered_map<string,int> mp;

int grid(int m, int n)
{
    string key= to_string(m) + "," + to_string(n);
    string key2= to_string(n) + "," + to_string(m);

    if(mp.count(key)==1) return mp[key];
    if(mp.count(key2)==1) return mp[key2];

    if(m==1 && n==1) return 1;
    if(m==0 || n==0) return 0;

    mp[key]=grid(m-1,n) + grid(m,n-1);
    return mp[key];
}

int32_t main()
{ 
    run();
    
    int a,b;
    cin>>a>>b;
    cout<<grid(a,b);

    return 0;
}