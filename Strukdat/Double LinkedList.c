#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct List{
    struct Node* head;
};

void insert(struct List* llist, int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if(llist->head == NULL){
        llist->head = new;
        return;
    }
    if(llist->head->next == NULL){
        llist->head->next = new;
        new->prev = llist->head;
        return;
    }
    struct Node* curr = llist->head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new;
    new->prev = curr;
}

void hapus(struct List* list, int data){
    if(list->head == NULL){
        printf("Tidak ada data!");
        return;
    }
    struct Node* curr = list->head;
    if(list->head->data == data){
        if(list->head->next == NULL){
            list->head = NULL;
            printf("Data berhasil dihapus!");
            return;
        }
        else if(list->head->next != NULL){
            list->head = list->head->next;
            free(curr);
            printf("Data berhasil dihapus!");
            return;
        }
    }
    while(curr!=NULL && curr->data != data){
        curr = curr->next;
    }
    if(curr == NULL){
        printf("Data tidak ditemukan!");
        return;
    }
    if(curr->next == NULL){
        curr->prev->next = NULL;
        free(curr);
        printf("Data berhasil dihapus!");
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
    printf("Data berhasil dihapus!");
}

void display(struct List* list){
    struct Node* curr = list->head;
    if(list->head == NULL){
        printf("Tidak ada data!");
        return;
    }
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main()
{
    struct List list = {NULL};
    int data;
    int choice;
    char tumbal[3];
    do{
        system("clear");
        printf("1. Insert data");
        printf("\n2. Delete data");
        printf("\n3. Display list");
        printf("\n0. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                system("clear");
                printf("Data yang ingin diinsert: ");
                scanf("%d", &data);
                insert(&list, data);
                printf("Data berhasil diinsert!\n");
                printf("\nTekan Enter untuk keluar ");
                getchar();
                fgets(tumbal, 3, stdin);
                break;
            case 2:
                system("clear");
                printf("Data yang ingin dihapus: ");
                scanf("%d", &data);
                hapus(&list, data);
                printf("\nTekan Enter untuk keluar ");
                getchar();
                fgets(tumbal, 3, stdin);
                break;
            case 3:
                system("clear");
                display(&list);
                printf("\nTekan Enter untuk keluar ");
                getchar();
                fgets(tumbal, 3, stdin);
                break;
        }
    }while(choice!=0);

    return 0;
}
