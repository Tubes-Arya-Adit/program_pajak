#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

struct Pengguna
{
    char nama[100];
    char alamat[100];
    char no_telp[13];
    char username[100];
    char password[100];
    char npwp[17];
    char nik[17];
};

struct Tanggal
{
    int tanggal;
    int bulan;
    int tahun;
    int hari;
    int jam;
    int menit;
    int detik;
};

struct Transaksi
{
    char id;
    double denda;
    double jumlah_tagihan;
    double jumlah_tunai;
    char tanggal_pembayaran[11];
    char masa_pajak[25];
    char status_bayar[20];
};

int menu_awal, menu_opsi_pajak, i_pga;

struct Pengguna pengguna[50];
struct Pengguna input;
struct Pengguna pengguna_login;
struct Tanggal waktu_sekarang;

#include "src/validasi.h"
#include "src/data.h"
#include "src/opening.h"
#include "src/login.h"
#include "src/register.h"
#include "src/opsi_pajak.h"
#include "src/pph.h"
#include "src/ppn.h"
#include "src/pbb.h"
#include "src/output.h"

int main()
{
    opening();
    sinkronDataPengguna();

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    waktu_sekarang.hari = tm.tm_mday;
    waktu_sekarang.bulan = tm.tm_mon + 1;
    waktu_sekarang.tahun = tm.tm_year + 1900;
    waktu_sekarang.jam = tm.tm_hour;
    waktu_sekarang.menit = tm.tm_min;
    waktu_sekarang.detik = tm.tm_sec;

    if (menu_awal == 1)
    {
        system("cls");
        login_menu();
    }
    else if (menu_awal == 2)
    {
        system("cls");
        register_menu();
    }
    else
    {
        printf("\n\tPilihan Anda Salah!");
        printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
        printf("\n\tPilihan Anda : ");
        menu_awal = input_int(menu_awal);
        system("cls");
    }

    while (menu_opsi_pajak != 8)
    {
        system("cls");
        opsi_pajak();
        switch (menu_opsi_pajak)
        {
        case 1:
            system("cls");
            pph_menu();
            break;
        case 2:
            system("cls");
            ppn_menu();
            break;
        case 3:
            system("cls");
            pbb_menu();
            break;
        case 4:
            system("cls");
            pph_menu();
            break;
        case 5:
            system("cls");
            pph_menu();
            break;
        case 6:
            system("cls");
            pph_menu();
            break;
        case 7:
            system("cls");
            pph_menu();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("\n\tNilai yang Anda masukkan salah!");
            printf("\n\tSilahkan masukkan nilai yang benar!");
            printf("\n\tPilihan Anda : ");
            menu_opsi_pajak = input_int(menu_opsi_pajak);
            system("cls");
            break;
        }
    }

    system("PAUSE");
    return 0;
}