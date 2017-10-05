#include <bits/stdc++.h>
using namespace std;
bool trip[2<<25];
map<int,int> mp;
char mat[6][6];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool chk[25];
bool safe(int x,int y){
	return min(x,y)>=0&&max(x,y)<5;
}
void dfs(int now,int state){
	if(chk[now])
		return;
	chk[now]=true;
	int x=now/5;
	int y=now%5;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx,ny)&&(state&(1<<(nx*5+ny))))
			dfs(nx*5+ny,state);
	}
}
bool cc(int state){
	vector<int> p;
	int temp=state;
	while(state){
		p.push_back(mp[state&(-state)]);
		state-=state&(-state);
	}
	dfs(p[0],temp);
	bool ret=true;
	for(int i=0;i<p.size();i++){
		if(!chk[p[i]])
			ret=false;
		chk[p[i]]=false;
	}
	return ret;
}
int main(){
	int r=1;
	mp[1]=0;
	for(int i=1;i<25;i++){
		r*=2;
		mp[r]=i;
	}
	for(int i=0;i<5;i++)
		scanf("%s",mat[i]);
	int st=0;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(mat[i][j]=='*'){
				int now=i*5+j;
				st|=(1<<now);
			}
	queue<pair<int,int> > q;
	q.push({st,0});
	trip[st]=0;
	while(!q.empty()){
		int state=q.front().first;
		int cnt=q.front().second;
		q.pop();
		if(cc(state))
			return !printf("%d\n",cnt);
		vector<int> p;
		int temp=state;
		while(temp){
			p.push_back(mp[temp&(-temp)]);
			temp-=temp&(-temp);
		}
		for(int i=0;i<p.size();i++){
			int x=p[i]/5;
			int y=p[i]%5;
			int nstate=state&(~(1<<p[i]));
			for(int j=0;j<4;j++){
				int nx=x+dx[j];
				int ny=y+dy[j];
				int t=nx*5+ny;
				if(safe(nx,ny)&&!(nstate&(1<<t))&&!trip[nstate|(1<<t)]){
					trip[nstate|(1<<t)]=true;
					q.push({nstate|(1<<t),cnt+1});
				}
			}
		}
	}
	return 0;
}