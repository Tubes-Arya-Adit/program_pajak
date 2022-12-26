int npwp_format_check();
int nik_format_check();
int nama_format_check();
int no_telp_format_check();

// membuat fungsi untuk registrasi
void register_menu()
{
  int check;
  printf("\n\t=========================================================\n");
  printf("\n\t                    Laman Registrasi                     \n");
  printf("\n\t=========================================================\n");

  // Memasukan data - data yang dibutuhkan

  printf("\n\tMasukkan NPWP          : ");
  input_str(input.npwp);
  fflush(stdin);
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

  // menambah data pengguna ke struct
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

// memeriksa apakah npwp yang dimasukan sesuai format
int npwp_format_check()
{
  int len = strlen(input.npwp);

  if (len > 16)
    return 0;

  for (int i = 0; i < sizeof(input.npwp); i++)
  {
    if (isdigit(input.npwp[i]) == 0 && len < 15) // jika bukan 15 karakter numerik
      return 0;
  }
  return 1;
}

// memeriksa apakah nik yang dimasukan sesuai format
int nik_format_check()
{
  int len = strlen(input.nik);

  if (len > 16)
    return 0;

  for (int i = 0; i < sizeof(input.nik); i++)
  {
    if (isdigit(input.nik[i]) == 0 && len != 16) // jika bukan 16 karakter numerik
      return 0;
  }
  return 1;
}

// memeriksa apakah nama yang dimasukan sesuai format
int nama_format_check()
{
  for (int i = 0; i < sizeof(input.nama); i++)
  {
    if (isdigit(input.nama[i]) == 1) // jika mengandung angka
      return 0;
  }
  return 1;
}

// memeriksa apakah no_telp yang dimasukan sesuai format
int no_telp_format_check()
{
  int len = strlen(input.no_telp);

  if (len > 12)
    return 0;

  for (int i = 0; i < sizeof(input.no_telp); i++)
  {
    if (isdigit(input.no_telp[i]) == 1 && len != 12) // jika bukan 12 digit karakter numerik
      return 0;
  }
  return 1;
}