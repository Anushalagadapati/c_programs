#include<stdio.h>
int main() 
{ 
    int x = 10, y = 5; 
  
    // Code to swap 'x' and 'y' 
   /* x = x + y; // x now becomes 15 
    y = x - y; // y becomes 10 
    x = x - y; // x becomes 5 */

 	x= x ^ y;
    	y = x^ y;
    	x = x ^ y;    
	printf("%d,%d\n",x,y); 
} 
