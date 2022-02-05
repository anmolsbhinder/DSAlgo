#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define vi vector<int> 
 
void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}

int merge(vi &num,int s, int e)
{
    int i=s;
    int mid= (s+e)/2;
    int j= mid+1;

    vi temp;
    int k=0,c=0;
    while(i<=mid && j<=e)
    {
        if(num[i]<=num[j])
            temp.push_back(num[i++]);
        else
            {
                temp.push_back(num[j++]);
                c+=mid-i+1;
            }
    }

    while(i<=mid)
    {
        temp.push_back(num[i++]);
    }

    while(j<=e)
    {
        temp.push_back(num[j++]);
    }

    int l=0;
    for(int i=s;i<=e;i++)
    {
        num[i]=temp[l++];
    }
    return c;
}

int mergesort(vi &nums,int s, int e)
{
    if(s>=e) return 0;

    int mid= (s+e)/2;
    int c1=mergesort(nums,s,mid);
    int c2=mergesort(nums,mid+1,e);
    int c3=merge(nums,s,e);

    return c1+c2+c3;
}
 

int32_t main() 
{
    run();

    int n;
    cin>>n; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    int count=mergesort(nums,0,n-1);

    cout<<count<<endl;
   

    return 0;

}
