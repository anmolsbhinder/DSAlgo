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

int32_t main()
{
    run();
    string s[5];
    //input
    int maxi=INT_MIN;
    cout<<endl<<"INPUT"<<endl<<"---------------"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>s[i];
        int size=s[i].size();
        maxi= max(maxi,size);
    }
    cout<<endl;

    //Left Align
    cout<<"LEFT ALIGNED"<<endl<<"---------------"<<endl;
    for(int i=0;i<5;i++)
        cout<<s[i]<<endl;
    cout<<endl;

    //Right Align
    cout<<"RIGHT ALIGNED"<<endl<<"---------------"<<endl;
    for(int i=0;i<5;i++)
    {
        int space= maxi-s[i].size(),j;
        for(j=0;j<space;j++)
        cout<<" ";
        
        cout<<s[i]<<endl;
    }
    cout<<endl;

    //Top Align
    cout<<"TOP ALIGNED"<<endl<<"---------------"<<endl;
    for(int i=0; i<maxi;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i<s[j].size())
            cout<<s[j][i]<<" ";

            else cout<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    //Bottom Align
    cout<<"BOTTOM ALIGNED"<<endl<<"---------------"<<endl;
    for(int i=0; i<maxi;i++)
    {
        for(int j=0;j<5;j++)
        {
            int space= maxi-s[j].size();
            if(i<space)
            cout<<"  ";

            else cout<<s[j][i-space]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}