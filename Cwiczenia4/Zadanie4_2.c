#include <stdio.h>

int binary_search(int *p_tablica, int left, int right, int target){
    if (right >= left){
        int mid = left + (right - left) / 2;

        if(p_tablica[mid] == target){
            return mid;
        }
        if(p_tablica[mid] > target){
            return binary_search(p_tablica,left,mid-1,target);
        } else {
            return binary_search(p_tablica,mid+1,right,target);
        }

    }
    return -1;

}



int main(){

    int tablica[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p_tablica = &tablica[0];
    int n = sizeof(tablica) / sizeof(tablica[0]);
    int target;
    printf("Podaj element, ktory chcesz znalezc: ");
    scanf("%d",&target);
    int result = binary_search(p_tablica,0,n-1,target);

    if (result == -1)
        printf("Element %d nie zostal znaleziony w tablicy.\n", target);
    else
        printf("Element %d zostal znaleziony na indeksie %d.\n", target, result);

    return 0;

}