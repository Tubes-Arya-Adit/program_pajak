double njop,
    njkp,
    luas_tanah,
    luas_bangunan,
    nilai_tanah_meter,
    nilai_bangunan_meter,
    nilai_tanah,
    nilai_bangunan,
    pbb,
    denda,
    njoptkp = 0;
int menu_pbb, sektor, lihat_rincian;
char lokasi[100], provinsi[100], kota_kabupaten[100], kecamatan[100], kelurahan_desa[100], status[100];

void pbb_menu();

void output_pbb()
{
  char filename[100];
  sprintf(filename, "%s-bukti-bayar-pbb-%d-%02d-%02d-%02d-%02d.txt", pengguna_login.npwp, waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit);

  FILE *file = fopen(filename, "a");
  if (file)
  {
    fprintf(file, "\n\t--------------------+----------------------------------------");
    fprintf(file, "\n\t       *******      |                                        ");
    fprintf(file, "\n\t     ***********    |             BUKTI PEMBAYARAN           ");
    fprintf(file, "\n\t     *@@     ***    |             LUNAS PAJAK BUMI           ");
    fprintf(file, "\n\t     &&&     **@    |               DAN BANGUNAN             ");
    fprintf(file, "\n\t     &&&&&&&&&&&    |             NEGARA INDONESIA           ");
    fprintf(file, "\n\t       &&&&&&&      |                                        ");
    fprintf(file, "\n\t--------------------+----------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tA. IDENTITAS WAJIB PAJAK");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t NPWP           : %s", pengguna_login.npwp);
    fprintf(file, "\n\t NIK            : %s", pengguna_login.nik);
    fprintf(file, "\n\t Nama           : %s", pengguna_login.nama);
    fprintf(file, "\n\t Alamat         : %s", pengguna_login.alamat);
    fprintf(file, "\n\t No. Telp       : %s", pengguna_login.no_telp);
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tB. LETAK OBJEK PAJAK");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t Sektor         : ");
    if (sektor == 1)
      fprintf(file, "Perkebunan");
    else if (sektor == 2)
      fprintf(file, "Pertanian");
    else if (sektor == 3)
      fprintf(file, "Pertambangan");
    else if (sektor == 4)
      fprintf(file, "Pedesaan dan Perkotaan");
    fprintf(file, "\n\t Lokasi         : %s", lokasi);
    fprintf(file, "\n\t Provinsi       : %s", provinsi);
    fprintf(file, "\n\t Kota/Kabupaten : %s", kota_kabupaten);
    fprintf(file, "\n\t Kecamatan      : %s", kecamatan);
    fprintf(file, "\n\t Kelurahan/Desa : %s", kelurahan_desa);
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tC. RINCIAN OBJEK PAJAK DAN PERHITUNGAN PBB");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t                  URAIAN               |        JUMLAH       ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t BUMI                                                        ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t Luas (M2)                             | %*.0f M2", 16, luas_tanah);
    fprintf(file, "\n\t NJOP per M2                           | Rp.%*.0f", 16, nilai_tanah_meter);
    fprintf(file, "\n\t Total NJOP Bumi                       | Rp.%*.0f", 16, nilai_tanah);
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t BANGUNAN                                                    ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t Luas (M2)                             | %*.0f M2", 16, luas_bangunan);
    fprintf(file, "\n\t NJOP per M2                           | Rp.%*.0f", 16, nilai_bangunan_meter);
    fprintf(file, "\n\t Total NJOP Bangunan                   | Rp.%*.0f", 16, nilai_bangunan);
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t PERHITUNGAN PBB                                             ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t NJOP sebagai dasar pengenaan PBB      | Rp.%*.0f", 16, njop);
    fprintf(file, "\n\t NJOPTKP (NJOP Tidak Kena Pajak)       | Rp.%*.0f", 16, njoptkp);
    fprintf(file, "\n\t NJOP untuk penghitungan PBB           | Rp.%*.0f", 16, njop - njoptkp);
    fprintf(file, "\n\t PBB                                   | Rp.%*.0f", 16, pbb);
    fprintf(file, "\n\t Denda                                 | Rp.%*.0f", 16, denda);
    fprintf(file, "\n\t Total Pajak Bumi Bangunan             | Rp.%*.0f", 16, pbb + denda);
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tD. RINCIAN TRANSAKSI");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t Tahun Pajak     : %02d", waktu_sekarang.tahun);
    fprintf(file, "\n\t Tenggat         : 30 September");
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
  pbb_menu();
}

void pbb_hitung()
{
  printf("\n\t=========================================================\n");
  printf("\n\t           Pembayaran Pajak Bumi dan Bangunan            \n");
  printf("\n\t=========================================================\n");
  printf("\n\tSektor objek pajak ");
  printf("\n\t[1] Perkebunan");
  printf("\n\t[2] Pertanian");
  printf("\n\t[3] Pertambangan");
  printf("\n\t[4] Pedesaan dan Perkotaan");
  printf("\n\tPilih Sektor Objek Pajak : ");
  sektor = input_int();

  printf("\n\tMasukan alamat objek pajak : ");
  input_str(lokasi);

  printf("\n\tMasukan Provinsi : ");
  input_str(provinsi);

  printf("\n\tMasukan Kabupaten/Kota : ");
  input_str(kota_kabupaten);

  printf("\n\tMasukan Kecamatan : ");
  input_str(kecamatan);

  printf("\n\tMasukan Kelurahan/Desa : ");
  input_str(kelurahan_desa);

  printf("\n\tMasukan luas tanah (M2) : ");
  luas_tanah = input_double();

  printf("\n\tMasukan luas bangunan (M2) : ");
  luas_bangunan = input_double();

  printf("\n\tMasukan nilai tanah per meter persegi : Rp.");
  nilai_tanah_meter = input_double();

  printf("\n\tMasukan nilai bangunan per meter persegi : Rp.");
  nilai_bangunan_meter = input_double();

  nilai_tanah = luas_tanah * nilai_tanah_meter;
  nilai_bangunan = luas_bangunan * nilai_bangunan_meter;

  njop = nilai_tanah + nilai_bangunan;

  if (sektor < 4)
    njkp = 0.4 * njop;

  njkp = njop > 1000000000 ? 0.4 * njop : 0.2 * njop;

  pbb = 0.005 * njkp;

  struct tm due_date = {.tm_sec = 0,
                        .tm_min = 0,
                        .tm_hour = 0,
                        .tm_mday = 30,
                        .tm_mon = 9 - 1,
                        .tm_year = waktu_sekarang.tahun - 1900,
                        .tm_isdst = 0};

  time_t jatuh_tempo = mktime(&due_date);

  denda = 0;

  printf("\n\t-----------------------------------------------------------\n");
  printf("\n\tNJOP                              : Rp.%.0f", njop);
  printf("\n\tPBB                               : Rp.%.0f", pbb);
  if (current > jatuh_tempo)
  {
    int selisih_bulan = waktu_sekarang.bulan - 9;
    if (selisih_bulan <= 0)
      selisih_bulan = 1;
    denda = (pbb * 0.02) * selisih_bulan;

    printf("\n\tDenda                             : Rp.%.0f", denda);
  }
  printf("\n\tJumlah nominal yang harus dibayar : Rp.%.0f\n", pbb + denda);
  printf("\n\t-----------------------------------------------------------");

  if (denda == 0)
    strcpy(status, "Tepat Waktu");
  else
    strcpy(status, "Terlambat");

  strcpy(trs_input.id, pengguna_login.npwp);
  strcpy(trs_input.jenis_pajak, "PBB");
  trs_input.total_pajak = pbb;
  trs_input.denda = denda;
  trs_input.jumlah_nominal = pbb + denda;
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
    output_pbb();
  }
  else
  {
    system("cls");
    pbb_menu();
  }
}

void pbb_menu()
{
  printf("\n\t=========================================================\n");
  printf("\n\t      Konfirmasi Pembayaran Pajak Bumi dan Bangunan      \n");
  printf("\n\t=========================================================\n");
  printf("\n\t1. Bayar Pajak Bumi dan Bangunan");
  printf("\n\t2. Kembali");
  printf("\n\t---------------------------------------------------------\n");
  printf("\n\tPilihan Anda : ");
  menu_pbb = input_int();

  while (menu_pbb != 1 && menu_pbb != 2)
  {
    printf("\n\tPilihan Anda Salah!");
    printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
    printf("\n\tMasukan Pilihan Anda : ");
    menu_pbb = input_int();
  }

  switch (menu_pbb)
  {
  case 1:
    system("cls");
    pbb_hitung();
    break;
  case 2:
    system("cls");
    opsi_pajak();
  default:
    printf("\n\tPilihan Anda Salah!");
    break;
  }
}