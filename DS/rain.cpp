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

int water(vi nums)
{
    int n=nums.size();

    vi front(n), back(n);
    int m1=0,m2=0;

    for(int i=0;i<nums.size();i++)
    { 
        m1= max(m1,nums[i]);
        front[i]= m1;
    }
    
    for(int i=nums.size()-1;i>=0;i--)
    {
        m2= max(m2,nums[i]);
        back[i]=m2;
    }

    int count=0;

    for(int i=0;i<nums.size();i++)
    {
        int curr= min(back[i],front[i])-nums[i];
        count+=curr;
    }

    return count;
}
 

int32_t main() 
{
    run();

    int n;
    cin>>n; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<water(nums);

}
