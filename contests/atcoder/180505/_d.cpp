#include <cstdio>

int main(void){
    int ans[55]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
        149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
        227, 229, 233, 239, 241, 251, 257};
    int n;

    scanf("%d", &n);
    for (int i=0; i<n; i++) printf("%d%c", ans[i], " \n"[i==n-1]);

    return 0;
}
