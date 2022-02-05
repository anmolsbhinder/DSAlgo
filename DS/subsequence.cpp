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
 

int cnt=0;

void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}

vector<string> ss;

string subs(char str[])
{
	if(str[0]=='\0')
	return "";

	string s1= str[0]+ subs(str+1);
	ss.push_back(s1);
	return s1;
	string s2= subs(str+1);
	ss.push_back(s2);
	return s2;
}


int32_t main() 
{
    run();

    string a;
    cin>>a;

    int n=a.length();

    char s[n];

    for(int i=0;i<n;i++)
    cin>>s[i];

    string g=subs(s);

    for(int i=0;i<ss.size();i++)
    cout<<ss[i]<<" ";
}