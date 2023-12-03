#include <ncurses.h>
#include "iostream"
#include <vector>
#include <algorithm>
#include <functional>
#include "SFML/Audio.hpp"
#include <cstdlib>
#include <ctime>
#include <set>
#include <thread>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

void table_records(int h , int w);

class MazeGenerator{
    void generateMazeRecursive(int x, int y);
    int rows;
    int cols;
public:
    char** maze;
    MazeGenerator(int r, int c);
    void generateMaze();
    ~MazeGenerator();
};

class game_object{
public:
    int x, y;
    MazeGenerator* _map;
    char* graphics;
    virtual void move(int c) = 0;
};

class draw {
    int _h, _w;
    bool _developer_mode;
    MazeGenerator* _map;
public:
    int x, y;
    draw(int h, int w, MazeGenerator* map, bool developer_mode);
    void display(game_object*& object);
    void display_map();
    int display_pause(int h1, int w1);
};

class character : public game_object{
public:
    character(int nx, int ny, MazeGenerator* map);
    void move(int c) override;
};

class ghosts : public game_object{
public:
    int direction;
    ghosts(int nx, int ny, MazeGenerator* nmap);
    void move(int c) override;
};

class artifacts : public game_object{
public:
    artifacts(int nx, int ny, MazeGenerator* nmap);
    void move(int c) override;
};

bool display_settings(int h1, int w1, sf::Sound* sound, bool* developer_mode);

void game(int ch, bool developer_mode);