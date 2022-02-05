#include<bits/stdc++.h>
#include<stdio.h>
#include<fstream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Largest
{
   private:
   int a,b,c;

   public:
   void input()
   {
 
      cout<<"Enter 3 numbers: ";
      cin>>a>>b>>c;
 
      cout<<a<<" "<<b<<" "<<c<<endl<<endl;
   }
 
   void output()
   {
      if(a>=b && a>=c)
      cout<<"The largest number is: "<<a;
   
      else if(b>=a && b>=c)
      cout<<"The largest number is: "<<b;
 
      else
      cout<<"The largest number is: "<<c;
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
   Largest obj;
   obj.input();
   obj.output();
   return 0;
}
