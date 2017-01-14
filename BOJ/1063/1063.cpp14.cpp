/*
#include "bits_stdc++.h"
using namespace std;

int height, width;
int arrY[4] = { -1, 0, 1, 0 };
int arrX[4] = { 0, 1, 0, -1 };
char Map[51][51];


int main()
{
	cin >> height >> width;
	for (int i = 0; i < height; i++)
		scanf("%s", &Map[i]);


}
*/

#include "bits/stdc++.h"
using namespace std;

int arrY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int arrX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n;
int order[51];
char king[3];
char stone[3];

bool range(int y, int x)
{
	if (y < 0 || y > 7 || x < 0 || x > 7)
		return false;
	else
		return true;
}

int main()
{
	cin >> king >> stone >> n;

	int ky = king[1] - '0' - 1;
	int kx = king[0] - 'A';
	int sy = stone[1] - '0' - 1;
	int sx = stone[0] - 'A';

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "B")
			order[i] = 0;
		else if (temp == "RB")
			order[i] = 1;
		else if (temp == "R")
			order[i] = 2;
		else if (temp == "RT")
			order[i] = 3;
		else if (temp == "T")
			order[i] = 4;
		else if (temp == "LT")
			order[i] = 5;
		else if (temp == "L")
			order[i] = 6;
		else if (temp == "LB")
			order[i] = 7;
	}

	int KY;
	int KX;
	int SY;
	int SX;
	for (int i = 0; i < n; i++)
	{
		if (range(ky + arrY[order[i]], kx + arrX[order[i]]))
		{
			KY = ky + arrY[order[i]];
			KX = kx + arrX[order[i]];
		}
		else
			continue;

		if (KY == sy && KX == sx)
		{
			if (range(sy + arrY[order[i]], sx + arrX[order[i]]))
			{
				SY = sy + arrY[order[i]];
				SX = sx + arrX[order[i]];
				sy = SY;
				sx = SX;
				ky = KY;
				kx = KX;
			}
			else
				continue;
		}
		ky = KY;
		kx = KX;
	}

	cout << (char)(kx + 'A') << ky + 1 << endl;
	cout << (char)(sx + 'A') << sy + 1 << endl;
}