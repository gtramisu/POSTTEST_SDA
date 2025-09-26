#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string kode;
    string tujuan;
    string status;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
int counterKode = 0;
string baseKode;
int posisiSisip;

void addLast(const string &tujuan, const string &status) {
    string kode;
    if (counterKode == 0) kode = baseKode;
    else kode = baseKode + "-" + to_string(counterKode);
    counterKode++;

    Node* baru = new Node{kode, tujuan, status, NULL, tail};
    if (head == NULL && tail == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void addMiddle(const string &tujuan, const string &status, int posisi) {
    string kode;
    if (counterKode == 0) kode = baseKode;
    else kode = baseKode + "-" + to_string(counterKode);
    counterKode++;

    if (posisi <= 1 || head == NULL) {
        Node* baru = new Node{kode, tujuan, status, head, NULL};
        if (head != NULL) head->prev = baru;
        head = baru;
        if (tail == NULL) tail = baru;
        return;
    }
    Node* temp = head;
    int idx = 1;
    while (temp->next != NULL && idx < posisi-1) {
        temp = temp->next;
        idx++;
    }
    if (temp->next == NULL) { 
        addLast(tujuan, status);
    } else {
        Node* baru = new Node{kode, tujuan, status, temp->next, temp};
        temp->next->prev = baru;
        temp->next = baru;
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << ">> Jadwal kosong!\n"; return;
    }
    cout << ">> Menghapus: " << head->kode << " - " << head->tujuan << "\n";
    Node* hapus = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete hapus;
}

void deleteLast() {
    if (tail == NULL) {
        cout << ">> Jadwal kosong!\n"; return;
    }
    cout << ">> Menghapus: " << tail->kode << " - " << tail->tujuan << "\n";
    Node* hapus = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete hapus;
}

void deleteMiddle(int pos) {
    if (head == NULL) {
        cout << ">> Jadwal kosong!\n"; return;
    }
    if (pos <= 1) { deleteFirst(); return; }

    Node* temp = head;
    int idx = 1;
    while (temp != NULL && idx < pos) {
        temp = temp->next;
        idx++;
    }
    if (temp == NULL) {
        cout << ">> Posisi tidak valid!\n"; return;
    }
    cout << ">> Menghapus posisi " << pos << ": " << temp->kode << " - " << temp->tujuan << "\n";
    if (temp == tail) {
        deleteLast();
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

void editData(const string &kode) {
    if (head == NULL) {
        cout << ">> Jadwal kosong!\n"; return;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->kode == kode) {
            cout << ">> Status lama: " << temp->status << "\n";
            cout << ">> Masukkan status baru: ";
            string st; getline(cin, st);
            if (st.empty()) {
                cout << ">> Status tidak boleh kosong!\n";
                return;
            }
            temp->status = st;
            cout << ">> Status berhasil diperbarui!\n"; return;
        }
        temp = temp->next;
    }
    cout << ">> Kode tidak ditemukan!\n";
}

void display() {
    if (head == NULL) {
        cout << ">> Tidak ada jadwal!\n"; return;
    }
    cout << "\n+-----------------+--------------------------+-------------------+\n";
    cout << "| " << setw(15) << left << "Kode"
         << " | " << setw(24) << left << "Tujuan"
         << " | " << setw(17) << left << "Status" << "|\n";
    cout << "+-----------------+--------------------------+-------------------+\n";
    Node* temp = head;
    while (temp != NULL) {
        cout << "| " << setw(15) << left << temp->kode
             << " | " << setw(24) << left << temp->tujuan
             << " | " << setw(17) << left << temp->status << "|\n";
        temp = temp->next;
    }
    cout << "+-----------------+--------------------------+-------------------+\n";
}

void displayReverse() {
    if (tail == NULL) {
        cout << ">> Tidak ada jadwal!\n"; return;
    }
    cout << "\n+-----------------+--------------------------+-------------------+\n";
    cout << "| " << setw(15) << left << "Kode"
         << " | " << setw(24) << left << "Tujuan"
         << " | " << setw(17) << left << "Status" << "|\n";
    cout << "+-----------------+--------------------------+-------------------+\n";
    Node* temp = tail;
    while (temp != NULL) {
        cout << "| " << setw(15) << left << temp->kode
             << " | " << setw(24) << left << temp->tujuan
             << " | " << setw(17) << left << temp->status << "|\n";
        temp = temp->prev;
    }
    cout << "+-----------------+--------------------------+-------------------+\n";
}

void searchData(const string &key) {
    if (head == NULL) {
        cout << ">> Jadwal kosong!\n"; return;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->kode == key || temp->tujuan == key) {
            cout << "\n>> Data ditemukan:\n";
            cout << "Kode   : " << temp->kode << "\n";
            cout << "Tujuan : " << temp->tujuan << "\n";
            cout << "Status : " << temp->status << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << ">> Data dengan input '" << key << "' tidak ditemukan!\n";
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama: "; getline(cin, nama);
    cout << "Masukkan NIM : "; getline(cin, nim);

    string last3 = nim.substr(nim.size()-3);
    while (last3.size() < 3) last3 = "0" + last3;
    baseKode = "JT-" + last3;
    int lastDigit = nim.back() - '0';
    posisiSisip = lastDigit + 1;

    int pilih;
    do {
        cout << "\n+================================================+\n";
        cout << "|             FLIGHT SCHEDULE SYSTEM             |\n";
        cout << "+================================================+\n";
        cout << "| Nama : " << left << setw(22) << nama
            << "| NIM : " << left << setw(10) << nim << "|\n";
        cout << "+================================================+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                   |\n";
        cout << "| 2. Sisipkan Jadwal                             |\n";
        cout << "| 3. Hapus Jadwal                                |\n";
        cout << "| 4. Update Status Penerbangan                   |\n";
        cout << "| 5. Tampilkan Semua Jadwal (Depan -> Belakang)  |\n";
        cout << "| 6. Tampilkan Semua Jadwal (Belakang -> Depan)  |\n";
        cout << "| 7. Cari Detail Jadwal                          |\n";
        cout << "| 0. Keluar                                      |\n";
        cout << "+================================================+\n";
        cout << ">> Pilih menu: ";
        if (!(cin >> pilih)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << ">> Input tidak valid! Masukkan angka.\n";
            continue;
        }
        cin.ignore();

        if (pilih == 1) {
            string tujuan, status;
            cout << ">> Tujuan : "; getline(cin, tujuan);
            cout << ">> Status : "; getline(cin, status);
            if (tujuan.empty() || status.empty()) {
                cout << ">> Input tujuan/status tidak boleh kosong!\n";
                continue;
            }
            addLast(tujuan, status);
        }
        else if (pilih == 2) {
            string tujuan, status;
            cout << ">> Tujuan : "; getline(cin, tujuan);
            cout << ">> Status : "; getline(cin, status);
            if (tujuan.empty() || status.empty()) {
                cout << ">> Input tujuan/status tidak boleh kosong!\n";
                continue;
            }
            addMiddle(tujuan, status, posisiSisip);
        }
        else if (pilih == 3) {
            int sub;
            cout << "\n+------ MENU DELETE ------+\n";
            cout << "1. Hapus Paling Awal\n";
            cout << "2. Hapus Paling Akhir\n";
            cout << "3. Hapus Posisi Tertentu\n";
            cout << ">> Pilih: ";
            if (!(cin >> sub)) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << ">> Input tidak valid!\n"; continue;
            }
            cin.ignore();
            if (sub == 1) deleteFirst();
            else if (sub == 2) deleteLast();
            else if (sub == 3) {
                int pos; cout << ">> Masukkan posisi: ";
                if (!(cin >> pos)) {
                    cin.clear(); cin.ignore(1000, '\n');
                    cout << ">> Posisi tidak valid!\n"; continue;
                }
                cin.ignore();
                deleteMiddle(pos);
            }
            else {
                cout << ">> Pilihan delete tidak valid!\n";
            }
        }
        else if (pilih == 4) {
            string kode;
            cout << ">> Masukkan kode penerbangan: "; getline(cin, kode);
            if (kode.empty()) {
                cout << ">> Kode tidak boleh kosong!\n"; continue;
            }
            editData(kode);
        }
        else if (pilih == 5) {
            display();
        }
        else if (pilih == 6) {
            displayReverse();
        }
        else if (pilih == 7) {
            string key;
            cout << ">> Masukkan Kode/Tujuan: "; getline(cin, key);
            if (key.empty()) {
                cout << ">> Input tidak boleh kosong!\n"; continue;
            }
            searchData(key);
        }
        else if (pilih == 0) {
            cout << ">> Keluar dari program...\n";
        }
        else {
            cout << ">> Pilihan tidak valid!\n";
        }
    } while (pilih != 0);

    return 0;
}