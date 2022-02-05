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

int binary(int target,vi nums)
{
    int s=0,e=nums.size()-1;
    int mid;

    while(s<=e)
    {
        mid= (s+e)/2;

        if(nums[mid]==target)
            return mid;

        else if(nums[mid]>target)
        {
            e=mid-1;
        }

        else if(nums[mid]<target)
        {
            s=mid+1;
        }
    }
    return -1;
}


int32_t main() 
{
    run();

    int n,target;
    cin>>n>>target;
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<binary(target, nums);
}
