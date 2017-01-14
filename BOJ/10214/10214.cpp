
#include <cstdio>

int main()
{
   int Case;
   scanf("%d",&Case);
   while(Case--)
   {
                int win,lose,draw;
                win=lose=draw=0;
                for(int i=0;i<9;i++)
                {
                        int Y,G;
                        scanf("%d%d",&Y,&G);
                        if(Y>G)
                        win++;
                        else if(G>Y)
                        lose++;
                        else
                        draw++;
                        }
                if(win>lose)
                printf("Yonsei\n");
                else if(lose>win)
                printf("Korea\n");
                else
                printf("Draw\n");
                }
    return 0;
    
}
