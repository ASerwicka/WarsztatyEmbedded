#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "array.h"

typedef struct tTuple2
{
    int firstOfPair;
    int secondOfPair;
} tTuple2;

typedef struct tTuple3
{
    int firstOfPair;
    int secondOfPair;
    int thirdOfPair;
} tTuple3;

tTuple2 * sumOfTwo(int * inputArray, int targetSum){

    tTuple2 *result = NULL;
    int inputArrayLength = array_length(inputArray);

    for (int i = 0; i < inputArrayLength; ++i){
        insert(targetSum-inputArray[i],inputArray[i]);
    }

    for (int i = 0; i < inputArrayLength; ++i){
        item = search(inputArray[i]);
        if(item != NULL)
        {
            tTuple2 cTuple;
            cTuple.firstOfPair = inputArray[i];
            cTuple.secondOfPair = item->data;
            array_push(result,cTuple);
        }
    }
    return result;
}

tTuple3 * sumOfThree(int * inputArray, int targetSum){

    tTuple3 *result = NULL;
    int* arrayOfTargetSums = NULL;
    int inputArrayLength = array_length(inputArray);

    for (int i = 0; i < inputArrayLength; ++i){
        array_push(arrayOfTargetSums,targetSum-inputArray[i]);
    }

    for (int i = 0; i < inputArrayLength; ++i){

        int targetSumInner = arrayOfTargetSums[i];

        tTuple2 *resultInner = NULL;

        for (int j = 0; j < inputArrayLength; ++j){
            if(i!=j) {
                insert(targetSumInner - inputArray[j], inputArray[j]);
            }
        }

        display();

        for (int j = 0; j < inputArrayLength; ++j) {
            if(i!=j) {
                item = search(inputArray[j]);
                if (item != NULL) {
                    tTuple3 cTuple;
                    cTuple.firstOfPair = inputArray[j];
                    cTuple.secondOfPair = item->data;
                    cTuple.thirdOfPair = targetSum - arrayOfTargetSums[i];
                    array_push(result, cTuple);
                }
            }
        }
        clear();
    }
    return result;
}

void print3(tTuple3* array)
{
    printf("[");
    for(int i=0;i< array_length(array);i++)
    {
        printf("(%d, ",array[i].firstOfPair);
        printf("%d, ",array[i].secondOfPair);
        printf("%d)",array[i].thirdOfPair);
    }
    printf("]");
}

void print2(tTuple2* array)
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
    array_push(array,4);
    array_push(array,3);
    array_push(array,2);

    tTuple3* result = sumOfThree(array,6);

    print3(result);

    return EXIT_SUCCESS;
}



