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

string s= "thequickbrownfox";
string words[]= { "the", "quickbrown", "quick", "brown", "fox"
};
 
int min_bars_helper(string s, string words[], int idx, unordered_set<string> &m)
{
    if(s[idx]=='\0')
    {
        return 0;
    }

    int ans= INT_MAX;
    string curr= "";

    for(int j=idx;j<s.length();j++)
    { 
        curr+=s[j];
        if(m .find(curr)!=m.end())
        {
            int rem= min_bars_helper(s,words,j+1,m);
            if(rem!=-1)
            {
                ans=min(ans, rem+1);
            }
        }
    }

    if(ans==INT_MAX)
    return -1;

    return ans;
}

int min_bars()
{
    unordered_set<string> m;

    for(string w: words)
    {
        m.insert(w);
    }

    int output= min_bars_helper(s,words,0,m);
    return output-1;
}

int32_t main() 
{
    run();
    cout<< min_bars();

    return 0;
}
