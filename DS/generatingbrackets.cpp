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


void bracket(string s, int n, int open, int close, int i)
{
    if(i==2*n)
    {
        cout<<s<<endl;
        return;
    }
    
    if(open<n)  
    {
        bracket(s+'(', n, open+1, close, i+1);
    }

    if(close<open)
    {
        bracket(s+')', n, open, close+1, i+1);
    }
}


int32_t main() 
{
    run();

    int n;
    cin>>n;
    
    bracket("",n,0,0,0);
}
