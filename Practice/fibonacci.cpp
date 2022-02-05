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

map<int,int> mp;

int fib(int n)
{
    if(mp[n]>0) return mp[n];
    if(n <= 2) return 1;
    mp[n]= fib(n-1)+fib(n-2);
    return mp[n];
}

int32_t main()
{
    run();
    
    int a,b,c;
    a=7;
    cout<<fib(a);

    return 0;
}