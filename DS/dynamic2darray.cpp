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
 
int **d2Darray(int rows,int cols)
{
    int **arr= new int*[rows];

    for(int i=0;i<rows;i++)
    {
        arr[i]= new int [cols];
    }

    int value=0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        arr[i][j]= value++;
    }

    return arr;
} 

int32_t main() 
{
    run();

    int rows,cols;
    cin>>rows>>cols;


    int **A= d2Darray(rows,cols);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
