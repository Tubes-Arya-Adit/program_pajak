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

struct Transaksi
{
    char id;
    double denda;
    double biaya_admin;
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

#include "src/validasi.h"
#include "src/data.h"
#include "src/opening.h"
#include "src/login.h"
#include "src/register.h"
#include "src/opsi_pajak.h"
#include "src/pph.h"
#include "src/pbb.h"
#include "src/output.h"

int main()
{
    opening();
    sinkronDataPengguna();

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

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

    opsi_pajak();

    switch (menu_opsi_pajak)
    {
    case 1:
        system("cls");
        pph_menu();
        break;
    case 2:
        system("cls");
        pph_menu();
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

    system("PAUSE");
    return 0;
}