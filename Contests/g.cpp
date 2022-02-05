#include<bits/stdc++.h>
#include<stdio.h>
#include<fstream>
using namespace std;
#include<string.h>
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
const int MAX = 26;
 
void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int num(char ch)
{
    int ans;

    if(ch=='0')
    return 0;

    ans='9'-ch;
    ans++;
    return ans;
}

void solve()
{
    
}


int32_t main()
{
    run();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}   

