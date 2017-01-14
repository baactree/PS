#include "bits/stdc++.h"
using namespace std;
const double PI = 2.0*acos(0.0);
struct vector2{
	double x, y;
	explicit vector2(double _x = 0, double _y = 0) :x(_x), y(_y) {}
	bool operator == (const vector2& rhs)const {
		return x == rhs.x&&y == rhs.y;
	}
	bool operator < (const vector2& rhs)const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	vector2 operator + (const vector2&rhs)const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2&rhs)const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator * (double rhs)const {
		return vector2(x*rhs, y*rhs);
	}
	double norm() const {
		return hypot(x, y);
	}
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	double polar() const {
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}
	double dot(const vector2&rhs)const {
		return x*rhs.x + y*rhs.y;
	}
	double cross(const vector2&rhs)const {
		return x*rhs.y - rhs.x*y;
	}
	vector2 project(const vector2& rhs)const {
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
typedef vector<vector2> polygon;
polygon giftWrap(const vector<vector2>& points) {
	int n = points.size();
	polygon hull;
	vector2 pivot = *min_element(points.begin(), points.end());
	hull.push_back(pivot);
	while (true) {
		vector2 ph = hull.back(), next = points[0];
		for (int i = 1; i < n; i++) {
			double cross = ccw(ph, next, points[i]);
			double dist = (next - ph).norm() - (points[i] - ph).norm();
			if (cross > 0 || (cross == 0 && dist < 0))
				next = points[i];
		}
		if (next == pivot)
			break;
		hull.push_back(next);
	}
	return hull;
}
polygon input;
int main() {
	int N;
	double a, b;
	vector2 temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &a, &b);
		temp.x = a;
		temp.y = b;
		input.push_back(temp);
	}
	polygon ans = giftWrap(input);
	printf("%d\n", ans.size());
}