#include <iostream>
using namespace std;

// struktur dasar buat node pohon biner
struct Node {
    int data;       // buat nyimpen angka di tiap node
    Node* left;     // pointer ke anak kiri
    Node* right;    // pointer ke anak kanan
};

// fungsi buat bikin node baru
Node* newNode(int value) {
    Node* nodeBaru = new Node();   // alokasi node baru di heap
    nodeBaru->data = value;        // ngisi data
    nodeBaru->left = nullptr;      // kalo belum ada anak kiri
    nodeBaru->right = nullptr;     // belum ada juga anak kanan
    return nodeBaru;               // balikin aja deh node yang udah jadi
}

// fungsi buat masukin data ke BST (biar terurut)
Node* insert(Node* root, int value) {
    if (root == nullptr) {         // kalo kosong, bikin node baru
        return newNode(value);
    }
    if (value < root->data) {      // kalo lebih kecil, masuk ke kiri
        root->left = insert(root->left, value);
    } else {                       // tapi kalo lebih besar atau sama, masuk ke kanan
        root->right = insert(root->right, value);
    }
    return root;                   // balikin root nya biar nyambung
}

// fungsi buat cari nilai terbesar dari ujung kanan
int cariTerbesar(Node* root) {
    if (root == nullptr) {
        cout << "Tree kosong!" << endl;
        return -1; // penanda aja ini kalo kosong
    }

    Node* current = root; // mulai dari root
    while (current->right != nullptr) { // jalan terus ke kanan
        current = current->right;
    }
    return current->data; // paling kanan = paling besar yaa
}

int main() {
    Node* root = nullptr;  // tree masih kosong

    // data buat isi BST
    int data[] = {20, 10, 30, 5, 15, 25, 40};
    int n = sizeof(data) / sizeof(data[0]);

    // masukin semua data ke tree
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // cari nilai terbesar di tree
    int maxValue = cariTerbesar(root);

    cout << "+---------------------------------+\n";
    cout << "|       CARI NILAI TERBESAR       |\n";
    cout << "+---------------------------------+\n";
    cout << "| Data Tree : ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << "|\n";
    cout << "+---------------------------------+\n";
    cout << "| Nilai Terbesar : " << maxValue << "             |\n";
    cout << "+---------------------------------+\n";

    return 0;
}
