 #include <stdio.h> 
 #include <stdlib.h>  
 
 int glob;
 
int main(){
	
	int local; 
	int *ptr ;	
		
	ptr = (int *)malloc (5*sizeof(int)) ;
	
	printf ("The main() function address is : %x" , &main);
	printf ("\nThe global variable address is : %x" , &glob);
	printf ("\nThe local variable address is : %x" , &local);
	printf ("\nThe dynamically allocated memory address is : %x" , ptr);
}
