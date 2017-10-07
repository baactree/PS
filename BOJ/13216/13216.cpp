#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	a=b=0;
	char in;
	int A,B;
	A=B=0;
	while(scanf("%c",&in)!=EOF){
		if(in=='A')
			a++;
		else
			b++;
		if(a==21){
			printf("%d-%d\n",a,b);
			A++;
			a=b=0;
		}
		else if(b==21){
			printf("%d-%d\n",a,b);
			B++;
			a=b=0;
		}
		if(A==2)
			return !printf("A\n");
		if(B==2)
			return !printf("B\n");
	}
	return 0;
}