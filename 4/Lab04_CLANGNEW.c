#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

long long int R0 = 0;

long long int R1 = 1, R2 = 0, R3 =2, R4 = 1, R5 = 0 , R6 = 0, R7 = 0, R8 = 0 , R9 , R10, R11, R12, R13, R14 = 3, R15 = 4, R16 = 9, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27 = NULL, R28, R29, R30, R31;
static jmp_buf buf ;

struct list 
{
    int id  ;
    short int value ; 	 
    struct list * next ; 	
};

void insertNodeList() {   // Input a node at the end of the list

R25 = (long long) malloc(sizeof(struct list));     
((struct list *)R25)->id = (int)  ++R4;
((struct list *)R25)->value = (short int)  R5;
((struct list *)R25)->next = (struct list*) R27;	

if (R6 != (long long)((struct list*)R27)) goto afterif ;  
     R2 = R25;  // Return value   
longjmp(buf,1);
afterif :
whileinsert :

if  (((struct list *)R6)->next == NULL)  goto afterloop ;
R6 = (long long)((struct list *)R6)->next;        
goto whileinsert; 

afterloop :
   ((struct list *)R6)->next = (struct list*)R25;      
longjmp(buf,1);
 }

void (*InsertNodeList)(void) = &insertNodeList;

void createList () // Create a list with a node
{     	
    if (R22 == R0) 
	{
		printf ("You have not created a list");	
		longjmp(buf,1);			
	}
	else if (R22 < R0)
	{
		printf ("Error! Enter a positive integer!\n");	
		longjmp(buf,1);	
	}
	else 
	{
		R8 = 1 ; // A list is created                	
		R6 = (long long) (malloc (sizeof(struct list)));
                                
                ((struct list *)R6)->id = (int)  R4;
		((struct list *)R6)->value = (short int)  R5;
                ((struct list *)R6)->next = (struct list*) R27;
		--R22 ; 
                R2 = R6 ; 
		longjmp(buf,1);	
	}	
	
	if (R6 == (long long) NULL) goto elsecreate ;
             R2 = R6 ; 
             longjmp(buf,1);	
             
	elsecreate :
	printf ("Operation failed\n");
        longjmp(buf,1);	
}

void deleteLastNode()   // Delete the last node of the list
{      
  if ((R6 != (long long) NULL) && (((struct list *)R6)->next==NULL))
  {
       free((struct list *)R6);
       R2 = (long long) NULL; // return value
  }
   else if (R2 == (long long) NULL)
   {
       printf ("The list is empty.\n");
   }
   else
   {
     while(((struct list *)R6)->next != NULL)
     {
        R28 = R6;
        R6= (long long)((struct list *)R6)->next;
     }
     free((struct list *)R6);
     ((struct list *)R28)->next=NULL; 
  }      
  longjmp(buf,1); 
}

void printElement ()  // Searches a node with the specified id and prints its id and value
{     
    whileprint :	
        if (R6 == (long long) NULL ) goto afterprint_loop ; 
        if (((struct list *)R6)->id != R7) goto elseprint_label ; 

        printf("Id: %d value: %d\n", ((struct list *)R6)->id,((struct list *)R6)->value);
        longjmp(buf,1);

        elseprint_label: 
              R6 = (long long) ((struct list *)R6)->next ;  

              goto whileprint ;	
                 afterprint_loop :  
                    printf ("The searched value is not found.\n");
                               longjmp(buf,1);     
}

void numOfElements ()
{    
    R22 = 0 ;
    while (R6 != (long long) NULL)
    {
	R22++ ; 
	R6 = (long long) ((struct list *)R6)->next ; 
    }
    
    printf ("The number of elements is : %ld.\n",R22);
    longjmp(buf,1);
}

void nodeAddress ()
{    
  
  while (R6 != (long long) NULL )
  {
        if (((struct list *)R6)->id==R7)
        {
            printf("Address of element: %x\n", R6);
             longjmp(buf,1);
        }                
  	else R6 = (long long) ((struct list *)R6)->next ;   	
  }
  printf ("The searched value is not found.\n") ; 
  longjmp(buf,1);
}

void listAddress ()
{
    printf ("The address of the list is : %x.\n",R2);
    longjmp(buf,1);
}

void minimumValue ()
{   
    if (R2 == (long long) NULL)        
    {
        printf ("The list is empty.\n");
        longjmp(buf,1);
    }
    else 
    {
    	
    while (R6 != (long long) NULL)
    {
	if ((((struct list *)R7)->value) > ((struct list *)R6)->value) R7 = R6 ;
	R6 = (long long) ((struct list *)R6)->next ; 
    }
    
    printf ("The node with the minimum value is : \n");
    printf ("Address : %d\n",((struct list *)R7));
    printf ("Id : %d\n",((struct list *)R7)->id);
    printf ("Value : %d\n",((struct list *)R7)->value);
    longjmp(buf,1);
    }
    longjmp(buf,1);
}

int main () {
	
 //  R18 : choice ,  R8 : list_created , R4 : id , R5 : value ,R6 head as parameter ,R7 id choice / tmpHead  , R0 , R1 , R3 , R14 ,R15,  R16 constants  
 // R2 returns head  , R20 call function , R22 : numofElements , R24 MinValue Node , R25 newNode , R27 NULL 
    
  // Function Pointers  
void (*CreateList)(void) = &createList;
void (*PrintElement)(void) = &printElement; 
void (*DeleteLastNode)(void) = &deleteLastNode;
void (*NumOfElements)(void) = &numOfElements;
void (*NodeAddress)(void) = &nodeAddress;
void (*ListAddress)(void) = &listAddress;
void (*MinimumValue)(void) = &minimumValue;
	
printf ("The software offers you the following options : \n");
printf ("Please enter your choice (1-9) : \n");

while_label : 
	
	printf ("\n1) Create a list.\n")	; // User Menu
	printf ("2) Input a value at the end of the list.\n")	;
	printf ("3) Delete the last value of the list.\n")	;
	printf ("4) Print a value of the list.\n")	;
	printf ("5) Print the number of nodes.\n")	; // User Menu
	printf ("6) Print the address of a node.\n")	;
	printf ("7) Print the address of the list.\n")	;
	printf ("8) Print the minimum value.\n")	;
	printf ("9) Exit the software.\n\n")	;
	
        scanf ("%Ld",&R18);  
	
	if (R18 < R1 ) goto else_label ;  
	if (R18 > R16) goto else_label ; 	
        
                if (R18 != R1) goto case2_label ; // case 1
                if (R8 != R0) goto else1_label;	 
        
                printf ("Enter the number of nodes , you wish the list to have : ");     
                scanf ("%Ld",&R22);  
                
                if (R22 <= R0) goto aftermainif ;
                
                    printf ("Enter the value of the first node : ");
                    scanf ("%Ld",&R5); 	// First Node
                    aftermainif :                
                
                R6 = R2; // Head Parameter
                R20 = (long long)CreateList;                                       
                if(!setjmp(buf)) goto *R20; 
                
                whilemain :
                    if ((R22--) == R0) goto after_while ;                    
                    printf ("Enter the value of the node : ");
                    scanf ("%Ld",&R5); 	// First Node
                    R6 = R2; // Parameter
                    R20 = (long long)InsertNodeList;                        
                    if(!setjmp(buf)) goto  *R20 ; 
                    goto whilemain ;
                after_while :
                
                goto while_label ; 		
			
                 else1_label :
			printf ("You have already created a list!\n");
			goto while_label ; 
		                        
                        
		case2_label : // case 2
			
                if (R18 != R3) goto case3_label ; 
		if (R8 == R0) goto else2_label ;
			
                     printf("Enter the value of the element.\n\n");
                     scanf("%Ld", &R5);	// Parameter
                     R6 = R2; 
                     R20 = (long long)InsertNodeList;                        
                     if(!setjmp(buf)) goto  *R20 ;                  
                        
        		goto while_label ; 
			
			else2_label :
			printf ("You have not created a list!\n\n");
			goto while_label;
				
                                           
		case3_label : // case 3
				
                        if (R18 != R14) goto case4_label ;			
			if (R8 == R0) goto else3_label ;
			     
                            R6 = R2;   // Parameter        
                            R20 = (long long)DeleteLastNode;                        
                            if(!setjmp(buf)) goto *R20 ; 
                                
			goto while_label ;
		
			else3_label :
			printf ("You have not created a list!\n\n");
			goto while_label ; 
			
			
		case4_label :
			
                        if (R18 != R15) goto case5_label ; // case 4
			if (R8 == R0) goto else4_label ;
			 
                           printf("Enter which element of the list you want printed. (1 for the first, and so on.)\n");	
			   scanf("%Ld", &R7); // Parameter
                           R6 = R2;
                           R20 = (long long)PrintElement;                        
                           if(!setjmp(buf)) goto  *R20 ;                            
			  
			goto while_label ; 			
			
			else4_label : // case 5
			printf ("You have not created a list!\n\n");
			goto while_label ; 
                                                                                       
                    case5_label :					
				
                        if (R18 != 5) goto case6_label ; // case 5
                        if (R8 == R0) goto else5_label ;	
                        
                            R6 = R2 ; // Parameter
                            R20 = (long long)NumOfElements;                        
                            if(!setjmp(buf)) goto  *R20 ; 
                        
                           goto while_label ; 			
			
			else5_label : // case 5
			printf ("You have not created a list!\n\n");
			goto while_label ;                        
                        
                    case6_label :	// case 6				
					
                        if (R18 != 6) goto case7_label ;  
			if (R8 == R0) goto else6_label ;	
                        
                             printf("Enter which element of the list you want its address printed. (1 for the first, and so on.)\n");	
                             scanf("%Ld", &R7); // Parameters
                             R6 = R2 ; 
                             R20 = (long long)NodeAddress;                        
                             if(!setjmp(buf)) goto  *R20 ; 
                        
                           goto while_label ; 			
			
			else6_label : // case 5
			printf ("You have not created a list!\n\n");
			goto while_label ; 
                        
                        
                    case7_label :	// case 7	 			
					
                        if (R18 != 7) goto case8_label ; 
                        if (R8 == R0) goto else7_label ;
                        
                            R6 = R2;
                            R20 = (long long)ListAddress;                        
                            if(!setjmp(buf)) goto  *R20 ; 
                        
                           goto while_label ; 			
			
			else7_label : 
			printf ("You have not created a list!\n\n");
			goto while_label ;
                        
                        
                    case8_label :	// case 8				
					
                        if (R18 != 8) goto case9_label ; 	
			if (R8 == R0) goto else8_label ;
                        
                        R6 = R2 ; // Parameters
                        R7 = R2 ;
                        R20 = (long long)MinimumValue;                        
                        if(!setjmp(buf)) goto  *R20 ; 
                        
                        goto while_label ; 			
			
			else8_label :
                        printf ("You have not created a list!\n\n");
                        goto while_label ;
                                                                                                
                    case9_label :  // case 9  
                        printf ("You have exited the software!\n\n");
                        return(EXIT_SUCCESS);  
                    
                        
                        else_label :	// default				
			printf ("Please choose one of the following options.\n\n");		
				
			goto while_label ;
	}

