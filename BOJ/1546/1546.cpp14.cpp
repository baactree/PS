#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


double grade[1000];
int N;
int main()
{
//	freopen("sample.txt","r",stdin);
	cin>>N;
	double Max=-1;
	for(int i=0;i<N;i++)
	{
		scanf("%lf",&grade[i]);
		Max=max(Max,grade[i]);
	}
	double sum;
	for(int i=0;i<N;i++)
	{
		grade[i]=grade[i]/Max*100;
		sum+=grade[i];
	}
	
	printf("%.2lf\n",sum/N);
//	while(true);
    return 0;
}
