#include <iostream>
#include <string>
using namespace std;

// mode untuk stack, tiap node itu menyimpan 1 karakter
struct Node {
    char data;
    Node* next;
};

// fungsi push= masukin karakter baru ke atas stack
void push(Node*& top, char data) {
    Node* nodeBaru = new Node{data, top}; // node baru nunjuk ke top lama
    top = nodeBaru;                       // ini untuk update top ke node baru
}

// fungsi pop= ambil karakter dari atas stack
char pop(Node*& top) {
    if (!top) return '\0';   // ini kalo stack nya kosong
    Node* temp = top;        // lanjut simpan node paling atas
    char value = temp->data; // terus ambil datanya
    top = top->next;         // dan geser top ke bawah
    delete temp;             // kalo ini untuk hapus node lama
    return value;            // dan ini kembalikan data
}

// nah ini fungsi untuk membalik string pakai stack
// ide= masukin semua char ke stack (LIFO)
// lalu pop satu-satu, otomatis jadi kebalik
string reverseString(string s) {
    Node* top = nullptr;
    for (char c : s) push(top, c);   // semua char itu dimasukin ke stack
    string hasil = "";
    while (top) hasil += pop(top);   // pop sampai kosong
    return hasil;
}

int main() {
    string text = "Struktur Data";
    string hasil = reverseString(text);

    // ini buat output
    cout << "+-----------------+---------------+" << endl; 
    cout << "|      Input      |     Output    |" << endl;
    cout << "+-----------------+---------------+" << endl;
    cout << "| " << text << "   | " << hasil << " |" << endl;
    cout << "+-----------------+---------------+" << endl;

    return 0;
}