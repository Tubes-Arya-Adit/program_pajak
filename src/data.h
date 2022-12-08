#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
FILE INI DIGUNAKAN UNTUK MENGATUR
OPERASI FILE DAN DATA
*/

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

void sinkronDataPengguna()
{
  FILE *file = fopen("./data/pengguna.txt", "r");
  char buff[255];
  i_pga = 0;
  memset(pengguna, 0, sizeof(pengguna));
  if (file)
  {
    while (!feof(file))
    {
      fscanf(file, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]", pengguna[i_pga].nama, pengguna[i_pga].alamat, pengguna[i_pga].no_telp, pengguna[i_pga].username, pengguna[i_pga].password, pengguna[i_pga].npwp, pengguna[i_pga].nik);
      i_pga++;
    }
  }
  else
    printf("Unable to load file!");
  fclose(file);
}

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
  }
  return -1;
}

int cariIndeksPengguna(char *username)
{
  int low = 0;
  int high = i_pga - 1;
  int mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (strcmp(pengguna[mid].username, username) == 0)
      return mid;
    else if (strcmp(pengguna[mid].username, username) > 0)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

void pindahData(char *username)
{
  int index = cariIndeksPengguna(username);
  pengguna_login = pengguna[index];
}