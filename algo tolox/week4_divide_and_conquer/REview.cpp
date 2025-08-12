#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int binary_search(const vector<int> &a, int x)
{
    int size = a.size();
    int left = 0;
    int right = size-1;
    while(left<=right)
    {
        int mid = size/2;
        if(a[mid]==x)return mid;
        else if(a[mid]<x)left=mid+1;
        else if(a[mid]>x)right=mid-1;
    }
    return -1;
}


vector<int>selection_sort(vector<int>nums)
{
   for(int i =0; i<nums.size()-1; i++)
   {
    int smallest =i;
    for(int j =i+1; j<nums.size(); j++)
    {
        if(nums[j]>smallest)
        {
            smallest=j;
        }
    }
    int pridge =nums[i];
    nums[i]=nums[smallest];
    nums[smallest]=pridge;
   }
}
// we need to compute this ac*10^n +((a+b)(c+d)-ac-bd)10^m+bd 
long long kara(long long x,long long y)
{
    if(x<=10 || y<=10)return x*y;

    int nof_digits = max((int )log10(x)+1, (int) log10(y)+1);
    int n = nof_digits/2;

    long long a = x/pow(10,n);
    long long b = (long long)x%pow(10,n);
    long long c = y/pow(10,n);
    long long d = (long long)y%pow(10,n);

    long long ac = kara(a,c);
    long long bd = kara(b,d);
    long long mid = kara(a+b,c+d);
    return ac*pow(10,n*2) + (mid-ac-bd)*pow(10,n)+bd;

}

vector<int>partition(vector<int>nums1,vector<int>nums2)
{
    vector<int>result;
    int i , j = 0;
    while(nums1.size()>i && nums2.size()>j)
    {
        if(nums1[i]<=nums[j])
        {
            result.push_back(nums1[i]);
            i++;
        }
        else 
        {
            result.push_back(nums2[j]);
            j++;
        }
    }
    while(nums1.size()>i)
    {
        result.push_back(nums1[i]);
        i++; 
    }
    while(nums2.size()>j)
    {
        result.push_back(nums2[j]);
        j++; 
    }
    return result ;
}


vector<int> Merge(vector<int>nums)
{
    if(nums.size()<=1)return nums ;
    int mid = nums.size()/2;

    vector<int>nums1(nums.begin(),nums.begin()+mid);
    vector<int>nums2(nums.begin()+mid,nums.end());

    nums1=Merge(nums1);
    nums2=Merge(nums2);

    partition(nums1,nums2);
}

vector<int>count_s(vector<int>nums)
{
    int max = nums[0];
    for(int i = 0; i<nums.size(); i++)if(nums[i]<max)max=nums[i];
    vector<int>count(max+1,0);
    for(int i =0; i<nums.size(); i++)
    {
        count[nums[i]]++;
    }
    int idx = 0;
    for(int i =0; i<=max; i++)
    {
        while(count[i]>0)
        {
            nums[idx]=i;
            idx++;
            count[i]--;
        }
    }
      return nums; 
}

int occ(vector<int>&a,int left,int right,int cadidate)
{
    int count = 0;
    for(int i = 0; i<right; i++)
    {
        if(a[i]==cadidate)count++;
    }
    return count;
}


int get_majority_element(vector<int> &a, int left, int right)
{
    if(left+1==right)return a[left];
    int mid = left+(right-left)/2;

    int left_maj = get_majority_element(a,left,mid);
    int right_maj = get_majority_element(a,mid,right);

    int left_count  = occ(a,left,right,left_maj);
    int right_count = occ(a,left,left,right_maj);

    int thresould = (right-left)/2;

}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
    int num_of_inver = 0;
    if(left+1<=right)return num_of_inver;

    int mid = left+(right-left)/2;
    num_of_inver += get_number_of_inversions(a,b,left,mid);
    num_of_inver += get_number_of_inversions(a,b,mid,right);

    size_t track_on_a = left, track_on_mid = mid, track_on_b = left;
    while(track_on_a<mid && track_on_mid<right)
    {
        if(a[track_on_a]<=a[track_on_b])
        {
            b[track_on_b]=a[track_on_a];
            track_on_a++;
            track_on_b++;
        }else{
            b[track_on_b]=a[track_on_mid];
            track_on_b++;
            track_on_mid++;
            num_of_inver += mid-track_on_a;
        }
    }
    while(track_on_a<mid){
        b[track_on_b]=a[track_on_a];
        track_on_a++;
        track_on_b++;
    }
    while(track_on_mid<right)
    {
        b[track_on_b] = a[track_on_mid];
        track_on_mid++;
        track_on_b++;
    }

}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
    vector<int>count(points.size());
    vector<tuple<int,char,int>>events;
    for(int s : starts)
    {
        events.emplace_back(s,'L',-1);
    }
    for(int e : ends)
    {
        events.emplace_back(e,'R',-1);
    }
    for(int i = 0; i<points.size(); i++)
    {
        events.emplace_back(points[i],'P',i);
    }
    sort(events.begin(),events.end());
    int active_seg = 0;
    for(auto[val,type,idx] : events)
    {
        if(type=='L')active_seg++;
        else if(type=='P')
        {
            count[idx]=active_seg;
        }
        else active_seg--;
    }
    return count;
}


int main() {
    int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
      cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}