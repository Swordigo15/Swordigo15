#include <stdio.h>

int main(){
    int jumlahSiswa;
    int jumlahTes;
    
    printf("Masukkan jumlah siswa\t: "); scanf("%d", &jumlahSiswa);
    printf("Masukkan jumlah tes\t: "); scanf("%d", &jumlahTes);
    
    int nilai[jumlahSiswa][jumlahTes];
    
    for(int i = 0; i < jumlahTes; i++){
        printf("Tes ke-%d\n : ", i + 1);
        for(int j = 0; j < jumlahSiswa; j++){
            printf("\tNilai siswa ke-%d : ", j + 1); scanf("%d", &nilai[i][j]);
        }
    }
}
