#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
int main()
{
	int Case;
	cin>>Case;
	while(Case--)
	{
		int prize,N,a,b;
		cin>>prize>>N;
		for(int i=0;i<N;i++)
		{
			cin>>a>>b;
			prize+=a*b;
		}
		printf("%d\n",prize);
		
	}
	return 0;
}
