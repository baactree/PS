#include "bits/stdc++.h"
using namespace std;
int N;
priority_queue<int> max_pq;
priority_queue<int> min_pq;
int main() {
	cin >> N;
	int in;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &in);
		if (max_pq.empty() || min_pq.empty())
			max_pq.push(in);
		else {
			if (in <= max_pq.top())
				max_pq.push(in);
			else if (in >= -min_pq.top())
				min_pq.push(-in);
			else
				max_pq.push(in);
		}
		while(!(max_pq.size()==min_pq.size()||max_pq.size()==min_pq.size()+1)){
            if(max_pq.size()>min_pq.size()){
                min_pq.push(-max_pq.top());
                max_pq.pop();
            }
            else{
                max_pq.push(-min_pq.top());
                min_pq.pop();
            }
        }
		printf("%d\n", max_pq.top());
	}
	return 0;
}