#include <bits/stdc++.h>
using namespace std;
const int sz=4096;
const int inf=0x3f3f3f3f;
struct Sg1{
	map<int,int> *tree[sz+2505];
	map<int,int>& get(int idx){
		if(tree[idx]==NULL)
			tree[idx]=new map<int,int>;
		return *tree[idx];
	}
	void insert(int x,int y,int a,int b){
		x+=sz;
		y+=sz;
		while(x<=y){
			if(x&1)
				get(x++).emplace(a,b);
			if(!(y&1))
				get(y--).emplace(a,b);
			x>>=1;
			y>>=1;
		}
	}
	void erase(int x,int y,int a,int b){
		x+=sz;
		y+=sz;
		while(x<=y){
			if(x&1)
				get(x++).erase(a);
			if(!(y&1))
				get(y--).erase(a);
			x>>=1;
			y>>=1;
		}
	}
	pair<int,int> query(int idx){
		pair<int,int> ret(inf,0);
		idx+=sz;
		while(idx){
			if(tree[idx]&&!get(idx).empty()){
				auto temp=get(idx).begin();
				if(ret.first>temp->first){
					ret.first=temp->first;
					ret.second=temp->second;
				}
			}
			idx>>=1;
		}
		return ret;
	}
};
struct Sg2{
	Sg1 tree[sz+2505];
	void insert(int x1,int y1,int x2,int y2,int a,int b){
		x1+=sz;
		x2+=sz;
		while(x1<=x2){
			if(x1&1)
				tree[x1++].insert(y1,y2,a,b);
			if(!(x2&1))
				tree[x2--].insert(y1,y2,a,b);
			x1>>=1;
			x2>>=1;
		}
	}
	void erase(int x1,int y1,int x2,int y2,int a,int b){
		x1+=sz;
		x2+=sz;
		while(x1<=x2){
			if(x1&1)
				tree[x1++].erase(y1,y2,a,b);
			if(!(x2&1))
				tree[x2--].erase(y1,y2,a,b);
			x1>>=1;
			x2>>=1;
		}
	}
	int query(int x,int y){
		pair<int,int> ret(inf,0);
		x+=sz;
		while(x){
			ret=min(ret,tree[x].query(y));
			x>>=1;
		}
		return ret.second;
	}
}sgt;
int n,m,q;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++){
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(a==1){
			sgt.insert(b,c,d,e,(d-b+1)*(e-c+1),i);
		}
		else if(a==2){
			sgt.erase(b,c,d,e,(d-b+1)*(e-c+1),i);
		}
		else{
			printf("%s\n",(sgt.query(b,c)==sgt.query(d,e))?"Yes":"No");
		}
	}
	return 0;
}