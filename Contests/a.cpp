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

int po(int n)
{
    int p=1;
    while(p<n)
    {
        if(p*2 <= n)
        p*=2;
 
        else 
        break;
    }

    return p;
}

void solve()
{
    int a,b;
    cin>>a>>b;

    
    int poa= po(a);
    int pob= po(b);
    int x=INT_MAX,y=INT_MAX,z=INT_MAX,q=INT_MAX,s=INT_MAX;

    //default
    x= b-a;

    //increase a then OR
    if((b-pob)>=a)
    {
        y=(b-pob)-a+1;
    }

    //increase b then OR
    if((b-pob)<=a)
    {
        z= a-(b-pob)+1;
    }


    if((a|b)==b)
    q=1;

    if(poa==pob)
    {
        if(a==poa)
        q=1;

        if(a==b)
        q=0;
    }

    if(a<=pob)
    s=pob-a+1;




    // cout<<x<<" "<<y<<" "<<z<<" ";
    cout<<min(x,min(y,min(z,min(q,s))))<<endl;

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

