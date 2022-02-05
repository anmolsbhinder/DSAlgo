#include<bits/stdc++.h> 
using namespace std; 
 
template<typename tn> 

class calculate
{ 
    tn x; 

    public: 
 
    void getdata()
    { 
        cout<<endl<<"x: "; 
        cin>>x;    
    } 
 
    void show()
    { 
        cout<<endl<<"x : "<<x<<endl;      
    } 
 
    template <typename tn1 ,typename tn2 > 
    friend void square(calculate<tn2> &obj); 
}; 
 
template<typename tn1 ,typename tn> 
void square(calculate<tn> &obj)
{ 
    tn1 ans; 
    ans =  obj.x * obj.x; 
    cout<<endl<<"Square: "<<ans<<endl; 
} 
 
int main()
{ 
    calculate<int> obj; 
    obj.getdata(); 
    double value =0; 
    square<int>(obj); 
    return 0; 
}