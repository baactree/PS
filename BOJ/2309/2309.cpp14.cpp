#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int tall[9];
int output[7];
void search(int index, int sum,int num){
	if(num==7){
		if(sum==100){
			for(int i=0;i<7;i++)
				printf("%d\n",tall[output[i]]);
			return;
		}
		else
			return;
	}
	if(index==9)
		return;
	for(int i = index;i<9;i++){
		output[num]=i;
		search(i+1,sum+tall[i],num+1);
	}	
}
int main(){
	for(int i=0;i<9;i++)
		cin>>tall[i];
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
			if(tall[i]>tall[j])
				tall[i]^=tall[j]^=tall[i]^=tall[j];
	search(0,0,0);
	return 0;
}
