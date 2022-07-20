 #include <stdio.h> 
 #include <stdlib.h>  
 
int main(){
	
	short int * ten1; 
	short int * ten2 ; 
	double * sixteen ; 
	double * thirytwo ;  
	
	ten1 = (short int * ) malloc (5*sizeof(short int)); // 10 bytes
	ten2 = (short int * ) malloc (5*sizeof(short int)); // 10 bytes
	sixteen = (double *) malloc  (2*sizeof (double)); // 16 bytes
	thirytwo = (double *) malloc  (4*sizeof (double)); // 32 bytes
	
	printf ("The first 'ten' array address is : %d",ten1);
	printf ("\nThe second 'ten' array address is : %d",ten2);
	printf ("\nThe 'sixteen' array address is : %d",sixteen);
	printf ("\nThe 'thirytwo' array address is : %d",thirytwo);
}
