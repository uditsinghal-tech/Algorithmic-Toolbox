#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a=0,b=1,c=0;
	if(n<=1){
		cout<<n<<endl;
	}
	else{
	    for(int i=0;i<n-1;i++){
	        c = a+b;
	        c=c%10;
	        a=b;
	        b=c;
	    }
	    cout<<c<<endl;
	}
	return 0;
}
