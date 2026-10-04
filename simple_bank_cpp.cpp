#include <iostream>
using namespace std;

int main()
{
    //DATA AWAL
    const string truepin = "1234"; //PIN ATM
    const int saldo_minimal = 50000; //minimal saldo di rekening
    const int maks_tarik_tunai = 1000000; //maksimal uang dalam sekali tarik tunai
    const int maks_setor_tunai = 5000000; //maksimal uang dalam sekali setor tunai
    const int biaya_admin = 6500; //biaya admin tiap transaksi
    const int kelipatan_tariksetor = 50000; //nominal kelipatan tarik dan setor tunai
    int saldo_heni = 1000000; //saldo awal di rekening heni

    //fitur login
    string pin;
    int percobaan = 3;
    bool PinBenar = false;
    
    //utk looping login (3x kesempatan)
    for (int i = 3;i > 0;i--){
        cout << "\nMasukkan PIN: ";
        cin >> pin;
        percobaan -= 1;
        if (pin == truepin){
            cout << "\n\nLogin Berhasil !";
            cout << "\nSelamat datang di ATM UPN BANK.\n";
            PinBenar = true;
            break;
        }else{
            cout << "\nPIN Salah !";
            cout << "\nSisa Percobaan: "; cout << percobaan;
        }
    }

    //cek kondisi setelah keluar dari looping login
    if (!PinBenar){
        cout << "\n\n=================================";
        cout << "\nKartu diblokir.";
        cout << "\nSilakan hubungi bank.";
        cout << "\n=================================";
        return 0;
    }

    //variabel di menu utama
    int pilihan;
    //variabel di case 1
    string pilihancase1; 
    //variabel di case 2
    int nominaltarik;
    //variabel di case 3
    int nominalsetor;
    //variabel di case 4
    int nominaltransfer;
    //variabel di case 5
    long long target_tabungan, target_bulan, setoran, kekurangan_tabungan;
    long long tabungan_sementara = 0;
    int hitungan_bulan = 0;

    //FITUR MENU UTAMA
    do {
        cout << "=================================\n";
        cout << "           ATM UPN BAIK          \n";
        cout << "=================================\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Tarik Tunai\n";
        cout << "3. Setor Tunai\n";
        cout << "4. Transfer\n";
        cout << "5. Simulasi Tabungan\n";
        cout << "6. Keluar\n";
        cout << "=================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan){

            //FITUR CEK SALDO
            case 1:
            cout << "\n===== CEK SALDO =====";
            cout << "\nSaldo Anda: Rp" << saldo_heni;
            cout << "\n\nBalik lagi ke menu? (y/n):";
            cin >> pilihancase1;

            if (pilihancase1 == "y"){
                cout << "\nMenu tampil lagi.\n";
                break; //break case 1, lalu kembali ke menu utama
            } else {
                cout << "\n\n================================= ";
                cout << "\nTerima kasih telah menggunakan ";
                cout << "\nATM UPN BANK.";
                cout << "\n=================================";
                return 0; //program selesai
            }

            //FITUR TARIK TUNAI
            case 2:
            cout << "\n===== TARIK TUNAI =====";
            cout << "\nMasukkan nominal: Rp";
            cin >> nominaltarik;

            if (nominaltarik < 0){ //cek, apakah nominal kurang dari 0
                cout << "\nNominal tidak valid.";
                break;
            } else {
                if (nominaltarik > maks_tarik_tunai){ //cek, apakah nominal lebih dari kapasitas maksimal tarik tunai (Rp1.000.000)
                    cout << "\nMaksimal penarikan adalah Rp1000000.\n";
                    break;
                } else {
                    if (nominaltarik % kelipatan_tariksetor != 0){ //cek, apakah nominal merupakan kelipatan tarik tunai (Rp50.000)
                        cout << "\nNominal harus kelipatan Rp50000.\n";
                        break;
                    } else {
                        if (nominaltarik > saldo_heni){ //cek, apakah nominal lebih dari saldo di rekening heni
                            cout << "\\nSaldo tidak mencukupi.\n";
                            break;
                        } else {
                            if ((saldo_heni - nominaltarik) < saldo_minimal){ //cek, apakah saldo tersisa kurang dari saldo minimal (Rp50.000)
                                cout << "\nTransaksi ditolak.";
                                cout << "\nSaldo minimal setelah penarikan adalah Rp50000.\n";
                                break;
                            } else { //lolos semua pengecekan, jalankan program tarik tunai
                                saldo_heni = saldo_heni - nominaltarik;
                                cout << "\nPenarikan berhasil.";
                                cout << "\nNominal: Rp" << nominaltarik;
                                cout << "\nSaldo sekarang: Rp" << saldo_heni;
                                break;                             
                            }
                        }
                    }
                }
            }

            //FITUR SETOR TUNAI
            case 3:
            cout << "\n===== SETOR TUNAI =====";
            cout << "\nMasukkan nominal: Rp";
            cin >> nominalsetor;

            if (nominalsetor < 0){ // cek, apakah nominal kurang dari 0
                cout << "\nNominal tidak valid.";
                break;
            } else {
                if (nominalsetor > maks_setor_tunai){ // cek, apakah nominal setor melebihi kapasitas maksimal setor (Rp5.000.000)
                    cout << "\nMaksimal setoran adalah Rp5000000.";
                    break;
                } else {
                    if (nominalsetor % kelipatan_tariksetor != 0){ // cek, apakah nominal setor tunai merupakan kelipatan Rp50.000
                        cout << "\nNominal harus kelipatan Rp50000.";
                        break;
                    } else { // lolos semua pengecekan, jalankan fitur setor tunai
                        saldo_heni = saldo_heni + nominalsetor;
                        cout << "\nSetoran berhasil.";
                        cout << "\nSaldo sekarang: Rp" << saldo_heni;
                        break;
                    }
                }
            }

            //FITUR TRANSFER
            case 4:
            cout << "\n===== TRANSFER =====";
            cout << "\nBiaya admin: Rp6500";
            cout << "\nMasukkan nominal transfer: Rp";
            cin >> nominaltransfer;

            if (nominaltransfer < 0){ // cek, apakah nominal transfer kurang dari 0
                cout << "\nNominal tidak valid.";
                break;
            } else {
                if (nominaltransfer > saldo_heni){ // cek, apakah nominal transfer melebihi saldo rekening heni
                    cout << "\nSaldo tidak mencukupi.";
                    break;
                } else {
                    if ((saldo_heni - nominaltransfer - biaya_admin) < saldo_minimal){ // cek, apakah saldo di rekening setelah transfer kurang dari saldo minimal (Rp50.000)
                        cout << "\nTransfer ditolak.";
                        cout << "\nSaldo minimal setelah transfer adalah Rp50000";
                    } else { // lolos semua pengecekan. menjalankan program transfer
                        saldo_heni = saldo_heni - nominaltarik - biaya_admin;
                        cout << "\n\nTransfer berhasil.";
                        cout << "\nNominal transfer: Rp" << nominaltransfer;
                        cout << "\nBiaya admin: Rp6500";
                        cout << "\nSaldo sekarang: Rp" << saldo_heni;
                        break;
                    }
                }
            }

            //FITUR SIMULASI TABUNGAN
            case 5:
            cout << "\n\n===== SIMULASI TABUNGAN =====";
            cout << "\nTarget tabungan: Rp";
            cin >> target_tabungan;
            cout << "\nSetoran per bulan: Rp";
            cin >> setoran;
            cout << "\nJumlah bulan:";
            cin >> target_bulan;

            if (target_tabungan < 0 || target_bulan < 0 || setoran < 0){ // cek, apakah input user bernilai kurang dari 0
                cout << "Input tidak valid.";
                break;
            } else {
                for (int i = 0; i <= target_bulan; i ++){ // melakukan looping sesuai dengan jumlah target bulan
                    tabungan_sementara = tabungan_sementara + setoran;
                    hitungan_bulan++;
                    cout << "bulan " << hitungan_bulan << " : Rp" << tabungan_sementara;

                    if (tabungan_sementara > target_tabungan){ // first check, apakah target tabungan terpenuhi sebelum sampai di target bulan
                        cout << "\nTarget tercapai pada bulan ke-" << hitungan_bulan;                        
                        break;
                    }

                    if (tabungan_sementara < target_tabungan){ // second check, apakah target tabungan belum terpenuhi setelah sampai di target bulan
                        kekurangan_tabungan = target_tabungan - tabungan_sementara;
                        cout << "\nTarget belum tercapai.";
                        cout << "\nKekurangan: Rp" << kekurangan_tabungan;
                        break;                     
                    } else { // eksekusi yg terjadi bila target tabungan tepat tercapai sesuai target bulan
                        cout << "\nTarget tercapai pada bulan ke-" << hitungan_bulan;                        
                        break;
                    }
                }
            }

            default:
            cout << "\n\nPilihan tidak tersedia.";
            break;
        }
    } while (pilihan != 6); //KELUAR DARI PROGRAM
    cout << "\n\n=================================";
    cout << "\nTerima kasih telah menggunakan";
    cout << "\nATM UPN BANK";
    cout << "\n=================================";

    return 0; //PROGRAM SELESAI
}