#include "header.h"

bool comparePlayers(const Player& player1, const Player& player2) {
    if (player1.artifactsCollected > player2.artifactsCollected) {
        return true;
    } else if (player1.artifactsCollected == player2.artifactsCollected) {
        return player1.timeTaken < player2.timeTaken;
    }
    return false;
}

void displayTable(const std::vector<Player>& players) {
    int c;
    while ('q' != (c = getch())) {
        clear();
        printw("%-20s %-20s %-20s\n", "Player Name", "Artifacts Collected", "Time Taken");
        for (const auto &player: players) {
            printw("%-20s %-20d %-20.2f\n", player.name.c_str(), player.artifactsCollected, player.timeTaken);
        }
    }
}

void displayResult(int artifactsCollected, double timeTaken){
    int c;
    char playerName[50];
    clear();
    printw("Enter player name: ");
    echo();
    bool choice = false;
    while (!choice) {
        getnstr(playerName, sizeof(playerName));
        timeout(500);
        for(int i = 0; i < 50; ++i){
            if(playerName[i] == ' '){
                choice = true;
            }
        }
    }
    noecho();
    std::ofstream outputFile("table_of_records.txt", std::ios::app);
    outputFile << playerName << artifactsCollected << " " << timeTaken << std::endl;
    outputFile.close();
}

void tableRecords(int h, int w){
    std::string filename = "table_of_records.txt";
    std::ifstream inputFile(filename);

    std::vector<Player> players;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        Player player;
        iss >> player.name >> player.artifactsCollected >> player.timeTaken;
        players.push_back(player);
    }
    inputFile.close();
    std::sort(players.begin(), players.end(), comparePlayers);
    displayTable(players);
}

