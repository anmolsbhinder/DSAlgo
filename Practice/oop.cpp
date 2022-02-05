#include <iostream>
using namespace std;
#define size 100

class num
{
  private:
  int arr[size];

  public:
  void create(int n)
  {
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
    cin >> arr[i];
    }
}

int search(int key, int n)
{
   for (int i = 0; i < n; i++)
   {
     if (numarr[i] == key)
     {
        return i; 
     }
   }
   return -1; 
 }
};

int main()
{
  num arr;
  cout << "Enter size: ";
  int n;
  cin >> n;

  arr.create(n);
  cout << "Number to search: ";
  int k;
  cin >> k;
  int ans = arr.search(k, n);

  if (ans == -1)
  {
   cout << k << " not present";
  }

  else
  {
   cout << k << "  present at index " << ans << endl;
  }

  return 0; 
}