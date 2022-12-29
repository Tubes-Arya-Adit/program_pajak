int i,      // indeks perulangan
    jumlah, // jumlah barang
    lihat_rincian,
    menu_status,
    menu_ppn,           // menampung nilai input saat memilih konfirmasi pembayaran atau kembali
    tgl_bayar,          // menampung nilai input tanggal transaksi barang
    bln_bayar,          // menampung nilai input bulan transaksi barang
    thn_bayar;          // menampung nilai input tahun transaksi barang
double total_harga = 0, // set total harga default
    ppn,                // nilai pajak ppn
    denda;              // denda jika pembayaran melewati batas waktu
char status[100];       // menyimpan string status pembayaran pajak, apakah "tepat waktu" atau "terlambat"

struct Barang
{
    char nama[100];
    int is_barang_mewah; // 1 = mewah 2 non mewah
    double harga;
    char status[100];
};

struct Barang barang[11];

// deklarasi prototype fungsi
void ppn_menu();

// fungsi untuk melakukan cetak pembayaran ppn
void output_ppn()
{
    char filename[100]; // string untuk menyimpan nama file
    // assign format nama file ke filename
    // digunakan untuk menyimpan output variabel yang dituju dengan format yang kita buat
    sprintf(filename, "%s-bukti-bayar-ppn-%d-%02d-%02d-%02d-%02d.txt", pengguna_login.npwp, waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit);

    FILE *file = fopen(filename, "a"); // deklarasi tipe data FILE, variabel file merupakan pointer ke tipe data FILE.
    // membuka file dengan nama filename, "a" (append) membuka file untuk ditulis di akhir file. Jika file tidak ada, maka file akan dibuat.
    if (file) // jika berhasil membuka file
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
        fprintf(file, "\n\t+----+-----------------------------------------------+--------------------+-----------------------");
        fprintf(file, "\n\t| NO |              URAIAN BARANG/JASA               |        HARGA       |        Status        |");
        fprintf(file, "\n\t|----|-----------------------------------------------|--------------------|-----------------------");
        for (i = 0; i < jumlah; i++) // perulangan sebanyak jumlah barang
        {
            fprintf(file, "\n\t| %-2d | %-48s | Rp.%15.0f | %-20s |", i + 1, barang[i].nama, barang[i].harga, barang[i].status); // menampilkan nomor, nama barang, dan harga
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
    else // jika file tidak berhasil dibuka
        fprintf(file, "Unable to load file!");
    fclose(file); // tutup file

    printf("\n\t==========================================================\n");
    printf("\n\t             Rincian Pembayaran berhasil dicetak          \n");
    printf("\n\t==========================================================\n");
    printf("\n\tSilahkan tekan tombol apapun untuk kembali ke Program\n");
    getch();
    system("cls");
    ppn_menu(); // kembali ke menu sebelumnya
}

void input_tgl_transaksi()
{
    tgl_bayar = bln_bayar = thn_bayar = 0; // reset tanggal pembelian barang
    printf("\n\tTanggal Transaksi Barang\n ");
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
    while (jumlah > 10)
    {
        printf("\n\tMaksimal barang yang dihitung 10 barang!");
        printf("\n\tSilahkan Masukan jumlah barang yang akan dihitung : ");
        jumlah = input_int();
    }

    for (i = 0; i < jumlah; i++)
    {
        printf("\n\tMasukan nama barang ke-%d : ", i + 1);
        input_str(temp);              // input nama barang ke-i
        strcpy(barang[i].nama, temp); // mengcopy temp ke uraian indeks ke-i

        printf("\n\tApakah termasuk barang mewah ?");
        printf("\n\t[1] Ya  [2] Tidak");
        printf("\n\tMasukan pilihan :");
        menu_status = input_int();

        while (menu_status < 1 || menu_status > 2)
        {
            printf("\n\tYang anda masukan salah!");
            printf("\n\tMasukan kembali : ");
            barang[i].is_barang_mewah = input_int();
        }

        if (menu_status == 1)
        {
            barang[i].is_barang_mewah = 1;
            strcpy(barang[i].status, "Barang Mewah");
        }
        else
        {
            barang[i].is_barang_mewah = 2;
            strcpy(barang[i].status, "Barang Non Mewah");
        }

        printf("\n\tMasukan harga %s : Rp.", barang[i].nama);
        barang[i].harga = input_double(); // input harga barang ke-i

        // total_harga += [i]; // menghitung total harga barang
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

    if (bln_bayar > 12)
    {
        bln_bayar = 1;
        thn_bayar += 1;
    }

    ppn = 0;

    // jika  barang mewah maka ppn = 10% dari harga barang dikurangi 40% (persentase blm pasti)
    for (int i = 0; i < jumlah; i++)
    {
        if (barang[i].is_barang_mewah == 1)
            ppn += (barang[i].harga * 0.1);
        else
            ppn += (0.1 * (barang[i].harga - (barang[i].harga * 0.4)));
    }

    // ppn = total_harga * 0.10;

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
    if (current > jatuh_tempo) // jika terlambat akan dikenakan denda
    {
        int selisih_bulan = waktu_sekarang.bulan - bln_bayar; // menghitung keterlambatan (dalam bulan)
        if (selisih_bulan <= 0)
            selisih_bulan = 1;
        denda = (ppn * 0.02) * selisih_bulan; // denda didapat dari 20% ppn dikali terlambat berapa bulan

        printf("\n\tDenda                             : Rp.%.0f", denda);
    }
    printf("\n\tJumlah nominal yang harus dibayar : Rp.%.0f\n", ppn + denda);
    printf("\n\t--------------------------------------------------------\n");

    if (denda == 0)
        strcpy(status, "Tepat Waktu");
    else
        strcpy(status, "Terlambat");

    // proses pencatatan history
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
    while (lihat_rincian < 1 && lihat_rincian > 2)
    {
        printf("\n\tPilihan Anda Salah!");
        printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
        printf("\n\tMasukan Pilihan Anda : ");
        lihat_rincian = input_int();
    }

    if (lihat_rincian == 1)
    {
        system("cls");
        output_ppn();
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

    while (menu_ppn < 1 && menu_ppn > 2)
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
