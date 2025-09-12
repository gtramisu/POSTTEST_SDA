#include <iostream>
#include <iomanip>
using namespace std;

void tukar(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x, y;
    cout << "Masukkan nilai pertama : ";
    cin >> x;
    cout << "Masukkan nilai kedua   : ";
    cin >> y;

    cout << "\n+------------+------------+\n";
    cout << "|    Variabel Sebelum    |\n";
    cout << "+------------+------------+\n";
    cout << "| x = " << setw(6) << x << " | y = " << setw(6) << y << " |\n";
    cout << "+------------+------------+\n";

    tukar(x, y);

    cout << "\n+------------+------------+\n";
    cout << "|    Variabel Sesudah    |\n";
    cout << "+------------+------------+\n";
    cout << "| x = " << setw(6) << x << " | y = " << setw(6) << y << " |\n";
    cout << "+------------+------------+\n";

    return 0;
}