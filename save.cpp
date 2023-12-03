#include "header.h"

void saveGame(MazeGenerator* map ,std::vector<GameObject*> objects, int numberArtifacts, double time){
    std::ofstream outputFile("save.txt");
    for(int i = 0; i < 47; ++i){
        for(int j = 0; j < 190; ++j) {
            outputFile << map->maze[i][j];
        }
    }
    outputFile << numberArtifacts << std::endl;
    outputFile << time << std::endl;
    for(auto& go: objects){
        outputFile << std::to_string(go->y) << std::endl;
        outputFile << std::to_string(go->x) << std::endl;
    }
}