#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cmath>
#include <deque>
using namespace std;
string check[10]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
int main()
{
	string arr[3];
	for(int i=0;i<3;i++)
		cin>>arr[i];
	unsigned long long sum=0;
	
	for(int i=0;i<10;i++)
		if(arr[0]==check[i])
			sum=10*i;
	for(int i=0;i<10;i++)
		if(arr[1]==check[i])
			sum+=i;
	for(int i=0;i<10;i++)
		if(arr[2]==check[i])
			sum*=pow((double)10,i);
			
	cout<<sum<<"\n";
	
	
    return 0;
}
