#include <stdio.h>

int jumlahSiswa;
int jumlahTes;

void Min(int[jumlahSiswa][jumlahTes]);
void Max(int[jumlahSiswa][jumlahTes]);

int main(){
    
    printf("Masukkan jumlah siswa\t: "); scanf("%d", &jumlahSiswa);
    printf("Masukkan jumlah tes\t: "); scanf("%d", &jumlahTes);
    
    int nilai[jumlahSiswa][jumlahTes];
    
    for(int i = 0; i < jumlahTes; i++){
        printf("Tes ke-%d :\n", i + 1);
        for(int j = 0; j < jumlahSiswa; j++){
            printf("   Nilai siswa ke-%d : ", j + 1); scanf("%d", &nilai[i][j]);
        }
    }
    Min(nilai);
    Max(nilai);
}

void Min(int n[jumlahSiswa][jumlahTes]){
    int x[jumlahTes], min;
    
    for(int i = 0; i < jumlahTes; i++){
        for(int j = 0; j < jumlahSiswa; j++){
            if(x[i] > n[i][j]) x[i] = n[i][j];
        }
        printf("nilai terendah tes ke-%d adalah %d\n", i + 1, x[i]);
        if(x[i + 1] < jumlahTes)
            if(x[i] > x[i + 1]) min = x[i + 1];
    }
    printf("nilai terendah adalah %d\n", min);
}

void Max(int n[jumlahSiswa][jumlahTes]){
    int x[jumlahTes], max;
    
    for(int i = 0; i < jumlahTes; i++){
        for(int j = 0; j < jumlahSiswa; j++){
            if(x[i] < n[i][j]) x[i] = n[i][j];
        }
        printf("nilai tertinggi tes ke-%d adalah %d\n", i + 1, x[i]);
        if(x[i] < x[i + 1]) max = x[i + 1];
    }
    printf("nilai tertinggi adalah %d\n", max);
}
