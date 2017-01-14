// =====================================================================================
// 
//       Filename:  10254.cpp
//        Created:  2017년 01월 15일 02시 38분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct vector2 {
	T x, y;
	explicit vector2(T x = 0, T y = 0) :x(x), y(y) {}
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
	vector2 operator * (int rhs)const {
		return vector2(x*rhs, y*rhs);
	}
	T norm() const {
		return hypot(x,y);
	}
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	T dot(const vector2&rhs)const {
		return x*rhs.x + y*rhs.y;
	}
	T cross(const vector2&rhs)const {
		return x*rhs.y - rhs.x*y;
	}
};
double ccw(vector2<double> a, vector2<double> b) {
	return a.cross(b);
}
double ccw(vector2<double> p, vector2<double> a, vector2<double> b) {
	return ccw(a - p, b - p);
}

int N;
vector2<double> input[200000];
vector2<double> hull[200000],up[200000],down[200000];
pair<vector2<double>, vector2<double>> ans;
vector2<double> toNext[200000];
int a, b;
int main() {
	int Case;
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) 
			scanf("%lf%lf", &input[i].x, &input[i].y);
		int idx, iup, idown;
		iup = idown = -1;
		sort(input, input + N);
		for (int i = 0; i < N; i++) {
			while (iup > 0 && ccw(up[iup - 1], up[iup], input[i]) > 0)iup--;
			up[++iup] = input[i];
			while (idown > 0 && ccw(down[idown - 1], down[idown], input[i]) < 0)idown--;
			down[++idown] = input[i];
		}
		for (idx = 0; idx <= iup; idx++)
			hull[idx] = up[idx];
		for (int i = idown - 1; i > 0; i--)
			hull[idx++] = down[i];
        int n = idx;
		int left = min_element(hull, hull+n) - hull;
		int right = max_element(hull, hull+n) - hull;
		vector2<double> calipersA(0, 1);
		double ret = (hull[right] - hull[left]).norm();
		ans.first = hull[right],ans.second = hull[left];
		for (int i = 0; i < n; i++)
			toNext[i] = (hull[(i + 1) % n] - hull[i]).normalize();
		int a = left, b = right;
		while (a != right || b != left) {
			double cosThetaA = calipersA.dot(toNext[a]);
			double cosThetaB = -calipersA.dot(toNext[b]);
			if (a!=right && (cosThetaA > cosThetaB || b == left)) {
				calipersA = toNext[a];
				a = (a + 1) % n;
			}
			else {
				calipersA = toNext[b] * (-1);
				b = (b + 1) % n;
			}
			if (ret < (hull[a] - hull[b]).norm()) {
				ret = (hull[a] - hull[b]).norm();
				ans.first = hull[a], ans.second = hull[b];
			}
		}
		printf("%d %d %d %d\n",  (int)ans.first.x, (int)ans.first.y, (int)ans.second.x, (int)ans.second.y);
	}
	return 0;
}
