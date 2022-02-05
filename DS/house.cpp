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

vector<pair<int,int>> house(vi nums, int target)
{
    int n=nums.size()-1,area=0,s=0,e=0;
    vector<pair<int,int>> p;
    
    int i=-1;
    while(!(i>=n && area<target))
    {
        if(area<target)
        {
            i++;
            area+=nums[i];
        }
        else if(area>target)
        {
            area-=nums[s];
            s++;
        }
        else if(area==target)
        {
            e=i;
            p.push_back({s, e});
            area-=nums[s];
            s++;
        }
        
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
