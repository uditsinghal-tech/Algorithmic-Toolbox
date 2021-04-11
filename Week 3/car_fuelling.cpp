#include<iostream>
using namespace std;
int main(){
long long d,m,n;
cin>>d>>m>>n;
long long arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int count=0,distance=arr[0],p=0;
for(int i=1;i<n;i++){
    if(arr[i]-arr[i-1]>m){
        p=1;
        break;
    }
    else{
        distance+=arr[i]-arr[i-1];
        if(distance>m){
            count++;
            distance=arr[i]-arr[i-1];
        }
    }
}
if(p==1 || d-arr[n-1]>m)
    cout<<-1;
else{
    if(distance+d-arr[n-1]>m)
    count++;
    cout<<count;
}
}

