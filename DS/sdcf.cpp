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

        int n;
        cin>>n;

        vi a(n),b(n);
        unordered_map<int,vi> mp;

        for (int i = 0; i < n; ++i)
        {
            cin>>b[i];
            mp[b[i]].push_back(i);
        }


        sort(b.begin(),b.end());
        int num=INT_MAX;

        for (int j = n-1; j >= 0; j--)
        {  
            int size= mp[b[j]].size()-1;
            int idx= mp[b[j]][size];


            if(b[j]==0)  
            {
                a[idx]=0;
                continue;
            }

            num=min(b[j]-1,num);
            a[idx]=num;
            mp[b[j]].pop_back();
            if(num>0)
            num--;
        }

        for (int i = 0; i < n; ++i)
        {
            cout<<a[i]<<" ";
        }

        cout<<endl;

    }
}
