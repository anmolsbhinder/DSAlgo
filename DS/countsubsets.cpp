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
 

int cnt=0;

void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}


void ways(int target,int nums[],int n,int i)
{
    if(target<0)
    return 0;

    if(target==0)
    return 1;


    return ways
}


int32_t main() 
{
    run();

    int n,target;
    cin>>n>>target;
    int nums[n],a=n;

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<ways(target, nums,n,0);

    
}
