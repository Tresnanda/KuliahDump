#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void insert(struct LinkedList* list, int data, char mode, int target) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;

    if (list->head == NULL) { //kalo kosong
        list->head = newNode;
        newNode->next = NULL;
        return;
    }

    if (mode == 'h') { // push head
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    if (mode == 't') { //push tail
        struct Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        return;
    }
    
    struct Node* temp = list->head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) { //node target ditemukan
        free(newNode);
        printf("Error, node target tidak ditemukan! \n");
        return;
    }

    if (mode == 'b') { // push sebelum target
        newNode->next = temp; //node baru akan menunjuk next pada target node
        if (prev != NULL) {
            prev->next = newNode; //node sebelumnya target node akan menunjuk next pada node baru
        } else {
            list->head = newNode; 
        }
        return;
    }

    if (mode == 'a') { // insert after target node
        newNode->next = temp->next; //node baru akan menunjuk next pada node setelah target node
        temp->next = newNode; //target node akan menunjuk next pada node baru
        return;
    }
}

void delete(struct LinkedList* list, int data) {
    struct Node* temp = list->head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        list->head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}
void pophead(struct LinkedList* list){
    if(list->head == NULL){
        printf("Linked list kosong, tidak ada yang bisa dihapus! \n");
        return;
    }
    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
} //end void

void poptail(struct LinkedList* list){
    if(list->head == NULL){
        printf("Linked list kosong, tidak ada yang bisa dihapus! \n");
        return;
    }
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        return;
    }
    
    struct Node* temp = list->head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteafter(struct LinkedList* list, int data){
    struct Node* temp = list->head;
    while(temp != NULL && temp->data != data){
        temp = temp->next;
    }
    if(temp == NULL || temp->next==NULL){
        printf("Tidak dapat dihapus! \n");
        return;
    }
    struct Node* dihapus = temp->next;
    temp->next = temp->next->next;
    free(dihapus);
}

void printList(struct LinkedList* list) {
    struct Node* temp = list->head;
    if(temp == NULL){
        printf("Linked list kosong!");
        exit(1);
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList list1 = {NULL}; //posisi linked list = {}

    insert(&list1, 5, 'h', 0); //insert 5 pada head     posisi linked list = {5}
    printf("Linked list setelah insert head dengan nilai 5: "); printList(&list1);
    insert(&list1, 10, 't', 0); //insert 10 pada tail.  posisi linked list = {5, 10}
    printf("\nLinked list setelah insert tail dengan nilai 10: "); printList(&list1);
    insert(&list1, 7, 'b', 10); //insert 7 sebelum 10.  posisi linked list = {5, 7, 10}
    printf("\nLinked list setelah insert elemen 7 sebelum nilai 10: "); printList(&list1);
    insert(&list1, 8, 'a', 10); //insert 8 setelah 10.  posisi linked list = {5, 7, 10, 8}
    printf("\nLinked list setelah insert elemen setelah nilai 10: "); printList(&list1);
    pophead(&list1);
    printf("\nLinked list setelah pop head: "); printList(&list1);  //pophead linked list = {7,10,8}
    deleteafter(&list1, 7); //menghapus elemen setelah 7 linked list = {7,8}
    printf("\nLinked list setelah menghapus elemen setelah 7: "); printList(&list1);
    poptail(&list1); //menghapus tail linked list = {7}
    printf("\nLinked list setelah pop tail: "); printList(&list1);
    delete(&list1, 7); //menghapus elemen 7 alias satu satunya elemen posisi linked list = {}
    printf("\nLinked list setelah menghapus elemen 7: "); printList(&list1);
    
    return 0;
}
