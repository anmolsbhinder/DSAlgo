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

int longest(vi nums)
{
    int maxi=0;
    unordered_map <int,int> mp;

    for(int i=0;i<nums.size();i++)
    mp[nums[i]]++;
    

    for(int i=0;i<nums.size();i++)
    {
        int curr=1,f1=0,f2=0, x=nums[i],y=nums[i];

        while(f1==0)
        {
            if(mp.count(--x)==1 && mp[x]==1)
            {
                curr++;
                mp[x]=0;
            }    
            else 
                f1=1;
        }

        while(f2==0)
        {
            if(mp.count(++y)==1 && mp[y]==1)
            {
                curr++;
                mp[y]=0;
            }
            else 
                f2=1;
        }

        maxi=max(curr,maxi);
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

    cout<<longest(nums);

}
