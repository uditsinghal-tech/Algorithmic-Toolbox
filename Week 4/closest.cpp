#include<bits/stdc++.h>
using namespace std;
struct m1m2
{
  int m1;
  int m2;
};
m1m2 partition3(vector<long long> &a, vector<long long> &b, int l, int r) {
  long long x = a[l];
  int j = l-1;
  int k = r+1;
  for (int i = l+1; i < k; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
      swap(b[i], b[j]);
    }
    else if (a[i]> x){
      k--;
      swap(a[i],a[k]);
      swap(b[i],b[k]);
      i--;
    }
  }
  m1m2 result = {j,k};
  return result;
}

void randomized_quick_sort(vector<long long> &a,vector<long long> &b, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  swap(b[l], b[k]);
  m1m2 M = partition3(a, b, l, r);
  randomized_quick_sort(a,b, l, M.m1);
  randomized_quick_sort(a,b, M.m2, r);
}

double calculate_dis(long long x1, long long y1, long long x2, long long y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

long double filter_dis(vector<long long> &x, vector<long long> &y, int l, int r, int mid, long double mind_lr){
  long double x_mid;
  if((r - l + 1)%2 == 0){x_mid = (x[mid] + x[mid + 1])/2;}
  else{x_mid = x[mid];}
  long double bound_l = x_mid - mind_lr;
  long double bound_r = x_mid + mind_lr;
  long double min_dis = mind_lr;
  vector<long long> x_in_range;
  vector<long long> y_in_range;
  for(int i = l; i <= r ; i++){
    if(x[i] >= bound_l && x[i] <= bound_r){
      x_in_range.push_back(x[i]);
      y_in_range.push_back(y[i]);
    }
  }
  randomized_quick_sort(y_in_range, x_in_range, 0, x_in_range.size()-1);
  bool points_crossed;
  long double new_dis;
  for(int j = 0; j < x_in_range.size(); j++){
    int cnt = 0;
    for(int k = j + 1; k < x_in_range.size(); k++){
      if(cnt > 7){break;}
      points_crossed = ((x_in_range[j] - x_mid)*(x_in_range[k] - x_mid) <= 0);
      if(points_crossed) {
        new_dis = calculate_dis(x_in_range[j],y_in_range[j],x_in_range[k],y_in_range[k]);
        min_dis = min<long double>(new_dis, min_dis);
      }
      cnt++;
    }
  }
  return min_dis;
}

long double find_min_dis(vector<long long> &x, vector<long long> &y, int l, int r){
  if(l == r - 1){return calculate_dis(x[l],y[l],x[r],y[r]);}
  if(l == r){return calculate_dis(x[l-1],y[l-1],x[r],y[r]);}
  int mid = (r + l)/2;
  long double mind_l = find_min_dis(x, y, l, mid);
  long double mind_r = find_min_dis(x, y, mid + 1, r);
  long double mind_lr = min<long double >(mind_l, mind_r);
  if(mind_lr == 0.0){return mind_lr;}
  long double mind_m = filter_dis(x, y, l, r, mid, mind_lr);
  return min<long double>(mind_lr, mind_m);
}

long double minimal_distance(vector<long long> &x, vector<long long> &y) {
  randomized_quick_sort(x, y, 0, x.size()-1);
  long double min_dis = find_min_dis(x, y, 0, x.size() - 1);
  return min_dis;
}

int main() {
  size_t n;
  cin >> n;
  vector<long long> x(n);
  vector<long long> y(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout << std::fixed;
  cout << setprecision(9) << minimal_distance(x, y) << "\n";
}
