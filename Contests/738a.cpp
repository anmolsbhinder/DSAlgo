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
        int size;
        cin>>size;

        string s;
        int beg,end;
        cin>>s;
       
        int i=-1;
        while(s[i]=='?')
        {
            i++;
        }

        if(i>=0)
        for(int p=i;p>=0;p--)
        {
            if(s[i+1]=='B')
                s[i]='R';

            else 
                s[i]='B';
        }

        i++;
        for( ;i<s.size();i++)
        {
            if(s[i]=='?')
            {
            if(s[i-1]=='B')
                s[i]='R';

            else 
                s[i]='B';
            }
        }

        cout<<s<<endl;

    }
}
