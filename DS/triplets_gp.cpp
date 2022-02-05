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
 
int32_t main() 
{
    run();
    
    int n,r;
    cin>>n>>r;
    vi arr(n);
    
    unordered_map<float,int> mp;
    unordered_map<float,int> curr;

    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    
    int sum=0;
    curr[arr[0]]++;

    for(int i=1;i<arr.size();i++)
    {
        float a= arr[i]/r;
        float b= arr[i]*r;

        sum+= (curr[a]*(mp[b]-curr[b]));
        
        curr[arr[i]]++;
    }

    cout<<sum;

    return 0;
}
