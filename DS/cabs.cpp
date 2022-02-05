#include<bits/stdc++.h>
#include<stdio.h>
#include<queue>
#include<fstream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define vi vector<int>
#define all(output) output.begin(),output.end()


class Car
{
public:
    string id;
    int x,y;

    Car(string id, int x, int y)
    {
        this->id=id;
        this->x=x;
        this->y=y;
    }

    int dist() const
    {
        return x*x + y*y;
    }
};
 
class CarCompare
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

void printnearest(vector<Car> cars, int k)
{
    priority_queue<Car,vector<Car>,CarCompare> max_heap(cars.begin(), cars.begin()+k);

    for(int i=k;i<cars.size();i++)
    {
        auto car= cars[i];

        if(car.dist()<max_heap.top().dist())
        {
            max_heap.pop();
            max_heap.push(car);
        }
    }

    vector<Car> output;
    while(!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    reverse(all(output));

    for(auto car : output)
    {
        cout<<car.id<<endl;
    }
}

int main() 
{
    run();
    int n,k;
    cin>>n>>k;

    string id;
    int x,y;

    vector<Car> cars;

    for(int i=0;i<n;i++)
    {
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    printnearest(cars,k);

    return 0;
}
