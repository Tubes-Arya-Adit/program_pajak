#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

struct Pajak
{
    char nama_pajak[100];
    int jenis_pajak;
    char jatuh_tempo[13];
};

struct Transaksi
{
    int id_transaksi;
    double denda;
    double biaya_admin;
    double jumlah_tagihan;
    double jumlah_tunai;
    char terbilang[100];
    char tanggal_pembayaran[11];
    char masa_pajak[25];
    char status_bayar[20];
};

int menu_awal, i_pga;

struct Pengguna pengguna[50];
struct Pengguna input;
struct Pengguna pengguna_login;

#include "src/validasi.h"
#include "src/data.h"
#include "src/opening.h"
#include "src/login.h"
#include "src/register.h"
#include "src/opsi_pajak.h"

int main()
{
    opening();
    sinkronDataPengguna();

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
    }

    opsi_pajak();

    system("PAUSE");
    return 0;
}