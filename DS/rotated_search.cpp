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

int search(vi nums, int key)
{
    int n=nums.size();
    int s=0, e=n-1;
    int mid;

    while(s<=e)
    {
        mid= (s+e)/2;

        if(nums[mid]==key)
        return mid;

        if(nums[mid]>=nums[s])
        {
            if(key>=nums[s] && key<=nums[mid])
            e=mid-1;

            else 
            s=mid+1;
        }
        
        else
        {
            if(key>=nums[mid] && key<=nums[e])
            s=mid+1;

            else 
            e=mid-1;
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
    
    cout<< search(nums, target);
}
