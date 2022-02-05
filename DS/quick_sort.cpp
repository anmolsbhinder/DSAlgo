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

void quicksort(vi &nums,int s, int e)
{
    if(s>=e) return;

    int p= partition(nums,s,e);
    quicksort(nums,s,p-1);
    quicksort(nums,p+1,e);
}
 

int32_t main() 
{
    run();

    int n;
    cin>>n; 
    vi nums(n);

    for(int i=0;i<n;i++)
    cin>>nums[i];

    quicksort(nums,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;

}
