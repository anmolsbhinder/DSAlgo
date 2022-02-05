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

string key[]= {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void word(string s, int n)
{
    if(n==0)
    {
        for(int i=s.length()-1; i>=0; i--)
        cout<<s[i];

        cout<<endl;
        return;
    }

    int rem= n%10;

    if(rem==0 || rem==1) word(s, n/10);

    for(int i=0;i<key[rem].size();i++)
    {
        word(s+key[rem][i], n/10);
    }
}


int32_t main() 
{
    run();

    int n;
    cin>>n;
    
    
    word("",n);
}
