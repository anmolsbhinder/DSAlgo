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
        int n,k;
        cin>>n>>k;

        vi arr(n);
        vi zero;
        int fc=0,count=0,sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]==0)
            {
                count++;
            }
            else
            {
                zero.push_back(count);
                fc+=count;
                count=0;
            }
        }

        int size= zero.size();

        if(arr[0]==0 && arr[n-1]==0)
        {
            zero[0]+=zero[size-1];
            zero.erase(zero.end());
            size-=1;
        }

        int c=fc,temp=fc;

        while(temp>0 && k--)
        {
            for(int i=0;i<size;i++)
            {
                if(zero[i]>=2)
                {
                    temp-=2;
                    zero[i]-=2;
                }

                if(zero[i]==1)
                {
                    temp-=1;
                    zero[i]-=1;
                }
            }

            c+=temp;
        }

        if(fc==0) k++;

        int ans= sum+ (k*2*n);
        ans-= (c*2);

        cout<<ans<<endl;


    }
    
       


    return 0;

}
