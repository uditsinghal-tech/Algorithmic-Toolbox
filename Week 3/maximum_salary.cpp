#include<bits/stdc++.h>
using namespace std;
bool cmp(string a , string b)
{
  string A , B;
  A = a.append(b);
  B = b.append(a);

  return A.compare(B) > 0 ? 1 : 0;
}
string largest_number(vector<string> a) {
  sort(a.begin() , a.end() , cmp);
  stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}
int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
}
