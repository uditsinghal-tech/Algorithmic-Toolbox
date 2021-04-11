#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(),numbers.end());
    if(n==1) cout<<numbers[0];
    else if(numbers[n-1]<=0){
        cout<<numbers[0]*numbers[1];
    }
    else if(numbers[0]>=0){
        cout<<numbers[n-1]* numbers[n-2];
    }
    else{
        cout<<max(numbers[0]*numbers[1],numbers[n-1]*numbers[n-2]);
    }
    return 0;
}
