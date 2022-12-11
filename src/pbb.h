double njop,
    njkp,
    luas_tanah,
    luas_bangunan,
    nilai_tanah_meter,
    nilai_bangunan_meter,
    nilai_tanah,
    nilai_bangunan,
    pbb,
    njoptkp = 0;
int menu_pbb, sektor, lihat_rincian;
char lokasi[100], provinsi[100], kota_kabupaten[100], kecamatan[100], kelurahan_desa[100];

void pbb_hitung()
{
  printf("\n\t=========================================================\n");
  printf("\n\t           Pembayaran Pajak Bumi dan Bangunan            \n");
  printf("\n\t=========================================================\n");
  printf("\n\tSektor Objek Pajak ");
  printf("\n\t[1] Perkebunan");
  printf("\n\t[2] Pertanian");
  printf("\n\t[3] Pertambangan");
  printf("\n\t[4] Pedesaan dan Perkotaan");
  printf("\n\tPilih Sektor Objek Pajak : ");
  sektor = input_int(sektor);

  printf("\n\tMasukan Alamat Objek Pajak : ");
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
  luas_tanah = input_double(luas_tanah);

  printf("\n\tMasukan luas bangunan (M2) : ");
  luas_bangunan = input_double(luas_bangunan);

  printf("\n\tMasukan nilai tanah per meter persegi : Rp.");
  nilai_tanah_meter = input_double(nilai_tanah_meter);

  printf("\n\tMasukan nilai bangunan per meter persegi : Rp.");
  nilai_bangunan_meter = input_double(nilai_bangunan_meter);

  nilai_tanah = luas_tanah * nilai_tanah_meter;
  nilai_bangunan = luas_bangunan * nilai_bangunan_meter;

  njop = nilai_tanah + nilai_bangunan;

  if (sektor < 4)
    njkp = 0.4 * njop;

  njkp = njop > 1000000000 ? 0.4 * njop : 0.2 * njop;

  printf("\n\tNKJP : Rp.%.0f", njkp);

  pbb = 0.005 * njkp;

  printf("\n\tPBB : Rp.%.0f", pbb);

  printf("\n\n\tLihat rincian pembayaran? [1] Ya [2] Tidak : ");
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
    output_pbb();
  }
}

void pbb_menu()
{
  printf("\n\t=========================================================\n");
  printf("\n\t              Laman Pajak Bumi dan Bangunan              \n");
  printf("\n\t=========================================================\n");
  printf("\n\t1. Hitung Pajak Bumi dan Bangunan");
  printf("\n\t2. Kembali");
  printf("\n\t---------------------------------------------------------\n");
  printf("\n\tPilihan Anda : ");
  menu_pbb = input_int(menu_pbb);

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
    break;
  }
}

void output_pbb()
{
    printf("\n\t--------------------+---------------------------------");
    printf("\n\t       *******      |                                 ");
    printf("\n\t     ***********    |         BUKTI PEMBAYARAN        ");
    printf("\n\t     *@@     ***    |         LUNAS PAJAK BUMI        ");
    printf("\n\t     &&&     **@    |           DAN BANGUNAN          ");
    printf("\n\t     &&&&&&&&&&&    |         NEGARA INDONESIA        ");
    printf("\n\t       &&&&&&&      |                                 ");
    printf("\n\t--------------------+---------------------------------");
    printf("\n");
    printf("\n\tA. IDENTITAS WAJIB PAJAK");
    printf("\n\t------------------------------------------------------");
    printf("\n\t NPWP              :");
    printf("\n\t NIK               :");
    printf("\n\t Nama              :");
    printf("\n\t Alamat            :");
    printf("\n\t No. Telp          :");
    printf("\n\t------------------------------------------------------");
    printf("\n");
    printf("\n\tB. LETAK OBJEK PAJAK");
    printf("\n\t------------------------------------------------------");
    printf("\n\t Sektor         : ");
    if (sektor == 1)
      printf("Perkebunan");
    else if (sektor == 2)
      printf("Pertanian");
    else if (sektor == 3)
      printf("Pertambangan");
    else if (sektor == 4)
      printf("Pedesaan dan Perkotaan");
    printf("\n\t Lokasi         : %s", lokasi);
    printf("\n\t Provinsi       : %s", provinsi);
    printf("\n\t Kota/Kabupaten : %s", kota_kabupaten);
    printf("\n\t Kecamatan      : %s", kecamatan);
    printf("\n\t Kelurahan/Desa : %s", kelurahan_desa);
    printf("\n\t------------------------------------------------------");
    printf("\n");
    printf("\n\tC. RINCIAN OBJEK PAJAK DAN PERHITUNGAN PBB");    
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t                  URAIAN               |        JUMLAH       ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t BUMI                                                        ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t Luas (M2)                             | %*.0lf M2", 16, luas_tanah);
    printf("\n\t Kelas                                 | ");
    printf("\n\t NJOP per M2                           | Rp.%*.0lf", 16, nilai_tanah_meter);
    printf("\n\t Total NJOP Bumi                       | Rp.%*.0lf", 16, nilai_tanah);
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t BANGUNAN                                                    ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t Luas (M2)                             | %*.0lf M2", 16, luas_bangunan);
    printf("\n\t Kelas                                 | ");
    printf("\n\t NJOP per M2                           | Rp.%*.0lf", 16, nilai_bangunan_meter);
    printf("\n\t Total NJOP Bangunan                   | Rp.%*.0lf", 16, nilai_bangunan);
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t PERHITUNGAN PBB                                             ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t NJOP sebagai dasar pengenaan PBB      | Rp.%*.0lf", 16, njop);
    printf("\n\t NJOPTKP (NJOP Tidak Kena Pajak)       | Rp.%*.0lf", 16, njoptkp);
    printf("\n\t NJOP untuk penghitungan PBB           | Rp.%*.0lf", 16, njop - njoptkp);
    printf("\n\t Total Pajak Bumi Bangunan             | Rp.%*.0lf", 16, pbb);
    printf("\n\t---------------------------------------+---------------------");
    printf("\n");
    printf("\n\tD. RINCIAN TRANSAKSI");
    printf("\n\t------------------------------------------------------");
    printf("\n\t Nomor           :");
    printf("\n\t Tahun Pajak     :");
    printf("\n\t Waktu Transaksi :");
    printf("\n\t Status Pajak    : Lunas");
    printf("\n\t Masa Pajak      :");
    printf("\n\t------------------------------------------------------");
}