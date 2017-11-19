#include <bits/stdc++.h>
using namespace std;
int n,l;
int mat[100][100];
bool possi(const vector<int> &arr){
	int cnt=1;
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			cnt++;
			continue;
		}
		if(arr[i]<arr[i+1]){
			if(arr[i+1]-arr[i]>1)
				return false;
			if(cnt<l)
				return false;
			cnt=1;
		}
		else{
			if(arr[i]-arr[i+1]>1)
				return false;
			int kk=1;
			for(int j=i+2;j<n;j++)
				if(arr[j]==arr[j-1])
					kk++;
				else
					break;
			if(kk<l)
				return false;
			i+=l-1;
			cnt=0;
		}
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	int ans=0;
	for(int i=0;i<n;i++){
		vector<int> vec;
		for(int j=0;j<n;j++)
			vec.push_back(mat[i][j]);
		if(possi(vec)){
			//printf("row %d\n",i);
			ans++;
		}
		vec.clear();
		for(int j=0;j<n;j++)
			vec.push_back(mat[j][i]);
		if(possi(vec)){
			//printf("cow %d\n",i);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}