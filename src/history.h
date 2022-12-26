void history()
{
  printf("\n\t=========================================================\n");
  printf("\n\t               Lamaan Riwayat Pembayaran                 \n");
  printf("\n\t=========================================================\n");

  printf("\n\tNama    : %s", pengguna_login.nama);
  printf("\n\tNPWP    : %s\n", pengguna_login.npwp);

  printf("\n\t------------------------------------------------------------------------------------------------------------");
  printf("\n\tJenis Pajak  |     Nominal     |     Denda      |    Total Bayar    |       Tanggal        |     Status    ");
  printf("\n\t------------------------------------------------------------------------------------------------------------");

  // Memnampilkan data riwayat transaksi berdasarkan NPWP pengguna
  for (int index = 0; index <= i_trs; index++)
  {
    if (strcmp(trs_pengguna[index].id, pengguna_login.npwp) == 0)
      printf("\n\t%-12s | Rp.%12.0f | Rp.%11.0f | Rp.%14.0f | %-20s | %11s ", trs_pengguna[index].jenis_pajak, trs_pengguna[index].total_pajak, trs_pengguna[index].denda, trs_pengguna[index].jumlah_nominal, trs_pengguna[index].tanggal, trs_pengguna[index].status);
  }

  printf("\n\t------------------------------------------------------------------------------------------------------------\n");

  printf("\n\tTekan Enter untuk kembali ke menu utama...");
  getch();
  opsi_pajak();
}