#include <bits/stdc++.h>

using namespace std;

class CheeseSlicing {
public:
	int cache[101][101][101];
	int solve(int a, int b, int c, int s){
	vector<int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	if(*min_element(temp.begin(), temp.end())<s)
		return 0;
	int &ret=cache[a][b][c];
	if(ret!=-1)
		return ret;
	ret=0;
	ret=max(ret, b*c+solve(a-s, b, c, s));
	ret=max(ret, a*c+solve(a, b-s, c, s));
	ret=max(ret,a*b+solve(a, b, c-s, s));
	return ret;
}
	int totalArea(int A, int B, int C, int S) {
	memset(cache, -1, sizeof(cache));
	return solve(A, B, C, S);
}
};


double test0() {
	int p0 = 1;
	int p1 = 3;
	int p2 = 3;
	int p3 = 2;
	CheeseSlicing * obj = new CheeseSlicing();
	clock_t start = clock();
	int my_answer = obj->totalArea(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 5;
	int p1 = 3;
	int p2 = 5;
	int p3 = 3;
	CheeseSlicing * obj = new CheeseSlicing();
	clock_t start = clock();
	int my_answer = obj->totalArea(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 25;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 5;
	int p2 = 5;
	int p3 = 2;
	CheeseSlicing * obj = new CheeseSlicing();
	clock_t start = clock();
	int my_answer = obj->totalArea(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 58;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 49;
	int p1 = 92;
	int p2 = 20;
	int p3 = 3;
	CheeseSlicing * obj = new CheeseSlicing();
	clock_t start = clock();
	int my_answer = obj->totalArea(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 30045;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
