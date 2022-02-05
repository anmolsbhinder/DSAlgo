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

// int power(int a, int n)
// {
//     if(n==0) return 1;

//     return a* power(a,n-1);
// }

int power(int a, int n)
{
    if(n==0) return 1;
    
    if(n%2==0)
    {
        int x=power(a,n/2);
        return x*x;
    }

    else 
    return a*power(a,n-1);
}


int32_t main() 
{
    run();

    int n,a;
    cin>>a>>n;
    
    
    cout<<power(a,n);
}
