#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
ll tree[2505][2505];
void update(int x,int y,ll val){
	while(x<2505){
		int y1=y;
		while(y1<2505){
			tree[x][y1]^=val;
			y1+=y1&(-y1);
		}
		x+=x&(-x);
	}
}
ll query(int x,int y){
	ll ret=0;
	while(x){
		int y1=y;
		while(y1){
			ret^=tree[x][y1];
			y1-=y1&(-y1);
		}
		x-=x&(-x);
	}
	return ret;
}
void paint(int x1,int y1,int x2,int y2,ll val){
	update(x1,y1,val);
	update(x1,y2+1,val);
	update(x2+1,y1,val);
	update(x2+1,y2+1,val);
}
set<ll> s;
ll get_color(){
	ll ret=rand()*rand()+rand()-rand()^rand();
	while(!s.insert(ret).second)
		ret=ret*rand()+rand()-rand()^rand();
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	map<pair<pair<int,int>,pair<int,int> >, ll> mp;
	while(q--){
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(a==1){
			ll col=get_color();
			mp[{{b,c},{d,e}}]=col;
			paint(b,c,d,e,col);
		}
		else if(a==2){
			ll col=mp[{{b,c},{d,e}}];
			paint(b,c,d,e,col);
		}
		else{
			printf("%s\n",(query(b,c)==query(d,e))?"Yes":"No");
		}
	}
	return 0;
}