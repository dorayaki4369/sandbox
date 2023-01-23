#pragma once
#include <functional>
#include <vector>

using namespace std;

class WaveGenerator {
    vector<double> xArray;
    function<double(const double&)> func;

public:
    explicit WaveGenerator(vector<double> x, function<double(const double&)>);
    vector<double> GenerateY() const;
};
