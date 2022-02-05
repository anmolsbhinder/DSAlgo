#include <iostream> 
#include<bits/stdc++.h>
#include <iostream> 
using namespace std;

int sum(int& n1,int& n2)
{ 
	int ans=n1+n2;
	return ans;
}

int diff(int& n1,int& n2)
{
	int ans=n1-n2; 
	return ans;
}

int prod(int& n1,int& n2)
{
	int ans=n1*n2;
	return ans; 
}

double divi(int& n1,int& n2)
{ 
	double ans=(double)n1/n2;
	return ans; 
}

void run()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   
}

int main()
{
	run();
  int n1,n2;
 
  cout<<"Enter n1 and n2: ";
  cin>>n1>>n2;
 
  cout<<n1<<" "<<n2<<endl;
 
  cout<<endl<<"Sum  : "<<sum(n1,n2)<<endl;
  cout<<"Difference : "<<diff(n1,n2)<<endl;
  cout<<"Product    : "<<prod(n1,n2)<<endl;
  cout<<"Division   : "<<(double)divi(n1,n2)<<endl;

  return 0;
}