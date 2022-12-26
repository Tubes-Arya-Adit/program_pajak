double penghasilan_pokok, // perbulan
    penghasilan_tambahan,
    biaya_jabatan,
    iuran_pensiun,
    bruto,
    netto,
    ptkp = 54000000, // set default
    pkp,
    pph,
    denda = 0,
    temp1, temp2, temp3, temp4;
int jml_anak = 0, menikah = 1, menu_pph, tarif_persen, lihat_rincian, tgl_bayar, bln_bayar, thn_bayar;
char nama_jabatan[100], status[100];

void pph_menu();

void output_pph()
{
  char filename[100];
  sprintf(filename, "%s-bukti-bayar-pph-%d-%02d-%02d-%02d-%02d.txt", pengguna_login.npwp, waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit);

  FILE *file = fopen(filename, "a");
  if (file)
  {
    fprintf(file, "\n\t--------------------+----------------------------------------");
    fprintf(file, "\n\t       *******      |                                        ");
    fprintf(file, "\n\t     ***********    |        BUKTI PEMBAYARAN PAJAK          ");
    fprintf(file, "\n\t     *@@     ***    |         PENGHASILAN PASAL 21           ");
    fprintf(file, "\n\t     &&&     **@    |        BAGI PEGAWAI TETAP ATAU         ");
    fprintf(file, "\n\t     &&&&&&&&&&&    |       PENERIMA PENSIUN BERKALA         ");
    fprintf(file, "\n\t       &&&&&&&      |                                        ");
    fprintf(file, "\n\t--------------------+----------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tA. IDENTITAS WAJIB PAJAK");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t NPWP              : %s", pengguna_login.npwp);
    fprintf(file, "\n\t NIK               : %s", pengguna_login.nik);
    fprintf(file, "\n\t Nama              : %s", pengguna_login.nama);
    fprintf(file, "\n\t Alamat            : %s", pengguna_login.alamat);
    fprintf(file, "\n\t No. Telp          : %s", pengguna_login.no_telp);
    fprintf(file, "\n\t Status            : ");
    if (menikah == 1)
      fprintf(file, "Menikah");
    else if (menikah == 2)
      fprintf(file, "Lajang");
    fprintf(file, "\n\t Jumlah Tanggungan : %d", jml_anak);
    fprintf(file, "\n\t Nama Jabatan      : %s", nama_jabatan);
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tB. RINCIAN PENGHASILAN DAN PERHITUNGAN PPh PASAL 21");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t                  URAIAN               |        JUMLAH       ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t PENGHASILAN BRUTO                                           ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t Penghasilan Pokok                     | Rp.%*.0f", 16, penghasilan_pokok);
    fprintf(file, "\n\t Penghasilan Lainnya                   | Rp.%*.0f", 16, penghasilan_tambahan);
    fprintf(file, "\n\t Jumlah Penghasilan Bruto              | Rp.%*.0f", 16, bruto);
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t PENGURANGAN                                                 ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t Biaya Jabatan                         | Rp.%*.0f", 16, biaya_jabatan);
    fprintf(file, "\n\t Iuran Pensiun                         | Rp.%*.0f", 16, iuran_pensiun);
    fprintf(file, "\n\t Jumlah Pengurangan                    | Rp.%*.0f", 16, biaya_jabatan + iuran_pensiun);
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t PERHITUNGAN PPh PASAL 21                                    ");
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n\t Penghasilan Netto Setahun             | Rp.%*.0f", 16, netto);
    fprintf(file, "\n\t Penghasilan Tidak Kena Pajak (PTKP)   | Rp.%*.0f", 16, ptkp);
    fprintf(file, "\n\t Penghasilan Kena Pajak (PKP)          | Rp.%*.0f", 16, pkp);
    fprintf(file, "\n\t Besar Tarif Progresif (%%)             | %*d%%", 18, tarif_persen);
    fprintf(file, "\n\t PPh 21 Setahun                        | Rp.%*.0f", 16, pph * 12);
    fprintf(file, "\n\t PPh 21 Sebulan                        | Rp.%*.0f", 16, pph);
    fprintf(file, "\n\t Denda                                 | Rp.%*.0f", 16, denda);
    fprintf(file, "\n\t Total PPh 21 Yang Perlu Di Bayar      | Rp.%*.0f", 16, pph + denda);
    fprintf(file, "\n\t---------------------------------------+---------------------");
    fprintf(file, "\n");
    fprintf(file, "\n\tC. RINCIAN TRANSAKSI");
    fprintf(file, "\n\t-------------------------------------------------------------");
    fprintf(file, "\n\t Tahun Pajak     : %02d", waktu_sekarang.tahun);
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
  pph_menu();
}

void pph_hitung()
{
  printf("\n\t=========================================================\n");
  printf("\n\t              Pembayaran Pajak Penghasilan               \n");
  printf("\n\t=========================================================\n");
  printf("\n\tMasukan Nama Jabatan : ");
  input_str(nama_jabatan);

  printf("\n\tMasukan penghasilan pokok    : Rp.");
  penghasilan_pokok = input_double();

  printf("\n\tMasukan penghasilan tambahan : Rp.");
  penghasilan_tambahan = input_double();

  printf("\n\tApakah Sudah Menikah? \n\t[1] Ya [2] Tidak");
  printf("\n\tMasukan Pilihan Anda : ");
  menikah = input_int();

  while (menikah != 1 && menikah != 2)
  {
    printf("\n\tPilihan Anda Salah!");
    printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
    printf("\n\tMasukan Pilihan Anda : ");
    menikah = input_int();
  }

  if (menikah == 1)
  {
    ptkp += 4500000; // ptkp ditambah 4.5jt jika sudah menikah

    printf("\n\tMasukan Jumlah Anak : ");
    jml_anak = input_int();
    while (jml_anak < 1)
    {
      printf("\n\tJumlah Anak Tidak Boleh 0!");
      printf("\n\tSilahkan Masukkan Jumlah Anak Kembali!");
      printf("\n\tMasukan Jumlah Anak : ");
      jml_anak = input_int();
    }

    if (jml_anak > 3)
    {
      jml_anak = 3;
      ptkp += (4500000 * jml_anak);
    }
  }

  printf("\n\tTanggal Pegawai Menerima Gaji ");
  printf("\n\tMasukan Hari  : ");
  tgl_bayar = input_hari();
  printf("\n\tMasukan Bulan : ");
  bln_bayar = input_bulan();
  printf("\n\tMasukan Tahun : ");
  thn_bayar = input_int();

  bln_bayar + 1;

  if (bln_bayar == 12)
  {
    bln_bayar = 1;
    thn_bayar += 1;
  }

  bruto = penghasilan_pokok + penghasilan_tambahan;

  biaya_jabatan = 0.05 * bruto;

  if (biaya_jabatan > 500000)
    biaya_jabatan = 500000;

  iuran_pensiun = 0.05 * bruto;

  if (iuran_pensiun > 200000)
    iuran_pensiun = 200000;

  // netto dalam sebulan
  netto = bruto - (biaya_jabatan + iuran_pensiun);
  // netto dalam setahub
  netto *= 12;

  // penghasilan kena pajak
  pkp = netto - ptkp;
  if (pkp < 0)
    pkp = 0;

  // PPh berdasarkan tarif progresif
  if (pkp <= 50000000)
  {
    tarif_persen = 5;
    temp1 = pkp * 0.05;
  }
  else if (pkp > 50000000 && pkp <= 250000000)
  {
    tarif_persen = 15;
    temp1 = 50000000 * 0.05;
    temp2 = (pkp - 50000000) * 0.15;
  }
  else if (pkp > 250000000 && pkp <= 500000000)
  {
    tarif_persen = 25;
    temp1 = 50000000 * 0.05;
    temp2 = (pkp - 50000000) * 0.15;
    temp3 = (pkp - 250000000) * 0.25;
  }
  else if (pkp > 500000000)
  {
    tarif_persen = 30;
    temp1 = 50000000 * 0.05;
    temp2 = (pkp - 50000000) * 0.15;
    temp3 = (pkp - 250000000) * 0.25;
    temp4 = (pkp - 500000000) * 0.30;
  }

  pph = (temp1 + temp2 + temp3 + temp4) / 12;

  struct tm due_date = {.tm_sec = 0,
                        .tm_min = 0,
                        .tm_hour = 0,
                        .tm_mday = 10,
                        .tm_mon = bln_bayar - 1,
                        .tm_year = thn_bayar - 1900,
                        .tm_isdst = 0};

  time_t jatuh_tempo = mktime(&due_date);

  denda = 0;

  printf("\n\t--------------------------------------------------------\n");
  printf("\n\tPPh Sebulan                       : Rp.%.0f", pph);

  if (current > jatuh_tempo)
  {
    int selisih_bulan = waktu_sekarang.bulan - bln_bayar;
    if (selisih_bulan <= 0)
      selisih_bulan = 1;
    denda = (pph * 0.02) * selisih_bulan;

    printf("\n\tDenda                             : Rp.%.0f", denda);
  }

  printf("\n\tJumlah nominal yang harus dibayar : Rp.%.0f\n", pph + denda);
  printf("\n\t--------------------------------------------------------\n");

  if (denda == 0)
    strcpy(status, "Tepat Waktu");
  else
    strcpy(status, "Terlambat");

  strcpy(trs_input.id, pengguna_login.npwp);
  strcpy(trs_input.jenis_pajak, "PPh");
  trs_input.total_pajak = pph;
  trs_input.denda = denda;
  trs_input.jumlah_nominal = pph + denda;
  sprintf(trs_input.tanggal, "%d-%02d-%02d %02d:%02d:%02d", waktu_sekarang.hari, waktu_sekarang.bulan, waktu_sekarang.tahun, waktu_sekarang.jam, waktu_sekarang.menit, waktu_sekarang.detik);
  strcpy(trs_input.status, status);

  tambahDataTransaksi();
  sinkronDataTransaksi();

  printf("\n\n\tLihat rincian pembayaran?\n");
  printf("\n\t[1] Ya    [2] Tidak \n");
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
    output_pph();
  }
  else
  {
    system("cls");
    pph_menu();
  }
}

void pph_menu()
{
  printf("\n\t=========================================================\n");
  printf("\n\t          Konfirmasi Pembayaran Pajak Penghasilan        \n");
  printf("\n\t=========================================================\n");
  printf("\n\t1. Bayar Pajak Penghasilan");
  printf("\n\t2. Kembali");
  printf("\n\t---------------------------------------------------------\n");

  printf("\n\tPilihan Anda : ");
  menu_pph = input_int();

  while (menu_pph != 1 && menu_pph != 2)
  {
    printf("\n\tPilihan Anda Salah!");
    printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
    printf("\n\tPilihan Anda : ");
    menu_pph = input_int();
  }

  switch (menu_pph)
  {
  case 1:
    system("cls");
    pph_hitung();
    break;
  case 2:
    system("cls");
    opsi_pajak();
  default:
    printf("\n\tPilihan Anda Salah!");
    break;
  }
}