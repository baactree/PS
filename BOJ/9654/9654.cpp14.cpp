#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char ship_name[6][16]={"SHIP NAME","N2 Bomber",
"J-Type 327","NX Cruiser","N1 Starfighter","Royal Cruiser"};
char CLASS[6][16]={"CLASS","Heavy Fighter","Light Combat","Medium Fighter",
"Medium Fighter","Light Combat"};
char DE[6][16]={"DEPLOYMENT","Limited","Unlimited","Limited","Unlimited","Limited"};
char IN[6][16]={"IN SERVICE","21","1","18","25","4"};
int main()
{
	for(int i=0;i<6;i++)
	{
		printf("%-15s%-15s%-11s%-10s\n",ship_name[i],CLASS[i],DE[i],IN[i]);
	}

    return 0;
}
