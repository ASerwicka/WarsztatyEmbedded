#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "array.h"

typedef struct tTuple
{
    int firstOfPair;
    int secondOfPair;
} tTuple;


tTuple * sumOfTwo(int * inputArray, int targetSum){

    tTuple *result = NULL;
    int inputArrayLength = array_length(inputArray);

    for (int i = 0; i < inputArrayLength; ++i){
        insert(targetSum-inputArray[i],inputArray[i]);
    }

    for (int i = 0; i < inputArrayLength; ++i){
        item = search(inputArray[i]);
        if(item != NULL)
        {
            tTuple cTuple;
            cTuple.firstOfPair = inputArray[i];
            cTuple.secondOfPair = item->data;
            array_push(result,cTuple);
        }
    }
    return result;
}

void print(tTuple* array)
{
    printf("[");
    for(int i=0;i< array_length(array);i++)
    {
        printf("(%d, ",array[i].firstOfPair);
        printf("%d)",array[i].secondOfPair);
    }
    printf("]");
}

int main (int argc, char * argv[])
{
    int* array = NULL;
    array_push(array,1);
    array_push(array,5);
    array_push(array,3);
    array_push(array,7);
    array_push(array,-1);

    tTuple* result = sumOfTwo(array,6);

    print(result);

    return EXIT_SUCCESS;
}



