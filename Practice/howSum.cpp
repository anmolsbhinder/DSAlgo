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

unordered_map<int,bool> mp;
vector a;

bool sum(int target,vi nums)
{
    if(mp.count(target)) return mp[target]; 
    if(target==0)
    {
        return true;
    }
    if(target<0) return false;

    for(auto x: nums)
    {
        int rem= target-x; 
        mp[rem]=sum(rem,nums);
        if(mp[rem])
        {
            a.push_back(x);
            return true;
        }
    }

    return false;
}

int32_t main() 
{
    run();

    int s,tar;
    cin >> tar>>s;
    vi b(s);

    for(int i=0;i<s;i++)
    cin>>b[i]; 
    
    sum(tar,b);

    for(auto x: a)
    cout<<x<<" ";
    
    if(a.size()==0 && tar>0)
    cout<<-1;
}
