#include <memory>
#include "WaveGenerator.h"
#include <valarray>

using namespace std;

int main(int argc, char* argv[]) {
    vector<double> x = { 0.0, 1.0, 2.0, 3.0 };

    //y = 2*x
    auto wg = std::make_unique<WaveGenerator>(x, [=](double i) {
        return i * 2;
    });
    auto ans = wg->GenerateY();//0.0, 2.0, 4.0, 3.0

    //y = cos(x)
    wg = std::make_unique<WaveGenerator>(x, [=](double i) {
        return cos(i);
    });
    ans = wg->GenerateY();//1.0, 0.5, -0.4, -0.9

    //‹éŒ`”g
    wg = make_unique<WaveGenerator>(x, [=](double i) {
        return cos(i) >= 0 ? 1 : 0;
    });
    ans = wg->GenerateY();//1.0, 1.0, 0.0, 0.0

    return 0;
}
