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

int first(int target,int nums[],int n,int a)
{
    if(nums[0]==target)
        return 0;

    if(n==0) return -1*a;


    return first(target, nums-1, n-1,a)+1;
}


int32_t main() 
{
    run();

    int n,target;
    cin>>n>>target;
    int nums[n],a=n;

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<n-1-first(target, nums+n-1, n-1,a);
}
