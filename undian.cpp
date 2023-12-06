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

    cout << "Masukkan Jumlah Peserta Undian: ";
    cin >> jumlahpeserta;
    
    //input nomor peserta
    int data[jumlahpeserta];
    for (int i= 1; i <= jumlahpeserta; i++){
        cout << "Masukkan data nomor peserta " << i << ": ";
        cin >> data[i];
    } 

    //Proses menghasilkan Nomor Pemenang secara acak
    for (int i= 0; i<jumlahpeserta; i++){
        do
        {
            undi=rand()%jumlahpeserta+1;            
            if(pertama==1){
                data[i]=undi;
                pertama=0;
            }
            else
            {
                for(int j=0; j<i; j++){
                    nomor=data[j];
                    if (undi==nomor)
                        break;
                    else 
                        data[i]=undi;
                }
                
            }
        } while (undi==nomor);

    }

    //Menampilkan Nomor Pemenang
    cout << "\n Daftar Pemenang Undian \n" ;
    for (int i= 0; i<3; i++){
        cout << "Pemenang UNDIAN ke-"<< i+1 << " : " << data[i] << endl;
    }
    cout << "Selamat Kepada Para Pemenang!" << endl;
    cout << endl;

    //mencari nomor peserta 
    cout << "Masukkan Nomor Peserta yang dicari : ";
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
 Muhammad Farhan Rizki npm isi sendiri
 Nugraha Aditya Wardana npm isi sendiri
 Anggun Safitri npm isi sendiri 
 */