#include <stdio.h>
#include <stdlib.h>

struct list 
{
	int id  ;
	short int value ; 	 
	struct list * next ; 	
};

struct list *createList (int v, short int value) // Create a list with a node
{
	struct list * head ; 
	
	head = (struct list *) malloc (sizeof (struct list));
	head->id = v;
	head->value = value;
	head->next = NULL;
	if (head!= NULL) return head ;	
	else printf ("Operation failed\n");
}

 struct list *insertNodeList(int v,short int value, struct list *head) {  // Input a node at the end of the list
   struct list *node, *returnValue;
   struct list *node2 = head;  
   node = (struct list *)malloc(sizeof(struct list));
   node->id = v;
   node->value = value;
   node->next = NULL;
   if (head == NULL) {  
     returnValue = node;      
     return returnValue;
   }
   while (node2->next != NULL)  
        node2 = node2->next;
   node2->next = node;
   return head;
 }


struct list * deleteFirstNode(struct list *head) // ???????? ?????? ??? ???? ??? ?????? 3
{  

struct list *ptr=head;
struct list *tmp;

if (ptr != NULL)
{
	tmp = ptr;
    ptr = ptr->next;
    free(tmp);	
    return ptr ; 
}
else
{
    printf ("The list is empty.\n");	
    return NULL ; 
}
}


int numOfElements (struct list *l) // Return the number of elements (nodes) that the list has
{

struct list * tmp = l ; 	
int counter = 0 ;	
	
while (tmp!=NULL)
{
	counter++ ; 
	tmp = tmp->next ; 
}	
return counter ;	
}

void printElement(int id, struct list *ptr) // Searches a node with the specified id and prints its id and value
{ 

  struct list * tmp = ptr ; 

  while (tmp!=NULL )
  {
  	if (tmp->id==id){
       printf("Id: %d value: %d\n", tmp->id, tmp->value);
       return;
    }                
  	else tmp = tmp->next ;  	
  }
  
  printf ("The searched value is not found.\n");
     
}

void printElementAddress(int id, struct list *ptr){ // Searches a node with the specified id and prints its address
     
  struct list * tmp = ptr ; 

  while (tmp!=NULL )
  {
  	if (tmp->id==id){
       printf("Address of element: %x\n", tmp);
       return;
    }                
  	else tmp = tmp->next ;  	
  }
  
  printf ("The searched value is not found.\n") ;       
}

void printFieldAddress(int id, struct list *ptr) // Searches a node with the specified id and prints the address of one of its fields
{ 

struct list * tmp = ptr ;
int choice; 

  while (tmp!=NULL )
  {
  	if (tmp->id==id){
       printf("Enter which field's address you want printed. 1 for id, 2 for value.\n");
       scanf("%d", &choice);
       if(choice==1)
	   {
            printf("Address of id is: %x", &(tmp->id));
       }
       else if(choice==2){
            printf("Address of value is: %x", &(tmp->value));     
       }
       else{ 
            printf("Invalid choice.\n");
       }
       return;    
       
    }                
  	else tmp = tmp->next ;  	
  }
  
  printf ("The searched value is not found.\n");
     
}

void printListAddress (struct list *head) //Prints the address of the list
{
	printf ("The address of the list is : %x.\n",head);	
}

void printSizeOfElement () // Prints the size of a node 10
{
	printf ("The size of an element is : %d bytes.\n",sizeof(struct list));
        return	 ;
}

void printSizeOfList (struct list * head) // Prints the size of list in bytes
{
    printf ("\nThe size of the list is : %d bytes.\n",sizeof(struct list)*numOfElements(head));
   
    struct list * tmp = head ; 
    long long sum=0;
    for(; tmp->next!=NULL; tmp=tmp->next){
        sum = sum + (long long) (tmp->next - tmp);
}
    printf("\nThe size of the list in bytes is:%d", sum);
  
}

struct list * (*createListPtr) (int, short int);
void (*printSizeOfElementPtr) () ;
void (*printSizeOfListPtr) (struct list * );
void (*printListAddressPtr) (struct list *);
void (*printFieldAddressPtr)(int , struct list *);
void (*printElementAddressPtr)(int , struct list *);
void (*printElementPtr)(int , struct list *);
int (*numOfElementsPtr) (struct list *) ;
struct list * (*deleteFirstNodePtr)(struct list *);
struct list * (*insertNodeListPtr)(int,short int , struct list *);
 void (*printFunctionPtr)();

void printFunction()
{
    int choice ; 
    
    printf ("You can print the addresses of following functions : \n");
    
    while(1)
    {       
       printf ("1.createList() \n");
       printf ("2.insertNodeList() \n");
       printf ("3.deleteFirstNode() \n");
       printf ("4.numOfElements() \n");
       printf ("5.printElement()\n");
       printf ("6.printElementAddress()\n");
       printf ("7.printFieldAddress() \n");
       printf ("8.printListAddress()\n");
       printf ("9.printSizeOfElement() \n");
       printf ("10.printSizeOfList()\n");             
       printf ("11.printFunction()\n");
       printf ("12.Exit the function printing menu");   

       printf ("Choose the respective number of the function you wish to print :  \n");       
       scanf ("%d", &choice);
       switch(choice)
       {
           case 1:
               printf ("The address of the createList() function is :%x .  \n",createListPtr);
               break ;            
           case 2:
               printf ("The address of the insertNodeList() function is :%x .  \n",insertNodeListPtr);
               break ;
           case 3:
               printf ("The address of the deleteFirstNode() function is :%x .  \n",deleteFirstNodePtr);
               break ;
           case 4:
               printf ("The address of the numOfElements() function is :%x .  \n",numOfElementsPtr);
               break ;
           case 5:
               printf ("The address of the printElement() function is :%x .  \n",printElementPtr);
               break ;
           case 6:
               printf ("The address of the printElementAddress() function is :%x .  \n",printElementAddressPtr);
               break ;
           case 7:
                printf ("The address of the printFieldAddress() function is :%x .  \n",printFieldAddressPtr);
               break ;
           case 8:
               printf ("The address of the printListAddress() function is :%x .  \n",printListAddressPtr);
               break ;
           case 9:
                printf ("The address of the printSizeOfElement() function is :%x .  \n",printSizeOfElementPtr);
               break ;
           case 10:
                printf ("The address of the printSizeOfList() function is :%x .  \n",printSizeOfListPtr);
               break ;
           case 11:
               printf ("The address of the printFunction() function is :%x .  \n",printFunctionPtr);
               break ;
           case 12 :
               return ;
               break ;
           default :
               printf ("Please choose one of the following options.\n");		
               break; 
       }
    }
}

int main (){
	
struct list * head = NULL ; 
int choice ,  id = 1 , list_created = 0 ; 
short int value ;
	
	
printf ("The software offers you the following options : \n");
printf ("Please enter your choice (1-12) : \n\n");

while (1) // It will exit only if the user chooses 11 
{	
	printf ("\n1) Create a list.\n")	; // User Menu
	printf ("2) Input a value at the end of the list.\n")	;
	printf ("3) Delete the first value of the list.\n")	;
	printf ("4) Print a value of the list.\n")	;
	printf ("5) Receive the number of values the list contains.\n")	;
	printf ("6) Print the memory address of a node.\n")	;
	printf ("7) Print the memory address of the list.\n")	;
	printf ("8) Print the memory address of the value of the node.\n")	;
	printf ("9) Print the size of the list in bytes.\n")	;
	printf ("10) Print the size of an element in bytes.\n")	;
        printf ("11) Print the address of a function.\n")	;
	printf ("12) Exit the software.\n\n")	;
	
	scanf ("%d", &choice);
	
	switch (choice)
	{
		case 1 :
			if (!list_created) // If the list is not created
			{   
                            createListPtr = &createList;
                            printf("Enter the value of the element.\n");
                            scanf("%hd", &value);
                            list_created = 1 ;	 // Shows that a list is created .
			    head = createListPtr(id,value);
                            id++; 			
			}
			else printf ("You have already created a list!\n");
			break;
		case 2 :
			if (list_created) // If the list is created
			{ 
                            insertNodeListPtr = &insertNodeList;
                            printf("Enter the value of the element.\n");
                            scanf("%hd", &value);			
                            head = insertNodeListPtr(id,value,head);
			    id++;
                         }
			else printf ("You must create a list first.\n")	;
			break;		
		case 3 :
			if (list_created)
                        {
                                deleteFirstNodePtr = &deleteFirstNode ;
				head = deleteFirstNodePtr (head); 
                        }
			else printf ("You must create a list first.\n")	;
			break;		
		case 4 :
			if (list_created)
			{  
                           int temp;
                           printElementPtr = &printElement ;
			   printf("Enter which element of the list you want printed. (1 for the first, and so on.)\n");	
			   scanf("%d", &temp);
			   printElementPtr(temp,head);
			}
			else printf ("You must create a list first.\n")	;
			break;			
		case 5 :
			if (list_created)	
                        {
                            numOfElementsPtr = &numOfElements ;
                            printf ("The list contains %d values.\n",numOfElementsPtr(head));	
                        }
			else printf ("You must create a list first.\n")	;
			break;			
		case 6 :
			if (list_created)
			{   
                            int temp;
                            printElementAddressPtr = &printElementAddress ;
			   printf("Enter which element of the list you want its address printed. (1 for the first, and so on.)\n");	
			   scanf("%d", &temp);	
			   printElementAddressPtr(temp,head);
			}
			else printf ("You must create a list first.\n")	;		
			break;			
		case 7 :
			if (list_created)
				printf ("The address of the list is %x", head );
			else printf ("You must create a list first.\n");	
			break;			
		case 8 :
			if (list_created)
			{   
                            int temp;
                            printFieldAddressPtr = &printFieldAddress ;
			    printf("Enter which element of the list you want printed. (1 for the first, and so on.)\n");	
			    scanf("%d", &temp);
                            printFieldAddressPtr(temp,head);
			}
			else printf ("You must create a list first.\n")	;
			break;			
		case 9 :
			if (list_created)                            
                        {
                            printSizeOfListPtr = &printSizeOfList; 
                            printSizeOfListPtr(head);
                        }
                        else printf ("You must create a list first.\n")	;
			break;			
		case 10 :
			if (list_created)
                        {
                            printSizeOfElementPtr = printSizeOfElement;
                            printSizeOfElementPtr();
                        }						
			else printf ("You must create a list first.\n")	;
                        break ; 
                case 11: 
                        if (list_created)
                        {
                            printFunctionPtr = printFunction ;
                            printFunctionPtr();  
                         }
                        else printf ("You must create a list first.\n")	; 
                        break;
		case 12 :
			return (EXIT_SUCCESS); 
		default :
			printf ("Please choose one of the following options.\n");		
			break ;
	}
}
}
