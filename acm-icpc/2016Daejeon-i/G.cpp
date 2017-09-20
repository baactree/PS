// =====================================================================================
// 
//       Filename:  G.cpp
//        Created:  2017년 09월 17일 19시 34분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int par[300005];
vector<int> adj[5005];
int mat[5005][5005];
bool chk[5005][5005];
int find(int x){
	if(x==par[x])
		return x;
	return par[x]=find(par[x]);
}
int calc1(){
	/*  
	int n;
	scanf("%d", &n);
	int m=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d", &k);
		while(k--){
			int v;
			scanf("%d", &v);
			mat[i][v]=m++;
			adj[i].push_back(v);
		}
	}
	if(m>=300005||(m&1))
		return -1;
	for(int i=0;i<m;i++)
		par[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			int a=find(mat[i][adj[i][j]]);
			int b=find(mat[adj[i][(j+1)%adj[i].size()]][i]);
			if(a==b)
				continue;
			par[b]=a;
		}
	}
	int f=0;
	for(int i=0;i<m;i++)
		if(find(i)==i)
			f++;
	m/=2;
	return	n-m+f==2?1:-1; 
	*/
	int n;
	scanf("%d", &n);
	int m=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d", &k);
		while(k--){
			int v;
			scanf("%d", &v);
			adj[i].push_back(v);
			m++;
		}
		for(int j=0;j<adj[i].size();j++){
			mat[i][adj[i][j]]=adj[i][(j+1)%adj[i].size()];
		}
	}
	m/=2;
	int f=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			int there=adj[i][j];
			int now=i;
			if(!chk[now][there]){
				while(!chk[now][there]){
					chk[now][there]=true;
					int temp=now;
					now=there;
					there=mat[there][temp];
				}
				f++;
			}
		}
	}
	return n-m+f==2?1:-1;
}
int calc2(){
	int n, m;
	scanf("%d%*d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int v=0;
	vector <int> num(n+1, 0);
    for (int i=1;i<=n;i++){
        if (adj[i].size() == 1) return -1;
        if (adj[i].size() > 2) num[i] = ++v;
    }
    if (v < 5 || v > 6) return -1;
    bool w[7][7] = {0,};
    for (int i=1;i<=n;i++) if (num[i]){
        for (int t: adj[i]){
            int v = t, f = i;
            while (!num[v]){
                int nxt;
                for (int i=0;i<2;i++) if (adj[v][i] != f) nxt = adj[v][i];
                f = v; v = nxt;
            }
            w[num[i]][num[v]] = 1;
        }
    }
    if (v == 5){
        for (int i=1;i<6;i++) for (int j=1;j<6;j++) if (i != j && !w[i][j]) return -1;
        return 1;
    }else{
        map <int, int> mem;
        for (int i=1;i<7;i++){
            int num = 0, cnt = 0;
            for (int j=1;j<7;j++) if (w[i][j]){
                cnt++;
                num = num*7 + j;
            }
            if (cnt != 3) return 0;
            mem[num]++;
        }
        if (mem.size() != 2) return -1;
        for (auto &it: mem){
            if (it.second != 3) return -1;
        }
        return 1;
    }
}
int main(){
	int mode;
	scanf("%d", &mode);
	printf("%d\n", (mode==1?calc1():calc2()));
	return 0;
}

