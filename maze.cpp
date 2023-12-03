#include "header.h"

const int rows = 46;
const int cols = 189;
enum Cell { WALL = '#', PATH = ' ' };

MazeGenerator::MazeGenerator(int r, int c) : rows(r), cols(c) {
    maze = new char* [rows];
    for (int i = 0; i < rows; ++i) {
        maze[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            maze[i][j] = WALL;
        }
    }
    srand(time(nullptr));
}

void MazeGenerator::generateMaze() {
    generateMazeRecursive(1, 1);
}

MazeGenerator::~MazeGenerator() {
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }
    delete[] maze;
}

void MazeGenerator::generateMazeRecursive(int x, int y) {
    static const int dirs[4][2] = { {0, 2}, {2, 0}, {0, -2}, {-2, 0} };

    int dir[4] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; ++i) {
        int randIndex = rand() % (4 - i) + i;
        std::swap(dir[i], dir[randIndex]);
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dirs[dir[i]][0];
        int ny = y + dirs[dir[i]][1];

        if (nx > 0 && ny > 0 && nx < rows - 1 && ny < cols - 1 && maze[nx][ny] == WALL) {
            maze[nx][ny] = PATH;
            maze[x + dirs[dir[i]][0] / 2][y + dirs[dir[i]][1] / 2] = PATH;
            generateMazeRecursive(nx, ny);
        }
    }
}