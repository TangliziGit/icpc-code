#include <cstdio>

int main(void){
    int n[2], m[2], matrix[3][100+5][100+5]={0};
    for (int i=0; i<2; i++){
        scanf("%d%d", &m[i], &n[i]);
        for (int y=0; y<m[i]; y++)
            for (int x=0; x<n[i]; x++) scanf("%d", &matrix[i][y][x]);
    }
    if (n[0]!=m[1]) printf("Error: %d != %d\n", n[0], m[1]);
    else {
        printf("%d %d\n", m[0], n[1]);
        for (int a=0; a<m[0]; a++)
            for (int b=0; b<n[1]; b++){
                int tmp=0;
                for (int i=0; i<n[0]; i++)
                    tmp+=matrix[0][a][i]*matrix[1][i][b];
                    // matrix[2][a*n[1]][b]+=matrix[0][a][j]*matrix[1][i][b];
                printf("%d%c", tmp, (b==n[1]-1)?'\n':' ');
            }
    }


    return 0;
}
