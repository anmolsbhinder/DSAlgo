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

int partition(vi &num,int s, int e)
{
    int pivot= num[e];
    int i=s;

    for(int j=s;j<e;j++)
    {
        if(num[j]<pivot)
        {
            swap(num[i],num[j]);
            i++;
        }
    }
    swap(num[e],num[i]);
    return i;
}

int quickselect(vi &nums,int s, int e,int k)
{
    int p= partition(nums,s,e);

    if(p==k)
    return nums[p];

    else if(k<p)
    return quickselect(nums,s,p-1,k); 
    
    else if(k>p)
    return quickselect(nums,p+1,e,k);
}
 

int32_t main() 
{
    run();

    int n,k;
    cin>>n>>k; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    cout<<quickselect (nums,0,n-1,k-1);
    return 0;

}
