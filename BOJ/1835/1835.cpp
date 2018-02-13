#include <bits/stdc++.h>
using namespace std;
int n;
deque<int> dq;
int main(){
	scanf("%d",&n);
	dq.push_back(n);
	for(int i=n-1;i>0;i--){
		dq.push_front(i);
		for(int j=0;j<i;j++){
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",dq[i]);
	printf("\n");
	return 0;
}