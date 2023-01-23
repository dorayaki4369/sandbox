#pragma once
#include <vector>
#include "CardHolder.h"

using namespace std;

class Player {
    string name;
    vector<card> hand = vector<card>();

public:
    explicit Player(string);
    void receiveCard(vector<card>);
    void handDisclosure();
    string getName() const;
    size_t total();
};