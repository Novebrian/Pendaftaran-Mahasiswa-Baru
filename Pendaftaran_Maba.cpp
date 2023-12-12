#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_SIZE = 10;

struct Mahasiswa {
    string nama;
    string ttl;
    string asek;
    string alamat;
    string agama;
    string jurusan;
    string hp;
    string prestasi;
};

struct Antrian {
    Mahasiswa data[MAX_SIZE];
    int awal, akhir, maba;
};

Antrian mhs;

// Fungsi untuk menginisialisasi antrian
void init() {
    mhs.awal = -1;
    mhs.akhir = -1;
}

// Fungsi untuk memeriksa apakah antrian penuh
bool full() {
    return (mhs.akhir == MAX_SIZE - 1);
}

// Fungsi untuk memeriksa apakah antrian kosong
bool empty() {
    return (mhs.akhir == -1);
}

// Fungsi untuk menampilkan data mahasiswa yang terdaftar
void displayData() {
    if (empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "\nData Mahasiswa:\n";
        for (int i = mhs.awal; i <= mhs.akhir; ++i) {
            cout << "Mahasiswa ke-" << i + 1 << endl;
            cout << "Nama: " << mhs.data[i].nama << endl;
            cout << "Tempat, Tanggal Lahir: " << mhs.data[i].ttl << endl;
            cout << "Asal Sekolah: " << mhs.data[i].asek << endl;
            cout << "Alamat: " << mhs.data[i].alamat << endl;
            cout << "No. Hp: " << mhs.data[i].hp << endl;
            cout << "Agama: " << mhs.data[i].agama << endl;
            cout << "Jurusan: " << mhs.data[i].jurusan << endl;
            cout << "Nilai Prestasi: " << mhs.data[i].prestasi << endl << endl;
        }
    }
}

// Fungsi untuk mendaftarkan mahasiswa baru
void inQueue() {
    if (!full()) {
        cout << "Banyak Mahasiswa yang mendaftar : ";
        cin >> mhs.maba;
        cout << endl;

        for (int a = 0; a < mhs.maba; a++) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nama Mahasiswa Baru  : ";
            getline(cin, mhs.data[mhs.akhir + 1].nama);
            cout << "Tempat, Tanggal Lahir: ";
            getline(cin, mhs.data[mhs.akhir + 1].ttl);
            cout << "Asal Sekolah         : ";
            getline(cin, mhs.data[mhs.akhir + 1].asek);
            cout << "Alamat               : ";
            getline(cin, mhs.data[mhs.akhir + 1].alamat);
            cout << "No. Hp               : ";
            getline(cin, mhs.data[mhs.akhir + 1].hp);
            cout << "Agama                : ";
            getline(cin, mhs.data[mhs.akhir + 1].agama);
            cout << "Pilih Jurusan        : ";
            getline(cin, mhs.data[mhs.akhir + 1].jurusan);
            cout << "Masukkan Nilai Akhir : ";
            getline(cin, mhs.data[mhs.akhir + 1].prestasi);

            mhs.akhir++;
        }
        cout << "\nData berhasil ditambahkan";
    } else {
        cout << "\nAntrian penuh";
    }
}

// Fungsi untuk menampilkan seluruh data mahasiswa yang telah didaftarkan
void displayAllData() {
    if (empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "\nData Mahasiswa yang Telah Didftar:\n";
        for (int i = 0; i <= mhs.akhir; ++i) {
            cout << "Mahasiswa ke-" << i + 1 << endl;
            cout << "Nama: " << mhs.data[i].nama << endl;
            cout << "Tempat, Tanggal Lahir: " << mhs.data[i].ttl << endl;
            cout << "Asal Sekolah: " << mhs.data[i].asek << endl;
            cout << "Alamat: " << mhs.data[i].alamat << endl;
            cout << "No. Hp: " << mhs.data[i].hp << endl;
            cout << "Agama: " << mhs.data[i].agama << endl;
            cout << "Jurusan: " << mhs.data[i].jurusan << endl;
            cout << "Nilai Prestasi: " << mhs.data[i].prestasi << endl << endl;
        }
    }
}

// Fungsi untuk menampilkan jumlah data mahasiswa
void tampildata() {
    cout << "Jumlah Data: " << mhs.akhir-mhs.awal << endl;
}

// Fungsi untuk menghapus data mahasiswa
void clear() {
    mhs.awal = -1;
    mhs.akhir = -1;
}

void dequeue() {
    if (empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Data Mahasiswa ke-1 telah dihapus" << endl;

        // Geser seluruh elemen antrian ke depan
        for (int i = 0; i < mhs.akhir; ++i) {
            mhs.data[i] = mhs.data[i + 1];
        }

        mhs.akhir--; // Kurangi jumlah elemen di antrian
    }
}

// Fungsi utama
int main() {
    int pilihan;

    cout << "SELAMAT DATANG DI UNIVERSITAS AMIKOM YOGYAKARTA" << endl;
    cout << "Fakultas : " << endl;
    cout << "1. FIK" << endl;
    cout << "2. FES" << endl;
    cout << "3. FST" << endl;

    init();

    do {
        cout << "\nPilih salah satu" << endl;
        cout << "1. Pendaftaran Mahasiswa Baru" << endl;
        cout << "2. Informasi Jurusan" << endl;
        cout << "3. Jumlah Data" << endl;
        cout << "4. Tampilkan Semua Data" << endl;
        cout << "5. Menghapus Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inQueue();
                break;
            case 2:
                // infojurusan();
                break;
            case 3:
                tampildata();
                break;
        	case 4:
        		displayAllData();
        		break;
            case 5:
                dequeue();
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
