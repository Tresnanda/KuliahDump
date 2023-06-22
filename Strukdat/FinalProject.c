/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Item{
    int harga;
    char nama[30];
    int stock;
};

struct Acc{
    char username[40];
    char password[40];
};

struct Node{
    struct Item item;
    struct Node* next;
};

struct NodeUser{
    struct Acc account;
    struct NodeUser* next;
};
 
struct Queue{
    struct Node* head;
    struct Node* tail;
};

struct NodeTree{
    struct Node* list;
    int harga;
    struct NodeTree* left;
    struct NodeTree* right;
};

struct Table{
    struct Node* itemtable[SIZE];
};

struct TableAcc{
    struct NodeUser* usertable[SIZE];
};

struct NodeStack{
    struct Item item;
    struct NodeStack* next;
};

struct StackList{
    struct NodeStack* top;
};

struct NodeStack* newStackNode(struct Item* item){
    struct NodeStack* new = (struct NodeStack*)malloc(sizeof(struct NodeStack));
    new->item = *item;
    new->next = NULL;
    return new;
}

void pushStack(struct StackList* stack, struct Item* item){
    if(stack->top == NULL){
        stack->top = newStackNode(item);
        return;
    }
    struct NodeStack* new = newStackNode(item);
    new->next = stack->top;
    stack->top = new; 
}

struct NodeStack* popStack(struct StackList* stack){
    if(stack->top == NULL){
        printf("\t\t\t\tError!\n");
        return NULL;
    }
    struct NodeStack* curr = stack->top;
    stack->top = stack->top->next;
    return curr;
}


void printQueue(struct Queue* queue){
    if(queue->head == NULL){
        printf("\t\t\t\tTidak ada barang!\n");
        return;
    }
    struct Node* curr = queue->head;
    while(curr != NULL){
        printf("\t\t\t\t%-15sRp.%-15d%-15d\n", curr->item.nama, curr->item.harga, curr->item.stock);
        curr = curr->next;
    }
    printf("\n");
}

int hashindex(char *namabarang){
    int jml=0;
    for (int i=0; namabarang[i] != '\0'; i++){
        jml += namabarang[i];
    }
    return jml % SIZE;
}

int userindex(char *username){
    int jml=0;
    for(int i=0; username[i] != '\0'; i++){
        jml += username[i];
    }
    return jml % SIZE;
}

struct Node* insertNode(struct Item* item){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->item = *item;
    new->next = NULL;
    return new;
}

void enqueue(struct Queue* queue, struct Item* item){
    struct Node* new = insertNode(item);
    if(queue->head==NULL){
        queue->head=queue->tail=new;
        return;
    }
    queue->tail->next = new;
    queue->tail = new;
    
    
}

struct Node* dequeue(struct Queue* queue){
    if(queue->head == NULL){
        printf("\t\t\t\tError!\n");
        return NULL;
    }
    if(queue->head==queue->tail){
        struct Node* temp = queue->head;
        queue->head = queue->tail = NULL;
        return temp;
    }
    struct Node* curr = queue->head;
    queue->head = queue->head->next;
    return curr;
}

void insertHash(struct Table* table, struct Item* item){
    int index = hashindex(item->nama);
    if(table->itemtable[index] == NULL){
        table->itemtable[index] = insertNode(item);
        return;
    }
    struct Node* new = insertNode(item);
    struct Node* curr = table->itemtable[index];
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new;
}

void daftarAcc(struct TableAcc* table, struct Acc* account){
    int index = userindex(account->username);
    struct NodeUser* new = (struct NodeUser*)malloc(sizeof(struct NodeUser));
    new->account = *account;
    new->next = NULL;
    if(table->usertable[index] == NULL){
        table->usertable[index] = new;
        return;
    }
    struct NodeUser* curr = table->usertable[index];
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new;
}

struct Item* searchnama(struct Table* table, char* nama){
    int index = hashindex(nama);
    struct Node* curr = table->itemtable[index];
    
    while(curr != NULL){
        if(strcmp(curr->item.nama, nama) == 0){
            return &(curr->item);
        }
        curr = curr->next;
    }
    return NULL;
}

int login(struct TableAcc* table, char* username, char* password){
    int index = userindex(username);
    struct NodeUser* curr = table->usertable[index];
    while(curr!=NULL){
        if(strcmp(curr->account.username, username) == 0){
            if(strcmp(curr->account.password, password) == 0){
                return 1;
            }
            else{
                return 2;
            }
        }
        curr = curr->next;
    }
    return 3;
}

struct NodeTree* insertTree(struct Item* item){
    struct NodeTree* new = (struct NodeTree*)malloc(sizeof(struct NodeTree));
    new->harga = item->harga;
    new->list = insertNode(item);
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct NodeTree* BST(struct NodeTree* root, struct Item* item){
    if(root == NULL){
        return insertTree(item);
    }
    if(item->harga == root->harga){
        struct Node* curr = root->list;
        struct Node* new = insertNode(item);
        if(curr == NULL){
            root->list = new;
        }
        else{
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new;
        }
    }
    else if(item->harga < root->harga){
        root->left = BST(root->left, item);
    }
    else if(item->harga > root->harga){
        root->right = BST(root->right, item);
    }
    return root;
}

void cariHarga(struct NodeTree* root, int harga){
    if(root == NULL){
        return;
    }
    if(harga == root->harga){
        struct Node* curr = root->list;
        while(curr != NULL){
            printf("\t\t\t\t%-15sRp%-15d%-15d\n", curr->item.nama, curr->item.harga, curr->item.stock);
            curr = curr->next;
        }
    }
    else if(harga < root->harga){
        cariHarga(root->left, harga);
    }
    else if(harga > root->harga){
        cariHarga(root->right, harga);
    }
}

void inorder(struct NodeTree* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    struct Node* curr = root->list;
    while(curr != NULL){
        printf("\t\t\t\t%-15sRp%-15d%-15d\n", curr->item.nama, curr->item.harga, curr->item.stock);
        curr = curr->next;
    }
    inorder(root->right);
}

struct NodeTree* deleteNode(struct NodeTree* root, char* nama) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(root->list->item.nama, nama) == 0) {
        struct Node* temp = root->list;
        root->list = root->list->next;
        free(temp);

        //cek list kosong ato tidak
        if (root->list == NULL) {
            //gaada sisa, hapus
            struct NodeTree* tempNode = root;

            //list gapunya children
            if (root->left == NULL && root->right == NULL) {
                root = NULL;
            }
            //punya child kanan
            else if (root->left == NULL) {
                root = root->right;
            }
            //punya child kiri
            else if (root->right == NULL) {
                root = root->left;
            }
            //punya 2 child
            else {
                struct NodeTree* successor = root->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                successor->left = root->left;
                root = root->right;
            }

            free(tempNode);
        }

        return root;
    }

    root->left = deleteNode(root->left, nama);
    root->right = deleteNode(root->right, nama);

    return root;
}


void hapusItem(struct Table* table, struct NodeTree** root, char* nama) {
    int index = hashindex(nama);
    struct Node* curr = table->itemtable[index];
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->item.nama, nama) == 0) {
            if (prev == NULL) {
                table->itemtable[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    
    *root = deleteNode(*root, nama);
}

void printStack(struct StackList* stack){
    if(stack->top == NULL){
        printf("\t\t\t\tKeranjang kosong!\n");
        return;
    }
    struct NodeStack* curr = stack->top;
    while(curr != NULL){
        printf("\t\t\t\t%-15sRp%-15d%-15d\n", curr->item.nama, curr->item.harga, curr->item.stock);
        curr = curr->next;
    }
    printf("\n");
}

void tampilkan(struct Table* table) {
    int a=1;
    for (int i = 0; i < SIZE; i++) {
        struct Node* curr = table->itemtable[i];
        while (curr != NULL) {
            a=0;
            printf("\t\t\t\t%-15sRp%-15d%-15d\n", curr->item.nama, curr->item.harga, curr->item.stock);
            curr = curr->next;
        }
    }
    if(a==1){
        printf("\t\t\t\tTidak ada barang!\n");
        return;
    }
}

void stacktoqueue(struct StackList* stack, struct Queue* queue, struct Table* table, struct NodeTree** root){
    struct NodeStack* curr = stack->top;
    
    while(curr!=NULL){
        struct Item* item2 = searchnama(table, curr->item.nama);
        if(item2 != NULL){
            int a = curr->item.stock;
            item2->stock -= a;
            *root = deleteNode(*root, curr->item.nama);
            *root = BST(*root, item2);
            enqueue(queue, &(curr->item));
        }
        curr = curr->next;
    }
    
    stack->top = NULL;
    
}

int itemTerproses(struct Queue* src, struct Queue* dst){
    int ka = rand()%2;
    if(ka == 1){
        if(src->head == NULL){
            return 0;
        }
        struct Node* temp = dequeue(src);
        enqueue(dst, &(temp->item));
        return 1;
    }
    else if(ka == 2){
        return 0;
    }
}

int isEmptyQueue(struct Queue* queue){
    if(queue->head == NULL){
        return 1;
    }
    return 0;
}


void editItem(struct Table* table, struct NodeTree** root, char* nama) {
    struct Item* item = searchnama(table, nama);
    int choice;
    if (item == NULL) {
        printf("\t\t\t\tItem tidak ditemukan!\n");
        return;
    }
    printf("\t\t\t\tBarang ditemukan!\n");
    printf("\t\t\t\t1. Ubah nama\n");
    printf("\t\t\t\t2. Ubah harga\n");
    printf("\t\t\t\t3. Ubah stok\n");
    printf("\t\t\t\t0. Exit\n");
    printf("\t\t\t\tOpsi pilihan: ");
    scanf("%d", &choice);
    if(choice==1){
    printf("\t\t\t\tNama baru: ");
    scanf("%s", item->nama);
    }
    else if(choice==2){
    printf("\t\t\t\tHarga baru: ");
    scanf("%d", &(item->harga));
    }
    else if(choice==3){
    printf("\t\t\t\tStock baru: ");
    scanf("%d", &(item->stock));
    }
    else{
        printf("\t\t\t\tTidak ada opsi!\n");
    }

    *root = deleteNode(*root, nama);
    *root = BST(*root, item);

    printf("\t\t\t\tUpdate barang sukses!\n");
}


int main()
{
    struct Table table;
    struct TableAcc tableacc;
    for(int i=0; i<SIZE; i++){
        table.itemtable[i] = NULL;
        tableacc.usertable[i] = NULL;
    }
    
    struct NodeTree* root = NULL;
    struct StackList stack = { NULL };
    struct StackList history = { NULL };
    struct Queue queue = {NULL, NULL};
    struct Queue historyQueue = {NULL, NULL};
    struct Item ko = {2000, "a", 4};
    struct Item da = {1500, "b", 2};
    struct Acc admin = {"admin", "admin"};
    daftarAcc(&tableacc, &admin);
    struct Acc asd = {"pasir", "pasir"};
    daftarAcc(&tableacc, &asd);
    insertHash(&table, &ko);
    root = BST(root, &ko);
    insertHash(&table, &da);
    int init = 0;
    root = BST(root, &da);
    int choice;
    int choice2;
    int choice3;
    int choice4;
    char username[40];
    char password[40];
    char tumbal[3];
    int koa = 0;
    do{
        system("clear");
        printf("\n\n");
        printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
        printf ("\n");
        printf ("\t\t\t\t------- Login or Register -------- \n");
        printf("\t\t\t\t1. Login\n");
        printf("\t\t\t\t2. Register account\n");
        printf("\t\t\t\t0. Exit\n");
        printf ("\t\t\t\t----------------------------------\n");
        printf("\t\t\t\tOpsi pilihan: ");
        scanf("%d", &choice4);
        if(choice4 == 1){
            system("clear");
            printf("\n\n");
            printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
            printf ("\n");
            printf ("\t\t\t\t----------- Login Page ----------- \n");
            printf("\t\t\t\tUsername: ");
            fflush(stdin); getchar();
            scanf("%s", username);
            printf("\t\t\t\tPassword: ");
            fflush(stdin); getchar();
            scanf("%s", password);
            int a = login(&tableacc, username, password);
            if(strcmp(username, "admin") == 0 && a == 1){
                do{
                system("clear");
                printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                printf ("\n");
                printf ("\t\t\t\t------- Administrator Page -------- \n");
                printf("\t\t\t\t1. Insert barang baru \n");
                printf("\t\t\t\t2. Delete barang\n");
                printf("\t\t\t\t3. Cari barang\n");
                printf("\t\t\t\t4. List barang\n");
                printf("\t\t\t\t5. List terkecil\n");
                printf("\t\t\t\t6. Update barang\n");
                printf("\t\t\t\t0. Exit\n");
                printf ("\t\t\t\t----------------------------------\n");
                printf("\t\t\t\tOpsi pilihan: ");
                scanf("%d", &choice2);
                
                if(choice2 == 1){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t---------- Tambah Barang ---------- \n");
                    struct Item item;
                    printf("\t\t\t\tNama barang: ");
                    getchar();
                    scanf("%s", item.nama);
                    printf("\t\t\t\tHarga barang: "); scanf("%d", &item.harga);
                    printf("\t\t\t\tStock barang: "); scanf("%d", &item.stock);
                    insertHash(&table, &item);
                    root = BST(root, &item);
                    printf("\t\t\t\tBarang berhasil dimasukkan!\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 2){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t---------- Hapus Barang ----------- \n");
                    char namaHapus[30];
                    printf("\t\t\t\tNama barang yang ingin dihapus: ");
                    getchar();
                    scanf("%s", namaHapus);
                    struct Item* carinama = searchnama(&table, namaHapus);
                    if(carinama != NULL){
                        hapusItem(&table, &root, namaHapus);
                        printf("\t\t\t\tBarang berhasil dihapus!\n");
                    }
                    else{
                        printf("\t\t\t\tBarang tidak ditemukan!\n");
                    }
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 3){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t----------- Cari Barang ----------- \n");
                    printf("\t\t\t\t1. Cari dengan nama\n");
                    printf("\t\t\t\t2. Cari dengan harga\n");
                    printf("\t\t\t\t0. Exit\n");
                    printf ("\t\t\t\t----------------------------------\n");
                    printf("\t\t\t\tOpsi pilihan: ");
                    scanf("%d", &choice3);
                    if(choice3 == 1){
                        char b[30];
                        system("clear");
                        printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                        printf ("\n");
                        printf ("\t\t\t\t------------ Cari Nama ------------ \n");
                        printf("\t\t\t\tNama barang: ");
                        getchar();
                        scanf("%s", b);
                        b[sizeof(b)-1] = '\0';
                        struct Item* carinama = searchnama(&table, b);
                        if(carinama != NULL){
                            printf("\t\t\t\t%-15sRp%-15d%-15d\n", carinama->nama, carinama->harga, carinama->stock);
                        }
                        else{
                            printf("\t\t\t\tBarang tidak ditemukan!");
                        }
                        printf ("\t\t\t\t----------------------------------\n");
                        printf("\n\t\t\t\tTekan Enter untuk keluar ");
                        getchar();
                        fgets(tumbal, 3, stdin);
                    }
                    if(choice3 == 2){
                        int d;
                        system("clear");
                        printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                        printf ("\n");
                        printf ("\t\t\t\t------------ Cari Harga ----------- \n");
                        printf("\t\t\t\tHarga barang: ");
                        scanf("%d", &d);
                        printf("\t\t\t\tItem dengan harga %d yang ditemukan: \n", d);
                        cariHarga(root, d);
                        printf ("\t\t\t\t----------------------------------\n");
                        printf("\n\t\t\t\tTekan Enter untuk keluar ");
                        getchar();
                        fgets(tumbal, 3, stdin);
                    }
                }
                if(choice2 == 4){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t----------- List Barang ----------- \n");
                    //printf("\t\t\t\t");
                    tampilkan(&table);
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 5){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t------- List Barang Terurut ------- \n");
                    inorder(root);
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 6){
                    system("clear");
                    char b[30];
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t---------- Update Barang ---------- \n");
                    printf("\t\t\t\tNama barang: ");
                    fflush(stdin); getchar();
                    scanf("%s", b);
                    editItem(&table, &root, b);
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
            }while(choice2 != 0);
            }
            else if(strcmp("admin", username) != 0 && a == 1){
                do{
                int kurang;
                int updated;
                if(isEmptyQueue(&queue)){
                    init = 0;
                    koa = 0;
                }
                if(init == 1 &&koa <= 2){
                    koa++;
                }
                else if(init == 1 && koa >2){
                    itemTerproses(&queue, &historyQueue);
                    //updated = queue->head->item.stock;
                    
                }
                system("clear");
                printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                printf ("\n");
                printf ("\t\t\t\t------------ User Page ------------ \n");
                printf("\t\t\t\t1. Cari barang\n");
                printf("\t\t\t\t2. List barang\n");
                printf("\t\t\t\t3. Masukkan ke kerangjang\n");
                printf("\t\t\t\t4. Liat Keranjang\n");
                printf("\t\t\t\t5. Hapus barang dari kerangjang\n");
                printf("\t\t\t\t6. Undo penghapusan dari keranjang\n");
                printf("\t\t\t\t7. Barang yang sedang diproses\n");
                printf("\t\t\t\t8. History pembelian\n");
                printf("\t\t\t\t9. List terkecil\n");
                printf("\t\t\t\t0. Exit\n");
                printf ("\t\t\t\t----------------------------------\n");
                printf("\t\t\t\tOpsi pilihan: ");
                scanf("%d", &choice2);
                
                if(choice2 == 1){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t----------- Cari Barang ----------- \n");
                    printf("\t\t\t\t1. Cari dengan nama\n");
                    printf("\t\t\t\t2. Cari dengan harga\n");
                    printf("\t\t\t\t0. Exit\n");
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\t\t\t\tOpsi pilihan: ");
                    scanf("%d", &choice3);
                    if(choice3 == 1){
                        char b[30];
                        system("clear");
                        printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                        printf ("\n");
                        printf ("\t\t\t\t------------ Cari Nama ------------ \n");
                        printf("\t\t\t\tNama barang: ");
                        getchar();
                        scanf("%s", b);
                        b[sizeof(b)-1] = '\0';
                        struct Item* carinama = searchnama(&table, b);
                        if(carinama != NULL){
                            char m;
                            printf("\t\t\t\t%-15sRp%-15d%-15d\n", carinama->nama, carinama->harga, carinama->stock);
                            printf("\n\t\t\t\tMasukkan ke keranjang? (y/n): "); getchar();
                            scanf("%c", &m);
                            if(m == 'y' || m == 'Y'){
                                printf("\t\t\t\tJumlah barang: ");
                                scanf("%d", &kurang);
                                if(kurang > carinama->stock){
                                    printf("\t\t\t\tStock tidak cukup!\n");
                                }
                                else{
                                    struct Item newItem = *carinama;
                                    newItem.stock = kurang;
                                    pushStack(&stack, &newItem);
                                }
                            }
                            
                        }
                        else{
                            printf("Barang tidak ditemukan!");
                        }
                        printf ("\t\t\t\t-----------------------------------\n");
                        printf("\n\t\t\t\tTekan Enter untuk keluar ");
                        getchar();
                        fgets(tumbal, 3, stdin);
                    }
                    if(choice3 == 2){
                        int d;
                        system("clear");
                        printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                        printf ("\n");
                        printf ("\t\t\t\t------------ Cari Harga ----------- \n");
                        printf("\t\t\t\tHarga barang: ");
                        scanf("%d", &d);
                        printf("\t\t\t\tItem dengan harga %d yang ditemukan: \n", d);
                        cariHarga(root, d);
                        printf ("\t\t\t\t-----------------------------------\n");
                        printf("\n\t\t\t\tTekan Enter untuk keluar ");
                        getchar();
                        fgets(tumbal, 3, stdin);
                    }
                }
                if(choice2 == 2){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t----------- List Barang ----------- \n");
                    tampilkan(&table);
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 3){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t------ Masukkan ke Keranjang ------ \n");
                    char b[30];
                    printf("\t\t\t\tNama barang: ");
                    getchar();
                    scanf("%s", b);
                    b[sizeof(b)-1] = '\0';
                    struct Item* carinama = searchnama(&table, b);
                    if(carinama != NULL){
                        printf("\t\t\t\tJumlah barang: "); scanf("%d", &kurang);
                        if(kurang > carinama->stock){
                            printf("\t\t\t\tStock tidak cukup!\n");
                        }
                        else{
                            struct Item newItem = *carinama;
                            newItem.stock = kurang;
                            pushStack(&stack, &newItem);
                            printf("\t\t\t\tItem dengan nama %s berhasil dimasukkan ke keranjang!\n", carinama->nama);
                        }
                    }
                    else{
                        printf("\t\t\t\tItem tidak ditemukan!\n");
                    }
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                    
                }
                if(choice2 == 4){
                    int asd;
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t--------- Liat Keranjang ---------- \n");
                    printStack(&stack);
                    printf("\t\t\t\t1. Checkout\n");
                    printf("\t\t\t\t0. Exit\n");
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\t\t\t\tOpsi pilihan: ");
                    scanf("%d", &asd);
                    if(asd == 1){
                    system("clear");
                        /**struct NodeStack* terproses;
                        struct Node* terproses2;
                        while(stack.top != NULL){
                            terproses = popStack(&stack);
                            struct Item ka = terproses->item;
                            enqueue(&queue, &ka);
                        }**/
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t--------- Liat Keranjang ---------- \n");
                    stacktoqueue(&stack, &queue, &table, &root);
                    init = 1;
                    printf("\t\t\t\tBerhasil checkout!\n");
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);    
                    }
                    
                }
                if(choice2 == 5){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t-------- Hapus Keranjang ---------- \n");
                    struct NodeStack* dihapus = popStack(&stack);
                    if(dihapus != NULL){
                        printf("\t\t\t\tItem dengan nama %s berhasil dikeluarkan dari keranjang!\n", dihapus->item.nama);
                        pushStack(&history, &dihapus->item);
                    }
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 6){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t--------- Undo Keranjang ---------- \n");
                    struct NodeStack* terhapus = popStack(&history);
                    if(terhapus != NULL){
                       printf("\t\t\t\tItem dengan nama %s dimasukkan kembali ke keranjang!\n", terhapus->item.nama);
                       pushStack(&stack, &terhapus->item); 
                    }
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 7){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t-------- Barang Diproses ---------- \n");
                    printQueue(&queue);
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 8){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t----- History Pembelanjaan -------- \n");
                    printQueue(&historyQueue);
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
                if(choice2 == 9){
                    system("clear");
                    printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
                    printf ("\n");
                    printf ("\t\t\t\t------- List Barang Terurut ------- \n");
                    inorder(root);
                    printf ("\t\t\t\t-----------------------------------\n");
                    printf("\n\t\t\t\tTekan Enter untuk keluar ");
                    getchar();
                    fgets(tumbal, 3, stdin);
                }
            }while(choice2 != 0);
            }else if(a == 2){
                printf("\t\t\t\tUsername atau Password salah!\n");
                printf ("\t\t\t\t-----------------------------------\n");
                printf("\n\t\t\t\tTekan Enter untuk keluar ");
                getchar();
                fgets(tumbal, 3, stdin);
            }
            else if(a == 3){
                printf("\t\t\t\tAccount tidak ditemukan!\n");
                printf ("\t\t\t\t-----------------------------------\n");
                printf("\n\t\t\t\tTekan Enter untuk keluar ");
                getchar();
                fgets(tumbal, 3, stdin);
            }
        }
        else if(choice4 == 2){
            struct Acc daftar;
            system("clear");
            printf ("\t\t\t\t=== Final Project Struktur Data ===\n");
            printf ("\n");
            printf ("\t\t\t\t---------- Register Page ---------- \n");
            printf("\t\t\t\tUsername baru: ");
            fflush(stdin); getchar();
            scanf("%s", daftar.username);
            printf("\t\t\t\tPassword baru: ");
            fflush(stdin); getchar();
            scanf("%s", daftar.password);
            daftarAcc(&tableacc, &daftar);
            printf("\t\t\t\tBerhasil daftar!\n");
            printf ("\t\t\t\t-----------------------------------\n");
            printf("\n\t\t\t\tTekan Enter untuk keluar ");
            getchar();
            fgets(tumbal, 3, stdin);
            
        }
    }while(choice4 != 0);
    return 0;
}







