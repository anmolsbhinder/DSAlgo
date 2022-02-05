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
 
bool isSafe(int mat[][9],int i,int j, int no, int n)
{
    int sx= (i/3) * 3;
    int sy= (j/3) * 3;

    for(int k=0; k<n;k++)
    {
        if(mat[i][k]==no || mat[k][j]==no)
        return false;
    }

    for(int x=sx; x<sx+3;x++)
    for(int y=sy; y<sy+3;y++)
    {
        if(mat[x][y]==no)
        return false;
    }

    return true;

}

bool sudoku(int mat[][9],int i,int j,int n)
{
    if(i==n) 
    {
        for(int p=0;p<n;p++)
        {
        for(int q=0;q<n;q++)
        {
            cout<<mat[p][q]<<" ";
        }
        cout<<endl;
        }
        return true;
    }

    if(j==n)
    {
        return sudoku(mat, i+1, 0,n);
    }

    if(mat[i][j]>0)
    { 
        return sudoku(mat, i, j+1,n);
    }

    for(int no=1; no<=n; no++)
    {
        if(isSafe(mat, i, j, no, n))
        {
            mat[i][j]=no;
            bool subp= sudoku(mat,i,j+1,n);;
            if(subp)
            {
                return true;
            }
        }
    }

    mat[i][j]=0;
    return false;
}
    



int32_t main() 
{
    run();

    int n=9;
    int mat[9][9];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        cin>>mat[i][j];
    }
    
    bool ans=sudoku(mat,0 ,0 ,n);
}
