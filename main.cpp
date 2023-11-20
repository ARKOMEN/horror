#include "header.h"

int main() {
    setlocale(LC_ALL,"Russian");

    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("Alien_Shooter_OST_-_Menu_Theme_62497557.wav")){
        std::cerr << "unable to open the file.";
        exit(1);
    }
    sf::Sound sound;
    sound.setBuffer(buffer);

    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(50);

    if(has_colors() == FALSE){
        endwin();
        std::cerr << "Your terminal does not support color\n";
        exit(1);
    }

    int highlight = 1;
    int c;
    const char *options[] = {
            "New game",
            "Continue from the checkpoint",
            "Settings",
            "Exit"
    };

    int h1, w1;
    getmaxyx(stdscr, h1, w1);
    int h = h1/2;
    int w = w1/2;

    bool choice = true;

    sound.play();
    sound.setLoop(true);

    while ('q' != (c = getch()) && choice) {
        clear();

        switch (c) {
            case KEY_UP:
                if (highlight == 1) {
                    highlight = 4;
                } else {
                    highlight--;
                }
                break;
            case KEY_DOWN:
                if (highlight == 4) {
                    highlight = 1;
                } else {
                    highlight++;
                }
                break;
            case 10: // клавиша ENTER
                if(highlight == 1) {
                    sound.stop();
                    game(highlight);
                    sound.play();
                }
                else if(highlight == 2){
                    //продолжить с контрольной точки
                }
                else if(highlight == 3){//настройки
                    display_settings(h, w, &sound);

                }
                else if(highlight == 4){
                    choice = false;
                }
                break;
        }
        for (int i = 0; i < 4; i++) {
            if (highlight == i + 1) {
                attron(A_REVERSE);
            }
            wmove(stdscr, h + i, w);
            printw("%s", options[i]);
            attroff(A_REVERSE);
        }
    }
    endwin();
    return 0;
}