#include <functional>
#include "WaveGenerator.h"

using namespace std;

WaveGenerator::WaveGenerator(vector<double> xArray, function<double(const double&)> f) : xArray(xArray), func(f) {}

vector<double> WaveGenerator::GenerateY() const {
    vector<double> y;
    for (auto x : xArray) {
        y.push_back(func(x));
    }
    return y;
}
