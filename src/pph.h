double penghasilan_pokok, // perbulan
    penghasilan_tambahan,
    biaya_jabatan,
    iuran_pensiun,
    bruto,
    netto,
    ptkp = 54000000, // set default
    pkp,
    pph,
    temp1, temp2, temp3, temp4;
int jml_anak = 0, menikah = 1, menu_pph, tarif_persen, lihat_rincian;
char nama_jabatan[100];

void pph_hitung()
{
  printf("\n\t=========================================================\n");
  printf("\n\t              Pembayaran Pajak Penghasilan               \n");
  printf("\n\t=========================================================\n");
  printf("\n\tMasukan Nama Jabatan : ");
  input_str(nama_jabatan);

  printf("\n\tMasukan penghasilan pokok    : Rp.");
  penghasilan_pokok = input_double(penghasilan_pokok);

  printf("\n\tMasukan penghasilan tambahan : Rp.");
  penghasilan_tambahan = input_double(penghasilan_tambahan);

  printf("\n\tApakah Sudah Menikah? [1] Ya [2] Tidak : ");
  printf("\n\tMasukan Pilihan Anda : ");
  menikah = input_int(menikah);

  while (menikah != 1 && menikah != 2)
  {
    printf("\n\tPilihan Anda Salah!");
    printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
    printf("\n\tMasukan Pilihan Anda : ");
    menikah = input_int(menikah);
  }

  if (menikah == 1)
  {
    printf("\n\tMasukan Jumlah Anak : ");
    jml_anak = input_int(jml_anak);
    while (jml_anak < 1)
    {
      printf("\n\tJumlah Anak Tidak Boleh 0!");
      printf("\n\tSilahkan Masukkan Jumlah Anak Kembali!");
      printf("\n\tMasukan Jumlah Anak : ");
      jml_anak = input_int(jml_anak);
    }

    // penghasilan tidak kena pajak
    ptkp += 4500000;

    if (jml_anak > 3)
    {
      jml_anak = 3;
      ptkp += (4500000 * jml_anak);
    }
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

  pph = temp1 + temp2 + temp3 + temp4;

  printf("\n\tPPh Setahun : %.0f", pph);      
  printf("\n\tPPh Sebulan : %.0f", pph / 12); 

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
    output_pph();
  }
}

void pph_menu()
{
  printf("\n\t=========================================================\n");
  printf("\n\t                  Laman Pajak Penghasilan                \n");
  printf("\n\t=========================================================\n");
  printf("\n\t1. Hitung Pajak Penghasilan");
  printf("\n\t2. Kembali");
  printf("\n\t---------------------------------------------------------\n");
  printf("\n\tPilihan Anda : ");
  menu_pph = input_int(menu_pph);

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
    break;
  }
}

void output_pph()
{
    printf("\n\t--------------------+---------------------------------");
    printf("\n\t       *******      |                                 ");
    printf("\n\t     ***********    |     BUKTI PEMBAYARAN PAJAK      ");
    printf("\n\t     *@@     ***    |      PENGHASILAN PASAL 21       ");
    printf("\n\t     &&&     **@    |     BAGI PEGAWAI TETAP ATAU     ");
    printf("\n\t     &&&&&&&&&&&    |    PENERIMA PENSIUN BERKALA.    ");
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
    printf("\n\t Status            : ");
    if (menikah == 1)
      printf("Menikah");
    else if (menikah == 2)
      printf("Lajang");
    printf("\n\t Jumlah Tanggungan : %d", jml_anak);
    printf("\n\t Nama Jabatan      : %s", nama_jabatan);
    printf("\n\t------------------------------------------------------");
    printf("\n");
    printf("\n\tB. RINCIAN PENGHASILAN DAN PERHITUNGAN PPh PASAL 21");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t                  URAIAN               |        JUMLAH       ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t PENGHASILAN BRUTO                                           ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t Penghasilan Pokok                     | Rp.%*.0f", 16, penghasilan_pokok);
    printf("\n\t Penghasilan Lainnya                   | Rp.%*.0f", 16, penghasilan_tambahan);
    printf("\n\t Jumlah Penghasilan Bruto              | Rp.%*.0f", 16, bruto);
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t PENGURANGAN                                                 ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t Biaya Jabatan                         | Rp.%*.0f", 16, biaya_jabatan);
    printf("\n\t Iuran Pensiun                         | Rp.%*.0f", 16, iuran_pensiun);
    printf("\n\t Jumlah Pengurangan                    | Rp.%*.0f", 16, biaya_jabatan + iuran_pensiun);
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t PERHITUNGAN PPh PASAL 21                                    ");
    printf("\n\t---------------------------------------+---------------------");
    printf("\n\t Jumlah Penghasilan Netto              | Rp.%*.0f", 16, netto);
    printf("\n\t Penghasilan Tidak Kena Pajak (PTKP)   | Rp.%*.0f", 16, ptkp);
    printf("\n\t Penghasilan Kena Pajak (PKP)          | Rp.%*.0f", 16, pkp);
    printf("\n\t Besar Tarif Progresif (%%)             | %*d%%", 18, tarif_persen);
    printf("\n\t Total Pajak Penghasilan Setahun       | Rp.%*.0f", 16, pph);
    printf("\n\t---------------------------------------+---------------------");
    printf("\n");
    printf("\n\tC. RINCIAN TRANSAKSI");
    printf("\n\t------------------------------------------------------");
    printf("\n\t Nomor           :");
    printf("\n\t Tahun Pajak     :");
    printf("\n\t Waktu Transaksi :");
    printf("\n\t Status Pajak    : Lunas");
    printf("\n\t Masa Pajak      :");
    printf("\n\t------------------------------------------------------");
}