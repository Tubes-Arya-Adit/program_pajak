int i, jumlah, lihat_rincian, menu_ppn, tgl_bayar, bln_bayar, thn_bayar;
double total_harga = 0, ppn, denda;
char status[100];

void ppn_menu();

// fungsi untuk melakukan cetak pembayaran ppn
void output_ppn(char uraian[jumlah][51], double harga[])
{
    char filename[100];
    sprintf(filename, "%s-bukti-bayar-ppn-%d-%02d-%02d-%02d-%02d.txt", pengguna_login.npwp, waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit);

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
        fprintf(file, "\n\t NPWP            : %s", pengguna_login.npwp);
        fprintf(file, "\n\t NIK             : %s", pengguna_login.nik);
        fprintf(file, "\n\t Nama            : %s", pengguna_login.nama);
        fprintf(file, "\n\t Alamat          : %s", pengguna_login.alamat);
        fprintf(file, "\n\t No. Telp        : %s", pengguna_login.no_telp);
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
        fprintf(file, "\n\t Total Harga                   : %.0f", total_harga);
        fprintf(file, "\n\t PPN                           : %.0f", ppn);
        fprintf(file, "\n\t Denda                         : %.0f", denda);
        fprintf(file, "\n\t Total Pajak Pertambahan Nilai : %.0f", ppn + denda);
        fprintf(file, "\n\t------------------------------------------------------");
        fprintf(file, "\n");
        fprintf(file, "\n\tC. RINCIAN TRANSAKSI");
        fprintf(file, "\n\t------------------------------------------------------");
        fprintf(file, "\n\t Tahun Pajak              : %02d", waktu_sekarang.tahun);
        fprintf(file, "\n\t Tanggal Pembelian Barang : %d-%d-%d", tgl_bayar, bln_bayar, thn_bayar);
        fprintf(file, "\n\t Waktu Transaksi          : %d-%02d-%02d %02d:%02d:%02d", waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit, waktu_sekarang.detik);
        fprintf(file, "\n\t Status                   : %s", status);
        fprintf(file, "\n\t------------------------------------------------------");
        fprintf(file, "\n\n\n");
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

void input_tgl_transaksi()
{
    tgl_bayar = bln_bayar = thn_bayar = 0; // reset tanggal pembelian barang
    printf("\n\tTanggal Transaksi Barang : ");
    printf("\n\tMasukan Hari  : ");
    tgl_bayar = input_hari();
    printf("\n\tMasukan Bulan : ");
    bln_bayar = input_bulan();
    printf("\n\tMasukan Tahun : ");
    thn_bayar = input_int();
}

// fungsi untuk menghitung ppn
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
    }

    // memasukan tanggal transaksi barang
    input_tgl_transaksi();

    // check apakah tanggal sesuai format
    while (checkTgl(tgl_bayar, bln_bayar, thn_bayar) == 0)
    {
        input_tgl_transaksi();
    }

    // menambah bulan pembayaran menjadi bulan berikutnya dan
    // apakah bulan yang dimasukan adalah desember
    bln_bayar + 1;

    if (bln_bayar == 12)
    {
        bln_bayar = 1;
        thn_bayar += 1;
    }

    ppn = total_harga * 0.10;

    // membuat tanggal atau waktu menggunakan struct dengan waktu yang spesifik
    struct tm due_date = {.tm_sec = 0,
                          .tm_min = 0,
                          .tm_hour = 0,
                          .tm_mday = 20,
                          .tm_mon = bln_bayar - 1,
                          .tm_year = thn_bayar - 1900,
                          .tm_isdst = 0};

    // mengubah format waktu menjadi UNIX timestamp
    time_t jatuh_tempo = mktime(&due_date);

    denda = 0;

    printf("\n\t--------------------------------------------------------\n");
    printf("\n\tTotal Harga Barang                : Rp.%.0f", total_harga);
    printf("\n\tPPN                               : Rp.%.0f", ppn);

    // menghitung denda jika pembayaran terlambat
    if (current > jatuh_tempo)
    {
        int selisih_bulan = waktu_sekarang.bulan - bln_bayar;
        if (selisih_bulan <= 0)
            selisih_bulan = 1;
        denda = (ppn * 0.02) * selisih_bulan;

        printf("\n\tDenda                             : Rp.%.0f", denda);
    }
    printf("\n\tJumlah nominal yang harus dibayar : Rp.%.0f\n", ppn + denda);
    printf("\n\t--------------------------------------------------------\n");

    if (denda == 0)
        strcpy(status, "Tepat Waktu");
    else
        strcpy(status, "Terlambat");

    // memasukan data transaksi ke struct
    strcpy(trs_input.id, pengguna_login.npwp);
    strcpy(trs_input.jenis_pajak, "PPn");
    trs_input.total_pajak = ppn;
    trs_input.denda = denda;
    trs_input.jumlah_nominal = ppn + denda;
    sprintf(trs_input.tanggal, "%d-%02d-%02d %02d:%02d:%02d", waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit, waktu_sekarang.detik);
    strcpy(trs_input.status, status);

    tambahDataTransaksi();
    sinkronDataTransaksi();

    printf("\n\n\tLihat rincian pembayaran?");
    printf("\n\t[1] Ya    [2] Tidak ");
    printf("\n\tMasukan Pilihan Anda : ");
    lihat_rincian = input_int();
    while (lihat_rincian != 1 && lihat_rincian != 2)
    {
        printf("\n\tPilihan Anda Salah!");
        printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
        printf("\n\tMasukan Pilihan Anda : ");
        lihat_rincian = input_int();
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

// fungsi untuk melakukan konfirmasi pembayaran ppn
void ppn_menu()
{
    printf("\n\t=========================================================\n");
    printf("\n\t                   Konfirmasi Pembayaran PPN             \n");
    printf("\n\t=========================================================\n");
    printf("\n\t1. Bayar PPN");
    printf("\n\t2. Kembali");
    printf("\n\t---------------------------------------------------------\n");

    printf("\n\tPilihan Anda : ");
    menu_ppn = input_int();

    while (menu_ppn != 1 && menu_ppn != 2)
    {
        printf("\n\tPilihan Anda Salah!");
        printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
        printf("\n\tMasukan Pilihan Anda : ");
        menu_ppn = input_int();
    }

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
        printf("\n\tPilihan Anda Salah!");
        break;
    }
}
