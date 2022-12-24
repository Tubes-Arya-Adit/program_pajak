#include <stdio.h>

// void output_pph()
// {
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n\t       *******      |                                 ");
//     printf("\n\t     ***********    |     BUKTI PEMBAYARAN PAJAK      ");
//     printf("\n\t     *@@     ***    |      PENGHASILAN PASAL 21       ");
//     printf("\n\t     &&&     **@    |     BAGI PEGAWAI TETAP ATAU     ");
//     printf("\n\t     &&&&&&&&&&&    |    PENERIMA PENSIUN BERKALA.    ");
//     printf("\n\t       &&&&&&&      |                                 ");
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n");
//     printf("\n\tA. IDENTITAS WAJIB PAJAK");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t NPWP              :");
//     printf("\n\t NIK               :");
//     printf("\n\t Nama              :");
//     printf("\n\t Alamat            :");
//     printf("\n\t No. Telp          :");
//     printf("\n\t Jenis Kelamin     :");
//     printf("\n\t Status            :");
//     printf("\n\t Jumlah Tanggungan :");
//     printf("\n\t Nama Jabatan      :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tB. RINCIAN PENGHASILAN DAN PERHITUNGAN PPh PASAL 21");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t                  URAIAN               |    JUMLAH    ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t PENGHASILAN BRUTO                                    ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t Penghasilan Pokok                     |              ");
//     printf("\n\t Penghasilan Lainnya                   |              ");
//     printf("\n\t Jumlah Penghasilan Bruto              |              ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t PENGURANGAN                                          ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t Biaya Jabatan                         |              ");
//     printf("\n\t Iuran Pensiun                         |              ");
//     printf("\n\t Jumlah Pengurangan                    |              ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t PERHITUNGAN PPh PASAL 21                             ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t Jumlah Penghasilan Netto              |              ");
//     printf("\n\t Penghasilan Tidak Kena Pajak (PTKP)   |              ");
//     printf("\n\t Penghasilan Kena Pajak (PKP)          |              ");
//     printf("\n\t Besar Tarif Progresif (%%)             |             ");
//     printf("\n\t Total Pajak Penghasilan               |              ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n");
//     printf("\n\tC. RINCIAN TRANSAKSI");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t Nomor           :");
//     printf("\n\t Tahun Pajak     :");
//     printf("\n\t Waktu Transaksi :");
//     printf("\n\t Status Pajak    :");
//     printf("\n\t Masa Pajak      :");
//     printf("\n\t------------------------------------------------------");
// }

// void output_pbb()
// {
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n\t       *******      |                                 ");
//     printf("\n\t     ***********    |         BUKTI PEMBAYARAN        ");
//     printf("\n\t     *@@     ***    |         LUNAS PAJAK BUMI        ");
//     printf("\n\t     &&&     **@    |           DAN BANGUNAN          ");
//     printf("\n\t     &&&&&&&&&&&    |         NEGARA INDONESIA        ");
//     printf("\n\t       &&&&&&&      |                                 ");
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n");
//     printf("\n\tA. IDENTITAS WAJIB PAJAK");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t NPWP              :");
//     printf("\n\t NIK               :");
//     printf("\n\t Nama              :");
//     printf("\n\t Alamat            :");
//     printf("\n\t No. Telp          :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tB. LETAK OBJEK PAJAK");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t Lokasi         :");
//     printf("\n\t Kelurahan/Desa :");
//     printf("\n\t RT             :");
//     printf("\n\t RW             :");
//     printf("\n\t Kecamatan      :");
//     printf("\n\t Kota/Kabupaten :");
//     printf("\n\t Provinsi       :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tC. RINCIAN OBJEK PAJAK DAN PERHITUNGAN PBB");
//     printf("\n\t---------------+-------------+---------+---------------+-------------");
//     printf("\n\t  OBJEK PAJAK  |  LUAS (M2)  |  KELAS  |  NJOP PER M2  | TOTAL NJOP  ");
//     printf("\n\t---------------+-------------+---------+---------------+-------------");
//     printf("\n\t Bumi          |             |         |               |             ");
//     printf("\n\t Bangunan      |             |         |               |             ");
//     printf("\n\t---------------+-------------+---------+---------------+-------------");
//     printf("\n\t NJOP sebagai dasar pengenaan PBB :");
//     printf("\n\t NJOPTKP (NJOP Tidak Kena Pajak)  :");
//     printf("\n\t NJOP untuk penghitungan PBB      :");
//     printf("\n\t Total Pajak Bumi Bangunan        :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tD. RINCIAN TRANSAKSI");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t Nomor           :");
//     printf("\n\t Tahun Pajak     :");
//     printf("\n\t Waktu Transaksi :");
//     printf("\n\t Status Pajak    :");
//     printf("\n\t Masa Pajak      :");
//     printf("\n\t------------------------------------------------------");
// }

// void output_ppn()
// {
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n\t       *******      |                                 ");
//     printf("\n\t     ***********    |         BUKTI PEMBAYARAN        ");
//     printf("\n\t     *@@     ***    |            LUNAS PAJAK          ");
//     printf("\n\t     &&&     **@    |         PERTAMBAHAN NILAI       ");
//     printf("\n\t     &&&&&&&&&&&    |         NEGARA INDONESIA        ");
//     printf("\n\t       &&&&&&&      |                                 ");
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n");
//     printf("\n\tA. IDENTITAS PENGUSAHA KENA PAJAK");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t NPWP              :");
//     printf("\n\t NIK               :");
//     printf("\n\t Nama              :");
//     printf("\n\t Alamat            :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tB. IDENTITAS PEMBELI BARANG KENA PAJAK");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t NIK               :");
//     printf("\n\t Nama              :");
//     printf("\n\t Alamat            :");
//     printf("\n\t No. Telp          :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tC. RINCIAN BARANG/JASA KENA PAJAK DAN PERHITUNGAN PPN");
//     printf("\n\t----+----------------------------------+--------------");
//     printf("\n\t NO |        URAIAN BARANG/JASA        |     HARGA    ");
//     printf("\n\t----+----------------------------------+--------------");
//     printf("\n\t    |                                  |              ");
//     printf("\n\t----+----------------------------------+--------------");
//     printf("\n\t Jumlah Harga Jual                       :");
//     printf("\n\t Dikurangi Potongan Harga                :");
//     printf("\n\t Dikurangi Uang Muka yang Telah Diterima :");
//     printf("\n\t Dasar Pengenaan Pajak                   :");
//     printf("\n\t PPn = 10%% * Dasar Pengenaan Pajak       :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tD. RINCIAN TRANSAKSI");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t Nomor           :");
//     printf("\n\t Tahun Pajak     :");
//     printf("\n\t Waktu Transaksi :");
//     printf("\n\t Status Pajak    :");
//     printf("\n\t------------------------------------------------------");
// }

// void output_impor()
// {
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n\t       *******      |                                 ");
//     printf("\n\t     ***********    |         BUKTI PEMBAYARAN        ");
//     printf("\n\t     *@@     ***    |         LUNAS PAJAK IMPOR       ");
//     printf("\n\t     &&&     **@    |        (BEA MASUK, CUKAI,       ");
//     printf("\n\t     &&&&&&&&&&&    |          DAN/ATAU PAJAK)        ");
//     printf("\n\t       &&&&&&&      |                                 ");
//     printf("\n\t--------------------+---------------------------------");
//     printf("\n");
//     printf("\n\tA. IDENTITAS IMPORTIR/WAJIB PAJAK");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t NPWP              :");
//     printf("\n\t Nama              :");
//     printf("\n\t Alamat            :");
//     printf("\n\t No. Telp          :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tB. IDENTITAS EKSPORTIR");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t Nama              :");
//     printf("\n\t Negara            :");
//     printf("\n\t Alamat            :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tC. IDENTITAS PENGANGKUT");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t Nama              :");
//     printf("\n\t Negara            :");
//     printf("\n\t Alamat            :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tD. RINCIAN BARANG");
//     printf("\n\t----+----------------------------------+-------------------------+----------------+--------------");
//     printf("\n\t NO |          URAIAN BARANG           |  JUMLAH & JENIS SATUAN  |  NILAI PABEAN  |   POS TARIF  ");
//     printf("\n\t----+----------------------------------+-------------------------+----------------+--------------");
//     printf("\n\t    |                                  |                         |                |              ");
//     printf("\n\t----+----------------------------------+-------------------------+----------------+--------------");
//     printf("\n\t NDPBM :");
//     printf("\n\t------------------------------------------------------");
//     printf("\n");
//     printf("\n\tE. RINCIAN PAJAK IMPOR");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t                  URAIAN               |    JUMLAH    ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t BEA CUKAI                                            ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t Bea Masuk                             |              ");
//     printf("\n\t Cukai                                 |              ");
//     printf("\n\t Jumlah Bea Cukai                      |              ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t PAJAK LAINNYA                                        ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t PPN                                   |              ");
//     printf("\n\t PPnBM                                 |              ");
//     printf("\n\t PPh                                   |              ");
//     printf("\n\t Jumlah Pajak Lainnya                  |              ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t PAJAK IMPOR                                          ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n\t Jumlah Bea Masuk, Cukai, dan Pajak    |              ");
//     printf("\n\t---------------------------------------+--------------");
//     printf("\n");
//     printf("\n\tE. RINCIAN TRANSAKSI");
//     printf("\n\t------------------------------------------------------");
//     printf("\n\t Nomor           :");
//     printf("\n\t Tahun Pajak     :");
//     printf("\n\t Waktu Transaksi :");
//     printf("\n\t Status Pajak    :");
//     printf("\n\t------------------------------------------------------");
// }
