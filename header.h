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

void tableRecords(int h , int w);

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

class GameObject{
public:
    int x, y;
    MazeGenerator* _map;
    char* graphics;
    virtual void move(int c) = 0;
};

class Draw {
    int _h, _w;
    bool _developerMode;
    MazeGenerator* _map;
public:
    int x, y;
    Draw(int h, int w, MazeGenerator* map, bool developerMode);
    void display(GameObject*& object);
    void displayMap();
    int displayPause(int h1, int w1);
};

class Character : public GameObject{
public:
    Character(int nx, int ny, MazeGenerator* map);
    void move(int c) override;
};

class Ghosts : public GameObject{
public:
    int direction;
    Ghosts(int nx, int ny, MazeGenerator* nmap);
    void move(int c) override;
};

class Artifacts : public GameObject{
public:
    Artifacts(int nx, int ny, MazeGenerator* nmap);
    void move(int c) override;
};

struct Player {
    std::string name;
    int artifactsCollected;
    double timeTaken;
};

bool displaySettings(int h1, int w1, sf::Sound* sound, bool* developerMode);

void game(int ch, bool developerMode);

void saveGame(MazeGenerator* map ,std::vector<GameObject*> objects, int numberArtifacts, double time);

void tableRecords(int h, int w);

void displayResult(int artifactsCollected, double timeTaken);

void displayTable(const std::vector<Player>& players);

bool comparePlayers(const Player& player1, const Player& player2);