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

bool orderout(vi nums,int x)
{
    if(x==0) return nums[0]>nums[1];
    if(x==nums.size()-1) return nums[x]<nums[x-1];
    return (nums[x]>nums[x+1] || nums[x]<nums[x-1]);
}

pii subarray(vi nums)
{
    int n=nums.size();
    int mini=INT_MAX ,maxi=INT_MIN;

    for(int i=0;i<nums.size();i++)
    { 
        if(orderout(nums,i))
        {
            mini= min(mini,nums[i]);
            maxi= max(maxi,nums[i]);
        }
    }

    if(mini==INT_MAX) return {-1,-1};

    int left=0;
    while(mini >= nums[left]) left++;

    int right=nums.size()-1;
    while(maxi <= nums[right]) right--;

    return {left,right};
    
}
 

int32_t main() 
{
    run();

    int n;
    cin>>n; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    auto ans=subarray(nums);

    cout<<ans.first<<" "<<ans.second;

}
