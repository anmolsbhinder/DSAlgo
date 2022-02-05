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

bool check(vi nums, int b, int mid)
{
    int last= nums[0];
    int i=1;
    b--;
    while(b>0 && i<=nums.size()-1)
    {
        if(nums[i]-last>=mid)
        {
            b--;
            last=nums[i];
        }
        
        i++;
    }

    return b==0;
}

int angry(vi nums, int n ,int b)
{
    int s=0 ,e=(nums[n-1]+nums[0]);
    int mid;

    while(s<=e)
    {
        mid= (s+e)/2;

        if(check(nums,b,mid) && !check(nums,b,mid+1))
        return mid;

        else if(check(nums,b,mid) && check(nums,b,mid+1))
        {
            s=mid+1;
        }

        else
        {
            e=mid-1;
        }
    }
    return -1;
}


int32_t main() 
{
    run();

    int n,b;
    cin>>n>>b;
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<angry(nums,n,b);
}
