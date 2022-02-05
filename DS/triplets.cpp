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

vector<vi> triplets(vi nums, int target)
{
    vector<vi> ans;

    sort(nums.begin(),nums.end());
  
    for(int i=0;i<nums.size()-2;i++)
    {
        int j=i+1;
        int k=nums.size()-1;

        while(j<k)
        {
            int sum= nums[i];
            sum+= nums[j]+nums[k];

            if(sum==target)
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }
            else if(sum>target)
                k--;
            else 
                j++;
        }
    }

    return ans;
}
 

int32_t main() 
{
    run();

    int n,target;
    cin>>n>>target;
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    auto ans=triplets(nums,target);

    for(auto v: ans)
    {
        for(int x: v)
            cout<<x<<" ";

        cout<<endl;
    }
}
