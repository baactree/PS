#include <bits/stdc++.h>
using namespace std;
vector<int> p;
int n;
int arr[5005];
bool contain(int x){
	for(int i=0;i<p.size();i++)
		if(x%p[i]==0)
			return true;
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<n;i++){
		if(contain(arr[i]-1))
			continue;
		p.push_back(arr[i]-1);
	}
	printf("%d\n",p.size());
	return 0;
}