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
int A[100000];
int B[100000];
bool search(int left,int right,int data,int *arr)
{
		int mid=(left+right)/2;
	if(left==right)
	{
		if(arr[left]==data)
			return true;
		else
			return false;
	}

	if(arr[mid]==data)
		return true;
	
	if(arr[mid]>data)
	{
		return	search(left,mid,data,A);	
	}
	else if(arr[mid]<data)
	{
		return search(mid+1,right,data,A);
	}
	
}
int main()
{
	int N,M;
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	cin>>M;
	for(int i=0;i<M;i++)
		scanf("%d",&B[i]);
	
	sort(A,A+N);
	
	
	
	for(int i=0;i<M;i++)
		if(search(0,N-1,B[i],A))
			printf("1\n");
		else 
			printf("0\n");
	//while(true);
    return 0;
}
