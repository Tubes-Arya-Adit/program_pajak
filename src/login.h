void login_menu()
{
  char temp_username[100], temp_password[100]; //temporary variabel untuk menampung username dan password
  int check_username, check_password; //menampung nilai hasil compare string

  while (1)
  {
    printf("\n\t=========================================================\n");
    printf("\n\t                        Laman Login                      \n");
    printf("\n\t=========================================================\n");

    printf("\n\tUsername : ");
    input_str(temp_username);

    check_username = checkData("username", temp_username); //mengecek apakah username ada didalam pengguna txt, return 0 jika ada
    pindahData(temp_username); //pindahkan ke struct Pengguna login sebagai pengguna login saat ini

    printf("\n\tPassword : ");
    input_password(temp_password);

    check_password = strcmp(pengguna_login.password, temp_password); //mengecek apakah password sesuai, return 0 jika iya

    if (check_username == 0 && check_password == 0) //jika memenuhi
    {
      printf("\n\n\t----------------------------------------------------------\n");
      printf("\n\t                      Login berhasil                      ");
      printf("\n\t             Tekan enter untuk masuk ke program           \n");
      printf("\n\t----------------------------------------------------------\n");
      getch();
      system("cls");
      break;
    }
    else
    {
      printf("\n\n\t----------------------------------------------------------\n");
      printf("\n\tLogin gagal, masukan username & password dengan benar!");
      printf("\n\tTekan enter untuk mengulang \n");
      printf("\n\t----------------------------------------------------------\n");
      getch();
      system("cls");
    }
  }
}