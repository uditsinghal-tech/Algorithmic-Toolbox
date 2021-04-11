#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    long long a=0,b=1,c=0;
    if(n<=1) cout<<n;
    else{
    for(int i=2;i<=n;i++){
        c=b+a;
        a=b;
        b=c;
    }
    cout <<c<< '\n';
    }
    return 0;
}
