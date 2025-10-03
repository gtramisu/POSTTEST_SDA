#include <iostream>
using namespace std;

// node untuk circular doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// ini fungsi tukar posisi head dan tail
void exchangeHeadAndTail(Node*& head) {
    // kalo kosong atau cuma ada 1 node, ga usah ditukar
    if (!head || head->next == head) return;

    Node* headNext = head->next; // node setelah head
    Node* tail = head->prev;     // jadi tail itu sama dengan node sebelum head
    Node* tailPrev = tail->prev; // node sebelum tail

    // disini kasus khusus= list cuma ada 2 node
    if (head->next == tail) {
        tail->next = head;
        head->prev = tail;
        head->next = tail;
        tail->prev = head;
        head = tail; // ini untuk update head jadi tail lama
        return;
    }

    // disini kasus umum= lebih dari 2 node
    headNext->prev = tail;   // hubungkan node setelah head ke tail
    tailPrev->next = head;   // hubungkan node sebelum tail ke head
    head->prev = tailPrev;   // update prev head
    tail->next = headNext;   // update next tail
    tail->prev = head;       // tail.prev mengarah ke head
    head->next = tail;       // head.next mengarah ke tail

    head = tail; // update head ke tail lama
}

// sisipkan node di akhir list (insertEnd biasa)
void insertEnd(Node*& head, int data) {
    Node* nodeBaru = new Node{data, nullptr, nullptr};
    if (!head) {
        nodeBaru->next = nodeBaru;
        nodeBaru->prev = nodeBaru;
        head = nodeBaru;
        return;
    }
    Node* tail = head->prev;
    nodeBaru->next = head;
    nodeBaru->prev = tail;
    head->prev = nodeBaru;
    tail->next = nodeBaru;
}

// print list dari head sampai balik lagi ke head
void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node* head = nullptr;

    // buat list= 1 2 3 4 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    // tampilkan list sebelum tukar head & tail
    cout << "+-------------------------------+" << endl;
    cout << "|         List Sebelum          |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "| ";
    printList(head);
    cout << "                    |" << endl;
    cout << "+-------------------------------+" << endl;

    // tukar head dengan tail
    exchangeHeadAndTail(head);

    // tampilkan list setelah tukar
    cout << "+-------------------------------+" << endl;
    cout << "|         List Sesudah          |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "| ";
    printList(head);
    cout << "                    |" << endl;
    cout << "+-------------------------------+" << endl;

    return 0;
}