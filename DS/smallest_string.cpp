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

bool compare(string x, string y)
{
    return x+y < y+x;
}

int32_t main() 
{
    run();

    int n;
    cin>>n;
    vector<string> s(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }

    sort(s.begin(),s.end(),compare);

    for(auto x: s)
    {
        cout<<x;
    }

    return 0;

}
