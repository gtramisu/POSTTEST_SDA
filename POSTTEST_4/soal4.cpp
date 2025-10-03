#include <iostream>
using namespace std;

// node untuk circular doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// fungsi buat masukin data secara terurut (ascending)
void sortedInsert(Node*& head, int data) {
    Node* nodeBaru = new Node{data, nullptr, nullptr};

    // disini kasus list masih kosong
    if (!head) {
        nodeBaru->next = nodeBaru;
        nodeBaru->prev = nodeBaru;
        head = nodeBaru;
        return;
    }

    Node* tail = head->prev;

    // disini kasus data lebih kecil dari head (makanya jadi elemen paling depan)
    if (data < head->data) {
        nodeBaru->next = head;   // sambung ke head lama
        nodeBaru->prev = tail;   // baru sambung ke tail
        head->prev = nodeBaru;   // update prev head
        tail->next = nodeBaru;   // update next tail
        head = nodeBaru;         // update head ke node baru
        return;
    }

    // kalo datanya lebih besar, dia cari posisi yang pas
    Node* curr = head;
    while (curr->next != head && curr->next->data < data) 
        curr = curr->next;

    // sisipkan nodeBaru setelah curr
    nodeBaru->next = curr->next;
    nodeBaru->prev = curr;
    curr->next->prev = nodeBaru;
    curr->next = nodeBaru;
}

// cetak list dari head sampai balik lagi ke head
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

    // masukin data acak, otomatis tersimpan terurut
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "+-------------------------------+" << endl;
    cout << "|          Output List          |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "| ";
    printList(head);
    cout << "                  |" << endl;
    cout << "+-------------------------------+" << endl;

    return 0;
}
