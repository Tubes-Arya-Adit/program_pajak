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
    int bulan;
    int tahun;
    int hari;
    int jam;
    int menit;
    int detik;
};

struct Transaksi
{
    char id[17];
    char jenis_pajak[50];
    double total_pajak;
    double denda;
    double jumlah_nominal;
    char tanggal[20];
    char status[20];
};

int menu_awal, menu_opsi_pajak, i_pga, i_trs, i_trs_filtered;
time_t current;

struct Pengguna pengguna[50];
struct Pengguna input;
struct Pengguna pengguna_login;

struct Tanggal waktu_sekarang;

struct Transaksi trs_pengguna[50];
struct Transaksi trs_input;
struct Transaksi trs_filtered[50];

#include "src/validasi.h"
#include "src/data.h"
#include "src/open-close.h"
#include "src/login.h"
#include "src/register.h"
#include "src/opsi_pajak.h"
#include "src/pph.h"
#include "src/ppn.h"
#include "src/pbb.h"
#include "src/impor.h"
#include "src/info-pengguna.h"
#include "src/history.h"

int main()
{
    opening();
    sinkronDataPengguna();
    sinkronDataTransaksi();

    current = time(NULL);
    struct tm tm = *localtime(&current);

    waktu_sekarang.hari = tm.tm_mday;
    waktu_sekarang.bulan = tm.tm_mon + 1;
    waktu_sekarang.tahun = tm.tm_year + 1900;
    waktu_sekarang.jam = tm.tm_hour;
    waktu_sekarang.menit = tm.tm_min;
    waktu_sekarang.detik = tm.tm_sec;

    while (menu_awal < 1 || menu_awal > 2)
    {
        printf("\n\tPilihan Anda Salah!");
        printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
        printf("\n\tPilihan Anda : ");
        menu_awal = input_int();
    }

    if (menu_awal == 1)
    {
        system("cls");
        login_menu();
    }
    else
    {
        system("cls");
        register_menu();
    }

    opsi_pajak();

    system("PAUSE");
    return 0;
}