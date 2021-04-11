#include <bits/stdc++.h>
using namespace std;
int lcs2(vector<int> &a, vector<int> &b) {
	int n = a.size();
	int m = b.size();
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++)
	{
		d[i][0] = 0;
	}
	for (int i = 0; i <= m; i++)
	{
		d[0][i] = 0;
	}
	int cost = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else
			{
				d[i][j] =max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	return d[n][m];
}

int main() {
	size_t n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		cin >> b[i];
	}
	cout << lcs2(a, b) <<endl;
	return 0;
}
