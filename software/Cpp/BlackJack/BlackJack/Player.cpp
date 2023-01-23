#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "Player.h"
#include <numeric>

using namespace std;

Player::Player(string name) : name(std::move(name)) {}

void Player::receiveCard(vector<card> cards) {
    hand.insert(hand.end(), cards.begin(), cards.end());
}

void Player::handDisclosure() {
    if (hand.empty()) {
        cout << name << " don't have a card" << endl;
        return;
    }

    cout << name << "'s card ... ";
    for (const auto card : hand) {
        cout << card << ", ";
    }
    cout << endl;
}

string Player::getName() const {
    return this->name;
}

size_t Player::total() {
    return accumulate(hand.begin(), hand.end(), 0);
}
