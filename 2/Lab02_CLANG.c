#include <stdio.h>
#include <stdlib.h>

int R0 = 0;

int R1 = 1, R2, R3 =2, R4 = 3 , R5 = 4, R6 = 5, R7, R8 = 0 , R9 = 1, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31;

struct list 
{
	int id  ;
	short int value ; 	 
	struct list * next ; 	
};

struct list *createList (int R9 ,int R10) // Create a list with a node
{
	struct list * head ; 
	
	head = (struct list *) malloc (sizeof (struct list));
	head->id = R9;
	head->value = R10;
	head->next = NULL;
	if (head == NULL) goto elsecreate ; 	
	 return head ;	
	
	elsecreate :
	printf ("Operation failed\n");
	
}

 struct list *insertNodeList(int R9,int R10, struct list *head) {   // Input a node at the end of the list
   struct list *node, *returnValue;
   struct list *node2 = head;  
   node = (struct list *)malloc(sizeof(struct list));
   node->id = R9;
   node->value = R10;
   node->next = NULL;
   
   if (head != NULL) goto afterif ;  
     returnValue = node;       
     return returnValue;
     
     afterif :
   
   whileinsert :
   
   if  (node2->next == NULL)  goto afterloop ;
        node2 = node2->next;
        goto whileinsert; 
        
        afterloop : 
        
   node2->next = node;
   return head;
 }


struct list * deleteFirstNode(struct list *head)   // Delete the first node of the list
{  

struct list *ptr=head;
struct list *tmp;

if (ptr == NULL) goto elsedelete ;

	tmp = ptr;
    ptr = ptr->next;
    free(tmp);	
    return ptr ;     

elsedelete :
 printf ("The list is empty.\n");	
 return NULL ; 
}

void printElement (int R9, struct list *ptr)  // Searches a node with the specified id and prints its id and value
{ 

  struct list *tmp = ptr ; 

whileprint :
	
  if (tmp == NULL ) goto afterprint_loop ; 
  
  	if (tmp->id != R9) goto elseprint_label ; 
	
       printf("Id: %d value: %d\n", tmp->id, tmp->value);
       return;
                   
  	elseprint_label: 
	  tmp = tmp->next ;  
	  
	  goto whileprint ;	
  afterprint_loop :
  
  printf ("The searched value is not found.\n");
     
}

int main () {
	
struct list * head = NULL ;  // R7 : choice ,  R8 : list_created , R9 : id , R10 : value , R11 : head (pointer)
	
printf ("The software offers you the following options : \n");
printf ("Please enter your choice (1-5) : \n\n");

while_label : 
	
	printf ("\n1) Create a list.\n")	; // User Menu
	printf ("2) Input a value at the end of the list.\n")	;
	printf ("3) Delete the first value of the list.\n")	;
	printf ("4) Print a value of the list.\n")	;
	printf ("5) Exit the software.\n\n")	;
	
	scanf ("%d", &R7);
	
	if (R7 < R1 ) goto else_label ;  // default για το αρχικο switch
	if (R7 > R6) goto else_label ; 
	
	if (R7 != R1) goto case2_label ; // case 1

		if (R8 != 0) goto else1_label;
			  
				printf("Enter the value of the element.\n");
                scanf("%d", &R10);
                R8 = 1 ;	
				head = createList(R9,R10);
                R9++; 	
				goto while_label ; 		
			
			else1_label :
			printf ("You have already created a list!\n");
			goto while_label ; 
		
		case2_label :
			
	if (R7 != R3) goto case3_label ; // case 2
			
			if (R8 == 0) goto else2_label ;
			
                printf("Enter the value of the element.\n");
                scanf("%d", &R10);			
                // R8 = (int)pointer
                // pointer = (void *)R8
                
				head = insertNodeList(R9,R10,head);
				R9++;
        		goto while_label ; 
			
			else2_label :
			printf ("You have already created a list!\n");
			goto while_label;
				
		case3_label :
				
	if (R7 != R4) goto case4_label ; // case 3
			
			if (R8 == 0) goto else3_label ;
			
				head = deleteFirstNode (head); 
				goto while_label ;
		
			else3_label :
			printf ("You have already created a list!\n");
			goto while_label ; 
			
			
		case4_label :
			
	if (R7 != R5) goto case5_label ; // case 4
	
			if (R8 == 0) goto else4_label ;
			 
               printf("Enter which element of the list you want printed. (1 for the first, and so on.)\n");	
			   scanf("%d", &R11);
			   printElement(R11,head);
			   goto while_label ; 			
			
			else4_label : // case 5
			printf ("You have already created a list!\n");
			goto while_label ; 
						
			
	case5_label : return (0);					
					
			else_label :	// default				
			printf ("Please choose one of the following options.\n");
			
				
			goto while_label ;
	}

