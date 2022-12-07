#include <bits/stdc++.h>
using namespace std;

int a1[10000 + 5] = {0}, a2[10000 + 5] = {0};

int main()
{	
	int k = 0, m = 0;
	int t;
	char c, n;
	while (scanf("%d", &t))
	{
		if (t == 46) break;
		scanf("%c%c", &c, &n);
			a1[k++] = t;
		if (c == '.' && n == '\n') break;
	}
	while (scanf("%d", &t))
	{
		if (t == 46) break;
		scanf("%c%c", &c, &n);
		a2[m++] = t;
		if (c == '.' && n == '\n') break;
	}
	
	int i;
	for (i = 0; i < k; ++i)
	{
		if (a1[i] <= a2[i])
			cout << a1[i] << "->" << a2[i] << "->";
		else
			cout << a2[i] << "->" << a1[i] << "->";
	}
	if (k > m)
	{
		for (int j = i; j < k; ++j)
			cout << a1[j] << "->";
	}
	else if (k < m)
	{
		for (int j = i; j < m; ++j)
			cout << a2[j] << "->";
	}
		cout << "NULL";
	return 0;
}
