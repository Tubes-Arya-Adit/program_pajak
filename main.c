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

#include "validasi.h"
#include "data.h"
#include "opening.h"
#include "register.h"

int main()
{
    opening(&menu_awal);

    if (menu_awal == 1)
    {
        system("cls");
    }
    else if (menu_awal == 2)
    {
        system("cls");
        register_menu(input);
    }
    else
    {
        printf("\n\tPilihan Anda Salah!");
        printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
    }

    system("PAUSE");
    return 0;
}