#include <algorithm>
#include <iostream>
#include <vector>
using namespace std ;
int get_majority_element_0(vector<int> &a)
 {
  // 2 3 9 2 2 ==> 2 2 2 3 9 int left, int right
  sort(a.begin(), a.end());

  int half = a.size()/2;
  int count =1;

  for(int i=1; i<a.size(); i++)
  {
    if(a[i]==a[i-1])
  {
    count++;
    if(count > half)
    {
      return 1; 
    }
  }else 
  {
    count =1;  
  }
  
}
return 0;
}

///////////////////////////////////////////////////////////////////////////////////////



 int occourrence(vector<int> &a,int left, int right, int candidate)
 {
  int count=0;
  for(int i=left; i<right; i++)
  {
    
    if(a[i]==candidate)count++;
  }
  return count;
 }


 int get_majority_element(vector<int> &a, int left, int right) 
 {
  //Base case
  if(left+1==right)return a[left];
  //Divide
  int mid = left+(right-left)/2;
  int left_maj=get_majority_element(a,left,mid);
  int right_maj=get_majority_element(a,mid,right);
  //Occurrence
  int left_count = occourrence(a,left,right,left_maj);
  int right_count = occourrence(a,left,right,right_maj);
  int thresould = (right-left)/2;
  if(left_count>thresould)return left_maj;
  if(right_count>thresould)return right_maj;
  return -1;
 }

 int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
      cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size())) << '\n';
}