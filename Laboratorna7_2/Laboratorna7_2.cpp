#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int N = 5;
    int matrix[N][N];

    ifstream file("matrix.txt");

    if (!file) {
        cout << "Не вдалося відкрити файл matrix.txt\n";
        return 1;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file >> matrix[i][j];

    file.close();

    cout << "Матриця:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << "\t";
        cout << "\n";
    }

    int minValue = INT32_MAX;
    for (int i = 0; i < N; i++) {
        const int element = matrix[i][N - 1 - i];
        minValue = min(minValue, element);
    }

    cout << "Мінімальний елемент побічної діагоналі: " << minValue << "\n";

    return 0;
}