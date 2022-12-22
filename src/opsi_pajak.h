void pph_menu(), pbb_menu(), ppn_menu();

void opsi_pajak()
{
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
  printf("\n\t [7] Tentang Kami                               \n");
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
    pph_menu();
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
    pph_menu();
    break;
  case 8:
    exit(1);
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