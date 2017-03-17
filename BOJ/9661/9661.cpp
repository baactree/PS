// =====================================================================================
// 
//       Filename:  9661.cpp
//        Created:  2017년 03월 14일 17시 26분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
/*
 *     sk cy
 *  0   l w
 *  1   w l
 *  2   l w
 *  3   w l
 *  4   w l
 *  5   l w
 *  6   w l
 *  7   l w
 *  8   w l
 *  9   w l
 *  10  l w
 *  11  w l
 *  12  l w
 *  13  w l
 *  14  w l
 *  15  l w
 * 
 *
 * */
int arr[5]={0, 1, 0, 1, 1};
int main(){
	long long int n;
	scanf("%lld", &n);
	n=n%5;
	printf("%s\n", arr[n]?"SK":"CY");
	return 0;
}

