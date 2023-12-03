#include "header.h"

void game(int ch, bool developerMode) {
    if(ch == 1){
        int h1, w1;
        getmaxyx(stdscr, h1, w1);
        int h = h1/2;
        int w = w1/2;

        MazeGenerator map(h1, w1);
        map.generateMaze();

        Draw picture(h1, w1, &map, developerMode);


        std::vector<GameObject*> objects;
        Character pacMan(w1/2, h1/2, &map);
        objects.push_back(static_cast<GameObject*>(&pacMan));
        int numberArtifacts = 5;
        for(int i = 0; i < numberArtifacts; ++i){
            int nx, ny;
            while(true){
                nx = rand()%(w1 - 2) +2;
                ny = rand()%(h1 - 2) +2;
                if(map.maze[ny][nx] == ' '){
                    break;
                }
            }
            objects.push_back(static_cast<GameObject*>(new Artifacts(nx, ny, &map)));
        }
        for(int i = 0; i < 10; ++i){
            int nx, ny;
            while(true){
                nx = rand()%(w1 - 2) +2;
                ny = rand()%(h1 - 2) +2;
                if(map.maze[ny][nx] == ' '){
                    break;
                }
            }
            objects.push_back(static_cast<GameObject*>(new Ghosts(nx, ny, &map)));
        }
        bool gameOver = false;
        int c;
        auto startTime = std::chrono::high_resolution_clock::now();
        while ('q' != (c = getch()) && !gameOver){
            picture.x = pacMan.x;
            picture.y = pacMan.y;
            if(c == 27){
                if(picture.displayPause(h1, w1) == 2){
                    auto endTime = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();
                    saveGame(&map, objects, numberArtifacts, duration);
                    gameOver = true;
                }
            }
            for(int i = 1; i < 1 + numberArtifacts; ++i){
                if(pacMan.x == objects[i]->x && pacMan.y == objects[i]->y){
                    numberArtifacts--;
                    objects.erase(objects.begin() + i);
                    if(numberArtifacts == 0){
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();
                        displayResult(5 - numberArtifacts, duration);
                        gameOver = true;
                    }
                }
            }
            for(int i = 1 + numberArtifacts; i < 1 + numberArtifacts + 10; ++i){
                if(pacMan.x == objects[i]->x && pacMan.y == objects[i]->y){
                    auto endTime = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();
                    displayResult(5 - numberArtifacts, duration/60);
                    gameOver = true;
                }
            }
            clear();
            for(auto& go: objects){
                go->move(c);
            }
            picture.displayMap();
            for(auto& go: objects){
                picture.display(go);
            }
            timeout(250);
        }
    }
    else{
        int h1, w1;
        getmaxyx(stdscr, h1, w1);
        int h = h1/2;
        int w = w1/2;
        int c;
        std::string tmp1, tmp2;
        std::vector<GameObject*> objects;
        std::string filename = "save.txt";
        std::ifstream inputFile(filename);
        MazeGenerator map(h1, w1);
        std::string line;
        for(int i = 0; i < 47; ++i) {
            for (int j = 0; j < 190; ++j) {
                inputFile.get(map.maze[i][j]);
            }
        }
        Draw picture(h1, w1, &map, developerMode);
        std::getline(inputFile, tmp1);
        int numberArtifacts = std::stoi(tmp1);
        std::getline(inputFile, tmp1);
        int time = std::stoi(tmp1);
        std::getline(inputFile, tmp1);
        std::getline(inputFile, tmp2);
        Character pacMan(std::stoi(tmp2), std::stoi(tmp1), &map);
        objects.push_back(static_cast<GameObject*>(&pacMan));
        for(int i = 0; i < numberArtifacts; ++i){
            std::getline(inputFile, tmp1);
            std::getline(inputFile, tmp2);
            objects.push_back(static_cast<GameObject*>(new Artifacts(std::stoi(tmp2), std::stoi(tmp1), &map)));
        }
        for(int i = 0; i < 10; ++i){
            std::getline(inputFile, tmp1);
            std::getline(inputFile, tmp2);
            objects.push_back(static_cast<GameObject*>(new Ghosts(std::stoi(tmp2), std::stoi(tmp1), &map)));
        }
        inputFile.close();
        bool gameOver = false;
        auto startTime = std::chrono::high_resolution_clock::now();
        while ('q' != (c = getch())){
            picture.x = pacMan.x;
            picture.y = pacMan.y;
            if(c == 27){
                if(picture.displayPause(h1, w1) == 2){
                    auto endTime = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();
                    saveGame(&map, objects, numberArtifacts, duration/60 + time);
                }
            }
            for(int i = 1; i < 1 + numberArtifacts; ++i){
                if(pacMan.x == objects[i]->x && pacMan.y == objects[i]->y){
                    numberArtifacts--;
                    objects.erase(objects.begin() + i);
                    if(numberArtifacts == 0){
                        auto endTime = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();
                        displayResult(5 - numberArtifacts, duration/60 + time);
                        gameOver = true;
                    }
                }
            }
            for(int i = 1 + numberArtifacts; i < 1 + numberArtifacts + 10; ++i){
                if(pacMan.x == objects[i]->x && pacMan.y == objects[i]->y){
                    auto endTime = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();
                    displayResult(5 - numberArtifacts, duration/60 + time);
                    gameOver = true;
                }
            }
            clear();
            for(auto& go: objects){
                go->move(c);
            }
            picture.displayMap();
            for(auto& go: objects){
                picture.display(go);
            }
            timeout(250);
        }
    }
}