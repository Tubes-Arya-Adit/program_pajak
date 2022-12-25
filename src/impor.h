#define kurs_dollar 15600

int lihat_rincian, menu_impor, isApi, jenis_barang, selisih_hari = 0;
double bea_masuk, bea_masuk_persen, ppn_pajak, ppn_persen, pph22, pph22_persen, pabean, cost, freight, insurance, total_pajak;
char negara[50], api[11] = "-", nama_barang[100], hs_code[9];

void impor_menu();

void output_impor()
{
  char filename[100];
  sprintf(filename, "%s-bukti-bayar-impor.txt", pengguna_login.npwp);

  FILE *file = fopen(filename, "a");
  if (file)
  {
    fprintf(file, "\n\t--------------------+--------------------------------------");
    fprintf(file, "\n\t       *******      |                                      ");
    fprintf(file, "\n\t     ***********    |                                      ");
    fprintf(file, "\n\t     *@@     ***    |        BUKTI PEMBAYARAN LUNAS        ");
    fprintf(file, "\n\t     &&&     **@    |        PAJAK IMPOR INDONESIA         ");
    fprintf(file, "\n\t     &&&&&&&&&&&    |                                      ");
    fprintf(file, "\n\t       &&&&&&&      |                                      ");
    fprintf(file, "\n\t--------------------+--------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tA. IDENTITAS WAJIB PAJAK");
    fprintf(file, "\n\t-----------------------------------------------------------");
    fprintf(file, "\n\t NPWP                 : %s", pengguna_login.npwp);
    fprintf(file, "\n\t Angka Pengenal Impor : %s", api);
    fprintf(file, "\n\t NIK                  : %s", pengguna_login.nik);
    fprintf(file, "\n\t Nama                 : %s", pengguna_login.nama);
    fprintf(file, "\n\t Alamat               : %s", pengguna_login.alamat);
    fprintf(file, "\n\t No. Telp             : %s", pengguna_login.no_telp);
    fprintf(file, "\n\t-----------------------------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tB. BARANG KENA PAJAK");
    fprintf(file, "\n\t-----------------------------------------------------------");
    fprintf(file, "\n\t HC Code        : %s", hs_code);
    fprintf(file, "\n\t Jenis Barang   : ");
    if (jenis_barang == 1)
      fprintf(file, "Produk Tekstil");
    else if (jenis_barang == 2)
      fprintf(file, "Tas");
    else if (jenis_barang == 3)
      fprintf(file, "Sepatu");
    else if (jenis_barang == 4)
      fprintf(file, "Buku Ilmu Pengetahuan");
    else if (jenis_barang == 5)
      fprintf(file, "Lainnya");
    fprintf(file, "\n\t Nama Barang    : %s", nama_barang);
    fprintf(file, "\n\t Negara Asal    : %s", negara);
    fprintf(file, "\n\t-----------------------------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tC. RINCIAN BARANG DAN PERHITUNGAN PAJAK IMPOR");
    fprintf(file, "\n\t-------------------------------------+---------------------");
    fprintf(file, "\n\t                URAIAN               |        JUMLAH       ");
    fprintf(file, "\n\t-------------------------------------+---------------------");
    fprintf(file, "\n\t CIF                                                       ");
    fprintf(file, "\n\t-------------------------------------+---------------------");
    fprintf(file, "\n\t Cost                                | $  %*.0f", 16, cost);
    fprintf(file, "\n\t Insurance                           | $  %*.0f", 16, insurance);
    fprintf(file, "\n\t Freight                             | $  %*.0f", 16, freight);
    fprintf(file, "\n\t Total CIF                           | $  %*.0f", 16, cost + insurance + freight);
    fprintf(file, "\n\t-------------------------------------+---------------------");
    fprintf(file, "\n\t PERHITUNGAN PAJAK IMPOR                                   ");
    fprintf(file, "\n\t-------------------------------------+---------------------");
    fprintf(file, "\n\t Kurs Dollar                         | Rp.%*.d", 16, kurs_dollar);
    fprintf(file, "\n\t Nilai Pabean                        | Rp.%*.0f", 16, pabean);
    fprintf(file, "\n\t Bea Masuk                           | Rp.%*.0f", 16, bea_masuk);
    fprintf(file, "\n\t PPN                                 | Rp.%*.0f", 16, ppn_pajak);
    fprintf(file, "\n\t PPh22                               | Rp.%*.0f", 16, pph22);
    fprintf(file, "\n\t Pajak Impor                         | Rp.%*.0f", 16, total_pajak);
    fprintf(file, "\n\t Denda                               | Rp.%*.0f", 16, denda);
    fprintf(file, "\n\t Total Pajak Impor                   | Rp.%*.0f", 16, total_pajak + denda);
    fprintf(file, "\n\t-------------------------------------+---------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tD. RINCIAN TRANSAKSI");
    fprintf(file, "\n\t-----------------------------------------------------------");
    fprintf(file, "\n\t Tahun Pajak     : %02d", waktu_sekarang.tahun);
    fprintf(file, "\n\t Waktu Transaksi : %d-%02d-%02d %02d:%02d:%02d", waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit, waktu_sekarang.detik);
    fprintf(file, "\n\t Status Pajak    : ");
      if(denda == 0)
        fprintf(file, "Pembayaran Tepat Waktu");
      else
        fprintf(file, "Pembayaran Terlambat");
    // fprintf(file, "\n\t Masa Pajak      :");
    fprintf(file, "\n\t-----------------------------------------------------------");
    fprintf(file, "\n\n\n");
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
  impor_menu();
}

void impor_hitung()
{
  struct tm waktu_tiba;
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("\n\t=========================================================\n");
  printf("\n\t                  Pembayaran Pajak Impor                 \n");
  printf("\n\t=========================================================\n");

  printf("\n\tApakah Anda Memiliki Angka Pengenal Impor?\n\t[1] Ya [2] Tidak\n\tMasukan Pilihan : ");
  isApi = input_int();
  fflush(stdin);
  while (isApi < 1 || isApi > 2)
  {
    printf("\n\tPilihan tidak tersedia!");
    printf("\n\tSilahkan masukan kembali : ");
    isApi = input_int();
  }
  fflush(stdin);

  if (isApi == 1)
  {
    pph22_persen = 0.025;
    printf("\n\tMasukan Angka Pengenal Impor : ");
    input_str(api);
    fflush(stdin);
  }
  else
  {
    pph22_persen = 0.075;
  }

  printf("\n\tList Barang :");
  printf("\n\t [1] Produk Tekstil");
  printf("\n\t [2] Tas");
  printf("\n\t [3] Sepatu");
  printf("\n\t [4] Buku Ilmu Pengetahuan");
  printf("\n\t [5] Lainnya");
  printf("\n\tMasukan Jenis Barang Yang Di Impor : ");
  jenis_barang = input_int(jenis_barang);
  while (jenis_barang < 1 || jenis_barang > 5)
  {
    printf("\n\tPilihan tidak tersedia!");
    printf("\n\tSilahkan masukan kembali : ");
    jenis_barang = input_int(jenis_barang);
  }
  fflush(stdin);

  printf("\n\tMasukan Nama Barang : ");
  input_str(nama_barang);

  printf("\n\tMasukan HS Code : ");
  input_str(hs_code);

  printf("\n\tMasukan Negara Asal Barang : ");
  input_str(negara);

  printf("\n\tMasukan Cost atau Nilai Barang : $");
  cost = input_double();

  printf("\n\tMasukan Insurance atau Asuransi : $");
  insurance = input_double();

  printf("\n\tMasukan Freight atau Biaya Kirim : $");
  freight = input_double();

  printf("\n\tTanggal Barang Sampai di Pelabuhan\n");
  printf("\n\tMasukan Hari  : ");
  waktu_tiba.tm_mday = input_hari();
  printf("\n\tMasukan Bulan : ");
  waktu_tiba.tm_mon = input_bulan();
  printf("\n\tMasukan Tahun : ");
  waktu_tiba.tm_year = input_int();

  if (cost < 3)
  {
    bea_masuk_persen = 0;
    ppn_persen = 0.1;
  }
  else
  {
    bea_masuk_persen = 0.075;
    ppn_persen = 0.1;

    if (jenis_barang == 1)
      bea_masuk_persen = 0.25;
    else if (jenis_barang == 2)
      bea_masuk_persen = 0.2;
    else if (jenis_barang == 3)
      bea_masuk_persen = 0.3;
    else if (jenis_barang == 4)
    {
      bea_masuk_persen = 0;
      ppn_persen = 0;
      pph22_persen = 0;
    }
  }

  printf("\n\tSelisih Hari : %d", selisih_hari);
  pabean = (cost + insurance + freight) * kurs_dollar;
  bea_masuk = bea_masuk_persen * pabean;
  ppn_pajak = ppn_persen * (cost * kurs_dollar);
  pph22 = pph22_persen * (cost * kurs_dollar);
  total_pajak = bea_masuk + ppn_pajak + pph22;

  printf("\n\n\t--------------------------------------------------------\n");
  printf("\n\tPajak Impor                       : Rp.%.0f", total_pajak);
  if (selisih_hari > 7)
  {
    if (selisih_hari > 14)
      denda = total_pajak * 0.2;
    else
      denda = total_pajak * 0.1;

    printf("\n\tDenda                             : Rp.%.0f", denda);
  }
  printf("\n\tJumlah nominal yang harus dibayar : Rp.%.0f\n", total_pajak + denda);
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
    lihat_rincian = input_int();
  }

  if (lihat_rincian == 1)
  {
    system("cls");
    output_impor();
  }
  else
  {
    system("cls");
    impor_menu();
  }
}

void impor_menu()
{
  printf("\n\t=========================================================\n");
  printf("\n\t             Konfirmasi Pembayaran Pajak Impor           \n");
  printf("\n\t=========================================================\n");
  printf("\n\t1. Bayar Pajak Impor");
  printf("\n\t2. Kembali");
  printf("\n\t---------------------------------------------------------\n");
  printf("\n\tPilihan Anda : ");
  menu_impor = input_int();

  switch (menu_impor)
  {
  case 1:
    system("cls");
    impor_hitung();
    break;
  case 2:
    system("cls");
    opsi_pajak();
  default:
    break;
  }
}