#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	char input[11];
	cin>>input;
	for(int i=0;i<strlen(input);i++)
		for(int j=i+1;j<strlen(input);j++)
			if(input[j]>input[i])
				input[j]^=input[i]^=input[j]^=input[i];
	cout<<input<<endl;
	return 0;
}
