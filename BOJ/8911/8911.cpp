// =====================================================================================
// 
//       Filename:  8911.cpp
//        Created:  2017년 03월 05일 17시 20분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		string order;
		cin>>order;
		int x, y, dir;
		x=y=dir=0;
		int max_x, min_x, max_y, min_y;
		max_x=min_x=max_y=min_y=0;
		for(int i=0;i<order.size();i++){
			if(order[i]=='F'){
				x=x+dx[dir];
				y=y+dy[dir];
				max_x=max(max_x, x);
				min_x=min(min_x, x);
				max_y=max(max_y, y);
				min_y=min(min_y, y);
			}
			else if(order[i]=='B'){
				x=x-dx[dir];
				y=y-dy[dir];
				max_x=max(max_x, x);
				min_x=min(min_x, x);
				max_y=max(max_y, y);
				min_y=min(min_y, y);
			}
			else if(order[i]=='L'){
				dir=(dir+3)%4;
			}
			else{
				dir=(dir+1)%4;
			}
		}
		printf("%d\n", (max_x-min_x)*(max_y-min_y));
	}
	return 0;
}

