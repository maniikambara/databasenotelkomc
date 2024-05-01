#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max 100

typedef struct {
    int nomor;
    char nama[50];
    char alamat[100];
} Telkom;

Telkom data[max];
int num = 0;

int fungsiHash(int nomor) {
    return nomor % max;
}

void tambahData() {
    if (num >= max) {
        printf("Database full, tidak dapat menambahkan data.\n\n");
        return;
    }

    Telkom baru;
    baru.nomor = rand() % 899999999999 + 100000000000;
    sprintf(baru.nama, "Nama %d", num + 1);
    sprintf(baru.alamat, "Alamat %d", num + 1);

    int index = fungsiHash(baru.nomor);
    int probe = 1;
    while (data[index].nomor != 0) {
        index = (index + probe) % max;
        probe = (probe + 1) % max;
    }
    data[index] = baru;
    num++;

    printf("Data baru ditambah dengan sukses.\n\n");
}

void hapusData() {
    int nomor;
    printf("+-----------------------------------------+\n\n");
    printf("\t\tHAPUS DATA\n\n");
    printf("+-----------------------------------------+\n\n");
    printf("Masukkan nomor HP untuk dihapus: ");
    scanf("%d", &nomor);

    int index = fungsiHash(nomor);
    while (data[index].nomor != nomor && data[index].nomor != 0) {
        index = (index + 1) % max;
    }

    if (data[index].nomor == 0) {
        printf("Nomor HP tidak ditemukan.\n\n");
        return;
    }

    data[index].nomor = 0;
    strcpy(data[index].nama, "");
    strcpy(data[index].alamat, "");
    num--;

    printf("Data telah dihapus dengan sukses.\n\n");
}

void tampilkanData() {
    printf("+-----------------------------------------+\n\n");
    printf("\t\tDATA TELKOM\n\n");
    printf("+-----------------------------------------+\n\n");
    for (int i = 0; i < max; i++) {
        if (data[i].nomor != 0) {
            printf("\t     No. HP: %d\n\t     Nama: %s\n\t     Alamat: %s\n\n", data[i].nomor, data[i].nama, data[i].alamat);
        }
    }
}

int main() {
    srand(time(NULL));

    int pilihan;
    while (1) {
        system("cls");
        printf("+-----------------------------------------+\n\n");
        printf("\t  PROGRAM DATABASE TELKOM\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("\t     1. Tambahkan Data\n");
        printf("\t     2. Hapus Data\n");
        printf("\t     3. Tampilkan Data\n");
        printf("\t     4. Keluar\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("   I Ketut Manik Ambarawan (2308561017)\n\n");
        printf("\tPILIHAN (1-4) : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                system("cls");
                tambahData();
                system("pause");
                break;
            case 2:
                system("cls");
                hapusData();
                system("pause");
                break;
            case 3:
                system("cls");
                tampilkanData();
                system("pause");
                break;
            case 4:
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
                system("pause");
                break;
        }
    }
}