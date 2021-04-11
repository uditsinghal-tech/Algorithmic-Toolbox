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
return c-1;
}
int main(){
long long m,n;
cin>>m>>n;
if(n<=1)
    cout<<n;
else{
long long newm=(m+1)%60;
long long newn=(n+2)%60;
long long a,b;
if(newn<=1)
    a=newn-1;
else{
    a=fibo(newn);
}
if(newm<=1)
    b=newm-1;
else
    b=fibo(newm);
if(a>=b)
cout<<a-b;
else
    cout<<10+a-b;
}
}
