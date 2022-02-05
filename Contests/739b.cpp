#include<bits/stdc++.h>
#include<stdio.h>
#include<fstream>
#include<string>
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
        
        
        vi arr(62);
        arr[0]=1;
        for(int i=1;i<=62;i++)
        {
            arr[i]=arr[i-1]*2;        
        }

        string s1;
        cin>>s1;
        
        int mini=10000;

        for(int i=0;i<=62;i++)
        {
            string s2= to_string(arr[i]);
            int a=0,b=0,count=0;

            while(s1[a] && s2[b])
            { 
                if(s1[a]==s2[b])    
                {
                    b++;
                    count++;
                }

                a++;
            }

            int curr= (s1.length()-count) + (s2.length()-count);
            mini= min(curr,mini);

        }

        cout<< mini<<endl;
    
}
return 0;
}
