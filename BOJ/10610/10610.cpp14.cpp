#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>

using namespace std;

char num[100001];

int main()
{
	cin >> num;
	int len = strlen(num);
	int sum = 0;
	bool flag = false;

	for (int i = 0; i < len; i++)
	{
		if (num[i] == '0')
			flag = true;
		sum += num[i] - 48;
	}
	if (flag&&(sum % 3)==0)
	{
		sort(num, num + len);
		for (int i = len - 1; i >= 0; i--)
			printf("%c",num[i]);
		printf("\n");
	}
	else
		printf("-1\n");
	
	return 0;
}
