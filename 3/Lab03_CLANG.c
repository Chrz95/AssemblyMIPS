#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

long long R0 = 0;

long long R1 = 1, R2, R3 =2, R4 = 1, R5, R6, R7, R8 , R9 , R10, R11, R12, R13, R14 = 3, R15 = 4, R16 = 5, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27 = (long)NULL, R28, R29, R30, R31;
static jmp_buf buf ;



struct list 
{
	int id  ;
	short int value ; 	
	struct list * next ;	
};

void createList () // Create a list with a node
{        
       // struct list * head ;
	R24 = (long long) malloc (sizeof (struct list));
	struct list *head = (struct list*)R24;
	
	R27 = (long long) NULL;
	
	head->id = R4;
	head->value = R5;
	head->next = (struct list*) R27;
	R9 = (long long)head;
	
	if (R9 == R27) goto elsecreate ; 	

R2  =  R9;
longjmp(buf,1);
	
	elsecreate :
	printf ("Operation failed\n");
longjmp(buf,1);	
}
   void insertNodeList() {   // Input a node at the end of the list

R25 = (long long) malloc(sizeof(struct list)); 
R23 = R2;     
((struct list *)R25)->id = (int)  R4;
((struct list *)R25)->value = (short int)  R5;
((struct list *)R25)->next = (struct list*) R27;	

if (R23 != (long long)((struct list*)R27)) goto afterif ;  
     R2 = R25;     
longjmp(buf,1);
afterif :
whileinsert :

if  (((struct list *)R23)->next == NULL)  goto afterloop ;
R23 = (long long)((struct list *)R23)->next;        
goto whileinsert; 

afterloop :
   ((struct list *)R23)->next = (struct list*)R25;      
longjmp(buf,1);
 }


void deleteFirstNode()   // Delete the first node of the list
{  

struct list *ptr = (struct list *) R2;
struct list *tmp;

if (ptr == ((struct list*)R27)) goto elsedelete ;

	tmp = ptr;
ptr = ptr->next;
free(tmp);	
    R2 = (long long) ptr ;
longjmp(buf,1); 


elsedelete :
printf ("The list is empty.\n");	
longjmp(buf,1); 
}

void printElement ()  // Searches a node with the specified id and prints its id and value
{ 

struct list *tmp = (struct list * )R2; 

whileprint :
	
if (tmp == ((struct list*)R27) ) goto afterprint_loop ; 

	if (tmp->id != R7) goto elseprint_label ; 
	
printf("Id: %d value: %d\n", tmp->id, tmp->value);
longjmp(buf,1);

	elseprint_label: 
	tmp = tmp->next ;  
	
	goto whileprint ;	
afterprint_loop :

printf ("The searched value is not found.\n");
longjmp(buf,1);

}

int main () {
	
 //  R18 : choice ,  R8 : list_created , R4 : id , R5 : value  , R1 , R3 , R14 ,R15,  R16 are constants defined above , 
 //  R2 returns head  , R20 call function, R9 has the value of head, R27 contains NULL

  // Function Pointers  
void (*CreateList)(void) = &createList;
void (*InsertNodeList)(void) = &insertNodeList;
void (*PrintElement)(void) = &printElement; 
void (*DeleteFirstNode)(void) = &deleteFirstNode;
	
	
printf ("The software offers you the following options : \n");
printf ("Please enter your choice (1-5) : \n\n");

while_label :
	
	printf ("\n1) Create a list.\n")	; // User Menu
	printf ("2) Input a value at the end of the list.\n")	;
	printf ("3) Delete the first value of the list.\n")	;
	printf ("4) Print a value of the list.\n")	;
	printf ("5) Exit the software.\n\n")	;
	
	scanf ("%Ld", &R18);
	
	if (R18 < R1 ) goto else_label ;  
	if (R18 > R16) goto else_label ; 
	
			if (R18 != R1) goto case2_label ; // case 1
			if (R8 != R0) goto else1_label;	
			printf("Enter the value of the element.\n");
scanf("%Ld", &R5);

			 R8 = 1 ;

                R20 = (long long)CreateList;                        
if(!setjmp(buf)) goto  *R20 ;

               		 R4++;
goto while_label ; 	
			else1_label :
			printf ("You have already created a list!\n");
			goto while_label ; 
		
		case2_label :
			
			if (R18 != R3) goto case3_label ; // case 2
			if (R8 == R0) goto else2_label ;
			
printf("Enter the value of the element.\n");
scanf("%Ld", &R5);			


                     R20 = (long long)InsertNodeList;                        
if(!setjmp(buf)) goto  *R20 ; 
				


			R4++;
			goto while_label ; 			
			else2_label :
			printf ("You have not created a list!\n");
			goto while_label;
				
	case3_label :
				
			if (R18 != R14) goto case4_label ; // case 3			
			if (R8 == R0) goto else3_label ; 
               		 R20 = (long long)DeleteFirstNode;                        
if(!setjmp(buf)) goto  *R20 ; 

			goto while_label ;		
			else3_label :
			printf ("You have not created a list!\n");
			goto while_label ; 
			
			
	case4_label :
			
			if (R18 != R15) goto case5_label ; // case 4	
			if (R8 == R0) goto else4_label ;
			
printf("Enter which element of the list you want printed. (1 for the first, and so on.)\n");	
scanf("%Ld", &R7);
R20 = (long long)PrintElement;                        
if(!setjmp(buf)) goto  *R20 ; 

			
			goto while_label ; 			
			
			else4_label : // case 5
			printf ("You have not created a list!\n");
			goto while_label ; 
						
			
	case5_label : return (0);					
					
			else_label :	// default				
			printf ("Please choose one of the following options.\n");		
				
			goto while_label ;
	}

