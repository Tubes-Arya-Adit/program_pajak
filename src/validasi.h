/*
  FILE INI DIGUNAKAN UNTUK MENGATUR VALIDASI DATA
  YANG DIMASUKAN OLEH PENGGUNA
*/

// fungsi yang digunakan untuk menginput data dengan tipe data double
double input_double()
{
  char input[5];
  int i = 0, error = 0, negative = 0, decimal = 0, whole_num = 0, fract_num = 0, chars = 0;
  float zero_point = 1, output;

  fflush(stdin);
  scanf("%s", input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (input[i] == '-')
    {
      error = 1;
      input[i] = '\0';
    }
    else if (input[i] == '.')
    {
      decimal++;
      if (decimal > 1 || input[i + 1] == '\0' || input[0] == '.')
      {
        error = 1;
        input[i] = '\0';
      }
      i++;
    }
    else if (isdigit(input[i]))
    {
      if (decimal == 1)
      {
        fract_num = (fract_num * 10) + (input[i] - 48);
        chars++;
        i++;
      }
      else
      {
        whole_num = (whole_num * 10) + (input[i] - 48);
        i++;
      }
    }
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  if (decimal == 1)
  {
    for (int j = 0; j < chars; j++)
    {
      zero_point /= 10;
    }
    output = fract_num * zero_point + whole_num;
  }
  else
    output = whole_num;

  if (negative == 1)
    output -= (output * 2);

  if (error == 1)
  {
    printf("\n\tHarus berupa angka dan lebih dari 0! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return input_double();
  }
  else
    return output;
}

// fungsi yang digunakan untuk menginput data dengan tipe data string
char *input_str(char *input)
{
  int i = 0, error = 0;

  fflush(stdin);
  scanf("%[^\n]", input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (isdigit(input[i]))
      i++;
    else if (isalpha(input[i]))
      i++;
    else if (isspace(input[i]) || input[i] == '.')
      i++;
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }
  if (error == 1)
  {
    printf("\n\tMasukan huruf dengan benar ");
    printf("\n\tSilahkan masukan kembali : ");
    return input_str(input);
  }
  else
    return input;
}

// fungsi yang digunakan untuk menginput data dengan tipe data integer
int input_int()
{
  char input[5];
  int i = 0, output, error = 0;

  fflush(stdin);
  scanf("%s", input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (isdigit(input[i]))
      i++;
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  output = atoi(input);

  if (error == 1)
  {
    printf("\n\tYang anda masukan bukan angka! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return input_int();
  }
  else
    return output;
}

// fungsi yang digunakan untuk mengganti input password menjadi tanda *
char masking(char *password)
{
  char ch;
  int i = 0;
  while (1)
  {
    ch = getch();
    if (ch == 13)
    {
      password[i] = '\0';
      break;
    }
    else if (ch == 8)
    {
      if (i > 0)
      {
        i--;
        printf("\b \b");
      }
    }
    else
    {
      password[i] = ch;
      i++;
      printf("*");
    }
  }
}

// fungsi yang digunakan untuk mengisi password
char *input_password(char *input)
{
  int i = 0, error = 0;

  fflush(stdin);
  masking(input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (isdigit(input[i]))
      i++;
    else if (isalpha(input[i]))
      i++;
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  if (error == 1)
  {
    printf("\n\tMasukan huruf dengan benar ");
    printf("\n\tSilahkan masukan kembali : ");
    return input_password(input);
  }
  else
    return input;
}

// fungsi yang digunakan untuk mengisi hari
int input_hari()
{
  char input[5];
  int i = 0, output, error = 0;

  fflush(stdin);
  scanf("%s", input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (isdigit(input[i]))
      i++;
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  output = atoi(input);

  if (error == 1)
  {
    printf("\n\tYang anda masukan bukan angka! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return input_hari();
  }
  else if (output < 1 || output > 31)
  {
    printf("\n\tMasukan angka antara 1 - 31! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return input_hari();
  }
  else
    return output;
}

// fungsi yang digunakan untuk mengisi bulan
int input_bulan()
{
  char input[5];
  int i = 0, output, error = 0;

  fflush(stdin);
  scanf("%s", input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (isdigit(input[i]))
      i++;
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  output = atoi(input);

  if (error == 1)
  {
    printf("\n\tYang anda masukan bukan angka! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return input_bulan();
  }
  else if (output < 1 || output > 12)
  {
    printf("\n\tMasukan angka antara 1 - 12! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return input_bulan();
  }
  else
    return output;
}

int checkTgl(int hari, int bulan, int tahun)
{
  if ((hari > 28 && bulan == 2) || (hari > 29 && bulan == 2 && (tahun % 4 == 0 || tahun % 100 != 0 || tahun % 400 == 0)))
  {
    printf("\n\tBulan februari hanya memiliki 28 hari! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return 0;
  }
  else if ((bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) && hari > 30)
  {
    printf("\n\tBulan %d hanya memiliki 30 hari! ", bulan);
    printf("\n\tSilahkan masukan angka kembali : ");
    return 0;
  }
  else if (bulan == 1 || bulan == 3 || bulan == 5 || bulan == 7 || bulan == 8 || bulan == 10 || bulan == 12 && hari > 31)
  {
    printf("\n\tBulan %d hanya memiliki 31 hari! ", bulan);
    printf("\n\tSilahkan masukan angka kembali : ");
    return 0;
  }
  return 1;
}
