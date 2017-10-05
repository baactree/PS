#include <bits/stdc++.h>
using namespace std;
int calc(int a,int b){
	if(a==b)
		return a*10;
	return (a+b)%10;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	vector<int> vec;
	for(int i=1;i<=10;i++){
		if(a==i)
			continue;
		vec.push_back(i);
	}
	for(int i=1;i<=10;i++){
		if(b==i)
			continue;
		vec.push_back(i);
	}
	int p,q;
	p=q=0;
	for(int i=0;i<vec.size();i++)
		for(int j=i+1;j<vec.size();j++){
			p++;
			if(calc(a,b)>calc(vec[i],vec[j]))
				q++;
		}
	printf("%.3f\n",(double)q/p);
	return 0;
}