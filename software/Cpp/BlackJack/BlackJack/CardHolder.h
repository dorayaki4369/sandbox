#pragma once
#include <vector>

enum card {
    ace = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
};

class CardHolder {
    int counter[13] = {};

public:
    CardHolder();
    std::vector<card> pickCard(size_t);
    void showRemainingCards();
};
