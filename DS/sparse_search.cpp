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

int sparse(string str[], int n,string a)
{
    int s=0,e=n-1;
    int mid;
int i=1;
    while(s<=e)
    {
        mid= (s+e)/2;

        if(str[mid]=="")
        {
            int f=mid+1,b=mid-1;

            while(1)
            {
                if(b<s && f>e)
                return -1;

                
                else if(b>=s && str[b]!="")
                {    
                    mid=b;
                    break;
                }

                else if(f<=e && str[f]!="")
                {    
                    mid=f;
                    break;
                }

                b--;
                f++;
            }
        }

        if(str[mid]==a)
        return mid; 

        if(str[mid]>a)
        {
            e=mid-1;
        }

        if(str[mid]<a)
        {
            s=mid+1;
        }
    }
    return -1;
}

int32_t main() 
{
    int n=11;
    string s[]={"ai","","","bat","","","car","cat","","","dog"};
    string a;
    cin>>a;
    int x=sparse(s,n,a);

    cout<<x;

    return 0;

}