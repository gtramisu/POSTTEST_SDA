#include <iostream>
using namespace std;

// ini struktur node untuk tree 
struct Node {
    int data;           // buat nyimpan nilai/data node
    Node* left;         // pointer ke anak kiri
    Node* right;        // pointer ke anak kanan
};

// fungsi buat bikin node baru
Node* newNode(int value) {
    Node* nodeBaru = new Node();  // alokasi memori nya buat node baru
    nodeBaru->data = value;       // di isi datanya
    nodeBaru->left = nullptr;     // kalo anak kiri kosong
    nodeBaru->right = nullptr;    // anak kanan juga kosong
    return nodeBaru;              // balikin alamat node
}

// fungsi buat nambahin node ke tree (BST)
Node* insert(Node* root, int value) {
    // kalo belum ada root nya, bikin node baru jadi akar
    if (root == nullptr)
        return newNode(value);

    // kalo nilai lebih kecil dari root, taruh di kiri
    if (value < root->data)
        root->left = insert(root->left, value);
    // tapi kalo lebih besar, taruh di kanan
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;  // balikin root biar tree tetap nyambung
}

// fungsi buat traversal pre-order (root -> kiri -> kanan)
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " | ";   // tampilkan dulu data root nya
        preOrder(root->left);          // baru ke kiri
        preOrder(root->right);         // terakhir ke kanan
    }
}

int main() {
    // bikin tree kosong dulu
    Node* root = nullptr;

    // tambah data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "+---------------------------------------------+\n";
    cout << "|        Pre-order Traversal dari Tree        |\n";
    cout << "+---------------------------------------------+\n";
    cout << "| ";

    // baru tampilin deh hasil pre-order traversal nya
    preOrder(root);

    cout << "\n+---------------------------------------------+\n";

    return 0;
}