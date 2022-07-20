.data
.globl cflag # // Step 1
.globl cdata
.align 2
cflag: .space 4
.align 2 
cdata: .space 4

menu: .asciiz "\n1.Choice 1\n2.Choice 2\nPress Space to exit the software.\n"
choice_1: .asciiz "\nYou pressed 1\n"
choice_2: .asciiz "\nYou pressed 2.\n"
exit_message: .asciiz "\nYou have exited the software!\n"

.text
.globl main

main:

sw $zero,cflag # Initialize cflag to zero // Step 2

mfc0 $t0,$12 # Move status register content to $t0
ori $t0,$t0,1 # Interrupt Enable = 1 (0 bit of status register) (1 = 2^0) // Step 3
ori $t0,$t0,2048 # Διακοπές Πληκτρολογίου (Interrupt Mask) = 1 (11 bit of status register) (2048 = 2^11)
mtc0 $t0,$12 # Store new value to the status register 

lw $t0,0xffff0000 # Keyboard (Receiver) | Control Register | Interrupt Enable
ori $t0,$t0,2 # (2^1 = 2)
sw $t0,0xffff0000

menu_loop : 

li $v0,4 # Print the menu  // Step 4
la $a0,menu
syscall

cflag_loop : # //Step 5 , 6

lw $t1 , cflag # Read cflag 
beq $t1 , $zero , cflag_loop  

lw $t2 , cdata 
sw $zero,cflag # Set cflag memory to 0 //Step 7
bne $t2,49,Ch2_label  # 49 : Ascii Code for 1

#Choice 1

li $v0,4
la $a0,choice_1
syscall

Ch2_label : 
bne $t2,50,Exit_label # 50 : Ascii Code for 2
#Choice 2

li $v0,4
la $a0,choice_2
syscall

Exit_label :
bne $t2,32,menu_loop # 32 : Ascii Code for Space //Step 8

#Exit choice

li $v0,4
la $a0,exit_message
syscall

li $v0,10
syscall




