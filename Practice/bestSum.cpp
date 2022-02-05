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

int coins(int target,vi nums)
{
    vi dp(target+1,0);

    for(int i=1;i<=target;i++)
    {
        int mini= INT_MAX;
        for(int x: nums)
        {
            if(i-x >=0 && dp[i-x]<INT_MAX)
            mini= min(mini, dp[i-x]);
        }
        dp[i]= mini+1;
    }

    return dp[target]>=INT_MAX?-1:dp[target];
}


int32_t main() 
{
    run();

    int n,target;
    cin>>n>>target;
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<coins(target, nums);
}
