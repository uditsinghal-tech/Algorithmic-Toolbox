#include<bits/stdc++.h>
using namespace std;
struct m1m2
{
  int m1;
  int m2;
};
m1m2 partition3(vector<int> &a,vector<int> &b,vector<int> &c, int l, int r) {
  int x = a[l];
  int j = l-1;
  int k = r+1;
  for (int i = l+1; i < k; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
      swap(b[i], b[j]);
      swap(c[i], c[j]);
    }
    else if (a[i]> x){
      k--;
      swap(a[i],a[k]);
      swap(b[i],b[k]);
      swap(c[i],c[k]);
      i--;
    }
  }
  m1m2 result = {j,k};
  return result;
}

void randomized_quick_sort(vector<int> &a,vector<int> &b,vector<int> &c, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  swap(b[l], b[k]);
  swap(c[l], c[k]);
  m1m2 M = partition3(a, b, c, l, r);
  randomized_quick_sort(a,b,c, l, M.m1);
  randomized_quick_sort(a,b,c, M.m2, r);
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  vector<int> cnt_seg(starts.size());
  int v_size = starts.size() + ends.size() + points.size();
  vector<int> v1(v_size);
  vector<int> v2(v_size);
  vector<int> v3(v_size);
  int i,j = 0;
  for(i = 0; i < points.size(); i++){
    v1[i] = points[i];
    v2[i] = i;
    v3[i] = -1;
  }
  for(i = points.size(); i < v_size; i++){
    v1[i] = starts[j];
    v1[i+1] = ends[j];
    v2[i] = -1;
    v2[i+1] = -2;
    v3[i] = j;
    v3[i+1] = j;
    j += 1;
    i += 1;
  }
  randomized_quick_sort(v1, v2, v3, 0, v_size - 1);

  for(i = 0; i < v_size; i++){
    if(v1[i] == v1[i+1]){
      vector<int> idx_temp;
      int cnt_temp = 0;
      int same_element = v1[i];
      while(v1[i] == same_element){
        if(v3[i] == -1){idx_temp.push_back(v2[i]);}
        else{
          if(v2[i] == -1){cnt_seg[v3[i]] = (cnt_seg[v3[i]] + 1)%2;}
          else if(v2[i] == -2){
            cnt_seg[v3[i]] = (cnt_seg[v3[i]] + 1)%2;
            cnt_temp++;
          }
        }
        i++;
      }
      i--;
      for(int k = 0; k < idx_temp.size(); k++){cnt[idx_temp[k]] = cnt_temp + accumulate(cnt_seg.begin(),cnt_seg.end(),0);}
    }
    else if(v3[i] == -1){
      cnt[v2[i]] += accumulate(cnt_seg.begin(),cnt_seg.end(),0);
    }
    else{cnt_seg[v3[i]] = (cnt_seg[v3[i]] + 1)%2;}
  }
  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    cin >> points[i];
  }
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    cout << cnt[i] << ' ';
  }
}
