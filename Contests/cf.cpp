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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mini=INT_MAX;
        string s1=to_string(n);
        vector <pair<int,int>> vp;
        
        for(int i=s1.length()-1;i>=0;i--)
        {
            int x=s1[i]-'0';
            if(x!=0 && x!=2 && x!=5 && x!=7)
            continue;
            
            pair<int,int> p1;
            p1.first=x;
            p1.second=s1.length()-1-i;
            
            vp.push_back(p1);
        }
        
        for(int i=0;i<vp.size();i++)
        {
            for(int j=i+1;j<vp.size();j++)
            {
                int y=vp[i].first*10 + vp[j].first;
                if(y==00 || y==5 || y==52 || y==57)
                    mini=min(mini,vp[j].second-1);
            }
        }
        cout<<mini<<endl;
    }
    return 0;
}

// vector<string> str(100000);
    
    // for(int i=0, num=25 ;i<=99999; num+=25)
    // {
    //         str[i]= to_string(num);
    //         i++;
    // }

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int k;
    //     string s1;
    //     cin>>s1;

    //     int mini= INT_MAX;

    //     for(int i=0;i<=99999;i++)
    //     {
    //         string s2= str[i];
    //         int a=0,b=0,count=0;
 
    //         while(s1[a] && s2[b])
    //         { 
    //             if(s1[a]==s2[b])    
    //             {
    //                 b++;
    //                 count++;
    //             }
 
    //             a++;
    //         }

    //         if(b==s2.length())
    //         {
    //             int ans= s1.length()-s2.length();
    //             mini=min(mini,ans);
    //         }
 
    //     }

    //     cout<<mini<<endl;
    // }