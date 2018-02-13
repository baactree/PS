#include <bits/stdc++.h>
using namespace std;
string mat[9][4];
int r[9];
double cache[2000000];
double solve(vector<int> arr){
	int state=0;
	for(int i=0;i<arr.size();i++)
		state+=arr[i]*r[i];
	if(!state)
		return 1;
	double &ret=cache[state];
	if(ret>=-0.5)
		return ret;
	ret=0;
	vector<pair<int,int> > vec;
	for(int i=0;i<arr.size();i++)
		for(int j=i+1;j<arr.size();j++){
			if(!arr[i]||!arr[j])
				continue;
			if(mat[i][arr[i]-1][0]==mat[j][arr[j]-1][0])
				vec.push_back({i,j});
		}
	for(int i=0;i<vec.size();i++){
		int a=vec[i].first;
		int b=vec[i].second;
		arr[a]--;
		arr[b]--;
		ret+=solve(arr)/vec.size();
		arr[a]++;
		arr[b]++;
	}
	return ret;
}
int main(){
	r[0]=1;
	for(int i=1;i<9;i++)
		r[i]=r[i-1]*5;
	for(int i=0;i<2000000;i++)
		cache[i]=-1.0;
	for(int i=0;i<9;i++)
		for(int j=0;j<4;j++)
			cin>>mat[i][j];
	printf("%.6lf\n",solve(vector<int>(9,4)));
	return 0;
}