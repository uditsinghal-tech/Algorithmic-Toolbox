#include <bits/stdc++.h>
using namespace std;
long long fibo(long long n){
long long a=0,b=1,c;
for(int i=2;i<n+1;i++){
    c=a+b;
    c=c%10;
    a=b;
    b=c;
}
return c;
}

int main(){
long long n;
cin>>n;
long long n1=n%60;
long long n2=(n+1)%60;
long long a,b;
if (n1<=1)
    a=n1;
else
    a=fibo(n1);
if (n2<=1)
b=n2;
else
    b=fibo(n2);
cout<<(a*b)%10;
}

