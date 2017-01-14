#include "iostream"
#include "vector"
#include "string.h"
#include "algorithm"
#include "string"
#include "stack"
#include "queue"
using namespace std;
typedef long long ll;
int arr[1000000];
int main(){
	int Case;
	cin >> Case;
	while (Case--){
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		queue<int> st;
		ll ans = 0;
		for (int i = N - 1; i >= 0; i--){
			int now = arr[i];
			if (st.empty() || now <= st.front())
				st.push(now);
			else{
				int temp = st.front();
				st.pop();
				while (!st.empty()){
					ans += temp - st.front();
					st.pop();
				}
				st.push(now);
			}
		}
		if (!st.empty()){
			int temp = st.front();
			st.pop();
			while (!st.empty()){
				ans += temp - st.front();
				st.pop();
			}
		}
		printf("%lld\n", ans);
	}
}