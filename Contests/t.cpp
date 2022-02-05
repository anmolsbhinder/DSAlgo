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
    int t;
    cin >> t;
    while (t--)
    {
        int a1,a2,b1,b2,c1,c2;
        cin>>a1>>a2>>b1>>b2>>c1>>c2;

        int flag=0;

        if(a1==b1 || a2==b2)
            flag++;
        if(b2==c2 || b1==c1)
            flag++;

        int check=0;

        if((b1>a1 && b1<c1) || (b1<a1 && b1>c1))
            check=1;
        if((b2>a2 && b2<c2) || (b2<a2 && b2>c2))
            check=1;

        if(a1==b1==c1 && check==0)
            flag=0;
        if(a2==b2==c2 && check==0)
            flag=0;
        if(a1==b1==c1 && check==1)
            flag=2;
        if(a2==b2==c2 && check==1)
            flag=2;

        if((b1==c1 || b2==c2) && check==1)
            flag=2;

        if(flag==2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
