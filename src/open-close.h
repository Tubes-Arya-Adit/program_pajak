
// fungsi pembuka program
void opening()
{
  printf("\n\t=========================================================\n");
  printf("\n\t        Selamat Datang di Aplikasi Pembayaran Pajak     \n");
  printf("\n\t=========================================================\n\n\n");
  loadImage();
  printf("\n\n\n\t      Silahkan Login atau Register Terlebih Dahulu!\n");
  printf("\n\t----------------------------------------------------------\n");
  printf("\n\t              [1] Login           [2] Register\n");
  printf("\n\t----------------------------------------------------------\n");
  printf("\n\tMasukkan Pilihan Anda  : ");
  menu_awal = input_int();
}

// fungsi tampilan keluar pada program pembayaran pajak
void closing()
{
  system("cls");
  printf("\n\t=========================================================\n");
  printf("\n\t            Keluar dari Program Pembayaran Pajak    \n");
  printf("\n\t=========================================================\n\n\n");
  loadImage();
  printf("\n\n\n\t      Terima kasih telah membayar pajak tepat waktu\n");
  printf("\n\t                 \"Pajak Kita, Untuk Kita\"\n");
  printf("\n\t=========================================================\n\n\n");
  getch();
  exit(0);
}