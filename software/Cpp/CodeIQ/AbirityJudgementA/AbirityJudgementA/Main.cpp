#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int main() {
	string line;
	int n;
	int counter = 0;

	while (getline(cin, line)) {
		for (int i = 0;i < line.size();i++)line[i] = toupper(line[i]);
		n = stoi(line);
		for (int i = n; i < 2000000; i = i + n) {
			if (i % 2 != 0) {
				counter++;
			}
		}
		cout << counter << endl;
		counter = 0;
	}
}