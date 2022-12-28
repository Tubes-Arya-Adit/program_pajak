void pph_menu(), pbb_menu(), ppn_menu(), impor_menu(), pkb_menu(), profil(), info_pengguna(), history();

// Fungsi menu utama program pembayaran pajak
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
  printf("\n\t [5] Pembayaran Pajak Kendaraan             \n");
  printf("\n\t----------------------------------------------------------\n");
  printf("\n\t [6] Lihat Riwayat Pembayaran                              \n");
  printf("\n\t [7] Lihat Data Anda                               \n");
  printf("\n\t [8] Profil Dirjen Pajak                               \n");
  printf("\n\t [9] Keluar                               \n");
  printf("\n\t----------------------------------------------------------\n");
  printf("\n\tPilihan Anda : ");
  menu_opsi_pajak = input_int();

  while (menu_opsi_pajak < 1 || menu_opsi_pajak > 9)
  {
    printf("\n\tPilihan Anda Salah!");
    printf("\n\tSilahkan Masukkan Pilihan Anda Kembali!");
    printf("\n\tPilihan Anda : ");
    menu_opsi_pajak = input_int();
  }

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
    pkb_menu();
    break;
  case 6:
    system("cls");
    history();
    break;
  case 7:
    system("cls");
    info_pengguna();
    break;
  case 8:
    system("cls");
    profil();
    break;
  case 9:
    closing();
    break;
  default:
    printf("\n\tNilai yang Anda masukkan salah!");
    break;
  }
}

// fungsi untuk menampilkan profil dirjen pajak dengan membuka halaman website
void profil()
{
  int menu_profil;
  printf("\n\t==========================================================\n");
  printf("\n\t                    Profil Dirjen Pajak                \n");
  printf("\n\t==========================================================\n");
  printf("\n\tMembuka halaman website...\n");

  system("start https://pajak.go.id/id/selayang-pandang/");

  printf("\n\tTekan enter untuk kembali ke menu utama\n");
  printf("\n\t----------------------------------------------------------\n");
  fflush(stdin);
  getch();
  opsi_pajak();
}