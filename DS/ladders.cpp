// #include<bits/stdc++.h>
// #include<stdio.h>
// #include<fstream>
// using namespace std;
// #define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define MOD 1000000007
// #define endl "\n"
// #define int long long
// #define pb push_back
// #define ss second
// #define ff first
// #define vi vector<int>
// #define all(a) a.begin(),a.end()
// #define MAXN 10000005
// #define BLOCK 555
// #define pii pair<int,int>
 

// int cnt=0;

// void run()
// {
//     FAST
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif   
// }

// unordered_map<int,bool> mp;

// bool ways(int target,int nums[])
// {
//     if(target<0)
//     return false;

//     if(mp.count(target))
//     {
//         if(mp[target])
//         {
//             cnt++;
//             return true;
//         }

//         else
//         {
//             mp[target]= false;
//             return false;
//         }
//     }

//     for(int i=0;i<3;i++)
//     {
//         int x= target-nums[i]; 
//         if(x==0)
//         {
//             cnt++;
//             mp[target]= true;
//             return true;
//         }

//         else 
//         {
//             mp[target]=ways(x,nums);
//         }
//     }
//     return mp[target];
// }


// int32_t main() 
// {
//     run();

//     int n,target;
//     cin>>n>>target;
//     int nums[n],a=n;

//     for(int i=0;i<n;i++)
//     nums[i]=i+1;

//     ways(target, nums);

//     cout<<cnt;
// }



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
 

int cnt=0;

void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}


void ways(int target,int nums[],int n)
{
    if(target<0)
    return;


    for(int i=0;i<n;i++)
    {
        int x= target-nums[i]; 
        if(x==0)
        {
            cnt++;
            return;
        }

        else 
        ways(x,nums,n);
    }    
}


int32_t main() 
{
    run();

    int n,target;
    cin>>n>>target;
    int nums[n],a=n;

    for(int i=0;i<n;i++)
    cin>>nums[i];

    ways(target, nums,n);

    if(cnt>0)
    cout<<"YES";

    else cout<<"NO";
}

// #include<bits/stdc++.h>
// #include<stdio.h>
// #include<fstream>
// using namespace std;
// #define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define MOD 1000000007
// #define endl "\n"
// #define int long long
// #define pb push_back
// #define ss second
// #define ff first
// #define vi vector<int>
// #define all(a) a.begin(),a.end()
// #define MAXN 10000005
// #define BLOCK 555
// #define pii pair<int,int>
 

// unordered_map<int,bool> mp;

// void run()
// {
//     FAST
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif   
// }


// int ways(int target,int nums[])
// {
//     if(target<0)
//     return 0;

//     if(target==0)
//     return 1;

//     // if(mp.count(target))
//     // return mp[target]; ????wrong ans

//     int sum=0;

//     for(int i=0;i<3;i++)
//     {
//         int x= target-nums[i]; 
        
//         sum+=ways(x,nums);
//     }    

//     mp[target]=sum;
//     return sum;
// }


// int32_t main() 
// {
//     run();

//     int n,target;
//     cin>>n>>target;
//     int nums[n],a=n;

//     for(int i=0;i<n;i++)
//     // nums[i]=i+1;
//     cin>>nums[i];

//     cout<<ways(target, nums);

// }
