#include <iostream>

using namespace std;
int Map[100][100][4];
int N,M;
int f_x,f_y,f_z;
void move(int x, int y, int z, int index)
{
	if(z==0)
	{
		int add=1;
		while(y+add<M&&Map[x][y+add][z]!=-1&&(Map[x][y+add][z]==-2||Map[x][y+add][z]==index+1))
		{
	
			if(Map[x][y+add][z]==-2||Map[x][y+add][z]>index+1)
				Map[x][y+add][z]=index+1;
			if(add==3)
				break;
			add++;
			
		}
		if(Map[x][y][2]==-2)
		Map[x][y][2]=index+1;
		if(Map[x][y][3]==-2)
		Map[x][y][3]=index+1;
	}
	else if(z==1)
	{
		int add=1;
		while(y-add>=0&&Map[x][y-add][z]!=-1&&(Map[x][y-add][z]==-2||Map[x][y-add][z]==index+1))
		{
			if(Map[x][y-add][z]==-2||Map[x][y-add][z]>index+1)
			Map[x][y-add][z]=index+1;
			if(add==3)
				break;
			add++;
		}
		if(Map[x][y][2]==-2)
		Map[x][y][2]=index+1;
		if(Map[x][y][3]==-2)
		Map[x][y][3]=index+1;
	}
	else if(z==2)
	{
		int add=1;
		while(x+add<N&&Map[x+add][y][z]!=-1&&(Map[x+add][y][z]==-2||Map[x+add][y][z]==index+1))
		{
			if(Map[x+add][y][z]==-2||Map[x+add][y][z]>index+1)
			Map[x+add][y][z]=index+1;
			if(add==3)
				break;
			add++;
		}
		if(Map[x][y][0]==-2)
		Map[x][y][0]=index+1;
		if(Map[x][y][1]==-2)
		Map[x][y][1]=index+1;
	}
	else if(z==3)
	{
		int add=1;
		while(x-add>=0&&Map[x-add][y][z]!=-1&&(Map[x-add][y][z]==-2||Map[x-add][y][z]==index+1))
		{
			if(Map[x-add][y][z]==-2||Map[x-add][y][z]>index+1)
			Map[x-add][y][z]=index+1;
			if(add==3)
				break;
			add++;
		}
		if(Map[x][y][0]==-2)
		Map[x][y][0]=index+1;
		if(Map[x][y][1]==-2)
		Map[x][y][1]=index+1;
	}
}
void search(int index)
{					
	
	for(int j=0;j<M;j++)
		for(int q=0;q<4;q++)
			for(int i=0;i<N;i++)
			{
				if(Map[i][j][q]==index)
					move(i,j,q,index);
			}
}
int main(int argc, char *argv[])
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>Map[i][j][0];
	int s_x,s_y,s_z;

	cin>>s_x>>s_y>>s_z>>f_x>>f_y>>f_z;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(Map[i][j][0]==1)
				Map[i][j][0]=-1;
			else
				Map[i][j][0]=-2;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			for(int q=1;q<4;q++)
				Map[i][j][q]=Map[i][j][0];
	Map[s_x-1][s_y-1][s_z-1]=0;
	int index=0;
	while(true)
	{
		search(index);
		index++;
	
		/*
	for(int q=0;q<4;q++)
	{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			cout<<Map[i][j][q]<<" ";
		cout<<endl;
	}
	cout<<endl;
	}*/
	//cout<<endl;
		if(Map[f_x-1][f_y-1][f_z-1]!=-2)
			break;
	}
	
	cout<<Map[f_x-1][f_y-1][f_z-1]<<endl;
	
	
    return 0;
}
