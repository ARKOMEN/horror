#include <ncurses.h>
#include "iostream"
#include "vector"
#include "SFML/Audio.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int wall = 0, pass = 1, room = 4, mine = 10;

class map_class {
    int _h, _w;
public:
    int** maze;
    int get_h();
    int get_w();
    map_class(int h1, int w1);
    bool dead_end(int x, int y); // Вспомогательная функция, определяет тупики
    void maze_make(int k, int rheight, int rwidth); // Собственно алгоритм
};

void game(int ch);

class game_status{
    int _level;
    bool _game_over;
    int _c;
public:
    int x_ch, y_ch;
    bool signal;
    game_status(int level, bool game_over);
    int get_level();
    bool get_game_over();
    int get_c();
    void write_c(int c);
    void write_level(int level);
};

class game_object{
public:
    int x, y;
    int type;
    virtual void move(game_status* status, map_class m) = 0;
};

class main_ch : public game_object{
public:
    void move(game_status* status, map_class m) override;
};

class ghosts : public game_object{
public:
    void move(game_status* status, map_class m) override;
};

class bullet : public game_object{
public:
    void move(game_status* status, map_class m) override;
};

void display_settings(int h1, int w1, sf::Sound* sound);

class draw {
public:
    void display(game_object*& object, map_class m, game_status* status);
    int display_pause(int h1, int w1, game_status* status);
};
