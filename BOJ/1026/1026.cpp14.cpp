#include <iostream>
#include <stdio.h>
using namespace std;
int A[50];
int B[50];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N;i++)
		cin>>B[i];
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
		{
			if(A[i]>A[j])
				A[i]^=A[j]^=A[i]^=A[j];
			if(B[i]<B[j])
				B[i]^=B[j]^=B[i]^=B[j];
		}
	int sum=0;
	for(int i=0;i<N;i++)
		sum+=A[i]*B[i];
	printf("%d\n",sum);
    return 0;
}
