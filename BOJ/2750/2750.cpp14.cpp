#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int input[1000];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%d",&input[i]);
	sort(input,input+N);
	for(int i=0;i<N;i++)
		printf("%d\n",input[i]);
    return 0;
}
