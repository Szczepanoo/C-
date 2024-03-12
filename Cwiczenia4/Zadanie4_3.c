#include "stdio.h"


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *p_arr, int start, int end){
    if (start == end){
        for (int i = 0; i <= end; i++){
            printf("%d",p_arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++){
            swap(&p_arr[start], &p_arr[i]);
            permute(p_arr, start + 1, end);
            swap(&p_arr[start], &p_arr[i]);
        }
    }

}

int main(){
    int n;
    printf("Podaj liczbe elementow ciagu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Podaj kolejno elementy ciagu (zatwierdz ENTER'em).\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d:",i+1);
        scanf("%d", &arr[i]);
    }

    int *p_arr = &arr[0];

    printf("Permutacje ciagu:\n");
    permute(p_arr, 0, n - 1);


    return 0;
}