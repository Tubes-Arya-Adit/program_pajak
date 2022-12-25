void history()
{
  int index = 0;
  printf("\n\t=========================================================\n");
  printf("\n\t               Lamaan Riwayat Pembayaran                 \n");
  printf("\n\t=========================================================\n");

  printf("\n\tNama    : %s", pengguna_login.nama);
  printf("\n\tNPWP    : %s\n", pengguna_login.npwp);

  printf("\n\t------------------------------------------------------------------------------------------------\n");
  printf("\n\tNo.  |  Jenis Pajak  |    Nominal    |   Denda   |   Total Bayar   |   Tanggal   |    Status    \n");

  for (index; index <= i_trs; index++)
  {
    if (strcmp(trs_pengguna[index].id, pengguna_login.npwp) == 0)
      printf("\n\t%-3d    |  %-5s   |   Rp.%.0f  |   %.0f    |   %.0f    |  %s    |   %s    ", index + 1, trs_pengguna[index].jenis_pajak, trs_pengguna[index].total_pajak, trs_pengguna[index].denda, trs_pengguna[index].jumlah_nominal, trs_pengguna[index].tanggal, trs_pengguna[index].status);
  }

  printf("\n\t-------------------------------------------------------------------------------------------------\n");

  printf("\n\tTekan Enter untuk kembali ke menu utama...");
  getch();
  opsi_pajak();
}