#include "CardHolder.h"
#include <random>
#include <iostream>
#include <vector>

using namespace std;

CardHolder::CardHolder() = default;

vector<card> CardHolder::pickCard(const size_t num) {
    vector<card> cards = {};
    random_device rnd;

    for (size_t i = 0; i < num;) {
        const auto rnd_card = static_cast<int>(rnd() % king + 1);
        if (counter[rnd_card - 1] < 5) {
            counter[rnd_card - 1]++;
            cards.push_back(static_cast<card>(rnd_card));
            i++;
        }
    }

    return cards;
}

void CardHolder::showRemainingCards() {
    auto i = 1;
    for (auto c : counter) {
        cout << i << "---" << c << endl;
        i++;
    }
}


