#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* RandomString(int length) {
    char* str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

char* RandomIP() {
    char* ip = (char*) malloc(sizeof(char) * 16);
    sprintf(ip, "%d.%d.%d.%d", rand() % 256, rand() % 256, rand() % 256, rand() % 256);
    return ip;
}

char* RandomLokasi() {
    char* str = (char*) malloc(sizeof(char) * 20);
    sprintf(str, "Gedung %c", 'A' + rand() % 26);
    return str;
}


struct komp{
    char ip[20];
    char nama[20];
    char lokasi[20];
    struct komp* next;
};

struct komp* ht[20];

int hash(char* key){
    int a=0;
    for(int i=0; i<strlen(key); i++){
        a+=key[i];
    }
    return a%20;
}

void insert(char* ip, char* nama, char* lokasi){
    int index = hash(ip);
    struct komp* newNode = (struct komp*)malloc(sizeof(struct komp));
    strcpy(newNode->ip, ip);
    strcpy(newNode->nama, nama);
    strcpy(newNode->lokasi, lokasi);
    newNode->next = NULL;
    if(ht[index]==NULL){
        ht[index] = newNode;
    }
    else{
        struct komp* curr = ht[index];
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    printf("Data berhasil ditambahkan! \n");
}

void hapus(char* ip){
    int index = hash(ip);
    struct komp* curr = ht[index];
    struct komp* prev = NULL;
    while(curr!=NULL){
        if(strcmp(curr->ip, ip) == 0){
            if(prev == NULL){
                ht[index] = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
            printf("Data berhasil dihapus! \n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void disp(){
    int i;
    int a = 1;
    for(i=0; i<20; i++){
        struct komp* curr = ht[i];
        while(curr!=NULL){
            a = 0;
            printf("IP: %s\n", curr->ip);
            printf("Nama Komputer: %s\n", curr->nama);
            printf("Lokasi Komputer: %s\n", curr->lokasi);
            printf("\n");
            curr = curr->next;
        }
    }
    if(a == 1){
        printf("Tidak ada data! \n");
    }
}

void cari(char* ip){
    int index = hash(ip);
    struct komp* curr = ht[index];
    while(curr!=NULL){
        if(strcmp(curr->ip, ip) == 0){
            printf("IP: %s\n", curr->ip);
            printf("Nama Komputer: %s\n", curr->nama);
            printf("Lokasi Komputer: %s\n", curr->lokasi);
            return;
        }
        curr = curr->next;
    }
    printf("Data tidak ditemukan! \n");
}

int main() {
    char ip[20];
    char nama[20];
    char lokasi[20];
    
    char tumbal[3];
    int pil;
    do{
        system("clear");
        printf("1. Insert data\n");
        printf("2. Hapus data\n");
        printf("3. Liat data\n");
        printf("4. Cari data\n");
        printf("5. Insert data random\n");
        printf("0. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pil);
        switch(pil){
            case 1:
               system("clear");
               printf("IP: ");
               scanf(" %[^\n]", ip);
               printf("Nama Komputer: ");
               scanf(" %[^\n]", nama);
               printf("Lokasi: ");
               scanf(" %[^\n]", lokasi);
               insert(ip, nama, lokasi);
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
               
            case 2:
               system("clear");
               printf("IP Komputer yang ingin dihapus: ");
               scanf(" %[^\n]", ip);
               hapus(ip);
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
               
            case 3:
               system("clear");
               disp();
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
               
            case 4:
               system("clear");
               printf("IP Komputer yang ingin dilihat datanya: ");
               scanf(" %[^\n]", ip);
               cari(ip);
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
               
            case 5:
               srand(time(NULL));
               for(int i=0; i<4; i++){
               char* str = RandomString(5);
               char* rip = RandomIP();
               char* rlok = RandomLokasi();
               insert(rip, str, rlok);
               free(str);
               free(rip);
               free(rlok);
               }
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
        }
    }while(pil != 0);
    
    
    return 0;
}
