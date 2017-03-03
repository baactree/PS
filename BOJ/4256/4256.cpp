// =====================================================================================
// 
//       Filename:  4256.cpp
//        Created:  2017년 01월 15일 18시 34분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int N;
int preorder[1001];
int inorder[1001];
void solve(int pl, int pr, int il, int ir, int ti){
	if(pl==pr)
		return;
	int root=preorder[pl];
	int left_subtree_n=0;
	for(int i=il;i<ir;i++){
		if(inorder[i]==root)
			break;
		left_subtree_n++;
	}
	solve(pl+1, pl+1+left_subtree_n, il, il+left_subtree_n, ti*2);
	int right_subtree_n=pr-pl-left_subtree_n-1;
	solve(pr-right_subtree_n, pr, ir-right_subtree_n, ir, ti*2+1);
	printf("%d ", root);
}
int main(){
	int Case;
	cin>>Case;
	while(Case--){
		scanf("%d\n", &N);
		for(int i=0;i<N;i++)
			scanf("%d", &preorder[i]);
		for(int i=0;i<N;i++)
			scanf("%d", &inorder[i]);
		solve(0, N, 0, N, 1);
		printf("\n");
	}
	return 0;
}

