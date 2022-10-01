#include <stdio.h>
#include <iostream>
#include <string>

#pragma region utils

// returns string format of given array
std::string array2string(int arr[], int length)
{
    std::string output = "[";

    for(int i=0; i<length; i++)
    {
        output += std::to_string(arr[i]);

        // close parentheses at last index, else seperate
        if (i == length-1)
        {
            output += "]";
        } 
        else
        {
            output += ", ";
        }

    }

    return output;
}

// swaps the address of given integer variables
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// returns the minimum element' index from array
int findMinIndex(int arr[], int length, int currentIndex=0)
{
    int minIndex = currentIndex;

    for(int i=currentIndex; i<length; i++)
    {
        if (arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }

    return minIndex;
}

#pragma endregion

/*

    ~~ selection sort - [https://www.geeksforgeeks.org/selection-sort]

    algorithm:
        - initialize current index with zero
        - find minimum element in the array from current index
        - swap minimum element with current element
        - increment current index and repeat
    
    time complexity ~~O(n^2):
        - one loop to find minimum element in the array ~~O(n)
        - another recursive loop to iterate through all elements in the array ~~O(n)

    auxiliary space ~~O(1):
        - as the only extra memory used is for temporary variables while swapping values in array
        - since it never makes more than O(n) swaps, can be useful when memory write is a costly operation

    stability:
        - not stable
    
    in place:
        - yes, it doesn't require extra space
    
*/
void selectionSort(int arr[], int length, int currentIndex=0)
{
    // end recursion at the end of the array
    if (currentIndex == length+1)
    {
        return;
    }

    // find minimum element index for the rest of the array
    int minIndex = findMinIndex(arr, length, currentIndex);

    // swap current index with minimum element index
    swap(&arr[minIndex], &arr[currentIndex]);

    // start sorting from next index
    selectionSort(arr, length, currentIndex+1);
}

// to be implemented
void bubbleSort(int arr[], int length, int currentIndex=0)
{}


int main(){
    
    int inputs[] = {38, 27, 43, 3, 9, 82, 10};
    auto length = sizeof(inputs)/sizeof(inputs[0]);

    selectionSort(inputs, length);
    
    std::cout << array2string(inputs, length);

    return 0;
}