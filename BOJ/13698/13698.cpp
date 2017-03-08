// =====================================================================================
// 
//       Filename:  13698.cpp
//        Created:  2017년 03월 07일 17시 12분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> tt[6]={{1, 2 }, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
int arr[5]={0, 1, 0, 0, 2};
string order;
int main(){
	cin>>order;
	for(int i=0;i<order.size();i++){
		if(order[i]=='A'){
			swap(arr[tt[0].first], arr[tt[0].second]);
		}
		else if(order[i]=='B'){
			swap(arr[tt[1].first], arr[tt[1].second]);

		}
		else if(order[i]=='C'){
			swap(arr[tt[2].first], arr[tt[2].second]);

		}
		else if(order[i]=='D'){
			swap(arr[tt[3].first], arr[tt[3].second]);

		}
		else if(order[i]=='E'){
			swap(arr[tt[4].first], arr[tt[4].second]);

		}
		else{
			swap(arr[tt[5].first], arr[tt[5].second]);

		}
	}

	for(int i=1;i<=5;i++)
		if(arr[i]==1)
			printf("%d\n", i);
	for(int i=1;i<=5;i++)
		if(arr[i]==2)
			printf("%d\n", i);

	return 0;
}

