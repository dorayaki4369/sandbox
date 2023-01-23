#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

unique_ptr<CardHolder> card_holder(new CardHolder());
vector<Player> players = {Player("dealer")};


int main(void) {
    cout << "Game start!" << endl;

    while (true) {
        cout << "Please input your name" << endl;
        string name;
        cin >> name;
        cout << "Are you sure your name is " << name << "?(y/n)" << endl;
        if ([]()->char { char ch; cin >> ch; return ch; }() == 'y') {
            players.emplace_back(name);
            break;
        }
    }

    cout << "Distribute the card..." << endl;
    for (auto& player : players) {
        player.receiveCard(card_holder->pickCard(2));
    }

    cout << "Your hand" << endl;
    players[1].handDisclosure();
    if (players[0].total() == 21 && players[1].total() == 21) {
        cout << "draw" << endl;
    }
    else if (players[0].total() == 21 || players[1].total() > 21) {
        cout << players[1].getName() << " lose" << endl;
    }
    else if (players[0].total() > 21 || players[1].total() == 21) {
        cout << players[1].getName() << " win!" << endl;
    }

    cout << "What will you do?" << endl;
    cout << "1. HIT 2. STAND 3.DOUBLE" << endl;
    int answer;
    cin >> answer;
}