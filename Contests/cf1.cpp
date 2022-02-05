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
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}

int sum(int n)
{
   int s= n*(n+1);
   s/=2;
   return s;
}

int32_t main()
{
   run();
   int t;
   cin >> t;
   while(t--)
   {
      int n,k;
      cin>>n>>k;

      int s_pos= n-k;

      int extra= sum(n-1)-sum(s_pos)-((n-s_pos-1)*s_pos);

      int ans= extra/(n-s_pos);

      int final_ans= 2*(ans+s_pos);

      cout<<final_ans<<endl;
   }
	
	return 0;
}
