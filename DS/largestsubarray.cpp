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

int subarray(vi nums)
{
    int max_sum= nums[0], curr_sum= nums[0];

    for(int i=1;i<nums.size();i++)
    {
        curr_sum= max(curr_sum+nums[i], nums[i]);
        max_sum= max(max_sum,curr_sum);
    }

    return max_sum;
}


int32_t main() 
{
    run();

    int n;
    cin>>n;
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<subarray(nums);
}
