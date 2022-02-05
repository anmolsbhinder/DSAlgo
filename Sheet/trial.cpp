#include<bits/stdc++.h>
#include<stdio.h>
#include<fstream>
using namespace std;
#include<string.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define endl "\n"
#define int long long
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define all(a) a.begin(),a.end()
 
void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void solve()
{
        vector<int>nums{1,2,3};


        vector<int>v;
        v.push_back(nums[nums.size()-1]);
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<nums.size();i++)
        mp[nums[i]].push_back(i);
        
        int pos=0,flag=0;
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            int value=nums[i];
            auto it = upper_bound(v.begin(), v.end(), value); 
            v.insert(it, value);

            it = upper_bound(v.begin(), v.end(), value); 

            
            if(it!=v.end())
            {
                int temp= nums[i];
                pos= mp[*it][0];
                nums[i]=nums[pos];
                nums[pos]=temp;
                flag=1;
                break;
            }
            
        }
        
        if(flag==1)
        sort(nums.begin()+pos+1,nums.end());

        else
        sort(nums.begin(),nums.end());
}


int32_t main()
{
    run();
    solve();
}   

