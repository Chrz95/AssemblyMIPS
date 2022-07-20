.data
.globl askint
.globl repint
Menu_Print: .asciiz "Printing the menu : "
Choice1: .asciiz "1) Create a list"
Choice2: .asciiz "2) Input a value at the end of the list."
Choice3: .asciiz "3) Delete the first value of the list."
Choice4: .asciiz "4) Print a value of the list."
Choice5: .asciiz "5) Exit the software.: "
repint: .asciiz "The inserted value is : "
ChoicePrint: .asciiz "You chose : "
newline: .asciiz "\n"
endword : .asciiz "You have exited the software. "

.text
.globl main
main:

li $v0, 4 			 # 4 is the code to print a string
la $a0, Menu_Print  # a0 is the pointer to the string to # print and gets the value from # "variable" Menu_Print  					 
syscall

li $v0, 4 	
la $a0, newline	

loopstart : 

li $v0, 4 	
la $a0, newline	
syscall		

li $v0, 4 	
la $a0, newline	
syscall

					 
li $v0, 4 			 # 4 is the code to print a string
la $a0, Choice1 	 		# "1) Create a list"
syscall

li $v0, 4 	
la $a0, newline
syscall
					 
li $v0, 4 			# "2) Input a value at the end of the list."
la $a0, Choice2 					 
syscall

li $v0, 4 	 
la $a0, newline	
syscall
					 
li $v0, 4 			# "3) Delete the first value of the list."
 la $a0, Choice3 						 
syscall

li $v0, 4 	
la $a0, newline	
syscall
					 
li $v0, 4 			 # "4) Print a value of the list."
la $a0, Choice4 	 
syscall	

li $v0, 4 	
la $a0, newline	
syscall	
				 
li $v0, 4 			# "5) Exit the software.: "
la $a0, Choice5 	
syscall					 
					 
li $v0, 4 	
la $a0, newline	
syscall				 

li $v0, 4 			# "The inserted value is : "			
la $a0, repint			 
syscall

li $v0, 4 	
la $a0, newline	
syscall

li  $v0, 5  # 5 is the code to read an integer
syscall  # result is placed in $v0

move $s0 , $v0

li $v0, 4 			# "You chose : "
la $a0, ChoicePrint	
syscall

li $v0, 1 			# 1 is the code to print an integer
move $a0,$s0	
syscall

beq  $s0,5,exit 
b loopstart 

exit: 			 
		
li $v0, 4 	
la $a0, newline	
syscall		
		
li $v0, 4 			# "You have exited the software. "	 
la $a0, endword 	
syscall

li  $v0, 10 # Exits the software
syscall



