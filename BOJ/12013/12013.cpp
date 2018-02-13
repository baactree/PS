#include <bits/stdc++.h>
using namespace std;
int solve(int idx,vector<int> arr){
	if(idx==50)
		return *max_element(arr.begin(),arr.end());
	int ret=0;
	vector<int> next;
	for(int i=0;i<arr.size();i++){
		int now=arr[i];
		if(now==idx){
			int cnt=1;
			for(int j=i+1;j<arr.size();j++){
				if(arr[i]==arr[j])
					cnt++;
				else break;
			}
			if(cnt==1){
				next.push_back(arr[i]);
			}
			else if(cnt&1){
				for(int k=0;k<cnt/2;k++)
					next.push_back(now+1);
				ret=max(ret,solve(idx+1,next));
				next=vector<int>(cnt/2,now+1);
			}
			else{
				for(int k=0;k<cnt/2;k++)
					next.push_back(now+1);
			}
			i+=cnt-1;
		}
		else
			next.push_back(now);
	}
	ret=max(ret,solve(idx+1,next));
	return ret;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%d\n",solve(1,arr));
	return 0;
}