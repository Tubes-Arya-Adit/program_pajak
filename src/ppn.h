int i, jumlah, lihat_rincian, menu_ppn, tgl_bayar, bln_bayar, thn_bayar;
double total_harga = 0, ppn, denda;

void ppn_menu();

void output_ppn(char uraian[jumlah][51], double harga[])
{
    char filename[100];
    sprintf(filename, "%s-bukti-bayar-ppn.txt", pengguna_login.npwp);

    FILE *file = fopen(filename, "a");
    if (file)
    {
        fprintf(file, "\n\t--------------------+---------------------------------");
        fprintf(file, "\n\t       *******      |                                 ");
        fprintf(file, "\n\t     ***********    |         BUKTI PEMBAYARAN        ");
        fprintf(file, "\n\t     *@@     ***    |            LUNAS PAJAK          ");
        fprintf(file, "\n\t     &&&     **@    |         PERTAMBAHAN NILAI       ");
        fprintf(file, "\n\t     &&&&&&&&&&&    |         NEGARA INDONESIA        ");
        fprintf(file, "\n\t       &&&&&&&      |                                 ");
        fprintf(file, "\n\t--------------------+---------------------------------");
        fprintf(file, "\n");
        fprintf(file, "\n\tA. IDENTITAS PEMBELI BARANG KENA PAJAK");
        fprintf(file, "\n\t------------------------------------------------------");
        fprintf(file, "\n\t NPWP              : %s", pengguna_login.npwp);
        fprintf(file, "\n\t NIK               : %s", pengguna_login.nik);
        fprintf(file, "\n\t Nama              : %s", pengguna_login.nama);
        fprintf(file, "\n\t Alamat            : %s", pengguna_login.alamat);
        fprintf(file, "\n\t No. Telp          : %s", pengguna_login.no_telp);
        fprintf(file, "\n\t------------------------------------------------------");
        fprintf(file, "\n");
        fprintf(file, "\n\tB. RINCIAN BARANG/JASA KENA PAJAK DAN PERHITUNGAN PPN");
        fprintf(file, "\n\t+----+----------------------------------------------------+--------------------+");
        fprintf(file, "\n\t| NO |                 URAIAN BARANG/JASA                 |        HARGA       |");
        fprintf(file, "\n\t|----|----------------------------------------------------|--------------------|");
        for (i = 0; i < jumlah; i++) // perulangan sebanyak jumlah barang
        {
            fprintf(file, "\n\t| %-2d | %-50s | Rp.%15.0f |", i + 1, uraian[i], harga[i]); // menampilkan nomor, nama barang, dan harga
        }
        fprintf(file, "\n\t+----+----------------------------------------------------+--------------------+");
        fprintf(file, "\n\t Total Harga                             : %.0f", total_harga);
        fprintf(file, "\n\t Dasar Pengenaan Pajak                   : %.0f", total_harga);
        fprintf(file, "\n\t PPn = 10%% * Dasar Pengenaan Pajak      : %.0f", ppn);
        fprintf(file, "\n\t------------------------------------------------------");
        fprintf(file, "\n");
        fprintf(file, "\n\tD. RINCIAN TRANSAKSI");
        fprintf(file, "\n\t------------------------------------------------------");
        fprintf(file, "\n\t Nomor           :");
        fprintf(file, "\n\t Tahun Pajak     : %02d", waktu_sekarang.tahun);
        fprintf(file, "\n\t Waktu Transaksi : %d-%02d-%02d %02d:%02d:%02d", waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit, waktu_sekarang.detik);
        fprintf(file, "\n\t Status Pajak    : Lunas");
        fprintf(file, "\n\t------------------------------------------------------");
    }
    else
        fprintf(file, "Unable to load file!");
    fclose(file);

    printf("\n\t==========================================================\n");
    printf("\n\t             Rincian Pembayaran berhasil dicetak          \n");
    printf("\n\t==========================================================\n");
    printf("\n\tSilahkan tekan tombol apapun untuk kembali ke Program\n");
    getch();
    system("cls");
    ppn_menu();
}

void ppn_hitung()
{
    double harga[100];
    char temp[51]; // temporary string untuk input nama barang

    printf("\n\t=========================================================\n");
    printf("\n\t           Pembayaran Pajak Pertambahan Nilai            \n");
    printf("\n\t=========================================================\n");
    printf("\n\tMasukan jumlah barang : ");
    jumlah = input_int(); // input jumlah barang
    fflush(stdin);        // clear buffer

    char uraian[jumlah][51]; // array of string untuk menampung daftar nama barang

    for (i = 0; i < jumlah; i++)
    {
        printf("\n\tMasukan nama barang ke-%d : ", i + 1);
        input_str(temp);         // input nama barang ke-i
        strcpy(uraian[i], temp); // mengcopy temp ke uraian indeks ke-i

        printf("\n\tMasukan harga %s : Rp.", uraian[i]);
        harga[i] = input_double(); // input harga barang ke-i

        total_harga += harga[i]; // menghitung total harga barang
        // printf("\n\tTotal Harga : Rp. %.0f\n", total_harga);
    }

    printf("\n\tTanggal Transaksi Barang : ");
    printf("\n\tMasukan Hari  : ");
    tgl_bayar = input_hari();
    printf("\n\tMasukan Bulan : ");
    bln_bayar = input_bulan();
    printf("\n\tMasukan Tahun : ");
    thn_bayar = input_int();

    bln_bayar + 1;

    ppn = total_harga * 0.10;

    printf("\n\t--------------------------------------------------------\n");
    printf("\n\tPPN         : Rp.%.0f", ppn);
    if (waktu_sekarang.hari > 20 && waktu_sekarang.bulan >= bln_bayar)
    {
        int selisih_bulan = waktu_sekarang.bulan - bln_bayar;
        if (selisih_bulan == 0)
            selisih_bulan = 1;
        denda = (ppn * 0.02) * selisih_bulan;

        printf("\n\tDenda  : Rp.%.0f", denda);
    }
    printf("\n\tJumlah nominal yang harus dibayar  : Rp.%.0f\n", ppn + denda);
    printf("\n\t--------------------------------------------------------\n");

    printf("\n\n\tLihat rincian pembayaran?");
    printf("\n\t[1] Ya    [2] Tidak ");
    printf("\n\tMasukan Pilihan Anda : ");
    lihat_rincian = input_int(lihat_rincian);
    while (lihat_rincian != 1 && lihat_rincian != 2)
    {
        printf("\n\tPilihan Anda Salah!");
        printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
        printf("\n\tMasukan Pilihan Anda : ");
        lihat_rincian = input_int(lihat_rincian);
    }

    if (lihat_rincian == 1)
    {
        system("cls");
        output_ppn(uraian, harga);
    }
    else
    {
        system("cls");
        ppn_menu();
    }
}

void ppn_menu()
{
    printf("\n\t=========================================================\n");
    printf("\n\t                   Konfirmasi Pembayaran PPN             \n");
    printf("\n\t=========================================================\n");
    printf("\n\t1. Bayar PPN");
    printf("\n\t2. Kembali");
    printf("\n\t---------------------------------------------------------\n");

    printf("\n\tPilihan Anda : ");
    menu_ppn = input_int(menu_ppn);

    switch (menu_ppn)
    {
    case 1:
        system("cls");
        ppn_hitung();
        break;
    case 2:
        system("cls");
        opsi_pajak();
    default:
        break;
    }
}
