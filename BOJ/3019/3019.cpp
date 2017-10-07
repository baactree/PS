#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[100];
vector<vector<int> > p[8];
bool possi(vector<int> vec,int y){
	if(vec.size()+y>n)
		return false;
	for(int i=0;i<vec.size();i++)
		vec[i]+=arr[y+i];
	sort(vec.begin(),vec.end());
	return vec[0]==vec.back();
}
int main(){
	p[1].push_back(vector<int>({1}));
	//p[1].push_back(vector<int>({1}));
	p[1].push_back(vector<int>({1,1,1,1}));
	//p[1].push_back(vector<int>({1,1,1,1}));

	p[2].push_back(vector<int>({1,1}));
	//p[2].push_back(vector<int>({1,1}));
	//p[2].push_back(vector<int>({1,1}));
	//p[2].push_back(vector<int>({1,1}));

	p[3].push_back(vector<int>({2,2,1}));
	p[3].push_back(vector<int>({1,2}));
	//p[3].push_back(vector<int>({2,2,1}));
	//p[3].push_back(vector<int>({1,2}));

	p[4].push_back(vector<int>({1,2,2}));
	p[4].push_back(vector<int>({2,1}));
	//p[4].push_back(vector<int>({1,2,2}));
	//p[4].push_back(vector<int>({2,1}));

	p[5].push_back(vector<int>({1,2,1}));
	p[5].push_back(vector<int>({1,2}));
	p[5].push_back(vector<int>({1,1,1}));
	p[5].push_back(vector<int>({2,1}));

	p[6].push_back(vector<int>({2,1,1}));
	p[6].push_back(vector<int>({1,1}));
	p[6].push_back(vector<int>({1,1,1}));
	p[6].push_back(vector<int>({1,3}));

	p[7].push_back(vector<int>({1,1,2}));
	p[7].push_back(vector<int>({1,1}));
	p[7].push_back(vector<int>({1,1,1}));
	p[7].push_back(vector<int>({3,1}));


	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int ans=0;
	for(int i=0;i<p[m].size();i++){
		for(int j=0;j<n;j++)
			if(possi(p[m][i],j))
				ans++;
	}
	printf("%d\n",ans);
	return 0;
}