#include <stdio.h>

int i,j;

i=1;
j=1;
int main(){

    while (i<5||j>=0){
        i=i+1;
        j=j-1;
    }
printf("%d %d",i,j);

return 0;
}