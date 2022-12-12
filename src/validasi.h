/*
  FILE INI DIGUNAKAN UNTUK MENGATUR VALIDASI DATA
  YANG DIMASUKAN OLEH PENGGUNA
*/

double input_double()
{
  char input[5];
  int i = 0, error = 0, negative = 0, decimal = 0, whole_num = 0, fract_num = 0, chars = 0;
  float zero_point = 1, output;

  fflush(stdin);
  scanf("%s", input);
  getchar();

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

char *input_str(char *input)
{
  int i = 0, error = 0;

  fflush(stdin);
  scanf("%[^\n]", input);
  getchar();

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
    printf("\n\tSilahkan masukan angka kembali : ");
    return input_str(input);
  }
  else
    return input;
}

int input_int()
{
  char input[5];
  int i = 0, output, error = 0;

  fflush(stdin);
  scanf("%s", input);
  getchar();

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