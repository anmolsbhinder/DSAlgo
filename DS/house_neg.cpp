#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define vi vector<int>
 
void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}

// subtracting a subarray sum(0 to a) from subarray sum(0 to b) 
//gives us subarray sum(a+1 to b)
//this gives all possible subarray sums in O(n) 
//but we would only find the ones we need i.e with sum x

vector<pair<int,int>> house(vi nums, int target)
{
    int n=nums.size()-1,area=0;
    vector<pair<int,int>> p;
    unordered_map<int,int> mp;

    for(int i=0;i<=n;i++)
    {
        area+=nums[i];
        int x= area-target;

        if(area==target)
        {
            p.push_back({0, i});
        }   

        if(mp.count(x)==1)
        {
            p.push_back({mp[x]+1, i});
        }

        mp[area]=i;
    }

    return p;
}
 

int32_t main() 
{
    run();

    int n,target;
    cin>>n>>target; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    auto ans=house(nums,target);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;

}
