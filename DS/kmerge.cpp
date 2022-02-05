#include<bits/stdc++.h>
#include<stdio.h>
#include<queue>
#include<fstream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define vi vector<int>
#define all(output) output.begin(),output.end()

class merge
{
public:
    int kid;
    int val;

    merge(int kid, int val)
    {
        this->kid=kid;
        this->val=val;
    }
};
 
class mercmp
{
public:
    bool operator()(const Car A,const Car B)
    {
        return A.dist()<B.dist();
    } 
};

void run()
{
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}


int main() 
{
    run();
    int k;
    cin>>k;

    vector<vector<merge>> arr(k);
    vector<int> idx(k,0)

    priority_queue<merge,vector<merge>,mercmp> max_heap(arr.begin(), cars.begin()+k);
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<k;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<k;i++)
    {
        pq.push(arr[i][0]);
    }

    

    return 0;
}
