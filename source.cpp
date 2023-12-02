#include "header.h"

character::character(int nx, int ny, MazeGenerator* nmap){
    x = nx;
    y = ny;
    _map = nmap;
    graphics = "C";
}
ghosts::ghosts(int nx, int ny, MazeGenerator* nmap) {
    x = nx;
    y = ny;
    _map = nmap;
    graphics = "G";
}

artifacts::artifacts(int nx, int ny, MazeGenerator* nmap) {
    x = nx;
    y = ny;
    _map = nmap;
    graphics = "'";
}

draw::draw(int h, int w, MazeGenerator* map, bool developer_mode) :_h(h), _w(w), _map(map), _developer_mode(developer_mode){}

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

bool display_settings(int h, int w, sf::Sound* sound, bool* developer_mode) {
    int highlight = 1;
    int c;
    int volume = sound->getVolume();
    const char *options[] = {
            "Volume",
            "developer mode",
            "Back"
    };
    bool choice = true;
    while ('q' != (c = getch()) && choice) {
        clear();

        switch (c) {
            case KEY_UP:
                if (highlight == 1) {
                    highlight = 3;
                } else {
                    highlight--;
                }
                break;
            case KEY_DOWN:
                if (highlight == 3) {
                    highlight = 1;
                } else {
                    highlight++;
                }
                break;
            case KEY_RIGHT:
                if (highlight == 1) {
                    volume+=10;
                }
                break;
            case KEY_LEFT:
                if (highlight == 1) {
                    volume-=10;
                }
                break;
            case 10: // клавиша ENTER
                if(highlight == 2){
                    *developer_mode = !(*developer_mode);
                }
                if (highlight == 3) {
                    choice = false;
                }
        }
        volume = std::clamp(volume, 0, 100);
        sound->setVolume(static_cast<float>(volume));
        for (int i = 0; i < 3; i++) {
            if (highlight == i + 1) {
                attron(A_REVERSE);
            }
            wmove(stdscr, h + i, w );
            printw("%s", options[i]);
            attroff(A_REVERSE);
        }
        for (int j = 0; j < 10; j++) {
            wmove(stdscr, h, w + j + 7);
            if(j + 1 == volume/10){
                wprintw(stdscr, "%s", "+");
                continue;
            }
            wprintw(stdscr, "%s", "-");
        }
        if(*developer_mode == false){
            wmove(stdscr, h + 1, w + 15);
            wprintw(stdscr, "%s", "no");
        }
        else{
            wmove(stdscr, h + 1, w + 15);
            wprintw(stdscr, "%s", "yes");
        }
    }
    return developer_mode;
}

int draw::display_pause(int h1, int w1) {
    const char *options[] = {
            "Continue",
            "Save and exit menu",
    };
    int highlight = 1;
    bool choise = true;
    int h = h1/2;
    int w = w1/2;
/*
    do{
        status->write_c(getch());
        switch (status->get_c()) {
            case KEY_UP:
                if (highlight == 1) {
                    highlight = 2;
                } else {
                    highlight--;
                }
                break;
            case KEY_DOWN:
                if (highlight == 2) {
                    highlight = 1;
                } else {
                    highlight++;
                }
                break;
            case 10: // клавиша ENTER
                choise = false;
                break;
        }
        for (int i = 0; i < 2; i++) {
            if (highlight == i + 1) {
                attron(A_REVERSE);
            }
            wmove(stdscr, h + i, w);
            printw("%s", options[i]);
            attroff(A_REVERSE);
        }
    }while (status->get_c() != 'q' && choise);*/
    return highlight;
}

void draw::display_map() {
    if(!_developer_mode) {
        int r = 3;
        for (int i = -r; i < r; ++i) {
            for (int j = -r; j < r; ++j) {
                if (x + i < 0 || x + i > _w || y + i < 0 || y + i > _h) continue;
                mvaddch(y + j, x + i, _map->maze[y + j][x + i]);
            }
        }
    }
    else{
        for (int i = 0; i < _w; ++i) {
            for (int j = 0; j < _h; ++j) {
                mvaddch(j, i, _map->maze[j][i]);
            }
        }
    }
}

void draw::display(game_object *&object) {
    if(!_developer_mode) {
        int r = 3;
        if (object->x > x - r && object->x < x + r && object->y > y - r && object->y < y + r) {
            wmove(stdscr, object->y, object->x);
            wprintw(stdscr, "%s", object->graphics);
        }
    }
    else{
        wmove(stdscr, object->y, object->x);
        wprintw(stdscr, "%s", object->graphics);
    }
}

void ghosts::move(int c){
    timeout(300);
    if(abs(x - ch_x) + abs(y - ch_y) > 4) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                if (_map->maze[y - 1][x] == ' ') y --;
                break;
            case 1:
                if (_map->maze[y + 1][x] == ' ') y ++;
                break;
            case 2:
                if (_map->maze[y][x + 1] == ' ') x ++;
                break;
            case 3:
                if (_map->maze[y][x - 1] == ' ') x --;
        }
    }
    else{
        if(x < ch_x){
            x++;
        }
        else if(x > ch_x){
            x--;
        }
        else if(y < ch_y){
            y++;
        }
        else if(y > ch_y){
            y--;
        }
    }
}

void character::move(int c) {
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
    }
    if(graphics == "C")graphics = "c";
    else graphics = "C";
}

void artifacts::move(int c) {
    if(graphics == "'")graphics = "\"";
    else graphics = "'";
}

void game(int ch, bool developer_mode) {
    if(ch == 1){
        int h1, w1;
        getmaxyx(stdscr, h1, w1);
        int h = h1/2;
        int w = w1/2;

        MazeGenerator map(h1, w1);
        map.generateMaze();

        draw picture(h1, w1, &map, developer_mode);


        std::vector<game_object*> objects;
        character pac_man(w1/2, h1/2, &map);
        objects.push_back(static_cast<game_object*>(&pac_man));
        for(int i = 0; i < 10; ++i){
            int nx, ny;
            while(true){
                nx = rand()%(w1 - 2) +2;
                ny = rand()%(h1 - 2) +2;
                if(map.maze[ny][nx] == ' '){
                    break;
                }
            }
            objects.push_back(static_cast<game_object*>(new ghosts(nx, ny, &map)));
        }
        int c;
        artifacts artifacts(1, 1, &map);
        objects.push_back(static_cast<game_object*>(&artifacts));
        do {
            picture.x = pac_man.x;
            picture.y = pac_man.y;
            clear();
            for(auto& go: objects){
                go->ch_x = picture.x;
                go->ch_y = picture.y;
                go->move(c);
            }
            picture.display_map();
            for(auto& go: objects){
                picture.display(go);
            }
            timeout(300);
        } while ('q' != (c = getch()));
    }
}