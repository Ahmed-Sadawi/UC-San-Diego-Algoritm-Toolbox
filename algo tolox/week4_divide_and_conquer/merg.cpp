#include<iostream>
#include<vector>
using namespace std;
vector<int> MergeR(vector<int>nums1, vector<int>nums2)
{
    vector<int>result;
    int i=0 ,j=0;
    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i]<=nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
        }else{
            result.push_back(nums2[j]);
            j++;
        }
    }
    while(i<nums1.size()){
        result.push_back(nums1[i]);
        i++;
    }
    while(j<nums2.size()){
        result.push_back(nums2[j]);
        j++;
    }
    
  return result;
}


vector<int> mergeSort(vector<int>nums)
{
    int n=nums.size();
    if(n<=1)return nums; //Base statment 
    int mid = n/2;

    vector<int>nums1(nums.begin(), nums.begin()+mid);
    vector<int>nums2(nums.begin()+mid , nums.end());

  nums1 = mergeSort(nums1);
  nums2 = mergeSort(nums2);
    return MergeR(nums1,nums2);
}

int main() {
    vector<int> nums = {6, 3, 8, 5, 2, 7, 4, 1};
    vector<int> sorted = mergeSort(nums);

    cout << "Sorted Array: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    return 0;
}