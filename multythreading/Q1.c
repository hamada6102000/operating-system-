#include <pthread.h> //libaray thread
#include <stdio.h>   //libaray i/o
#include <stdlib.h>
#include <time.h> //libaray for random
int counter = 0;  // global variable
int count[5] = {0};
int sum = 0;
void *thread_code(void *param) //function choose random number
{
    int low = 1;
    int up = 10;
    srand(time(0));
    count[counter] = ((rand() % (up - low + 1)) + low);
    counter++;
}
int main() // main function
{
    pthread_t thread[5];        //create 5 thread
    for (int i = 0; i < 5; i++) // loop for create threads
    {
        pthread_create(&thread[i], 0, thread_code, 0);
    }

    for (int i = 0; i < 5; i++) // loop for waiting to finish all thraed
    {
        pthread_join(thread[i], 0);
    }
    for (int i = 0; i < 5; i++)
    {
        sum = sum + count[i]; // varible sum to sum all random number
    }
    printf(" sum for five thread = %d \n", sum); // print sum
}
