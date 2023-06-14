#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Buku {
public:
	string judul_buku;

	Buku(string judul) {
		judul_buku = judul;
	}
};

class Pengarang {
public:
	string nama_pengarang;
	vector<Buku*> buku;

	Pengarang(string pNama) {
		nama_pengarang = pNama;
	}

	void tambah_buku(string judul);
};

class Penerbit {
public:
	string nama_penerbit;
	vector<Pengarang*> pengarang;

	Penerbit(string pNama) {
		nama_penerbit = pNama;
	}

	void tambah_pengarang(Pengarang* pengarang) {
		this->pengarang.push_back(pengarang);
	}

	void daftar_pengarang() {
		cout << "Daftar pengarang pada penerbit\"" << this->nama_penerbit << "\":" << endl;
		for (Pengarang* pengarang : this->pengarang) {
			cout << pengarang->nama_pengarang << "\n";
		}
	}
};

int main() {
    Penerbit gamaPress("Gama Press");
    Penerbit intanPariwara("Intan Pariwara");

    Pengarang joko("Joko");
    joko.tambah_buku("Fisika");
    joko.tambah_buku("Algoritma");

    Pengarang lia("Lia");
    lia.tambah_buku("Basisdata");

    Pengarang asroni("Asroni");
    asroni.tambah_buku("Dasar Pemrograman");

    Pengarang giga("Giga");
    giga.tambah_buku("Matematika");
    giga.tambah_buku("Multimedia");

    gamaPress.tambah_pengarang(&joko);
    gamaPress.tambah_pengarang(&lia);
    gamaPress.tambah_pengarang(&giga);

    intanPariwara.tambah_pengarang(&asroni);
    intanPariwara.tambah_pengarang(&giga);

    gamaPress.daftar_pengarang();
    intanPariwara.daftar_pengarang();

    cout << "Daftar penerbit yang diikuti \"Giga\":" << endl;
    for (Pengarang* pengarang : giga.penerbit) {
        cout << pengarang->nama_pengarang << endl;
    }

    cout << "Daftar buku yang dikarang \"Joko\":" << endl;
    for (Buku buku : joko.buku) {
        cout << buku.judul_buku << endl;
    }

    cout << "Daftar buku yang dikarang \"Lia\":" << endl;
    for (Buku buku : lia.buku) {
        cout << buku.judul_buku << endl;
    }

    cout << "Daftar buku yang dikarang \"Asroni\":" << endl;
    for (Buku buku : asroni.buku) {
        cout << buku.judul_buku << endl;
    }

    cout << "Daftar buku yang dikarang \"Giga\":" << endl;
    for (Buku buku : giga.buku) {
        cout << buku.judul_buku << endl;
    }

    return 0;
}
