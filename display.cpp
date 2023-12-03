#include "header.h"


Draw::Draw(int h, int w, MazeGenerator* map, bool developerMode) :_h(h), _w(w), _map(map), _developerMode(developerMode){}

bool displaySettings(int h, int w, sf::Sound* sound, bool* developerMode) {
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
                    *developerMode = !(*developerMode);
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
        if(*developerMode == false){
            wmove(stdscr, h + 1, w + 15);
            wprintw(stdscr, "%s", "no");
        }
        else{
            wmove(stdscr, h + 1, w + 15);
            wprintw(stdscr, "%s", "yes");
        }
    }
    return developerMode;
}

int Draw::displayPause(int h1, int w1) {
    const char *options[] = {
            "Continue",
            "Save and exit menu",
    };
    int highlight = 1;
    bool choice = true;
    int h = h1/2;
    int w = w1/2;
    int c = 11;
    do{
        switch (c) {
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
                choice = false;
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
    }while ('q' != (c = getch()) && choice);
    return highlight;
}

void Draw::displayMap() {
    if(!_developerMode) {
        int r = 3;
        for (int i = -r - 2; i < r + 2; ++i) {
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

void Draw::display(GameObject *&object) {
    if(!_developerMode) {
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