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

// fungsi rekursif buat ngitung jumlah node
int hitungNode(Node* root) {
    if (root == nullptr) return 0; // kalo kosong ya 0
    return 1 + hitungNode(root->left) + hitungNode(root->right);
    // nambah 1 buat node sekarang + jumlah anak kiri + jumlah anak kanan
}

int main() {
    Node* root = nullptr;  // awalnya kosong

    // masukin data ke tree
    int data[] = {10, 5, 15, 3, 7, 12, 18};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // hitung jumlah node di tree
    int totalNode = hitungNode(root);

    cout << "+--------------------------------+\n";
    cout << "|       HITUNG JUMLAH NODE       |\n";
    cout << "+--------------------------------+\n";
    cout << "| Data Tree : ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << " |\n";
    cout << "+--------------------------------+\n";
    cout << "| Total Node : " << totalNode;
    cout << "                 |\n"; 
    cout << "+--------------------------------+\n";

    return 0;
}
