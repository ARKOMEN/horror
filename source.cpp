#include "header.h"

map_class::map_class(int h1, int w1) :_h(h1), _w(w1){
    srand((unsigned)time(NULL));
}

int map_class::get_h() {
    return _h;
}

int map_class::get_w() {
    return _w;
}

bool map_class::dead_end(int x, int y) {
    int a = 0;

    if(x != 1){
        if(maze[y][x-2] == pass || maze[y][x-2] == room)
            a+=1;
    }
    else a+=1;

    if (y != 1) {
        if (maze[y - 2][x] == pass || maze[y - 2][x] == room)
            a += 1;
    }
    else a += 1;

    if (x != _w - 2) {
        if (maze[y][x + 2] == pass || maze[y][x + 2] == room)
            a += 1;
    }
    else a += 1;

    if (y != _h - 2) {
        if (maze[y + 2][x] == pass || maze[y + 2][x] == room)
            a += 1;
    }
    else a += 1;

    if (a == 4)
        return 1;
    else
        return 0;
}

void map_class::maze_make(int k, int rheight, int rwidth) {
    int x, y, c, a;
    bool b, swap = 1;

    maze = new int *[_h];
    for (int i = 0; i < _h; i++)
        maze[i] = new int[_w];

    for (int i = 0; i < _h; i++) // Массив заполняется землей-ноликами
        for (int j = 0; j < _w; j++)
            maze[i][j] = wall;

    rheight--;
    rwidth--; // Исключительно для удобства

    for (int l = 0; l < k; l++) {  // Генерация комнат
        b = 1;
        while (b) {
            do { // Точка-центр комнаты
                if (rwidth % 4 == 0) // Комнаты, с разной делимостью на 4 ведут себя
                    x = 2 * (rand() % (_w / 2)) + 1; // по разному, унифицируем
                else
                    x = 2 * (rand() % (_w / 2)) + 2;
                if (rheight % 4 == 0)
                    y = 2 * (rand() % (_h / 2)) + 1;
                else
                    y = 2 * (rand() % (_h / 2)) + 2;
            } while (x < (rwidth + 2) || x > (_w - rwidth - 2) ||
                     y < (rheight + 2) || y > (_h - rheight - 2));

            b = 0; // Комнаты не должны прикасаться
            for (int i = (y - rheight - 2); i < (y + rheight + 2); i++)
                for (int j = (x - rwidth - 2); j < (x + rwidth + 2); j++)
                    if (maze[i][j] == room)
                        b = 1;

            if (b)
                continue;

            for (int i = (y - rheight / 2); i < (y + rheight / 2 + 1); i++) // Раскопки комнаты
                for (int j = (x - rwidth / 2); j < (x + rwidth / 2 + 1); j++)
                    maze[i][j] = room;

            for(int d = 0; d < 3; ++d) {

                c = rand() % 4; // Дверь в комнату, определяем в какую стену
                // Нижняя, верхняя, правая и левая соответственно
                // Нагромождение в виде rand()... нужно для того, чтобы дверь стояла в разных
                // местах стены
                if (c == 0) maze[y + rheight / 2 + 1][x - rwidth / 2 + 2 * (rand() % (rwidth / 2 + 1))] = room;
                if (c == 1) maze[y - rheight / 2 - 1][x - rwidth / 2 + 2 * (rand() % (rwidth / 2 + 1))] = room;
                if (c == 2) maze[y - rheight / 2 + 2 * (rand() % (rheight / 2 + 1))][x + rwidth / 2 + 1] = room;
                if (c == 3) maze[y - rheight / 2 + 2 * (rand() % (rheight / 2 + 1))][x - rwidth / 2 - 1] = room;
                // swap отвечает за возможность поворачивать комнату на 90°
                if (swap) {
                    rheight += rwidth;
                    rwidth = rheight - rwidth;
                    rheight -= rwidth;
                } // Вот так настоящие мужики меняют переменные значениями
            }
        }
    }

    x = 3; y = 3; a = 0; // Точка приземления крота и счетчик
    while (a < 10000) { // Да, простите, костыль, иначе есть как, но лень
        maze[y][x] = pass;
        a++;
        while (1) { // Бесконечный цикл, который прерывается только тупиком
            c = rand() % 4; // Напоминаю, что крот прорывает
            switch (c) {  // по две клетки в одном направлении за прыжок
                case 0:
                    if (y != 1)
                        if (maze[y - 2][x] == wall) { // Вверх
                            maze[y - 1][x] = pass;
                            maze[y - 2][x] = pass;
                            y -= 2;
                        }
                case 1:
                    if (y != _h - 2)
                        if (maze[y + 2][x] == wall) { // Вниз
                            maze[y + 1][x] = pass;
                            maze[y + 2][x] = pass;
                            y += 2;
                        }
                case 2:
                    if (x != 1)
                        if (maze[y][x - 2] == wall) { // Налево
                            maze[y][x - 1] = pass;
                            maze[y][x - 2] = pass;
                            x -= 2;
                        }
                case 3:
                    if (x != _w - 2)
                        if (maze[y][x + 2] == wall) { // Направо
                            maze[y][x + 1] = pass;
                            maze[y][x + 2] = pass;
                            x += 2;
                        }
            }
            if (dead_end(x, y))
                break;
        }
        if (dead_end(x, y)) // Вытаскиваем крота из тупика
            do {
                x = 2 * (rand() % ((_w - 1) / 2)) + 1;
                y = 2 * (rand() % ((_h - 1) / 2)) + 1;
            } while (maze[y][x] != pass && maze[y][x] != room);
    } // На этом и все.
    int i = 0;
    while (i < mine) {
        x = rand() % _w + 1;
        y = rand() % _h + 1;
        if (maze[y][x] == wall)
            continue;
        maze[y][x] = mine;
        i++;
    }
}
game_status::game_status(int level, bool game_over)
: _level(level), _game_over(game_over){}

int game_status::get_level() {
    return _level;
}

bool game_status::get_game_over() {
    return _game_over;
}

int game_status::get_c() {
    return _c;
}

void game_status::write_c(int c){
    _c  = c;
}

void game_status::write_level(int level){
    _level = level;
}

void display_settings(int h, int w, sf::Sound* sound) {
    int highlight = 1;
    int c;
    int volume = sound->getVolume();
    const char *options[] = {
            "Volume",
            "Back"
    };
    bool choice = true;

    while ('q' != (c = getch()) && choice) {
        clear();

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
                if (highlight == 2) {
                    choice = false;
                }
        }
        volume = std::clamp(volume, 0, 100);
        sound->setVolume(static_cast<float>(volume));
        for (int i = 0; i < 2; i++) {
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
    }
}

int draw::display_pause(int h1, int w1, game_status* status) {
    const char *options[] = {
            "Continue",
            "Save and exit menu",
    };
    int highlight = 1;
    bool choise = true;
    int h = h1/2;
    int w = w1/2;

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
    }while (status->get_c() != 'q' && choise);
    return highlight;
}

void draw::display(game_object *&object, map_class m, game_status* status) {
    if(object->type == 1) {
        for (int i = 0; i < m.get_w(); i++) {
            if (i > m.get_w() - 1 || i < 0)
                continue;
            for (int j = 0; j < m.get_h(); j++) {
                if (j < 0 || j > m.get_h() - 1)
                    continue;
                switch (m.maze[j][i]) {
                    case wall:
                        mvaddch(j, i, '#');
                        break;
                    case pass:
                        mvaddch(j, i, ' ');
                        break;
                    case room:
                        mvaddch(j, i, ' ');
                        break;
                    case mine:
                        mvaddch(j, i, '\'');
                        break;
                }
            }
        }
        wmove(stdscr, object->y, object->x);
        printw("C");
    }
    else if(object->type == 2){
        if(object->x >= status->x_ch - 6 && object->x <=status->x_ch + 6 && object->y >= status->y_ch - 3 && object->y <= status->y_ch + 3){
            wmove(stdscr, object->y, object->x);
            printw("G");
            std::cout << "haha" << std::endl;
        }
    }
}

void ghosts::move(game_status* status, map_class m){
    int dx, dy;
    bool f = true;
    if(status->signal){

    }
    else{
        while(f){
            dx = rand()%2 - 1;
            dy = rand()%2 - 1;
            switch (m.maze[x+dx][y+dy]) {
                case room: f = false;
                    break;
                case pass: f = false;
                    break;
                case mine: f = false;
                    break;
            }
        }
        x += dx;
        y += dy;
    }
}

void main_ch::move(game_status* status, map_class m) {
    status->signal = false;
    switch (status->get_c()) {
        case KEY_UP:
            switch (m.maze[y - 1][x]) {
                case pass:
                    y--;
                    break;
                case room:
                    y--;
                    break;
                case mine:
                    y--;
                    status->signal = true;
                    break;
            }
            break;
        case KEY_DOWN:
            switch (m.maze[y + 1][x]) {
                case pass:
                    y++;
                break;
                case room:
                    y++;
                    break;
                case mine:
                    y++;
                    status->signal = true;
                    break;
            }
            break;
        case KEY_LEFT:
            switch (m.maze[y][x - 1]) {
                case pass:
                    x--;
                break;
                case room:
                    x--;
                    break;
                case mine:
                    x--;
                    status->signal = true;
                    break;
            }
            break;
        case KEY_RIGHT:
            switch (m.maze[y][x + 1]) {
                case pass:
                    x++;
                break;
                case room:
                    x++;
                    break;
                case mine:
                    x++;
                    status->signal = true;
                    break;
            }
            break;
    }
    status->x_ch = x;
    status->y_ch = y;
}

void game(int ch) {
    if(ch == 1){
        game_status status(1, false);
        status.signal = false;

        int h1, w1;
        getmaxyx(stdscr, h1, w1);
        int h = h1/2;
        int w = w1/2;

        draw picture;

        main_ch character;
        character.type = 1;
        character.y = 3;
        character.x = 3;
        status.x_ch = character.x;
        status.y_ch = character.y;
        std::vector<game_object*> objects;
        objects.push_back(static_cast<game_object*>(&character));

        int k = 40; // Мы включили параметр количества комнат
        int rheight = 5, rwidth = 7; // Размеры комнаты
        map_class map(h1, w1 - 1);
        map.maze_make(k, rheight, rwidth);

        ghosts blind_g;
        blind_g.x = h;
        blind_g.y = w;
        blind_g.type = 2;
        objects.push_back(static_cast<game_object*>(&blind_g));
        do {
            status.write_c(getch());
            if(status.get_c() == 27){
                if(picture.display_pause(h1, w1, &status) == 2){
                    //сохраняем игру
                }
            }
            clear();
            for(auto& go: objects){
                go->move(&status, map);
            }
            for(auto& go: objects){
                picture.display(go, map, &status);
            }
        } while (status.get_c() != 'q');
    }
}