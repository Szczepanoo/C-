#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;
    printf("===[LISTA]===\n");
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void add_first(node_t **head, int val) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}


int pop(node_t ** head){
    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return -1;
    }

    int value = (*head)->val;
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);

    return value;
}

int remove_last(node_t ** head){
    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return -1;
    }

    int value;
    // Jeśli lista ma tylko jeden element
    if ((*head)->next == NULL) {
        value = (*head)->val;
        free(head);
        head = NULL;
        return value;
    }

    // Jeśli ma więcej
    node_t *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    value = current->next->val;
    free(current->next);
    current->next = NULL;

    return value;
}

int remove_by_index(node_t **head, int index) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return -1;
    }

    if (index < 0) {
        printf("Niepoprawny indeks.\n");
        return -1;
    }

    if (index == 0) {
        // Jeśli usuwamy pierwszy element
        int value = (*head)->val;
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return value;
    }

    node_t *current = *head;
    node_t *prev = NULL;
    int i = 0;

    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Indeks poza lista.\n");
        return -1;
    }

    int value = current->val;
    prev->next = current->next;
    free(current);

    return value;
}

int remove_by_value(node_t **head, int value) {
    if (*head == NULL) {
        printf("Lista jest pusta.");
        return -1;
    }

    node_t *current = *head;
    node_t *prev = NULL;

    // Szukamy węzła z daną wartością
    while (current != NULL && current->val != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Nieznaleziono wartosci.\n");
        return -1;
    }

    // Jeśli znaleziono wartość na początku listy
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    int removed_value = current->val;
    free(current);

    return removed_value;
}

void add_by_index(node_t **head, int index, int value) {
    if (index < 0) {
        printf("Niepoprawny indeks.\n");
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->val = value;

    if (index == 0) { // Dodanie na początek listy
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node_t *current = *head;
    node_t *prev = NULL;
    int i = 0;

    // Szukamy pozycji, na której chcemy wstawić nowy element
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (i != index) {
        printf("Indeks poza lista.\n");
        return;
    }

    // Wstawiamy nowy element między poprzedni a obecny element
    prev->next = new_node;
    new_node->next = current;
}

int main(){
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = NULL;



    char opcjaStr[2];
    int opcja = -1;

    while (opcja != 8) {
        print_list(head);
        printf("===[MENU]===\n");
        printf("1. Dodanie elementu na koncu listy. \n");
        printf("2. Dodanie elementu na poczatku listy. \n");
        printf("3. Dodanie elementu na okreslony indeks.\n");
        printf("4. Usuwanie pierwszego elementu. \n");
        printf("5. Usuwanie ostatniego elementu. \n");
        printf("6. Usuwanie konkretnego elementu (po indeksie).\n");
        printf("7. Usuwanie pierwszego elementu z okreslona wartoscia.\n");
        printf("8. Wyjscie. \n");
        printf("Wybierz numer: ");
        scanf("%1s",opcjaStr);
        opcja = atoi(opcjaStr);
        int value;
        int index;
        switch (opcja) {

            case 1:
                printf("Podaj wartosc do dodania: \n");
                scanf("%d",&value);
                push(head,value);
                break;
            case 2:
                printf("Podaj wartosc do dodania: \n");
                scanf("%d",&value);
                add_first(&head,value);
                break;
            case 3:
                printf("Podaj wartosc do dodania: \n");
                scanf("%d",&value);
                printf("Podaj indeks elementu: \n");
                scanf("%d",&index);
                add_by_index(&head,index,value);
                break;
            case 4:
                printf("Usunieta wartosc: %d\n",pop(&head));
                break;
            case 5:
                printf("Usunieta wartosc: %d\n",remove_last(&head));
                break;
            case 6:
                printf("Podaj indeks elementu do usuniecia: \n");
                scanf("%d",&index);
                printf("Usunieta wartosc: %d\n",remove_by_index(&head,index));
                break;
            case 7:
                printf("Podaj wartosc do usuniecia: \n");
                scanf("%d",&value);
                remove_by_value(&head,value);
                break;
            case 8:
                printf("Do zobaczenia.");
                break;
            default:
                printf("Podano nieprawdilowy numer. Wybierz ponownie. \n");
                break;
        }

    }
    return 0;
}