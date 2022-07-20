 #include <stdio.h> 
 #include <stdlib.h>  
 
struct one {
 	
 	char X ; 
 	int C ; 
 	char Y ; 
 	
 };
 
struct second {
 	
 	char X  , Y ;
 	int C ; 
 	
 }; 
 
 
int main(){
	
	printf ("The size of struct 'one' is : %d\n", sizeof(struct one));
	printf ("The size of struct 'second' is : %d\n", sizeof(struct second));	
	
}
