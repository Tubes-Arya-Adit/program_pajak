void pph_menu(), pbb_menu(), ppn_menu(), impor_menu(), profil();

void opsi_pajak()
{
  system("cls");
  printf("\n\t==========================================================\n");
  printf("\n\t            Program Pembayaran Pajak Online               \n");
  printf("\n\t==========================================================\n");
  printf("\n\t [1] Pembayaran Pajak Penghasilan (PPh)                   \n");
  printf("\n\t [2] Pembayaran Pajak Pertambahan Nilai (PPN)             \n");
  printf("\n\t [3] Pembayaran Pajak Bumi dan Bangunan (PBB)             \n");
  printf("\n\t [4] Pembayaran Pajak Impor             \n");
  printf("\n\t----------------------------------------------------------\n");
  printf("\n\t [5] Lihat Riwayat Pembayaran                              \n");
  printf("\n\t [6] Lihat Data Anda                               \n");
  printf("\n\t [7] Profil Dirjen Pajak                               \n");
  printf("\n\t [8] Keluar                               \n");
  printf("\n\t----------------------------------------------------------\n");
  printf("\n\tPilihan Anda : ");
  menu_opsi_pajak = input_int(menu_opsi_pajak);
  switch (menu_opsi_pajak)
  {
  case 1:
    system("cls");
    pph_menu();
    break;
  case 2:
    system("cls");
    ppn_menu();
    break;
  case 3:
    system("cls");
    pbb_menu();
    break;
  case 4:
    system("cls");
    impor_menu();
    break;
  case 5:
    system("cls");
    pph_menu();
    break;
  case 6:
    system("cls");
    pph_menu();
    break;
  case 7:
    system("cls");
    profil();
    break;
  case 8:
    closing();
    break;
  default:
    printf("\n\tNilai yang Anda masukkan salah!");
    printf("\n\tSilahkan masukkan nilai yang benar!");
    printf("\n\tPilihan Anda : ");
    menu_opsi_pajak = input_int(menu_opsi_pajak);
    system("cls");
    break;
  }
}

void profil()
{
  int menu_profil;
  printf("\n\t==========================================================\n");
  printf("\n\t                    Profil Dirjen Pajak                \n");
  printf("\n\t==========================================================\n");
  printf("\n\tMembuka halaman website......\n");

  system("start https://pajak.go.id/id/selayang-pandang/");

  printf("\n\tTekan enter untuk kembali ke menu utama\n");
  printf("\n\t----------------------------------------------------------\n");
  fflush(stdin);
  getch();
  opsi_pajak();
}