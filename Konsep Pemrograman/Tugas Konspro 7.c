#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nilai{
    int UTS;
    int UAS;
    int NilaiAkhir;
}nilai;

typedef struct Identitas{
    char nama[15];
    char NIM[8];
    char kelas;
    int umur;
    nilai nilaiPtr;
}identitas;


void SetIdentitas(identitas*, char[], char[], char, int, int, int, int);

int main()
{
    identitas id;
    char n[15], nim[8], k;
    int u, uts, uas, akhir;
    
    printf("Masukkan nama "); scanf("%s", n);
    printf("Masukkan NIM "); scanf("%s", nim);
    printf("Masukkan kelas "); scanf("%s", &k);
    printf("Masukkan umur "); scanf("%u", &u);
    printf("Masukkan nilai UTS "); scanf("%u", &uts);
    printf("Masukkan nilai UAS "); scanf("%u", &uas);
    printf("Masukkan nilai Akhir "); scanf("%u", &akhir);
    SetIdentitas(&id, n, nim, k, u, uts, uas, akhir);
    
    printf("Nama \t\t: %s\nNIM \t\t: %s\nKelas \t\t: %c\nUmur \t\t: %d\nNilai UTS \t: %d\nNilai UAS \t: %d\nNilai Akhir \t: %d\n", 
    id.nama, id.NIM, id.kelas, id.umur, id.nilaiPtr.UTS, id.nilaiPtr.UAS, id.nilaiPtr.NilaiAkhir);
}

void SetIdentitas(identitas *i, char n[], char nim[], char k, int u, int uts, int uas, int akhir){
    strcpy(i->nama, n);
    strcpy(i->NIM, nim);
    i->umur = u;
    i->kelas = k;
    i->nilaiPtr.UTS = uts;
    i->nilaiPtr.UAS = uas;
    i->nilaiPtr.NilaiAkhir = akhir;
}
