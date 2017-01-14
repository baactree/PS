#define p 3.1415926535897
double t=1;main(i,M){scanf("%d",&M);for(i=1;i<=M/2;i++)t*=(4*(pow(cos(i*p/(M+1)),2)+pow(cos(p/4),2)));printf("%d",M%2?0:(int)(t+.5));}