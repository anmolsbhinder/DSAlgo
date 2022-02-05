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
    
    string s;
    cin>>s;
    
    unordered_map<string,int> mp;

    for(int i=0;i<s.length();i++)
    {
        for(int j=1;j<=s.length()-i;j++)
        {
            string temp=s.substr(i, j);
            string hash= "00000000000000000000000000";
            for(int k=0;k<temp.length();k++)
            {
                int idx= temp[k]-'a';
                hash[idx]+=1;
            }

            mp[hash]++;
        }
    }
    
    int sum=0;
    for (auto i : mp)
    {
        int calc= i.second * (i.second - 1);
        calc/=2;
        sum+=calc;
    }

    cout<<sum;

    return 0;
}
