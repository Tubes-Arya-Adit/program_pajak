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
    printf("error can't load file");
  fclose(file);
}

// void sinkronDataPengguna(struct Pengguna *pengguna, int i_pga)
// {
//   FILE *file = fopen("./data/pengguna.txt", "r");
//   char buff[255];
//   i_pga = 0;
//   memset(pengguna, 0, sizeof(pengguna));
//   if (file)
//   {
//     while (fgets(buff, sizeof(buff), file))
//     {
//       fscanf(file, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]", pengguna[i_pga].nama, pengguna[i_pga].alamat, pengguna[i_pga].no_telp, pengguna[i_pga].username, pengguna[i_pga].password, pengguna[i_pga].npwp, pengguna[i_pga].nik);
//     }
//   }
//   else
//     printf("error can't load file");
//   fclose(file);
// }