
// Untuk menampilkan info data pribadi pengguna
void info_pengguna()
{
  printf("\n\t==========================================================\n");
  printf("\n\t                    Info Data Pribadi Anda               \n");
  printf("\n\t==========================================================\n");

  printf("\n\tNPWP           : %s \n", pengguna_login.npwp);
  printf("\n\tNIK            : %s \n", pengguna_login.nik);
  printf("\n\tNama Lengkap   : %s \n", pengguna_login.nama);
  printf("\n\tAlamat         : %s \n", pengguna_login.alamat);
  printf("\n\tNo. Telepon    : %s \n", pengguna_login.no_telp);
  printf("\n\tUsername       : %s \n", pengguna_login.username);
  printf("\n\tPassword       : %s \n", pengguna_login.password);

  printf("\n\tTekan Enter untuk kembali ke menu utama...");
  getch();
  opsi_pajak();
}