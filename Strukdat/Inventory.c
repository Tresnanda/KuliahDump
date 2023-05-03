#include <stdio.h>
#include <stdlib.h> 
#include <strings.h>

struct barang
{
  char nama[40];
  int harga;
  char bahan[40];
  int kuantitas;
  int kode;
};
int
main ()
{
  int jumlahbarang = 0;
  int pil;
  int jml;
  char pili;
  struct barang item[30];
  do
    {
      system ("clear");
      printf ("\n \n");
      printf ("\t\t\t\t=== TUGAS TOPIK 2 STRUKTUR DATA ===\n");
      printf ("\n\n");
      printf ("\t\t\t\t----------- Menu Utama ----------- \n");
      printf ("\t\t\t\t1. Input Barang\n");
      printf ("\t\t\t\t2. Daftar Barang\n");
      printf ("\t\t\t\t0. Keluar\n");
      printf ("\t\t\t\t----------------------------------\n");
      printf ("\t\t\t\tOpsi Pilihan: \t");
      scanf ("%d", &pil);
      switch (pil)
	{
	case 1:
	  system ("clear");
	  printf ("\n \n");
	  printf ("\t\t\t\t=== TUGAS TOPIK 2 STRUKTUR DATA ===\n");
	  printf ("\n");
	  printf ("\t\t\t\t----------- Input Barang ----------- \n");
	  printf ("\t\t\t\tBerapa barang yang ingin anda input?: \n");
	  printf ("\t\t\t\t");
	  scanf ("%d", &jml);
	  for (int i = jumlahbarang; i < jumlahbarang + jml; i++)
	    {
	      printf ("\n");
	      printf ("\t\t\t\tKode Barang[%d]: \t", i + 1);
	      fflush (stdin);
	      scanf ("%d", &item[i].kode);
	      printf ("\n");
	      printf ("\t\t\t\tNama Barang[%d]: \t", i + 1);
	      fflush (stdin);
	      scanf ("%s", item[i].nama);
	      printf ("\n");
	      printf ("\t\t\t\tBahan Dasar[%d]: \t", i + 1);
	      fflush (stdin);
	      scanf ("%s", item[i].bahan);
	      printf ("\n");
	      printf ("\t\t\t\tJumlah Barang[%d]: \t", i + 1);
	      fflush (stdin);
	      scanf ("%d", &item[i].kuantitas);
	      printf ("\n");
	      printf ("\t\t\t\tHarga Per Unit[%d]: \tRp.", i + 1);
	      fflush (stdin);
	      scanf ("%d", &item[i].harga);

//printf("\t\t\t\t------------------------------------ \n");
	      printf ("\n");
	    }
	  jumlahbarang += jml;
	  break;
	case 2:
	  system ("clear");
	  printf ("\n\n");
	  printf
	    ("\t---------------------------------------- Daftar Barang -------------------------------- ------- \n\n");
	  printf ("\t%-20s%-20s%-20s%-20s%-20s\n", "Kode Barang",
		  "Nama Barang", "Bahan Dasar", "Jumlah Barang",
		  "Harga Per Unit");
	  for (int i = 0; i < jumlahbarang; i++)
	    {
	      printf ("\t%-20d%-20s%-20s%-20dRp.%-20d\n", item[i].kode,
		      item[i].nama, item[i].bahan, item[i].kuantitas,
		      item[i].harga);
	    }
	  printf ("\n\n\n\n\n\n\n\n\n\n");
	  printf ("Masukkan apapun untuk keluar. \n");	//printf("\t\t\t\t");
	  scanf (" %c", &pili);
	}
    }
  while (pil != 0);
  return 0;
}
