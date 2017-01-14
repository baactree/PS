#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int L, C;
char compo[15];
char vowel[5] = { 'a','e','i','o','u' };
void search(int index,string pass)
{
	int len = pass.size();
	if (len == L)
	{
		int cnt = 0;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < 5; j++)
				if (pass[i] == vowel[j])
					cnt++;
		if (cnt > 0&&L-cnt>1)
			cout << pass << endl;
		return;
	}
	if (index == C)
		return;
	search(index + 1, pass + compo[index]);
	search(index + 1, pass);
}
int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> compo[i];
	sort(compo, compo + C);
	search(0,"");
	return 0;
}
