#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int pow(int a, int b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b % 2 == 0)
	{
		int temp = pow(a, b / 2);
		return (temp*temp)%10;
	}
	else
	{
		return (pow(a, b - 1)*a)%10;
	}

}
int main()
{
	int Case;
	cin >> Case;
	while (Case--)
	{


		int a, b;
		cin >> a >> b;
		int temp = pow(a, b);
		if (temp == 0)
			temp += 10;
		cout << temp << endl;
	}
	return 0;	

}
