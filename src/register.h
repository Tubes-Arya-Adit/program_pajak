#include <stdio.h>

void register_menu()
{

  printf("\n\t=========================================================\n");
  printf("\n\t                    Laman Registrasi                     \n");
  printf("\n\t=========================================================\n");
  printf("\n\tMasukkan NPWP          : ");
  input_str(input.npwp);

  while (checkData("npwp", input.npwp) == 0)
  {
    printf("\n\tNPWP sudah terdaftar, masukkan NPWP yang lain!");
    printf("\n\tMasukkan NPWP        : ");
    input_str(input.npwp);
  }

  printf("\n\tMasukkan NIK           : ");
  input_str(input.nik);
  printf("\n\tMasukkan Nama          : ");
  input_str(input.nama);
  printf("\n\tMasukkan Alamat        : ");
  input_str(input.alamat);
  printf("\n\tMasukkan Nomor Telepon : ");
  input_str(input.no_telp);
  while (checkData("no_telp", input.no_telp) == 0)
  {
    printf("\n\tNomor telepon sudah terdaftar, masukkan nomor yang lain!");
    printf("\n\tMasukkan Nomor Telepon : ");
    input_str(input.npwp);
  }

  printf("\n\tMasukkan Username      : ");
  input_str(input.username);
  while (checkData("username", input.username) == 0)
  {
    printf("\n\tUsername sudah terdaftar, masukkan Username yang lain!");
    printf("\n\tMasukkan Username     : ");
    input_str(input.npwp);
  }
  printf("\n\tMasukkan Password      : ");
  input_str(input.password);

  tambahDataPengguna();
  sinkronDataPengguna();

  printf("\n\t----------------------------------------------------------\n");
  printf("\n\t                    Berhasil Register!                     ");
  printf("\n\t                 Tekan enter untuk login                   \n");
  printf("\n\t----------------------------------------------------------\n");
  getch();
  system("cls");
  login_menu(pengguna_login);
}