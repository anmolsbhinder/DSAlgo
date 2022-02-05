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

void merge(vi &num,int s, int e)
{
    int i=s;
    int mid= (s+e)/2;
    int j= mid+1;

    vi temp;
    int k=0;
    while(i<=mid && j<=e)
    {
        if(num[i]<=num[j])
            temp.push_back(num[i++]);
        else
            temp.push_back(num[j++]);
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
    return;
}

void mergesort(vi &nums,int s, int e)
{
    if(s>=e) return;

    int mid= (s+e)/2;
    mergesort(nums,s,mid);
    mergesort(nums,mid+1,e);
    return merge(nums,s,e);
}
 

int32_t main() 
{
    run();

    int n;
    cin>>n; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    mergesort(nums,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<endl;
    }

    return 0;

}
