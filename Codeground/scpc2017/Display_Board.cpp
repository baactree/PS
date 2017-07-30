// =====================================================================================
// 
//       Filename:  Display_Board.cpp
//        Created:  2017년 07월 01일 00시 06분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int x,y,mode;
	Node(){}
	Node(int x,int y,int mode):x(x),y(y),mode(mode){}
};
int n,m;
int r[105][105];
int c[105][105];
vector<int> adj[50000];
int snum,vnum;
int dis[50000];
int scc[50000];
int ans[50000];
Node arr[50000];
stack<int> st;
int idx;
int get_idx(int x,int y,int mode){
	if(mode){
		if(r[x][y]==-1){
			arr[idx]=Node(x,y,mode);
			r[x][y]=idx++;
		}
		return r[x][y];
	}
	if(c[x][y]==-1){
		arr[idx]=Node(x,y,mode);
		c[x][y]=idx++;
	}
	return c[x][y];
}
int dfs(int now){
	int ret=dis[now]=vnum++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(dis[there]==-1)
			ret=min(ret,dfs(there));
		else if(scc[there]==-1)
			ret=min(ret,dis[there]);
	}
	if(ret==dis[now]){
		while(true){
			int temp=st.top();
			st.pop();
			scc[temp]=snum;
			if(temp==now)
				break;
		}
		snum++;
	}
	return ret;
}
int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int tc=1;tc<=testcase;tc++){
		memset(r,-1,sizeof(r));
		memset(c,-1,sizeof(c));
		for(int i=0;i<50000;i++)
			adj[i].clear();
		idx=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				int ridx=get_idx(i,b,1);
				int cidx=get_idx(j,c,0);
				if(a){
					adj[ridx*2].push_back(cidx*2);
					adj[cidx*2].push_back(ridx*2);
					adj[ridx*2+1].push_back(cidx*2+1);
					adj[cidx*2+1].push_back(ridx*2+1);
				}
				else{
					adj[ridx*2].push_back(cidx*2+1);
					adj[cidx*2+1].push_back(ridx*2);
					adj[ridx*2+1].push_back(cidx*2);
					adj[cidx*2].push_back(ridx*2+1);
				}
			}
		}
		snum=vnum=0;
		memset(dis,-1,sizeof(dis));
		memset(scc,-1,sizeof(scc));
		for(int i=0;i<idx*2;i++)
			if(dis[i]==-1)
				dfs(i);
		bool flag=false;
		for(int i=0;i<idx*2;i+=2){
			if(scc[i]==scc[i+1])
				flag=true;
		}
		printf("Case #%d\n",tc);
		if(flag){
			printf("Impossible\n");
			continue;
		}
		vector<pair<int,int> > order;
		for(int i=0;i<idx*2;i++)
			order.push_back(make_pair(-scc[i],i));
		sort(order.begin(),order.end());
		memset(ans,-1,sizeof(ans));
		for(int i=0;i<idx*2;i++){
			int now=order[i].second;
			if(ans[now/2]!=-1)
				continue;
			ans[now/2]=(now&1);
		}
		for(int i=0;i<idx;i++){
			if(ans[i]){
				if(arr[i].mode){
					printf("R%02d%02d ",arr[i].x,arr[i].y);
				}
				else{
					printf("C%02d%02d ",arr[i].x,arr[i].y);
				}
			}
		}
		printf("\n");
	}
	return 0;
}

