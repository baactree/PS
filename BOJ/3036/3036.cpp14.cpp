#include "iostream"
#include "algorithm"
using namespace std;
int gcd(int a, int b){
	return b ? gcd(b,a%b) : a;
}
int main(){
	int N;
	int arr[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int pivot = arr[0];
	for (int i = 1; i < N; i++){
		int a, b;
		a = pivot;
		b = arr[i];
		int g = gcd(a, b);
		a = a / g;
		b = b / g;
		printf("%d/%d\n", a, b);
	}
	return 0;
}