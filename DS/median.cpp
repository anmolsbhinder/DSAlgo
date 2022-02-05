#include<bits/stdc++.h>
#include<stdio.h>
#include<queue>
#include<fstream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define vi vector<int>
#define all(output) output.begin(),output.end()

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
    int n;
    cin>>n;

    vector<int> num(n);
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;

    cin>>num[0];
    max_heap.push(num[0]);
    cout<<num[0]<<endl;

    double med;

    for(int i=1;i<n;i++)
    {
        cin>>num[i];
        int x=num[i];
        
        if(max_heap.size()==min_heap.size())
        {
            if(x>min_heap.top())
            {
                min_heap.push(x);
                cout<<min_heap.top()<<endl;
            }

            else
            {
                max_heap.push(x);
                cout<<max_heap.top()<<endl;
            }
        }

        else if(max_heap.size()>min_heap.size())
        {
            if(x>max_heap.top())
            {
                min_heap.push(x);
            }

            else
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(x);
            }

            med= (double)(max_heap.top()+min_heap.top())/2;
            cout<<med<<endl;
        }

        else if(max_heap.size()<min_heap.size())
        {
            if(x<min_heap.top())
            {
                max_heap.push(x);
            }

            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(x);
            }

            med= (double)(max_heap.top()+min_heap.top())/2;
            cout<<med<<endl;
        }

    }


    return 0;
}
