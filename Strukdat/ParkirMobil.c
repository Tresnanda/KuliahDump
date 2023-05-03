

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mobil{
    int nomor;
    struct mobil* next;
};

struct antrian{
    struct mobil* head;
    struct mobil* tail;
};

struct stack{
    struct mobil* top;
};

void enqueue(struct antrian* Antrian, int a){
    struct mobil* temp = (struct mobil*)malloc(sizeof(struct mobil));
    temp->nomor = a;
    temp->next = NULL;
    
    if(Antrian->head == NULL){
        Antrian->head=Antrian->tail=temp;
    }
    else{
        Antrian->tail->next = temp;
        Antrian->tail = temp;
    }
}

void push(struct stack* Stack, struct mobil* mobil){
    struct mobil* temp = (struct mobil*)malloc(sizeof(struct mobil));
    if(Stack->top == NULL){
        Stack->top = mobil;
        mobil->next = NULL;
    }
    else{
        mobil->next = Stack->top;
        Stack->top = mobil;
    }
}

struct mobil* pop(struct stack* Stack){
    if(Stack->top == NULL){
        printf("Stack is empty!\n");
        return NULL;
    }
    else{
        struct mobil* temp = Stack->top;
        Stack->top = Stack->top->next;
        return temp;
    }
}

struct mobil* pophead(struct antrian* Antrian){
    if(Antrian->head == NULL){
        printf("ANTRIAN KOSONG! \n");
        return NULL;
    }
    else{
        struct mobil* temp = Antrian->head;
        Antrian->head = Antrian->head->next;
        return temp;
    }
}

void printstack(struct stack* Stack){
    if(Stack->top == NULL){
        printf("Stack kosong, tidak ada yang bisa diprint! \n");
        return;
    }
    else{
        struct mobil* temp = Stack->top;
        printf("\nMobil yang dikeluarkan sementara: ");
        while(temp != NULL){
            //if(temp->nomor != 0){
            printf("%d, ", temp->nomor);
            //}
            temp = temp->next;
        }
    }
}



void dequeue(struct antrian* Antrian, struct stack* Stack, int a){
    struct mobil* temp1 = Antrian->head;
    if(Antrian->head == NULL){
        printf("Antrian Kosong\n");
        return;
    }
    
    if(Antrian->head->nomor == a){
        Antrian->head = Antrian->head->next;
        free(temp1);
        printf("Mobil %d berhasil keluar! \n", a);
        return;
    }
    struct mobil* current = Antrian->head;
    struct mobil* prev = NULL;
    struct mobil* temp = NULL;
    struct mobil* headtemp = NULL;
    struct mobil* poptemp = NULL;
    
    while(current != NULL && current->nomor != a){
        prev = current;
        current = current->next;
    }
    temp = current;
    if(current != NULL){
        while(Antrian->head->nomor != current->nomor){
            headtemp = pophead(Antrian);
            push(Stack, headtemp);
        }
        printstack(Stack);
        current = current->next;
        Antrian->head = current;
        free(temp);
        while(Stack->top != NULL){
            poptemp = pop(Stack);
            poptemp->next = Antrian->head;
            Antrian->head = poptemp;
        }
        printf("\n");
        printf("Mobil %d telah keluar dari antrian\n", a);
    }
    else{
        printf("Mobil tidak ditemukan dalam antrian! \n");
    }
}





void tampilkan(struct antrian* Antrian){
    struct mobil* temp = Antrian->head;
    if(Antrian->head == NULL){
        printf("Antrian kosong!\n");
    }
    else{
        printf("Mobil dalam antrian: ");
    while(temp != NULL){
        printf("%d ", temp->nomor);
        temp = temp->next;
    }
    printf("\n");
    }
}
int main()
{
    int opsi;
    int keluar;
    char tumbal[3];
    int jumlah=1;
    struct antrian Antrian = {NULL};
    struct stack Stack = {NULL};
    do{
        system("clear");
        printf("1. Masukan mobil\n");
        printf("2. Keluarin mobil\n");
        printf("3. Liat mobil\n");
        printf("4. Liat Stack\n");
        printf("5. Keluar\n");
        printf("Opsi: ");
        scanf("%d", &opsi);
        switch(opsi){
            case 1:
            system("clear");
               printf("\n");
               enqueue(&Antrian, jumlah);
               printf("Mobil %d masuk!\n", jumlah);
               jumlah++;
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
            case 2:
               system("clear");
               printf("Mobil yang ingin dikeluarkan: ");
               scanf("%d", &keluar);
               dequeue(&Antrian, &Stack, keluar);
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
            case 3:
               system("clear");
               tampilkan(&Antrian);
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
            case 4:
               system("clear");
               printstack(&Stack);
               printf("\nTekan Enter untuk keluar ");
               getchar();
               fgets(tumbal, 3, stdin);
               break;
               
        }
    }while(opsi != 5);
    return 0;
}

