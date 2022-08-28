#include <stdio.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(){
    
    int inputs[] = {38, 27, 43, 3, 9, 82, 10};
    int length = sizeof(inputs) / sizeof(inputs[0]);
    
    for (int i = 0; i < length-2; i++) {
        
        // find minimum in sublist
        int minIndex = i;
        for (int j = i; j < length-1; j++) {
            if (inputs[j] < inputs[minIndex]){
                minIndex = j;
            }
        }

        swap(&inputs[i], &inputs[minIndex]);
    }

    // display
    for (int i=0; i<length-1; i++){
        printf("%d ", inputs[i]);
    }    
    
    return 0;
}