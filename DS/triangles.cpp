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
    
    int n;
    cin>>n;
    vi arr(n*2);
    
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;

    for(int i=0;i<arr.size();i+=2)
    {
        cin>>arr[i];
        cin>>arr[i+1];

        mp1[arr[i]]++;
        mp2[arr[i+1]]++;
    }
    
    int sum=0;

    for(int i=0;i<arr.size();i+=2)
    {
        int temp= (mp1[arr[i]]-1)*(mp2[arr[i+1]]-1);
        sum+=temp;
    }

    cout<<sum;

    return 0;
}
