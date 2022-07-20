.data

Welc: .asciiz "Give the string:"
err: .asciiz "Error"

array: .align 2
       .space 81

.text

.globl main

main:

la $a0, Welc
jal PrintString

la $a0, array
jal ReadString

la $a0, array
jal TurnToCaps

la $a0, array
jal PrintString

li $v0, 10
syscall

###########################################################

PrintString:

addi $sp,$sp,-8
sw $ra,0($sp)
sw $s0,4($sp)
move $s0,$a0

while1:

lb $a0, 0($s0)
beq $a0,$zero,end_Label

jal Write_ch
addi $s0,$s0,1

b while1

end_Label:

lw $ra,0($sp)
lw $s0,4($sp)
addi $sp,$sp,8
jr $ra

###########################################################

Write_ch:

addi $sp, $sp, -8
sw $ra, 0($sp)
sw $s0, 4($sp)

while2:

lb $s0, 0xffff0008
andi $s0, $s0, 1

beq $s0, $zero, while2

sb $a0, 0xffff000c

lw $ra, 0($sp)
lw $s0, 4($sp)
addi $sp, $sp, 8

jr $ra

###########################################################

Read_ch:

addi $sp, $sp, -4
sw $ra, 0($sp)

while3:

lb $t0, 0xffff0000
andi $t0, $t0, 1

beq $t0, $zero, while3

lb $v0, 0xffff0004

lw $ra, 0($sp)
addi $sp, $sp, 4

jr $ra

############################################################

ReadString:

addi $sp, $sp, -8
sw $ra, 0($sp)
sw $s0, 4($sp)
move $s0,$a0

while4:

jal Read_ch

sb $v0, 0($s0)
move $a0, $v0

jal Write_ch

addi $s0, $s0, 1

bne $v0, 10, while4
sb $zero, 0($s0)

lw $ra, 0($sp)
lw $s0, 4($sp)
addi $sp, $sp, 4

jr $ra

#############################################################

TurnToCaps:

addi $sp, $sp, -8
sw $ra, 0($sp)
sw $s0, 4($sp)

move $s0, $a0

while5:

lb $t1, 0($s0)

beq $t1, $zero, exit_el
beq $t1, 32, repeat
blt $t1, 97, repeat

addi $t1, $t1, -32
sb $t1,0($s0)
addi $s0, $s0, 1

b while5

repeat:
addi $s0, $s0, 1
b while5

exit_el:

move $v0, $s0
lw $ra, 0($sp)
lw $s0, 4($sp)
addi $sp, $sp, 8

jr $ra

############################################################# 