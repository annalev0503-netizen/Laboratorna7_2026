#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("number.txt");

    if (!file) {
        cout << "Не вдалося відкрити файл number.txt\n";
        return 1;
    }

    int product = 1;
    bool hasNegative = false;
    int number;

    while (file >> number) {
        if (number < 0) {
            product *= number;
            hasNegative = true;
        }
    }

    file.close();

    if (hasNegative) {
        cout << "Добуток від'ємних чисел: " << product << "\n";
    }
    else {
        cout << "Від'ємних чисел немає\n";
    }

    return 0;
}