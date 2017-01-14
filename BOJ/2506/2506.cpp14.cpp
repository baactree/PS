#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int input[100];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%d",&input[i]);
	
	int sum=0;
	int before=0;
	for(int i=0;i<N;i++)
	{
		if(input[i]==1)
		{
			sum+=before+1;
			before++;
		}
		else
			before=0;
	}
	printf("%d\n",sum);
	
    return 0;
}
