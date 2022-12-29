int jenis_kendaraan, tahunan_pajak, kode_ranmor, is_thn_pertama, kepemilikan_ke, menu_pkb, lihat_rincian, thn_bayar, bln_bayar, tgl_bayar;
double njkb,   // nilai jual kendaraan bermotor
    bbnkb = 0, // Bea Balik Nama Kendaraan Bermotor (BBN KB)
    pkb,
    swdkllj,
    pnbp_stnk,
    pnbp_tnkb,
    denda,
    pengesahan_stnk,
    koefisien,
    total, 
    admin = 50000;
char merk[100], tipe[100], str_jenis_kendaraan[100], str_kode_ranmor[100], stnk[100], str_tahunan_pajak[100], status[100];

void output_pkb();
void pkb_menu();
void motor();
void mobil();
void tarif_progresif();

// Fungsi untuk mencetak bukti pembayaran pkb
void output_pkb()
{
  char filename[100];
  // digunakan untuk menyimpan output variabel yang dituju dengan format yang kita buat
  sprintf(filename, "%s-bukti-bayar-pkb-%d-%02d-%02d-%02d-%02d.txt", pengguna_login.npwp, waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit);

  FILE *file = fopen(filename, "a");
  if (file)
  {
    fprintf(file, "\n\t--------------------+----------------------------------------");
    fprintf(file, "\n\t       *******      |                                        ");
    fprintf(file, "\n\t     ***********    |             BUKTI PEMBAYARAN           ");
    fprintf(file, "\n\t     *@@     ***    |          LUNAS PAJAK KENDARAAN         ");
    fprintf(file, "\n\t     &&&     **@    |                 BERMOTOR               ");
    fprintf(file, "\n\t     &&&&&&&&&&&    |             NEGARA INDONESIA           ");
    fprintf(file, "\n\t       &&&&&&&      |                                        ");
    fprintf(file, "\n\t--------------------+----------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tA. IDENTITAS PEMILIK KENDARAAN");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t NPWP           : %s", pengguna_login.npwp);
    fprintf(file, "\n\t NIK            : %s", pengguna_login.nik);
    fprintf(file, "\n\t Nama           : %s", pengguna_login.nama);
    fprintf(file, "\n\t Alamat         : %s", pengguna_login.alamat);
    fprintf(file, "\n\t No. Telp       : %s", pengguna_login.no_telp);
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tB. IDENTITAS KENDARAAN BERMOTOR");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t Nomor STNK      : %s", stnk);
    fprintf(file, "\n\t Jenis Kendaraan : %s", str_jenis_kendaraan);
    fprintf(file, "\n\t Tipe Kendaraan  : %s", tipe);
    fprintf(file, "\n\t Merk            : %s", merk);
    fprintf(file, "\n\t Kode Kendaraan  : %s", str_kode_ranmor);
    fprintf(file, "\n\t Kepemilikan Ke  : %d", kepemilikan_ke);
    fprintf(file, "\n\t Jenis Pajak     : %s", str_tahunan_pajak);
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tC. RINCIAN PERHITUNGAN PKB");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t                  URAIAN               |        JUMLAH       ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t Bea Balik Nama Kendaraan (BBN-KB)     | Rp.%*.0lf", 16, bbnkb);
    fprintf(file, "\n\t Nilai Jual Kendaraan Bermotor (NJKB)  | Rp.%*.0lf", 16, njkb);
    fprintf(file, "\n\t Pajak Kendaraan Bermotor (PKB)        | Rp.%*.0lf", 16, pkb);
    fprintf(file, "\n\t SWDKLLJ                               | Rp.%*.0lf", 16, swdkllj);
    fprintf(file, "\n\t Biaya Perpanjangan STNK               | Rp.%*.0lf", 16, pnbp_stnk);
    fprintf(file, "\n\t Biaya Pengesahan STNK                 | Rp.%*.0lf", 16, pengesahan_stnk);
    fprintf(file, "\n\t Biaya TNKB                            | Rp.%*.0lf", 16, pnbp_tnkb);
    fprintf(file, "\n\t Denda                                 | Rp.%*.0lf", 16, denda);
    fprintf(file, "\n\t Total Pajak Kendaraan Bermotor        | Rp.%*.0lf", 16, total + denda);
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tD. RINCIAN TRANSAKSI");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t Tahun Pajak     : %02d", waktu_sekarang.tahun);
    fprintf(file, "\n\t Tenggat         : 31 Desember");
    fprintf(file, "\n\t Waktu Transaksi : %d-%02d-%02d %02d:%02d:%02d", waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit, waktu_sekarang.detik);
    fprintf(file, "\n\t Status          : %s", status);
    fprintf(file, "\n\t-------------------------------------------------------------");
  }
  else
    printf("Unable to load file!");
  fclose(file);

  printf("\n\t==========================================================\n");
  printf("\n\t             Rincian Pembayaran berhasil dicetak          \n");
  printf("\n\t==========================================================\n");
  printf("\n\tSilahkan tekan tombol apapun untuk kembali ke Program\n");
  getch();
  system("cls");
  pkb_menu();
}

void input_tgl_bayar()
{
  printf("\n\tMasukan Tanggal Pembayaran Pajak Sebelumnya : ");
  printf("\n\tMasukan Hari : ");
  tgl_bayar = input_int();
  printf("\n\tMasukan Bulan : ");
  bln_bayar = input_int();
  printf("\n\tMasukan Tahun : ");
  thn_bayar = input_int();
}

// Fungsi untuk melakukan pembayaran pkb
void pkb_hitung()
{
  total = 0;
  printf("\n\t=========================================================\n");
  printf("\n\t           Pembayaran Pajak Kendaraan Bermotor           \n");
  printf("\n\t=========================================================\n");

  printf("\n\tPilih Jenis Kendaraan");
  printf("\n\t[1] Pajak Mobil");
  printf("\n\t[2] Pajak Motor");
  printf("\n\tMasukan Pilihan : ");
  jenis_kendaraan = input_int();
  while (jenis_kendaraan < 1 || jenis_kendaraan > 2)
  {
    printf("\n\tPilihan Tidak Tersedia!");
    printf("\n\tMasukan Pilihan Anda : ");
    jenis_kendaraan = input_int();
  }

  printf("\n\tPilih Jenis Pajak");
  printf("\n\t[1] Pajak Tahunan");
  printf("\n\t[2] Pajak Lima Tahunan");
  printf("\n\tMasukan Pilihan : ");
  tahunan_pajak = input_int();
  while (tahunan_pajak < 1 || tahunan_pajak > 2)
  {
    printf("\n\tPilihan Tidak Tersedia!");
    printf("\n\tMasukan Pilihan Anda : ");
    tahunan_pajak = input_int();
  }

  if (tahunan_pajak == 1)
    strcpy(str_tahunan_pajak, "Pajak Tahunan");
  else
    strcpy(str_tahunan_pajak, "Pajak 5 Tahunan");

  printf("\n\tMasukan Nomor STNK : ");
  input_str(stnk);

  printf("\n\tMasukan Harga Pasaran Umum Kendaraan : ");
  njkb = input_double();

  printf("\n\tMasukan kepemilikan ke : ");
  kepemilikan_ke = input_int();

  if (tahunan_pajak == 1)
  {
    printf("\n\tApakah Pajak Tahun Pertama?\n\t[1] Ya [2] Tidak\n\tMasukan Pilihan : ");
    is_thn_pertama = input_int();
    while (is_thn_pertama < 1 || is_thn_pertama > 2)
    {
      printf("\n\tPilihan Tidak Tersedia!");
      printf("\n\tMasukan Pilihan Anda : ");
      is_thn_pertama = input_int();
    }
  }

  // membuat tanggal atau waktu menggunakan struct dengan waktu yang spesifik
  struct tm pajak_sblmnya = {.tm_sec = 0,
                             .tm_min = 0,
                             .tm_hour = 0,
                             .tm_mday = waktu_sekarang.hari,
                             .tm_mon = waktu_sekarang.bulan - 1,
                             .tm_year = waktu_sekarang.tahun - 1900,
                             .tm_isdst = 0}; // dayligth saving time flag

  // jika bukan tahun pertama masukan tanggal pembayaran pajak sebelumnya
  if (is_thn_pertama == 2)
  {
    input_tgl_bayar();

    while (checkTgl(tgl_bayar, bln_bayar, thn_bayar) == 0)
    {
      printf("\n\tTanggal Pembayaran Tidak Valid!");
      input_tgl_bayar();
    }

    pajak_sblmnya.tm_mday = tgl_bayar;
    pajak_sblmnya.tm_mon = bln_bayar - 1;
    pajak_sblmnya.tm_year = thn_bayar - 1900;
  }

  // mengubah format waktu menjadi UNIX timestamp
  time_t tgl_pajak_sblmnya = mktime(&pajak_sblmnya);

  printf("\n\tMasukan merk kendaraan : ");
  input_str(merk);

  printf("\n\tMasukan tipe kendaraan : ");
  input_str(tipe);

  if (jenis_kendaraan == 1)
  {
    strcpy(str_jenis_kendaraan, "Mobil");
    mobil();
  }
  else
  {
    strcpy(str_jenis_kendaraan, "Motor");
    motor();
  }

  denda = 0;

  // membuat tanggal atau waktu menggunakan struct dengan waktu yang spesifik
  struct tm due_date = {.tm_sec = 0,
                        .tm_min = 0,
                        .tm_hour = 0,
                        .tm_mday = 31,
                        .tm_mon = 12 - 1,
                        .tm_year = waktu_sekarang.tahun - 1900,
                        .tm_isdst = 0}; // dayligth saving time flag

  // jika memilih pajak lima tahunan tambah tenggat tahun 5 tahun
  if (tahunan_pajak == 2)
    due_date.tm_year += 5;

  // mengubah format waktu menjadi UNIX timestamp
  time_t jatuh_tempo = mktime(&due_date);

  int selisih_tahun = difftime(current, jatuh_tempo) / (60 * 60 * 24 * 365);
  int selisih_bulan = difftime(current, jatuh_tempo) / (60 * 60 * 24 * 30);
  int selisih_hari = difftime(current, jatuh_tempo) / (60 * 60 * 24);

  printf("\n\t-----------------------------------------------------------\n");
  printf("\n\tTotal Pajak Kendaraan Bermotor    : Rp.%.0lf\n", total);

  if (tgl_pajak_sblmnya > jatuh_tempo)
  {
    if (selisih_tahun >= 3)
      denda = 3 * pkb * 0.25 + swdkllj;
    else if (selisih_tahun == 2)
      denda = 2 * pkb * 0.25 + swdkllj;
    else if (selisih_tahun == 1)
      denda = pkb * 0.25 + swdkllj;
    else if (selisih_bulan >= 6)
      denda = pkb * 0.25 * (6 / 12) + swdkllj;
    else if (selisih_bulan >= 3)
      denda = pkb * 0.25 * (3 / 12) + swdkllj;
    else if (selisih_bulan >= 2)
      denda = pkb * 0.25 * (2 / 12) + swdkllj;
    else if (selisih_bulan >= 1)
      denda = pkb * 0.25;
    else if (selisih_hari >= 2)
      denda = pkb * 0.25;

    printf("\n\tDenda Pajak Kendaraan Bermotor  : Rp.%.0lf\n", denda);
  }

  printf("\n\tJumlah Nominal Yang Harus Dibayar : Rp.%.0lf\n", total + denda);
  printf("\n\t-----------------------------------------------------------");

  if (denda == 0)
    strcpy(status, "Tepat Waktu");
  else
    strcpy(status, "Terlambat");

  // memasukan data transaksi ke dalam struct
  strcpy(trs_input.id, pengguna_login.npwp);
  strcpy(trs_input.jenis_pajak, "PKB");
  trs_input.total_pajak = total;
  trs_input.denda = denda;
  trs_input.jumlah_nominal = total + denda;
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
    output_pkb();
  }
  else
  {
    system("cls");
    pkb_menu();
  }
}

// Fungsi untuk melakukan konfirmasi pembayaran pkb
void pkb_menu()
{
  printf("\n\t=========================================================\n");
  printf("\n\t      Konfirmasi Pembayaran Pajak Kendaraan Bermotor     \n");
  printf("\n\t=========================================================\n");
  printf("\n\t1. Bayar Pajak Kendaraan Bermotor");
  printf("\n\t2. Kembali");
  printf("\n\t---------------------------------------------------------\n");
  printf("\n\tPilihan Anda : ");
  menu_pkb = input_int();

  while (menu_pkb != 1 && menu_pkb != 2)
  {
    printf("\n\tPilihan Anda Salah!");
    printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
    printf("\n\tMasukan Pilihan Anda : ");
    menu_pkb = input_int();
  }

  switch (menu_pkb)
  {
  case 1:
    system("cls");
    pkb_hitung();
    break;
  case 2:
    system("cls");
    opsi_pajak();
  default:
    printf("\n\tPilihan Anda Salah!");
    break;
  }
}

// fungsi untuk menghitung tarif progresif berdasarkan kepemilikan kendaraan ke berapa
void tarif_progresif()
{
  if (kepemilikan_ke == 1)
    pkb = 0.02 * njkb;
  else if (kepemilikan_ke == 2)
    pkb = 0.025 * njkb;
  else if (kepemilikan_ke == 3)
    pkb = 0.03 * njkb;
  else if (kepemilikan_ke == 4)
    pkb = 0.035 * njkb;
  else if (kepemilikan_ke == 5)
    pkb = 0.04 * njkb;
  else if (kepemilikan_ke == 6)
    pkb = 0.045 * njkb;
  else if (kepemilikan_ke == 7)
    pkb = 0.05 * njkb;
  else if (kepemilikan_ke == 8)
    pkb = 0.055 * njkb;
  else if (kepemilikan_ke == 9)
    pkb = 0.06 * njkb;
  else if (kepemilikan_ke == 10)
    pkb = 0.065 * njkb;
  else if (kepemilikan_ke == 11)
    pkb = 0.07 * njkb;
  else if (kepemilikan_ke == 12)
    pkb = 0.075 * njkb;
  else if (kepemilikan_ke == 13)
    pkb = 0.08 * njkb;
  else if (kepemilikan_ke == 14)
    pkb = 0.085 * njkb;
  else if (kepemilikan_ke == 15)
    pkb = 0.09 * njkb;
  else if (kepemilikan_ke == 16)
    pkb = 0.085 * njkb;
  else
    pkb = 0.09 * njkb;
}

void mobil()
{
  printf("\n\tPilih Kode Ranmor Sesuai Kendaraan Anda");
  printf("\n\t[1] A (Mobil Ambulance, Mobil Jenazah, dan Mobil Damkar)");
  printf("\n\t[2] B (Traktor, Buldozer, Forklift, Mobil Derek, Excafator, dan Crane)");
  printf("\n\t[3] DP (Sedan, Mobil Penumpang Bukan Umum, Mobil Barang s.d 2400cc)");
  printf("\n\t[4] DU (Mobil Penumpang Angkutan Umum s.d 1600 cc, Jeep, Minibus)");
  printf("\n\t[5] EP (Bus dan Mikrobus, Bukan Angkutan Umum)");
  printf("\n\t[6] EU (Mikrobus Angkutan Umum, Mobil Penumpang > 1600cc, Blind Van, Pickup)");
  printf("\n\t[7] F (Truk, Mobil Tangki, Mobil Gandeng, Truk Container > 2400cc)");
  printf("\n\tMasukan Pilihan : ");
  kode_ranmor = input_int();
  while (kode_ranmor < 1 || kode_ranmor > 7)
  {
    printf("\n\tPilihan Tidak Tersedia!");
    printf("\n\tMasukan Pilihan Anda : ");
    kode_ranmor = input_int();
  }

  if (is_thn_pertama == 1)
    bbnkb = 0.1 * njkb;

  // menetapkan tarif berdasarkan kode kendaraan bermotor
  if (kode_ranmor == 1)
  {
    koefisien = 1;
    njkb *= koefisien;
    swdkllj = 0;
    pnbp_stnk = 200000;
    pnbp_tnkb = 100000;
    strcpy(str_kode_ranmor, "A");
  }
  else if (kode_ranmor == 2)
  {
    koefisien = 1;
    njkb *= koefisien;
    swdkllj = 23000;
    pnbp_stnk = 0;
    pnbp_tnkb = 0;
    strcpy(str_kode_ranmor, "B");
  }
  else if (kode_ranmor == 3)
  {
    koefisien = 1.025;
    njkb *= koefisien;
    swdkllj = 143000;
    pnbp_stnk = 200000;
    pnbp_tnkb = 100000;
    strcpy(str_kode_ranmor, "DP");
  }
  else if (kode_ranmor == 4)
  {
    koefisien = 1.050;
    njkb *= koefisien;
    swdkllj = 73000;
    pnbp_stnk = 200000;
    pnbp_tnkb = 100000;
    strcpy(str_kode_ranmor, "DU");
  }
  else if (kode_ranmor == 5)
  {
    koefisien = 1.100;
    njkb *= koefisien;
    swdkllj = 153000;
    pnbp_stnk = 200000;
    pnbp_tnkb = 100000;
    strcpy(str_kode_ranmor, "EP");
  }
  else if (kode_ranmor == 6)
  {
    koefisien = 1.085;
    njkb *= koefisien;
    swdkllj = 73000;
    pnbp_stnk = 200000;
    pnbp_tnkb = 100000;
    strcpy(str_kode_ranmor, "EU");
  }
  else
  {
    koefisien = 1.300;
    njkb *= koefisien;
    swdkllj = 73000;
    pnbp_stnk = 200000;
    pnbp_tnkb = 163000;
    strcpy(str_kode_ranmor, "F");
  }

  // menghitung tarif progresif berdasarkan kepemilikan kendaraan ke berapa
  tarif_progresif();

  // jika pajak dibayar per tahun
  if (tahunan_pajak == 1)
  {
    // jika pajak kendaraan tahun pertama (baru)
    if (is_thn_pertama == 1)
      total = pkb + bbnkb + swdkllj + pnbp_stnk + pnbp_tnkb;
    // jika pajak kendaraan bukan tahun pertama (lama)
    else
      total = pkb + swdkllj;
  }
  // jika pajak dibayar per lima tahun
  else
  {
    pengesahan_stnk = 50000;
    pnbp_tnkb = 100000;

    total = pkb + swdkllj + pengesahan_stnk + pnbp_stnk + pnbp_tnkb;
  }
}

void motor()
{
  printf("\n\tPilih Kode Ranmor Sesuai Kendaraan Anda");
  printf("\n\t[1] C1 (Sepeda Motor, Sepeda Kumbang, Scooter 50cc s.d 250cc)");
  printf("\n\t[2] C2 (Sepeda Motor dan Skuter > 250cc)");
  printf("\n\tMasukan Pilihan : ");
  kode_ranmor = input_int();
  while (kode_ranmor < 1 || kode_ranmor > 7)
  {
    printf("\n\tPilihan Tidak Tersedia!");
    printf("\n\tMasukan Pilihan Anda : ");
    kode_ranmor = input_int();
  }

  if (is_thn_pertama == 1)
    bbnkb = 0.1 * njkb;

  // menetapkan tarif berdasarkan kode kendaraan bermotor
  if (kode_ranmor == 1)
  {
    koefisien = 1;
    njkb *= koefisien;
    swdkllj = 35000;
    strcpy(str_kode_ranmor, "C1");
  }
  else if (kode_ranmor == 2)
  {
    koefisien = 1;
    njkb *= koefisien;
    swdkllj = 83000;
    strcpy(str_kode_ranmor, "C2");
  }

  // menghitung tarif progresif berdasarkan kepemilikan kendaraan ke berapa
  tarif_progresif();

  // jika pajak dibayar per tahun
  if (tahunan_pajak == 1)
  {
    pnbp_stnk = 100000;
    pnbp_tnkb = 60000;

    // jika pajak kendaraan tahun pertama (baru)
    if (is_thn_pertama == 1)
      total = pkb + bbnkb + swdkllj + pnbp_stnk + pnbp_tnkb;
    // jika pajak kendaraan bukan tahun pertama (lama)
    else
      total = pkb + swdkllj;
  }
  // jika pajak dibayar per lima tahun
  else
  {
    pnbp_stnk = 100000;
    pengesahan_stnk = 50000;
    pnbp_tnkb = 60000;

    total = pkb + swdkllj + pengesahan_stnk + pnbp_stnk + pnbp_tnkb;
  }
}
