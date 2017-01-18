// =====================================================================================
// 
//       Filename:  9660.cpp
//        Created:  2017년 01월 18일 22시 19분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
/*
 *   상근 창영
 * 0  l		w
 * 1  w 	l
 * 2  l		w
 * 3  w		l
 * 4  w		l
 * 5  w		l
 * 6  w		l
 * 7  l		w
 * 8  w		l
 * 9  l		w
 * 10 w		l
 * 11 w		l
 * 12 w		l
 * 13 w		l
 *
 *
 */
int main(){
	long long N;
	scanf("%lld", &N);
	N=N%7;
	string ans[7]={"CY", "SK", "CY", "SK", "SK", "SK", "SK"};
	cout<<ans[N]<<endl;
	return 0;
}

