#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) 
{
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;

  size_t mid = left + (right - left) / 2;//Express indix
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid, right);
  
  size_t track_on_a=left , track_on_mid=mid , copy_in_b=left;
  while(track_on_a<mid && track_on_mid<right)
  {
    if(a[track_on_a]<=a[track_on_mid])
    {
      b[copy_in_b]=a[track_on_a];
      track_on_a++;
      copy_in_b++;
    }
    else{
      b[copy_in_b]=a[track_on_mid];
      track_on_mid++;
      copy_in_b++;
      number_of_inversions += mid-track_on_a;
    }
  }
  while(track_on_a<mid)
  {
    b[copy_in_b]=a[track_on_a];
    track_on_a++;
    copy_in_b++;
  }
  while(track_on_mid<right)
  {
    b[copy_in_b]=a[track_on_mid];
    track_on_mid++;
    copy_in_b++;
  }
  for(size_t m=left; m<right; ++m)
  {
    a[m]=b[m];
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
