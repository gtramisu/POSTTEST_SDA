#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    int *kiri = arr;
    int *kanan = arr + n - 1;
    while (kiri < kanan) {
        int temp = *kiri;
        *kiri = *kanan;
        *kanan = temp;
        kiri++;
        kanan--;
    }
}

int main() {
    const int n = 7;
    int data[n] = {2, 3, 5, 7, 11, 13, 17};

    cout << "+---------------------------+\n";
    cout << "|  Array Sebelum & Sesudah  |\n";
    cout << "+---------------------------+\n";

    cout << "Sebelum : ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;

    balikArray(data, n);

    cout << "Sesudah : ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;

    cout << "+---------------------------+\n";

    return 0;
}