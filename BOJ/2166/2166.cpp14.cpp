#include "bits/stdc++.h"
using namespace std;
const double PI = 2.0*acos(0.0);
struct vector2 {
	double x, y;
	explicit vector2(double _x=0, double _y=0) :x(_x), y(_y) {}
	bool operator ==(const vector2&rhs)const {
		return x == rhs.x&&y == rhs.y;
	}
	bool operator < (const vector2&rhs)const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	vector2 operator + (const vector2&rhs)const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2&rhs)const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator *(double rhs)const {
		return vector2(x*rhs, y*rhs);
	}
	double norm() const {
		return hypot(x, y);
	}
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	double polar() const {
		return  fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}
	double dot(const vector2& rhs)const {
		return x*rhs.x + y*rhs.y;
	}
	double cross(const vector2&rhs)const {
		return x*rhs.y - y*rhs.x;
	}
	vector2 project(const vector2&rhs)const {
		vector2 r = rhs.normalize();
		return r*r.dot(*this);
	}
};
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}
double area(const vector<vector2>& p) {
	double ret = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1)%p.size();
		ret += p[i].x*p[j].y - p[j].x*p[i].y;
	}
	return fabs(ret) / 2.0;
}
vector<vector2> input;
int main() {
	int N;
	scanf("%d", &N);
	vector2 temp;
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &temp.x, &temp.y);
		input.push_back(temp);
	}
	double ans = area(input);
	printf("%.1f\n", ans);
	return 0;
}