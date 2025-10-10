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

// fungsi buat traversal postorder
void postOrder(Node* root) {
    if (root == nullptr) return;   // kalo kosong, ya di stop aja

    // Urutan postorder: kiri -> kanan -> akar
    postOrder(root->left);         // telusuri anak kiri dulu
    postOrder(root->right);        // terus anak kanan
    cout << root->data << " ";     // terakhir baru cetak akar nya
}

int main() {
    Node* root = nullptr;  // awalnya kosong

    // data buat isi tree
    int data[] = {10, 5, 15, 3, 7, 12, 20};
    int n = sizeof(data) / sizeof(data[0]);

    // masukin semua data ke tree
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    cout << "+-------------------------------+\n";
    cout << "|       POSTORDER TRAVERSAL     |\n";
    cout << "+-------------------------------+\n";
    cout << "| Data Tree : ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << "|\n";
    cout << "+-------------------------------+\n";
    cout << "| Postorder : ";
    postOrder(root);                
    cout << "|\n";
    cout << "+-------------------------------+\n";

    return 0;
}
