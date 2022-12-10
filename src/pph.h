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
int jml_anak = 0, menikah = 1, menu_pph;

void pph_hitung()
{
  printf("\n\t=========================================================\n");
  printf("\n\t              Pembayaran Pajak Penghasilan               \n");
  printf("\n\t=========================================================\n");
  printf("\n\tMasukan penghasilan pokok  : Rp.");
  penghasilan_pokok = input_double(penghasilan_pokok);
  printf("\n\tMasukan penghasilan tambahan  : Rp.");
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
    temp1 = pkp * 0.05;
  }
  else if (pkp > 50000000 && pkp <= 250000000)
  {
    temp1 = 50000000 * 0.05;
    temp2 = (pkp - 50000000) * 0.15;
  }
  else if (pkp > 250000000 && pkp <= 500000000)
  {
    temp1 = 50000000 * 0.05;
    temp2 = (pkp - 50000000) * 0.15;
    temp3 = (pkp - 250000000) * 0.25;
  }
  else if (pkp > 500000000)
  {
    temp1 = 50000000 * 0.05;
    temp2 = (pkp - 50000000) * 0.15;
    temp3 = (pkp - 250000000) * 0.25;
    temp4 = (pkp - 500000000) * 0.30;
  }

  pph = temp1 + temp2 + temp3 + temp4;

  printf("\n\n\tpph setahun = %.0f", pph);    // check
  printf("\n\tpph sebulan = %.0f", pph / 12); // check
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