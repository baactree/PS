#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int a, b;
	int m_a, m_b, m_c;
	cin >> a >> b;
	m_c = b % 10;
	m_b = (b % 100 - m_c)/10;
	m_a = b / 100;
	printf("%d\n%d\n%d\n%d\n", a*m_c, a*m_b, a*m_a, a*b);

	return 0;
}
