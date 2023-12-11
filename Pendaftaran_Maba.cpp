#include <iostream>
#include <conio.h>
#include <stdio.h> 
#include <string.h>
#define MAX 10 // maksimal nomor antrian 

using namespace std;

//struct dan array
struct queue {
	int data [10];
	int awal, akhir;
}antrian;
//fungsi untuk mengkosongkan antrian
void init(){
	antrian.awal=-1;
	antrian.akhir=-1;
}
//fungsi untuk pengecekan antrian yang sudah di buat queue
bool full(){
	if(antrian.akhir == MAX -1){
		return true;
	}else{
		return false;
	}
}
bool empty(){
	if(antrian.akhir == -1){
		return true;
	}else{
		return false;
	}
}
//queue memasukkan data antrian yg didalamnya ada pointer
void inQueue(){
	   string  nama,ttl, asek, alamat, agama, jurusan,hp,prestasi;
	int nilai,maba, *mabax;
	mabax = &maba;
	cout<<"\nBanyak Mahasiswa Yang Mendaftar : ";
	cin>>maba;
			 for (int a = 0; a < maba; a++) {
		cin.ignore();
        cout << "Nama Mahasiswa Baru    : ";
        getline(cin, nama);
        cout << "Tempat, Tanggal Lahir  : ";
        getline(cin, ttl);
        cout << "Asal Sekolah           : ";
        getline(cin, asek);
        cout << "Alamat                 : ";
        getline(cin, alamat);
        cout << "No.Hp                  : ";
        getline(cin, hp);
        cout << "Agama                  : ";
        getline(cin, agama);
        cout<<"Masukkan Nilai Akhir   : ";
        cin>>nilai;
        cin.ignore();
        cout<<"Prestasi	       : ";
        getline(cin, prestasi);
        cout << "Pilih Jurusan          : ";
         getline(cin, jurusan);
        cout<<endl;
    }
	if (empty()){
		antrian.awal =0;
		antrian.akhir =0;
		antrian.data[antrian.awal]=*mabax;
	}else {
		if(!full()){
			antrian.akhir++;
			cout<<"\nData berhasil ditambahkan";
			antrian.data[antrian.akhir]=*mabax;
		}else{
			cout<<"\nAntrian penuh";
		}
	}getchar();
}


void tampildata(){
	int i;
	for (i=antrian.awal; i<=antrian.akhir; i++){
		cout<<"Jumlah Data : "<<antrian.data[i];
	}cout<<"\n";
}


void infojurusan(){
	string jurusan[3]={"FIK","FES","FST"};
	string prodi[3]={"Sistem Informasi, Ilmu Komputer, Teknik Informatika", "Ilmu komunikasi, Akuntansi, Ilmu Ekonomi","Arsitektur, Perencanaan Wilayah dan Kota, Geografi"};
	string temp;
	
	//buble sort
		for (int k=1;k<3;k++){
		for (int j=3-1;j>=k;j--){
			if(jurusan[j]<jurusan[j-1]){
				temp=jurusan[j];
				jurusan[j]=jurusan[j-1];
				jurusan[j-1]=temp;
			}
		}
	}
	//insertion sort
	for(int i=0;i<3;i++){
		string key = prodi[i];
		int j = i-1;
		while(j>=0 && prodi[j]>key){
			prodi[j+1]=prodi[j];
			j--;
		}prodi[j+1]=key;
	}
	
	
	string dtCari, jurusan_ketemu;
	bool ketemu= false;
	
	cout<<"Fakultas yang dicari : ";
	cin>>dtCari;
	//searching sentinel
	for(int i=0;i<3;i++){
		if(jurusan[i]==dtCari){
			ketemu=true;
			jurusan_ketemu = jurusan[i];
		}
	}if (ketemu= true){ //searching
		cout<<"\nFakultas ditemukan"<<endl;
		cout<<"\nHasil pencarian Fakultas "<<jurusan_ketemu<<" berisi Prodi :";
		if (jurusan_ketemu == "FIK")
		cout<<prodi[2];
		if (jurusan_ketemu == "FES")
		cout<<prodi[1];
		if (jurusan_ketemu == "FST")
		cout<<prodi[0];
	}
	else {
		cout<<"Fakultas tidak ditemukan !";
	}
}

void clear(){
	antrian.awal=-1;
	antrian.akhir=-1;
}
int main(){
	
	int pilihan, elemen;
	
	cout<<"\n=====================================";
	cout<<"\n|    	   SELAMAT DATANG DI         |";
	cout<<"\n|    UNIVERSITAS AMIKOM YOGYAKARTA   |";
	cout<<"\n=====================================";
	cout<<"\n|          Fakultas :	             |";
	cout<<"\n| 1. FIK			     |";
	cout<<"\n| 2. FES 			     |";
	cout<<"\n| 3. FST			     |";
	cout<<"\n=====================================";
	cout<<endl;
	init();
	
	do{
	cout<<endl;
	cout<<"\n-----------------------------------";
	cout<<"\n      Pilih salah satu";
	cout<<"\n-----------------------------------";
	cout<<"\n    1. Pendaftaran Mahasiswa Baru";
	cout<<"\n    2. Informasi Jurusan";
	cout<<"\n    3. Jumlah Data";
	cout<<"\n    4. menghapus data";
	cout<<"\n    0. keluar";
	cout<<"\n==================================";
	cout<<"\nMasukan pilihan anda = ";
	cin>>pilihan;
	
	switch (pilihan){
		case 1: inQueue();
		break;
		case 2: infojurusan();
		break;
		case 3: tampildata();
		break;
		case 4: clear();
		break;
	
	
		
		}
	}
	while(pilihan!=0);
	return 0;
	
}

