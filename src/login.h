#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login_menu()
{
  char temp_username[100], temp_password[100];
  int check_username, check_password;

  while (1)
  {
    printf("\n\t=========================================================\n");
    printf("\n\t                        Laman Login                      \n");
    printf("\n\t=========================================================\n");

    printf("\n\tUsername : ");
    input_str(temp_username);
    check_username = checkData("username", temp_username);

    pindahData(temp_username);
    printf("%s#%s#%s#%s#%s#%s#%s\n", pengguna_login.nama, pengguna_login.alamat, pengguna_login.no_telp, pengguna_login.username, pengguna_login.password, pengguna_login.npwp, pengguna_login.nik);

    printf("\n\tPassword : ");
    input_str(temp_password);

    check_password = strcmp(pengguna_login.password, temp_password);

    if (check_username == 0 && check_password == 0)
    {
      printf("\n\t----------------------------------------------------------\n");
      printf("\n\tLogin berhasil");
      system("cls");
      break;
    }
    else
    {
      printf("\n\t----------------------------------------------------------\n");
      printf("\n\tLogin gagal, masukan username & password dengan benar!");
      printf("\tTekan enter untuk mengulang");
      system("cls");
    }
  }
}