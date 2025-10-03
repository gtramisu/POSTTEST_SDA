#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

// node queue, tiap node itu menyimpan nama dokumen
struct Node {
    string document;
    Node* next;
};

// enqueue = masukin dokumen ke antrian (belakang)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* nodeBaru = new Node{document, nullptr};
    if (!front) 
        front = rear = nodeBaru;    // kalokosong, front & rear itu jadi nodeBaru
    else {
        rear->next = nodeBaru;      // baru sambung node baru di belakang
        rear = nodeBaru;            // ini untuk update rear nya
    }
}

// dequeue= ambil dokumen dari antrian (depan)
string dequeue(Node*& front, Node*& rear) {
    if (!front) return "";          // kalo kosong, dia balikin string yg kosong
    Node* temp = front;             // ini untuk simpan node depan
    string doc = temp->document;    // ambil nama dokumennya
    front = front->next;            // geser front ke berikutnya
    if (!front) rear = nullptr;     // kalo udah kosong, rear ikut null
    delete temp;                    // ini untuk hapus node lama
    return doc;                     // dan ini untuk balikin nama dokumen
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // masukin 3 dokumen ke dalam antrian
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    int width = 30;
    cout << "+" << string(width, '-') << "+" << endl;
    cout << "| " << left << setw(width - 2) << "Output Pemrosesan" << " |" << endl;
    cout << "+" << string(width, '-') << "+" << endl;

    // proses semua dokumen (FIFO)
    while (front) {
        string line = "Memproses: " + dequeue(front, rear);
        cout << "| " << left << setw(width - 2) << line << " |" << endl;
    }

    cout << "+" << string(width, '-') << "+" << endl;
    return 0;
}
