#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int k;
	string le,ri;
	bool bitset[15][1<<15];
};
int n,m;
Node arr[205];
bool possi(const string &str,int idx,int x){
	int h=0;
	for(int i=0;i+x<=str.size();i++){
		if(i==0){
			for(int j=0;j<x;j++)
				h=h*2+str[j]-'0';
		}
		else{
			h=h*2+str[i+x-1]-'0';
			h=(h&((1<<x)-1));
		}
		arr[idx].bitset[x][h]=1;
	}
	for(int i=0;i<(1<<x);i++)
		if(!arr[idx].bitset[x][i])
			return false;
	return true;
}
void merge(int a,int b,int idx){
	arr[idx].k=max(arr[a].k,arr[b].k);
	arr[idx].le=arr[a].le+arr[b].le;
	if(arr[idx].le.size()>15)
		arr[idx].le=string(arr[idx].le.begin(),arr[idx].le.begin()+15);
	arr[idx].ri=arr[a].ri+arr[b].ri;
	if(arr[idx].ri.size()>15)
		arr[idx].ri=string(arr[idx].ri.end()-15,arr[idx].ri.end());
	for(int i=0;i<15;i++)
		for(int j=0;j<1<<15;j++)
			arr[idx].bitset[i][j]|=(arr[a].bitset[i][j]|arr[b].bitset[i][j]);
	string mid=arr[a].ri+arr[b].le;
	for(int i=1;i<15;i++)
		if(possi(mid,idx,i))
			arr[idx].k=i;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		arr[i].le=arr[i].ri=str;
		if(arr[i].le.size()>15)
			arr[i].le=string(arr[i].le.begin(),arr[i].le.begin()+15);
		if(arr[i].ri.size()>15)
			arr[i].ri=string(arr[i].ri.end()-15,arr[i].ri.end());
		arr[i].k=0;
		for(int j=1;j<15;j++){
			if(possi(str,i,j))
				arr[i].k=j;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		merge(a,b,n+i);
		printf("%d\n",arr[n+i].k);
	}
	return 0;
}