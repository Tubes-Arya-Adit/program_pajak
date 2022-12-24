int npwp_format_check();
int nik_format_check();
int nama_format_check();
int no_telp_format_check();

void register_menu()
{
  int check;
  printf("\n\t=========================================================\n");
  printf("\n\t                    Laman Registrasi                     \n");
  printf("\n\t=========================================================\n");
  printf("\n\tMasukkan NPWP          : ");
  input_str(input.npwp);
  while (npwp_format_check() == 0)
  {
    printf("\n\tFormat NPWP salah, NPWP terdiri dari 16 karakter numerik!");
    printf("\n\tMasukkan NPWP          : ");
    input_str(input.npwp);
  }
  while (checkData("npwp", input.npwp) == 0)
  {
    printf("\n\tNPWP sudah terdaftar, masukkan NPWP yang lain!");
    printf("\n\tMasukkan NPWP          : ");
    input_str(input.npwp);
    while (npwp_format_check() == 0)
    {
      printf("\n\tFormat NPWP salah, NPWP terdiri dari 16 karakter numerik!");
      printf("\n\tMasukkan NPWP          : ");
      input_str(input.npwp);
    }
  }

  printf("\n\tMasukkan NIK           : ");
  input_str(input.nik);
  while (nik_format_check() == 0)
  {
    printf("\n\tFormat NIK salah, NIK terdiri dari 16 karakter numerik!");
    printf("\n\tMasukkan NIK           : ");
    input_str(input.nik);
  }

  printf("\n\tMasukkan Nama          : ");
  input_str(input.nama);
  while (nama_format_check() == 0)
  {
    printf("\n\tNama tidak boleh mengandung karakter numerik!");
    printf("\n\tMasukkan Nama          : ");
    input_str(input.nama);
  }

  printf("\n\tMasukkan Alamat        : ");
  input_str(input.alamat);

  printf("\n\tMasukkan Nomor Telepon : ");
  input_str(input.no_telp);
  while (no_telp_format_check() == 0)
  {
    printf("\n\tNo. telp terdiri dari 12 karakter numerik!");
    printf("\n\tMasukkan Nomor Telepon : ");
    input_str(input.no_telp);
  }
  while (checkData("no_telp", input.no_telp) == 0)
  {
    printf("\n\tNomor telepon sudah terdaftar, masukkan nomor yang lain!");
    printf("\n\tMasukkan Nomor Telepon : ");
    input_str(input.npwp);
    while (no_telp_format_check() == 0)
    {
      printf("\n\tNo. telp terdiri dari 12 karakter numerik!");
      printf("\n\tMasukkan Nomor Telepon : ");
      input_str(input.no_telp);
    }
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

  printf("\n\n\t----------------------------------------------------------\n");
  printf("\n\t                    Berhasil Register!                     ");
  printf("\n\t                 Tekan enter untuk login                   \n");
  printf("\n\t----------------------------------------------------------\n");
  getch();
  system("cls");
  login_menu(pengguna_login);
}

int npwp_format_check()
{
  int len = strlen(input.npwp);
  for(int i = 0; i < sizeof(input.npwp); i++)
  {
    if(isdigit(input.npwp[i]) == 0 && len != 16) //jika bukan 16 karakter numerik
      return 0;
  }
  return 1;
}

int nik_format_check()
{
  int len = strlen(input.nik);
  for(int i = 0; i < sizeof(input.nik); i++)
  {
    if(isdigit(input.nik[i]) == 0 && len != 16) //jika bukan 16 karakter numerik
      return 0;
  }
  return 1;
}

int nama_format_check()
{
  for(int i = 0; i < sizeof(input.nama); i++)
  {
    if(isdigit(input.nama[i]) == 1) //jika mengandung angka
      return 0;
  }
  return 1;
}

int no_telp_format_check()
{
  int len = strlen(input.no_telp);
  for(int i = 0; i < sizeof(input.no_telp); i++)
  {
    if(strlen(input.no_telp) != 12 && isdigit(input.no_telp[i]) == 0) //jika bukan 12 digit karakter numerik
      return 0;
  }
  return 1;
}