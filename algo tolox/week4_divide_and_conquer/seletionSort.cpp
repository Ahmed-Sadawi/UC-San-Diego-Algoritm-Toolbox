#include<iostream>
#include<vector>

using namespace std;

vector<int>seleSort(vector<int>arr)
{
    int n = arr.size();
    for(int i=0; i<n-1; i++)
    {
        int Sidx =i;
        //int comelem = ;
      for(int j=i+1; j<n; j++ )
      {
        if(arr[j]<arr[Sidx])
        {
            Sidx=j;
        }
      }
     int bridg = arr[i];
     arr[i]=arr[Sidx];
     arr[Sidx]=bridg;
    }
     return arr; 
}
// Time complexity for it O(n^2) for that it is not effecient 
int main()
{
   vector<int>nums= seleSort({2,2,1,4,5,3,8});
    for(int i : nums )cout<<i<<endl;
}