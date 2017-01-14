#include <iostream>
using namespace std;
int ce[5000];
int search(int left, int right, int data)
{
	if(left==right)
	{
		if(ce[left]>data)
			return left-1;
		else return left;
	}
		
	int mid=(left+right)/2;
	
	if(ce[mid]==data)
		return mid;
	
	if(ce[mid]>data)
		return search(left,mid,data);
	if(ce[mid]<data)
		return search(mid+1,right,data);
}
int main()
{
	ce[1]=1;
	ce[2]=3;
	for(int i=3;i<5000;i++)
		if(i%2==0)
			ce[i]=ce[i-2]+2*i-1;
		else
			ce[i]=ce[i-1]+1;
			
	int X;
	cin>>X;
	int k=search(0,4999,X);
	if(X<ce[k]+k)
	{
		int abs=X-ce[k];
		int m,s;
		s=k;
		m=1;
		while(abs--)
		{
			s--;
			m++;
		}
		printf("%d/%d\n",s,m);
	}
	else
	{
		int temp=ce[k]+k;
		int abs=X-temp;
		int m,s;
		m=k+1;
		s=1;
		while(abs--)
		{
			m--;
			s++;
			
		}
		printf("%d/%d\n",s,m);
	}
//	while(true);
    return 0;
}
