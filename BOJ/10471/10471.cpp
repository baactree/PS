#include <bits/stdc++.h>
using namespace std;
int w,p;
vector<int> arr;
int main(){
	arr.push_back(0);
	scanf("%d%d",&w,&p);
	for(int i=0;i<p;i++){
		int in;
		scanf("%d",&in);
		arr.push_back(in);
	}
	arr.push_back(w);
	set<int> ans;
	for(int i=1;i<arr.size();i++){
		for(int j=0;j<i;j++)
			ans.insert(arr[i]-arr[j]);
	}
	for(auto x:ans)
		printf("%d ",x);
	printf("\n");
	return 0;
}