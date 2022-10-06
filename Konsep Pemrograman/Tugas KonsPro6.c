#include <stdio.h>

int jumlahSiswa;
int jumlahTes;

void Min(int[][jumlahTes]);
void Max(int[][jumlahTes]);
int penjumlahan(int[][jumlahTes]);

int main(){
    int jumlahNilai;
    float rataRata;
    
    printf("Masukkan jumlah siswa\t: "); scanf("%d", &jumlahSiswa);
    printf("Masukkan jumlah tes\t: "); scanf("%d", &jumlahTes);
    
    int nilai[jumlahSiswa][jumlahTes];
    
    for(int i = 0; i < jumlahTes; i++){
        printf("Tes ke-%d :\n", i + 1);
        for(int j = 0; j < jumlahSiswa; j++){
            printf("   Nilai siswa ke-%d : ", j + 1); scanf("%d", &nilai[j][i]);
        }
    }
    
    for(int i = 0; i < jumlahTes; i++){
        for(int j = 0; j < jumlahSiswa; j++){
            printf("%d ", nilai[j][i]);
        }
        puts("");
    }
    
    Min(nilai);
    puts("");
    Max(nilai);
    puts("");
    //x[i] = penjumlahan(nilai);
    //printf("Jumlah tes ke-%d : %d\n", i + 1, x[i]);
    jumlahNilai = penjumlahan(nilai);
    printf("%d\n", jumlahNilai);
    
    rataRata = (float)jumlahNilai / jumlahSiswa;
    printf("Rata-rata keseluruhan adalah %.2f", rataRata);
}

void Min(int n[][jumlahTes]){
    puts("Minimum");
    int x[jumlahSiswa], min;
    for(int i = 0; i < jumlahTes; i++){
        x[i] = n[0][i];
        for(int j = 0; j < jumlahSiswa; j++){
            if(x[i] > n[j][i]){
                x[i] = n[j][i];
            }
        }
        printf("Nilai terendah pada tes ke-%d : %d\n", i + 1, x[i]);
        min = x[i];
        if(min > x[i]){
            min = x[i];
        }
    }
    printf("terendah %d\n", min);
}

void Max(int n[][jumlahTes]){
    puts("Maximum");
    int x[jumlahSiswa], max;
    for(int i = 0; i < jumlahTes; i++){
        x[i] = n[0][i];
        for(int j = 0; j < jumlahSiswa; j++){
            if(x[i] < n[j][i]){
                x[i] = n[j][i];
            }
        }
        printf("Nilai tertinggi pada tes ke-%d : %d\n", i + 1, x[i]);
        max = x[i];
        if(max > x[i]){
            max = x[i];
        }
    }
    printf("tertinggi %d\n", max);
}

int penjumlahan(int data[][jumlahTes]){
    int x, y;
    for(int i = 0; i < jumlahTes; i++){
        for(int j = 0; j < jumlahSiswa; j++){
            printf("%d + %d\n", y, data[j][i]);
            y += data[j][i];
        }
        x = y;
        printf("Jumlah nilai tes ke-%d : %d\n", i + 1, x);
    }
    return y;
}
