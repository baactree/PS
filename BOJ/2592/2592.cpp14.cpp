#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
int input[10];
int cnt[10];
int main()
{
	int sum=0;
	
	for(int i=0;i<10;i++)
	{
		cin>>input[i];
		sum+=input[i];
	}
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(input[i]==input[j])
				cnt[i]++;
	int M,Mc;
	M=0;
	for(int i=0;i<10;i++)
		if(M<cnt[i])
		{
			M=cnt[i];
			Mc=input[i];
		}
	printf("%d\n%d\n",sum/10,Mc);
	return 0;
}
