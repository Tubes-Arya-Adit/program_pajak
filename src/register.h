#include <stdio.h>
#include <stdlib.h>

void register_menu()
{

  printf("\n\t=========================================================\n");
  printf("\n\t                    Laman Registrasi                     \n");
  printf("\n\t=========================================================\n");
  printf("\n\tMasukkan NPWP     : ");
  input_str(input.npwp);
  printf("\n\tMasukkan NIK      : ");
  input_str(input.nik);
  printf("\n\tMasukkan Nama     : ");
  input_str(input.nama);
  printf("\n\tMasukkan Alamat   : ");
  input_str(input.alamat);
  printf("\n\tMasukkan No. Telp : ");
  input_str(input.no_telp);
  printf("\n\tMasukkan Username : ");
  input_str(input.username);
  printf("\n\tMasukkan Password : ");
  input_str(input.password);

  tambahDataPengguna();
  sinkronDataPengguna();

  printf("\n\t----------------------------------------------------------\n");

  system("cls");
  login_menu();
}