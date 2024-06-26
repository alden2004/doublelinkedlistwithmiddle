#include <iostream>
using namespace std;

struct DataFilm {
  string judul;
  int durasi;
  int harga;
  DataFilm *prev;
  DataFilm *next;
};

DataFilm *kepala = nullptr, *ekor = nullptr, *cur = nullptr, *newNode = nullptr, *del = nullptr, *afterNode = nullptr;

// membuat Double Linked List
void buatDoubleLinkedList(string judul, int durasi, int harga) {
  kepala = new DataFilm();
  kepala->judul = judul;
  kepala->durasi = durasi;
  kepala->harga = harga;
  kepala->prev = nullptr;
  kepala->next = nullptr;
  ekor = kepala;
}

// hitung Double Linked List
int hitungDoubleLinkedList() {
  if (kepala == nullptr) {
    return 0;
  } else {
    cur = kepala;
    int jumlah = 0;
    while (cur != nullptr) {
      jumlah++;
      cur = cur->next;
    }
    return jumlah;
  }
}

// Add awal
void tambahawal(string judul, int durasi, int harga) {
  if (kepala == nullptr) {
    cout << "Double Linked List belum dibuat!";
  } else {
    newNode = new DataFilm();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->prev = nullptr;
    newNode->next = kepala;
    kepala->prev = newNode;
    kepala = newNode;
  }
}

// Add akhir
void tambahakhir(string judul, int durasi, int harga) {
  if (kepala == nullptr) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    newNode = new DataFilm();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->prev = ekor;
    newNode->next = nullptr;
    ekor->next = newNode;
    ekor = newNode;
  }
}

// Add Middle
void tambahtengah(string judul, int durasi, int harga, int posisi) {
  if (kepala == nullptr) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    int jumlah = hitungDoubleLinkedList();
    if (posisi <= 1 || posisi > jumlah) {
      cout << "Posisi diluar jangkauan!!!" << endl;
    } else {
      newNode = new DataFilm();
      newNode->judul = judul;
      newNode->durasi = durasi;
      newNode->harga = harga;

      cur = kepala;
      int nomor = 1;
      while (nomor < posisi - 1) {
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      if (afterNode != nullptr) {
        afterNode->prev = newNode;
      }
    }
  }
}

// hapus awal
void hapusawal() {
  if (kepala == nullptr) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else if (kepala->next == nullptr) {
    delete kepala;
    kepala = ekor = nullptr;
  } else {
    del = kepala;
    kepala = kepala->next;
    kepala->prev = nullptr;
    delete del;
  }
}

// hapus akhir
void hapusakhir() {
  if (kepala == nullptr) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else if (ekor->prev == nullptr) {
    delete ekor;
    kepala = ekor = nullptr;
  } else {
    del = ekor;
    ekor = ekor->prev;
    ekor->next = nullptr;
    delete del;
  }
}

// hapus Middle
void hapusMiddle(int posisi) {
  if (kepala == nullptr) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    int jumlah = hitungDoubleLinkedList();
    if (posisi <= 1 || posisi >= jumlah) {
      cout << "Posisi bukan posisi tengah atau diluar jangkauan!!" << endl;
    } else {
      cur = kepala;
      int nomor = 1;
      while (nomor < posisi - 1) {
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      if (afterNode != nullptr) {
        afterNode->prev = cur;
      }
      delete del;
    }
  }
}

// mencetak
void cetakDoubleLinkedList() {
  if (kepala == nullptr) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = kepala;
    while (cur != nullptr) {
      // cetak
      cout << "Judul Film : " << cur->judul << endl;
      cout << "Durasi Film : " << cur->durasi << " menit" << endl;
      cout << "Harga Tiket : " << cur->harga << " IDR\n" << endl;
      // step
      cur = cur->next;
    }
  }
}

int main() {
  buatDoubleLinkedList("Avengers: Endgame", 181, 50000);
  cetakDoubleLinkedList();

  tambahawal("Titanic", 195, 40000);
  cetakDoubleLinkedList();

  tambahakhir("Inception", 148, 45000);
  cetakDoubleLinkedList();

  tambahtengah("The Matrix", 136, 35000, 3);
  cetakDoubleLinkedList();

  hapusMiddle(2);
  cetakDoubleLinkedList();

  hapusawal();
  cetakDoubleLinkedList();

  hapusakhir();
  cetakDoubleLinkedList();
}
