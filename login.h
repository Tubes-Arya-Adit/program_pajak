#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login_menu(struct Pengguna input)
{
  char temp_username[100], temp_password[100];
  int check_username, check_password;
  
  while(1)
  {
    printf("\n\t=========================================================\n");
    printf("\n\t                        Laman Login                      \n");
    printf("\n\t---------------------------------------------------------\n");

    printf("\n\tUsername : ");
    input_str(temp_username);
    printf("\n\tPassword : ");
    input_str(temp_password);

    check_username = strcmp(temp_username, input.username);
    check_password = strcmp(temp_password, input.password);
    
    if (check_username == 0 && check_password == 0)
    {
      printf("\n\t----------------------------------------------------------\n");
      puts("\n\tLogin berhasil");
      break;
    }
    else
    {
      printf("\n\t----------------------------------------------------------\n");
      puts("\n\tLogin gagal, masukan username & password dengan benar!");
      puts("\tTekan enter untuk mengulang");
      getch();
      system("cls");
    }
  }
}