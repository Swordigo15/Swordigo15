#include <stdio.h>

int jumlahSiswa;
int jumlahTes;

void Min(int[][jumlahTes]);
void Max(int[][jumlahTes]);
void RataRata(int[][jumlahTes]);

int main(){
    
    printf("Masukkan jumlah siswa\t: "); scanf("%d", &jumlahSiswa);
    printf("Masukkan jumlah tes\t: "); scanf("%d", &jumlahTes);
    
    int nilai[jumlahSiswa][jumlahTes];
    
    for(int i = 0; i < jumlahTes; i++){
        printf("Tes ke-%d :\n", i + 1);
        for(int j = 0; j < jumlahSiswa; j++){
            printf("   Nilai siswa ke-%d : ", j + 1); scanf("%d", &nilai[j][i]);
        }
    }
    
    Min(nilai);
    puts("");
    Max(nilai);
    puts("");
    RataRata(nilai);
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

void RataRata(int data[][jumlahTes]){
    int x[jumlahTes], y = 0;
    float rt = 0;
    for(int i = 0; i < jumlahTes; i++){
        x[i] = 0;
        for(int j = 0; j < jumlahSiswa; j++){
            //printf("%d + %d\n", x[i], data[j][i]);
            x[i] += data[j][i];
        }
        y += x[i];
        printf("Jumlah nilai tes ke-%d\t\t: %d\n", i + 1, x[i]);
        printf("Rata-rata tes ke-%d\t\t: %.2f\n", i + 1, (float)x[i] / jumlahSiswa);
    }
    rt = (float)y / jumlahSiswa;
    printf("Jumlah nilai keseluruhan adalah %.2f\n", (float)y);
    printf("Rata-rata keseluruhan adalah %.2f", rt);
}
