#include <bits/stdc++.h>
using namespace std;
int arr[8];
int main(){
	for(int i=0;i<8;i++)
		scanf("%1d",&arr[i]);
	for(int i=0;i<8;i++)
		for(int j=i+1;j<8;j++)
			if(arr[i]+arr[j]==10)
				return !printf("Yes\n");
	printf("No\n");
	return 0;
}