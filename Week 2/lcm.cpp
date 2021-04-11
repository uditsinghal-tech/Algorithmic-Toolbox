#include <iostream>
using namespace std;
int main() {
  long long a, b,c;
  cin >> a >> b;
  long long d=a;
  long long e=b;
  while(b!=0){
    c=a%b;
    a=b;
    b=c;
  }
  cout<<(d*e)/a;
  return 0;
}
