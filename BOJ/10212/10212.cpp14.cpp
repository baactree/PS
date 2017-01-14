#include <cstdio>
int main() {
    FILE *fp = fopen("a.txt","r");
    if (fp == NULL) {
        printf("Korea\n");
    } else {
        printf("Yonsei\n");
        fclose(fp);
    }
    fp = fopen("a.txt","w");
    fprintf(fp,"asdf");
    fclose(fp);
    return 0;
}