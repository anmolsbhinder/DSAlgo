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

int mountain(vi nums)
{
    int maxi=0;
    vi deep;

    if(nums[1]>nums[0]) deep.push_back(0);

    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<nums[i-1] && nums[i]<nums[i+1])
        {
            deep.push_back(i);
        }
    }

    for(int i=1;i<deep.size();i++)
    {
        int width = deep[i]-deep[i-1]+1;

        maxi=max(width,maxi);
    }

    return maxi;
}
 

int32_t main() 
{
    run();

    int n;
    cin>>n; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<mountain(nums);

}
