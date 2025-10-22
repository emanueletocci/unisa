# i=$t0, x=$t1, s=$t2, num=$t3
#Legge da input num valori interi e calcola la somma dei soli valori positivi.

li $t2, 0
li $v0, 5	#scan
syscall
move $t3, $v0
li $t0,0
for: bge $t0, $t3, next		#branch if grater or equal (if(i>=num) goto next
li $v0, 5	#scan
syscall
move $t1, $v0
slt   $t5, $zero, $t1	#set on less than
add $t2, $t2, $t1	# s=s+x
addi $t0, $t0,1		#i++
j for
next:
li $v0, 1		#printf
syscall
move $t2, $v0
