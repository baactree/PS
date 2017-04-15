// =====================================================================================
// 
//       Filename:  3392.cpp
//        Created:  2017년 04월 15일 13시 13분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
class Sgtree{
	public:
		int n;
		vector<pair<int, int>> tree;
		Sgtree(int n):n(n){
			tree=vector<pair<int, int>> (n*4, {0, 0});
		}
		int query(){
			return tree[1].first;
		}
		void update(int le, int ri, int val, int nodele, int noderi, int node){
			if(le>noderi||ri<nodele)
				return;
			if(le<=nodele&&noderi<=ri){
				tree[node].second+=val;
				if(tree[node].second){
					tree[node].first=noderi-nodele+1;
				}
				else{
					if(nodele==noderi)
						tree[node].first=0;
					else
						tree[node].first=tree[node*2].first+tree[node*2+1].first;
				}
				return ;
			}
			int mid=(nodele+noderi)/2;
			update(le, ri, val, nodele, mid, node*2);
			update(le, ri, val, mid+1, noderi, node*2+1);
			if(tree[node].second){
				tree[node].first=noderi-nodele+1;
			}
			else{
				if(nodele==noderi)
					tree[node].first=0;
				else
					tree[node].first=tree[node*2].first+tree[node*2+1].first;
			}
		}
		void update(int le, int ri, int val){
			update(le, ri, val, 0, n, 1);
		}

};
struct Line{
	int x, y1, y2;
	bool type;
	bool operator < (const Line &rhs)const{
		if(x==rhs.x){
			if(y1==rhs.y1){
				return y2<rhs.y2;
			}
			return y1<rhs.y1;
		}
		return x<rhs.x;
	}
};
vector<Line> line;
int n;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		line.push_back({a, b, d, 0});
		line.push_back({c, b, d, 1});
	}
	sort(line.begin(), line.end());
	int x=0;
	int ans=0;
	Sgtree sg(30005);
	for(int i=0;i<line.size();i++){
		ans+=(line[i].x-x)*max(0, sg.query());
		x=line[i].x;
		sg.update(line[i].y1, line[i].y2-1, line[i].type?-1:1);
	}
	printf("%d\n", ans);
	return 0;
}

