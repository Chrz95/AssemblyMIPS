.data
.globl array
.globl Input
.globl Inst1
.globl Inst2
.globl Inst3
.globl Inst4
.globl Inst5
.globl Inst6
.globl Inst7
.globl Inst8
.globl Inst9
.globl err1
.globl err2
.globl err3
.globl ttl
.globl addr
.globl crMsg
.globl val
.globl id
.globl nline
.globl addfunc
.globl headadd
.globl err_notF
.globl errPos
.globl min1
.globl min2
.globl min3

min1: .asciiz "The address of the lowest value is:" 
min2: .asciiz " The id of the lowest value is:"
min3: .asciiz " The lowest value is: "
headadd: .asciiz "The address of the list is: "
addfunc: .asciiz "The address of the variable is: "
nline: .asciiz "\n"
id: .asciiz "Id is : "
val: .asciiz "Value is : "
crMsg: .asciiz " values will be inserted.\n"
addr: .asciiz "Enter which value's address you want printed. (1 for the first and so on...)\n"
Input: .asciiz "Welcome. Enter a number from 1 to 9.\n"
Inst1: .asciiz "\nPress 1 to create a list with a specific number of values.\n"
Inst2: .asciiz "Press 2 to insert a value at the end of the list.\n"
Inst3: .asciiz "Press 3 to delete the last value of the list.\n"
Inst4: .asciiz "Press 4 to print a value  of the list.\n"
Inst5: .asciiz "Press 5 to print the total number of nodes.\n"
Inst6: .asciiz "Press 6 to print the address of a node.\n"
Inst7: .asciiz "Press 7 to print the address of the list.\n"
Inst8: .asciiz "Press 8 to print the minimum value of the list.\n"
Inst9: .asciiz "Press 9 to exit the software.\n\n"
err1: .asciiz "Invalid input. Choose among 1 and 9.\n"
crList: .asciiz "Enter the number of nodes you want the list to have.\n"
insval: .asciiz "Enter the value to be inserted.\n"
print1: .asciiz "Enter which element you want printed. (1 for the first and so on...)\n"
ttl: .asciiz "The total number of values of the list is: "
err2: .asciiz "A list has already been created.\n"
err3: .asciiz "You need to create a list first.\n" 
err_notF :  .asciiz "The requested node does not exist. \n"
errPos :  .asciiz "Please enter a positive integer.\n"

array: .align 2
       .space 800

.text
.globl main

main:

la $s1, array    
li $s2, 0 # the counter.
li $s3, 1 # id

move $t1, $s1

menu:

li $v0, 4
la $a0, Input
syscall

li $v0, 4
la $a0, Inst1
syscall

li $v0, 4
la $a0, Inst2
syscall

li $v0, 4
la $a0, Inst3
syscall

li $v0, 4
la $a0, Inst4
syscall

li $v0, 4
la $a0, Inst5
syscall

li $v0, 4
la $a0, Inst6
syscall

li $v0, 4
la $a0, Inst7
syscall

li $v0, 4
la $a0, Inst8
syscall

li $v0, 4
la $a0, Inst9
syscall

li $v0, 5
syscall

move $s0, $v0

blez $s0, err_label # The program checks if the user has given an input less than one...
bgt $s0, 9, err_label # ...or more than 9. 

######################################################################################

bne $s0, 1, case2 #the program will skip the code below if the user has not chosen one.
bne $s2, 0, err_l2

li $v0, 4
la $a0, crList
syscall

li $v0, 5
syscall

move $s0, $v0
add $s2, $s2, $s0

move $a0, $s0 # the number of values to be inserted.
move $a1, $s1 # address of head.
move $a2, $s2 # counter.
move $a3, $s3 # id.

jal CreateList

move  $s3 , $v0 
addi $s3 , $s3 , -1

b menu

######################################################################################

case2:

bne $s0, 2, case3
beq $s2, 0, err_l3

li $v0, 4
la $a0, insval
syscall

li $v0, 5
syscall

move $s0, $v0
addi $s2, $s2, 1

move $a0, $s0 # The value to be inserted.
move $a1, $s1 # Address of head.
move $a2, $s2 # The counter.
move $a3, $s3 # The id.

jal insertNode

move $s3 , $v0 

b menu

######################################################################################

case3:

bne $s0, 3, case4
beq $s2, 0, err_l3

move $a1, $s1 #Address of head.
move $a2, $s2 #The counter.

jal deleteLastNode

move $s2, $v0

b menu

#######################################################################################

case4:

bne $s0, 4, case5
beq $s2, 0, err_l3

li $v0, 4
la $a0, print1
syscall

li $v0, 5
syscall

move $s0, $v0

blez $s0, errPositive # The program checks if the user has given an input less than one...
bgt $s0, $s2, err_notFound # ...or a value bigger than the length of the list.

move $a0, $s0 # the value (its id) that we want printed.
move $a1, $s1 # Address of Head.
move $a2, $s2 # The counter.

jal PrintValue

b menu

#######################################################################################

case5:

bne $s0, 5, case6
beq $s2, 0, err_l3

move  $a2 , $s2


jal NumberOfNodes

b menu

#######################################################################################

case6:

bne $s0, 6, case7
beq $s2, 0, err_l3

li $v0, 4
la $a0, addr
syscall

li $v0, 5
syscall
 
blez $v0, errPositive # The program checks if the user has given an input less than one...
bgt $v0, $s2, err_notFound # ...or a value bigger than the length of the list.

move $a0, $v0

jal PrintValueAddress

b menu

#######################################################################################

case7:

bne $s0, 7, case8
beq $s2, 0, err_l3

jal PrintListAddress

li $v0, 4
la $a0, nline
syscall

b menu

#######################################################################################

case8:

bne $s0, 8, case9
beq $s2, 0, err_l3

move $a1, $s1 #Address of Head.
move $a2, $s2 #Counter.

jal FindMinValue

b menu

#######################################################################################

case9:

li $v0, 10
syscall

#######################################################################################

err_label:

li $v0, 4
la $a0, err1
syscall  

b menu

##########################################################################################

err_l2:

li $v0, 4
la $a0, err2
syscall

b menu

##########################################################################################

err_l3:

li $v0, 4
la $a0, err3
syscall

b menu

##########################################################################################

err_notFound:

li $v0, 4
la $a0, err_notF
syscall  

b menu

##########################################################################################


errPositive:

li $v0, 4
la $a0, errPos
syscall  

b menu

##########################################################################################

#main has ended

##########################################################################################

CreateList:

move $t0, $a0 #number of elements to be added. 
move $t1, $a1 #address of the array.
move $t2, $a2 #counter 
move $t3, $a3 #id.

li $v0, 1 
move $a0, $t0
syscall

# The 3 lines above print the number of values that are going to be inserted.

li $v0, 4
la $a0, crMsg
syscall

# The message itself

inputloop:

li $v0, 4
la $a0, insval
syscall

#Print string

li $v0, 5
syscall

#Read integer.

move $t4, $v0 #the value

sw $t3, 0($t1)
addi $t1, $t1, 4

sw $t4, 0($t1)
addi $t1, $t1, 4

addi $t0, $t0, -1 

addi $t3, $t3, 1

move $v0 , $t3

beq $t0, 0, exitfunc

b inputloop

exitfunc:

jr $ra 

##########################################################################################

insertNode:

move $t0, $a0 #value to be inserted
move $t1, $a1 #address of the array
move $t2, $a2 #counter
move $t4, $a3 #counter

addi $t4, $t4, 1 #increase id.

li $t3, 1 #variable to tranverse the list.

ins_loop:

addi $t1, $t1, 8
addi $t3, $t3, 1

bne $t3, $t2, ins_loop # branch

inst:

sw $t4, 0($t1)
addi $t1, $t1, 4

sw $t0, 0($t1)

move $v0 , $t4

jr $ra

##########################################################################################

deleteLastNode:

move $t1, $a1 #address of the array
move $t2, $a2 #counter

li $t3, 1 # variable to tranverse the list.

trav3:

beq $t3, $t2, del

addi $t3, $t3, 1
addi $t1, $t1, 8

b trav3

del:

addi $t2, $t2, -1
move $v0, $t2

jr $ra

##########################################################################################

PrintValue:

move $t0, $a0 #value to be printed
move $t1, $a1 #address of the array
move $t2, $a2 #counter

li $t3, 1 # variable to tranverse the list.

trav:

beq $t3, $t0, PrintVal

addi $t3, $t3, 1
addi $t1, $t1, 8

b trav

PrintVal:

lw $t4, 0($t1)
addi $t1, $t1, 4

lw $t5, 0($t1)
addi $t1, $t1, 4

li $v0, 4
la $a0, id
syscall

li $v0, 1
move $a0, $t4
syscall

li $v0, 4
la $a0, nline
syscall

li $v0, 4
la $a0, val
syscall

li $v0, 1
move $a0, $t5
syscall

li $v0, 4
la $a0, nline
syscall

jr $ra

#############################################################################################

PrintValueAddress:

move $t0, $a0 #value to be printed
move $t1, $a1 #address of the array
move $t2, $a2 #counter

li $t3, 1 # variable to tranverse the list.

trav2:

beq $t3, $t0, PrintValAdd

addi $t3, $t3, 1
addi $t1, $t1, 8

b trav2

PrintValAdd:

la $t4, 0($t1)

li $v0, 4
la $a0, addfunc
syscall

li $v0, 1
move $a0, $t4
syscall

li $v0, 4
la $a0, nline
syscall

jr $ra

#############################################################################################

PrintListAddress:

move $t1, $a1 #address of the array

li $v0, 4
la $a0, headadd
syscall

li $v0, 1
move $a0, $t1
syscall

jr $ra

#############################################################################################

FindMinValue:

move $t1, $a1 #Address of Head.
move $t2, $a2 #Counter (number of values).

addi $t2 , $t2 , -1 # The comparisons that must happen are counter - 1
lw $t3, 0($t1) # Holds the id of the lowest Value.
move $t4, $t1 # Holds the lowest value's address. 

addi $t1, $t1, 4

lw $t6, 0($t1) # Holds the lowest value.

beq $t2 , 0 , OneElement # The case where there is only one element

addi $t1, $t1, 8

MinLoop:

lw $t5, 0($t1)

blt $t5, $t6, newMin
addi $t1, $t1, 8
addi $t2, $t2, -1

bne $t2, $zero, MinLoop
b endfunc

newMin:

move $t6, $t5 # Insert the new min value.
addi $t1, $t1, -4

lw $t7, 0($t1)
move $t3, $t7

move $t4, $t1 # Insert the new address.
addi $t2, $t2, -1
addi $t1, $t1, 12 
 
bne $t2, $zero, MinLoop

endfunc:

li $v0, 4
la $a0, min1
syscall

li $v0, 1
move $a0, $t4
syscall

li $v0, 4
la $a0, nline
syscall

li $v0, 4
la $a0, min2
syscall

li $v0, 1
move $a0, $t3
syscall

li $v0, 4
la $a0, nline
syscall

li $v0, 4
la $a0, min3
syscall

li $v0, 1
move $a0, $t6
syscall

li $v0, 4
la $a0, nline
syscall

b endfunc2

################

OneElement :

li $v0, 4
la $a0, min1
syscall

li $v0, 1
move $a0, $t4
syscall

li $v0, 4
la $a0, nline
syscall

li $v0, 4
la $a0, min2
syscall

li $v0, 1
move $a0, $t3
syscall

li $v0, 4
la $a0, nline
syscall

li $v0, 4
la $a0, min3
syscall

li $v0, 1
move $a0, $t6
syscall

li $v0, 4
la $a0, nline
syscall

endfunc2 :

jr $ra

##########################################################################################

NumberOfNodes :

move $t1,$a2

li $v0, 4
la $a0, ttl
syscall

li $v0, 1
move $a0, $t1
syscall

li $v0, 4
la $a0, nline
syscall

jr $ra