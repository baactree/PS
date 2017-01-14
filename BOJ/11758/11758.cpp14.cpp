#include "bits/stdc++.h"
using namespace std;
struct vector2 {
	double x, y;
	explicit vector2(double _x=0, double _y=0) :x(_x), y(_y) {}
	vector2 operator - (const vector2&rhs)const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator *(double rhs)const {
		return vector2(x*rhs, y*rhs);
	}
	double cross(const vector2&rhs)const {
		return x*rhs.y - y*rhs.x;
	}
};
vector2 p[3];
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	double ans = ccw(p[0], p[1], p[2]);
	printf("%d\n",ans>0?1:ans==0?0:-1);
}