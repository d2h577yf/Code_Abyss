#include <stdio.h>

int main() {
    int speed, limit;
    scanf("%d %d", &speed, &limit);
if(speed < limit*1.1){
  printf("OK\n");
}else if(speed >=(int)limit*1.1 && speed < (int)limit *1.5){
  printf("Exceed %.0f%%.Ticket 200",(double)speed/limit*10);
}else{
  printf("Exceed %.0f%%. License Revoked",(double)speed/limit*10);
}

    return 0;
}