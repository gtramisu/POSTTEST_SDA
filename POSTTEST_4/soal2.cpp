#include <iostream>
#include <string>
using namespace std;

// node stack untuk simpan karakter kurung
struct Node {
    char data;
    Node* next;
};

// kalo buka kurung, simpan dulu di stack lewat fungsi push
void push(Node*& top, char data) {
    Node* nodeBaru = new Node{data, top};
    top = nodeBaru;
}

// pop= ambil buka kurung terakhir dari stack
char pop(Node*& top) {
    if (!top) return '\0';    // kalo stack nya kosong
    Node* temp = top;
    char value = temp->data;  // ambil dari data node teratas
    top = top->next;          // geser top
    delete temp;              // hapus node lama
    return value;
}

// fungsi utama untuk cek keseimbangan bracket
bool areBracketsBalanced(string expr) {
    Node* top = nullptr; // awalnya stack kosong

    for (char c : expr) {
        // kalo ketemu buka kurung, push ke stack
        if (c == '(' || c == '{' || c == '[') push(top, c);

        // kalo ketemu tutup kurung, bisa cek stack
        else if (c == ')' || c == '}' || c == ']') {
            if (!top) return false;   // kalo kosong, dia ga seimbang
            char x = pop(top);        // jadi ambil buka kurung terakhir
            // cek apakah pasangannya itu cocok
            if ((c == ')' && x != '(') || 
                (c == '}' && x != '{') || 
                (c == ']' && x != '['))
                return false;         // kalo beda, berarti ga seimbang
        }
    }
    // setelah dicek semua, stack harus kosong
    return top == nullptr;
}

int main() {
    string expr1 = "{[()]}";   // ini yg seimbang
    string expr2 = "{[(])}";   // ini yg ga seimbang

    string out1 = areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang";
    string out2 = areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang";

    cout << "+----------+-----------------+" << endl;
    cout << "| Ekspresi |      Output     |" << endl;
    cout << "+----------+-----------------+" << endl;
    cout << "| " << expr1 << "   | " << out1 << "        |" << endl;
    cout << "| " << expr2 << "   | " << out2 << "  |" << endl;
    cout << "+----------+-----------------+" << endl;

    return 0;
}
