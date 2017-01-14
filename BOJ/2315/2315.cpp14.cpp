#include "iostream"
#include "vector"
#include "string.h"
#include "algorithm"
using namespace std;
int N, M;
pair<int, int> arr[1001];
int cache[1001][1001][2];
int sum[1001];
//lr true 오른쪽
int solve(int left, int right, int lr){
	if(left==1&&right==N)
		return 0;
	int &ret = cache[left][right][lr];
	if (ret != -1)
		return ret;
	ret = 0x3f3f3f3f;
	//오른쪽
	if (lr){
		//오른쪽
		if (right != N){
			ret = min(ret, solve(left, right + 1, 1) + (arr[right + 1].first - arr[right].first)*(sum[left - 1] - sum[0] + sum[N] - sum[right]));
		}
		//왼쪽
		if (left != 1){
			ret = min(ret, solve(left - 1, right, 0) + (arr[right].first - arr[left - 1].first)*(sum[left - 1] - sum[0] + sum[N] - sum[right]));
		}
		return ret;
	}
	//왼쪽

	//오른쪽
	if (right != N){
		ret = min(ret, solve(left, right + 1, 1) + (arr[right + 1].first - arr[left].first)*(sum[left - 1] - sum[0] + sum[N] - sum[right]));
	}
	//왼쪽
	if (left != 1){
		ret = min(ret, solve(left - 1, right, 0) + (arr[left].first - arr[left - 1].first)*(sum[left - 1] - sum[0] + sum[N] - sum[right]));
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		sum[i] += sum[i - 1] + arr[i].second;
	}
	printf("%d\n", solve(M, M, 1));
	return 0;
}