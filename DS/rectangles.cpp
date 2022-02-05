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
    
    int n;
    cin>>n;
    vi arr(n*2);
    
    unordered_map<string,int> mp;

    for(int i=0;i<arr.size();i+=2)
    {
        cin>>arr[i];
        cin>>arr[i+1];

        string str= to_string(arr[i])+" "+ to_string(arr[i+1]);
        mp[str]++;
    }
    
    int sum=0;

    for(int i=0;i<arr.size();i+=2)
    {
        for(int j=i+2;j<arr.size();j+=2)
        {
            string s1= to_string(arr[i])+" "+ to_string(arr[j+1]); //x1,y2
            string s2= to_string(arr[j])+" "+ to_string(arr[i+1]); //x2,y1

            bool diag= false;
            if(arr[i]!=arr[j] && arr[i+1]!=arr[j+1]) //comparing x1!=x2 and y1!=y2
            diag=true;

            if(mp[s1]>0 && mp[s2]>0 && diag)
            sum++;
        }
    }

    cout<<sum/2; //One rectangle 2 diagonals

    return 0;
}
