double njop,
    njkp,
    luas_tanah,
    luas_bangunan,
    nilai_tanah_meter,
    nilai_bangunan_meter,
    nilai_tanah,
    nilai_bangunan,
    pbb;
int menu_pbb, sektor;

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

  printf("\n\tMasukan luas tanah : ");
  luas_tanah = input_double(luas_tanah);

  printf("\n\tMasukan luas bangunan : ");
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