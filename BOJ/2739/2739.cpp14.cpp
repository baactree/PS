#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int A;
	cin>>A;
	for(int i=1;i<=9;i++)
	{
		printf("%d * %d = %d\n",A,i,A*i);
	}
    return 0;
}
