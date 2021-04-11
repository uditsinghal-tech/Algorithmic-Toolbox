#include<bits/stdc++.h>
using namespace std;
int get_change(int m) {
	vector<vector<int>> table(4);
	int i, j, x, y;
	for (i = 0; i < 4; i++)
	{
		table[i] = vector<int>(m+1);
	}
	for (i = 0; i < m+1; i++)
	{
		table[0][i] = i;
	}
	for (i = 0; i < 4; i++)
	{
		table[i][0] = 0;
	}
	int coin[4] = {0,1,3,4 };
	for (i = 1; i < 4; i++)
	{
		for (j = 1; j < m+1; j++)
		{

			if (j >= coin[i])
			{
				x = table[i - 1][j];
				y = 1 + table[i][j - coin[i]];
				table[i][j] = std::min(x, y);
			}
			else
				table[i][j] = table[i - 1][j];

		}

	}
	return table[3][m];
}
int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
	return 0;
}
