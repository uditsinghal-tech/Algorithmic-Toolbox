#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int binary_search(vector<int> &a, int x) {
  int left = 0, right = (int)a.size();
  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (a[mid] == x)
      return mid;

    else if (a[mid] > x)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  vector<int> c;
  c.push_back(a[0]);
  for(int i=1;i<a.size();i++){
    if(a[i]!=a[i-1])
        c.push_back(a[i]);
  }
  int k;
  cin >> k;
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < k; ++i) {
    cout << binary_search(c, b[i]) << ' ';
  }
}
