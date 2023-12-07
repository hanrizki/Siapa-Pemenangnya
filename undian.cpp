#include <iostream>
#include <stdlib.h> //library srand, rand
#include <time.h> // library time(0)
using namespace std;

// program mengundi pemenang jalan sehat 
// dengan menginput jumlah peserta jalan sehat dan nomor peserta 
// kemudian menginput nomornya sesuai rentang jumlah peserta
// hasil pemenang ditampilkan berupa no peserta jalan sehat 
// menggunakan srand(time(0)) dan rand() supaya menghasikan nomor undian secara acak
// Pengguna jg dapat mencari apakah nomor peserta yg dicari termasuk dalam daftar pemenang undian atau tidak


    // Fungsi untuk mengundian nomor pemenang
void undiPemenang(int data[], int jumlahpeserta) { 
       srand(time(0));
       int pertama = 1; 
	   int undi, nomor;
       for (int i = 0; i < jumlahpeserta; i++) { 
            do {
            	 undi = rand() % jumlahpeserta + 1;
             	 if (pertama == 1) { 
    	         	 data[i] = undi; 
     	         	 pertama = 0; 
     	         	 } 
             	 else { 
     	         	 for (int j = 0; j < i; j++) {
             	 	   nomor = data[j];
            	 	   if (undi == nomor) break; 
           	 	       else data[i] = undi;
    		 	         }
    		 	    }
    	       }
    	    while (undi == nomor);
        }
 } 

 // Fungsi untuk menampilkan pemenang
void tampilkanPemenang(int data[], int n) { 
    	cout << "\nDaftar Pemenang Undian: \n"; 
    	for (int i = 0; i < 3; i++) { 
    		cout << "Pemenang UNDIAN ke-" << i + 1 << " : " << data[i] << endl;
    		}
    	cout << "Selamat Kepada Para Pemenang!" << endl; 
    }


int main()
{
    cout << "-------------------------------------------------------" << endl;
    cout << "|          SELAMAT DATANG DI PROJEK UAP DDP           |" << endl;
    cout << "|     Progam Mencari Pemenang Undian by Kelompok 1    |" << endl; 
    cout << "-------------------------------------------------------"<< endl;
    
    int undi, jumlahpeserta, nomor, cari; 
    int pertama = 1;
    bool ketemu = false;
    srand(time(0));
    int temp = 0;

    cout << "Masukkan Jumlah Peserta Undian: ";
    cin >> jumlahpeserta;
    
    //input nomor peserta
    cout << "Masukkan data nomor peserta secara acak  " << ": ";
    int data[jumlahpeserta];
    for (int i= 0; i < jumlahpeserta; i++){
        cin >> data[i];
    } 

    for (int i= 0; i < jumlahpeserta; i++){
        for (int j=0; j<jumlahpeserta-i-1; j++){
            if (data[j] > data[j+1]){
                temp = data[j];
                data[j]= data[j+1];
                data[j+1]=temp;  }
        }

    }    
    cout << "Data Nomor Peserta Sudah Diurutkan : ";
    for(int i = 0; i<jumlahpeserta; i++){
        cout << data[i]<<" ";
    }
    cout << endl;

    // Memanggil fungsi undipemenang 
     undiPemenang(data, jumlahpeserta);
    cout << endl;
   	/// Menampilkan Daftar para pemenang undian
     tampilkanPemenang(data, jumlahpeserta); 
    
    cout << endl;
    // Mencari nomor peserta 
    cout << "Masukkan Nomor Peserta yang dicari : " ;
    cin >> cari ;
    for (int i= 0; i<data[i]; i++){
        if (data[i]== cari){
            ketemu = true;
            cout << "Peserta adalah pemenang ke-" << i+1;
            break;
        }
    }
    if (!ketemu)
        cout << "Maaf Anda belum beruntung :( ";
    
    
}


/*Nama Anggota:
 Putri Alena Sari 2307051024
 Muhammad Farhan Rizki 2307051005
 Anggun Safitri 2307051004
 Nugraha Aditya Wardana 2307051012 
 */