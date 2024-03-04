#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void hanoi(int n, char Beginning, char Destination, char Helper)
{
    if(n>0){
        hanoi(n-1, Beginning, Helper, Destination);
        hanoi(n-1, Helper, Destination, Beginning);
    }
    else{
        return;
    }
}


long long AmountOfMoves(int disc)
{
    long long result=1;
    for(int i=1; i<=disc; i++){
        result = result * 2;
    }
    return (result - 1);
}



int main()
{

    int n;

    char beginning_position = 'A';
    char destination = 'C';
    char helper = 'B';

    double total_duration=0.0;

    clock_t start, end;

    printf(" Amount of discs / Amount of moves / Amount of time\n");
    printf(" ---------------   ---------------   --------------\n");



    for(int i=1; i<=32; i++){
        n = i;

        start = clock();
        hanoi(n, beginning_position, destination, helper);
        end = clock();

        double duration = ((double)end - start)/CLOCKS_PER_SEC;

        total_duration = total_duration + duration;

        printf("%8d disc %13lld moves %11f second\n",n,AmountOfMoves(i),duration);
    }
    printf("\n Total process time  =  %9f second\n",total_duration);





    return 0;
}
