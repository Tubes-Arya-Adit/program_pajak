// Memuat Gambar logo
void loadImage()
{
  FILE *file = fopen("./data/logo.txt", "r");
  char buff[255];
  if (file)
  {
    while (fgets(buff, sizeof(buff), file))
    {
      printf("%s", buff);
    }
  }
  else
    printf("Unable to load file!");
  fclose(file);
}

// Memuat data pada file pengguna.txt dan menyimpannya pada struct Pengguna
void sinkronDataPengguna()
{
  FILE *file = fopen("./data/pengguna.txt", "r");
  i_pga = 0;
  memset(pengguna, 0, sizeof(pengguna)); //men-setting ulang data dari 0
  if (file)
  {
    while (!feof(file))
    {
      fscanf(file, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", pengguna[i_pga].nama, pengguna[i_pga].alamat, pengguna[i_pga].no_telp, pengguna[i_pga].username, pengguna[i_pga].password, pengguna[i_pga].npwp, pengguna[i_pga].nik);
      i_pga++;
    }
  }
  else
    printf("Unable to load file!");
  fclose(file);
}

// Menambah Data Pengguna
void tambahDataPengguna()
{
  FILE *file = fopen("./data/pengguna.txt", "a");
  if (file)
  {
    fprintf(file, "%s#%s#%s#%s#%s#%s#%s\n", input.nama, input.alamat, input.no_telp, input.username, input.password, input.npwp, input.nik);

    pengguna[i_pga] = input;
    i_pga++;
  }
  else
    printf("Unable to load file!");
  fclose(file);
}

// Periksa apakah data sudah ada atau belum berdasarkan comparator atau salah satu datanya
int checkData(char *data, char *comparator)
{
  for (int i = 0; i < i_pga; i++)
  {
    if (strcmp(data, "username") == 0)
    {
      if (strcmp(pengguna[i].username, comparator) == 0)
        return 0;
    }
    else if (strcmp(data, "password") == 0)
    {
      if (strcmp(pengguna[i].password, comparator) == 0)
        return 0;
    }
    else if (strcmp(data, "npwp") == 0)
    {
      if (strcmp(pengguna[i].npwp, comparator) == 0)
        return 0;
    }
    else if (strcmp(data, "no_telp") == 0)
    {
      if (strcmp(pengguna[i].no_telp, comparator) == 0)
        return 0;
    }
    else if (strcmp(data, "nik") == 0)
    {
      if (strcmp(pengguna[i].nik, comparator) == 0)
        return 0;
    }
  }
  return -1;
}

// Mencari indeks pengguna yang memiliki username yang dicari
int cariIndeksPengguna(char *username)
{
  for (int i = 0; i < i_pga; i++)
  {
    if (strcmp(pengguna[i].username, username) == 0)
      return i;
  }
  return -1;
}

// Memindahkan data pengguna yang login ke struct pengguna_login
void pindahData(char *username)
{
  int index = cariIndeksPengguna(username);
  pengguna_login = pengguna[index];
}

// Memuat data pada file history.txt dan menyimpannya pada struct Transaksi
void sinkronDataTransaksi()
{
  FILE *file = fopen("./data/history.txt", "r");
  i_trs = 0;
  memset(trs_pengguna, 0, sizeof(trs_pengguna));
  if (file)
  {
    while (!feof(file))
    {
      fscanf(file, "%[^#]#%[^#]#%lf#%lf#%lf#%[^#]#%[^\n]\n", trs_pengguna[i_trs].id, trs_pengguna[i_trs].jenis_pajak, &trs_pengguna[i_trs].total_pajak, &trs_pengguna[i_trs].denda, &trs_pengguna[i_trs].jumlah_nominal, trs_pengguna[i_trs].tanggal, trs_pengguna[i_trs].status);
      i_trs++;
    }
  }
  else
    printf("Unable to load file!");
  fclose(file);
}

// Menambah Data Transaksi
void tambahDataTransaksi()
{
  FILE *file = fopen("./data/history.txt", "a");
  if (file)
  {
    fprintf(file, "%s#%s#%lf#%lf#%lf#%s#%s\n", trs_input.id, trs_input.jenis_pajak, trs_input.total_pajak, trs_input.denda, trs_input.jumlah_nominal, trs_input.tanggal, trs_input.status);

    trs_pengguna[i_trs] = trs_input;
    i_trs++;
  }
  else
    printf("Unable to load file!");
  fclose(file);
}
