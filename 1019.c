#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int hours = N / 3600; 
    N %= 3600;            

    int minutes = N / 60; 
    N %= 60;              

    int seconds = N;      

    printf("%d:%d:%d\n", hours, minutes, seconds);
    
    return 0;
}
