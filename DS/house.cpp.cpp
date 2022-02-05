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

int swaps(vi nums)
{
    int n=nums.size();
    unordered_map<int,int> mp;
    vi arr= nums;
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=i;
    }

    int count=0;
    for(int i=0;i<n;)
    {
        int org=mp[nums[i]];

        if(i==org) 
        {
            i++;
            continue;
        }

        swap(nums[i],nums[org]);
        count++;
    }

    return count;
}
 

int32_t main() 
{
    run();

    int n;
    cin>>n; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<swaps(nums);

}
