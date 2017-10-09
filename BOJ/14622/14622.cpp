#include <bits/stdc++.h>
using namespace std;
bool prime[5000000];
int main(){
	prime[0]=prime[1]=true;
	for(int i=2;i<5000000;i++){
		if(!prime[i]){
			for(int j=i+i;j<5000000;j+=i)
				prime[j]=true;
		}
	}
	set<int> s;
	int n;
	priority_queue<int> a,b;
	long long sa,sb;
	sa=sb=0;
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(prime[x]){
			if(b.size()<3)
				sb+=1000;
			else
				sb-=b.top();
		}
		else if(!s.insert(x).second)
			sa-=1000;
		else{
			if(a.size()<3)
				a.push(-x);
			else if(-a.top()<x){
				a.pop();
				a.push(-x);
			}
		}
		if(prime[y]){
			if(a.size()<3)
				sa+=1000;
			else
				sa-=a.top();
		}
		else if(!s.insert(y).second)
			sb-=1000;
		else{
			if(b.size()<3)
				b.push(-y);
			else if(-b.top()<y){
				b.pop();
				b.push(-y);
			}
		}
	}
	if(sa>sb)
		printf("소수의 신 갓대웅\n");
	else if(sb>sa)
		printf("소수 마스터 갓규성\n");
	else
		printf("우열을 가릴 수 없음\n");
	return 0;
}