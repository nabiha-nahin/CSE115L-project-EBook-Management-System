#include <stdio.h>
#include <stdlib.h>



 int main( void )
 {

  int x;
  int y;
  int z;
  printf("Input the value of x: ");
  scanf("%d", &x);
  printf("Input the value of y: ");
  scanf("%d", &y);
  printf("z: ");
  scanf("%d", &z);

  printf("The total is %d\n", x*y*z);
  printf("The total is %d", x+y-z);

  return 0;
}
