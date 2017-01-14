#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int input[300][300];
int main()
{
	int min_h=987654321;
	int min_j=987654321;
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	min_h=min(min_h,a);
	min_h=min(min_h,b);
		min_h=min(min_h,c);
			min_j=min(min_j,d);
				min_j=min(min_j,e);
				printf("%d\n",min_h+min_j-50);
	return 0;
}
