// =====================================================================================
// 
//       Filename:  12781.cpp
//        Created:  2017년 05월 22일 16시 00분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct point{
	int x, y;
	int cross(const point &rhs)const{
		return x*rhs.y-y*rhs.x;
	}
	point operator - (const point &rhs)const{
		return {x-rhs.x, y-rhs.y};
	}
};
int ccw(const point &a, const point &b){
	int ret=a.cross(b);
	if(ret<0)
		ret=-1;
	else if(ret>0)
		ret=1;
	return ret;
}
int ccw(const point &p, const point &a, const point &b){
	return ccw(a-p, b-p);
}
point arr[4];
int main(){
	for(int i=0;i<4;i++)
		scanf("%d%d", &arr[i].x, &arr[i].y);
	printf("%d\n", ((ccw(arr[2], arr[0], arr[3])*ccw(arr[2], arr[1], arr[3]))<0
				&&(ccw(arr[0], arr[3], arr[1])*ccw(arr[0], arr[2], arr[1])<0)));
	return 0;
}

