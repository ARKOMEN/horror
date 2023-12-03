#include "header.h"

Character::Character(int nx, int ny, MazeGenerator* nmap){
    x = nx;
    y = ny;
    _map = nmap;
    graphics = "C";
}
Ghosts::Ghosts(int nx, int ny, MazeGenerator* nmap) {
    x = nx;
    y = ny;
    _map = nmap;
    graphics = "G";
    direction = 4;
}

Artifacts::Artifacts(int nx, int ny, MazeGenerator* nmap) {
    x = nx;
    y = ny;
    _map = nmap;
    graphics = "'";
}


void Ghosts::move(int c){
    if(direction != 4){
        switch (direction) {
            case 0:
                if (_map->maze[y - 1][x] == ' ') y --;
                else direction = 4;
                break;
            case 1:
                if (_map->maze[y + 1][x] == ' ') y ++;
                else direction = 4;
                break;
            case 2:
                if (_map->maze[y][x + 1] == ' ') x ++;
                else direction = 4;
                break;
            case 3:
                if (_map->maze[y][x - 1] == ' ') x --;
                else direction = 4;
                break;

        }
    }
    else{
        std::set<int> directions;
        if(_map->maze[y - 1][x] == ' ') directions.insert(0);
        if(_map->maze[y + 1][x] == ' ') directions.insert(1);
        if(_map->maze[y][x + 1] == ' ') directions.insert(2);
        if(_map->maze[y][x - 1] == ' ') directions.insert(3);
        int choice = rand()%directions.size();
        direction = *next(directions.begin(), choice);
    }
}

void Character::move(int c) {
    switch (c) {
        case KEY_UP:
            if(_map->maze[y - 1][x] == ' ') y --;
            break;
        case KEY_DOWN:
            if(_map->maze[y + 1][x] == ' ') y ++;
            break;
        case KEY_RIGHT:
            if(_map->maze[y][x + 1] == ' ') x ++;
            break;
        case KEY_LEFT:
            if(_map->maze[y][x - 1] == ' ') x --;
            break;
    }
    if(graphics == "C")graphics = "c";
    else graphics = "C";
}

void Artifacts::move(int c) {
    if(graphics == "'")graphics = "\"";
    else graphics = "'";
}