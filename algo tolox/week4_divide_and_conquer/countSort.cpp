#include <iostream>
#include <vector>
using namespace std;
vector<int>count_sort(vector<int>arr)
{
    int n = arr.size();
    int max =arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]>max)max =arr[i];
    }
    vector<int>count(max+1,0);
    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }
    int index=0; //Expresses the next indx we have to put the elem in it 
    for(int i =0; i<=max; i++)
    {    //The v ar i there Expresses value
        
    while(count[i]>0)
        //THE count fun have 0 or {1..n} 
        //0 Expresses the absence of the eleme 
        //{1..n} exp that the elem exist and the repeated of it 
        {
            arr[index]=i;
            index++;
            count[i]--;
        }
    }
  return arr;
}
int main() {
    
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    vector<int> sortedArr = count_sort(arr);
    cout << "Sorted array: ";
    for (int num : sortedArr) cout << num << " ";
    cout << endl;

    return 0;
}