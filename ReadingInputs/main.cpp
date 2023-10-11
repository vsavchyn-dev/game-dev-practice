#include <conio.h>
#include <iostream>

// New version of Sleep available
#pragma warning(disable : 4996)

bool termReRender = false;

struct player {
    int x = 0;
    int y = 0;
};

void printGrid(int grid[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << grid[i][j] << " ";
        std::cout << std::endl;
    }
}

void movePlOnGrid(int grid[10][10], player p1) {
    static int prevX = 0;
    static int prevY = 0;

    grid[prevY][prevX] = 0;
    grid[p1.y][p1.x] = 1;

    prevX = p1.x;
    prevY = p1.y;
}

int main() {
    char key = 0;
    int grid[10][10];
    player p1 = { 4, 4 };
    
    memset(&grid, 0, sizeof(int) * 10 * 10);

    movePlOnGrid(grid, p1);
    printGrid(grid);
    
    do {
        if (_kbhit()) {
            system("cls");
            key = _getch();

            switch (key) {
            case 'w':
                if (--p1.y < 0)
                    p1.y = 9;
                break;
            case 'a':
                if (--p1.x < 0)
                    p1.x = 9;
                break;
            case 's':
                if (++p1.y > 9)
                    p1.y = 0;
                break;
            case 'd':
                if (++p1.x > 9)
                    p1.x = 0;
                break;
            default:
                break;
            }
            
            movePlOnGrid(grid, p1);
            printGrid(grid);
        }
        _sleep((unsigned long)10);
    } while (int(key) != 27);

    return 0;
}
