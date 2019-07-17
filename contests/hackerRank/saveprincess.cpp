nclude <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    int mx, my, px, py;
    for (int y=0; y<n; y++)
        for (int x=0; x<n; x++)
            if (grid[y][x]=='m') {mx=x; my=y;}
            else if (grid[y][x]=='p') {px=x; py=y;}
    if (mx<px) for (int i=0; i<px-mx; i++)
        printf("RIGHT\n");
    if (my<py) for (int i=0; i<py-my; i++)
        printf("DOWN\n");
    if (mx>px) for (int i=0; i<mx-mp; i++)
        printf("LEFT\n");
    if (my>py) for (int i=0; i<mx-px; i++)
        printf("UP\n");
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
