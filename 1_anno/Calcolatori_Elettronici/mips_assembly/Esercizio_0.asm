#Calcola la somma di n valori letti da input

# I=$t0, X=$t1, S=$t2, num=$t3
li $t2, 0
li $v0, 5	#lettura
syscall 
addi $t3, $v0, 0	#$t3=num
for: bge $t0, $t3, next 	#if(i>=num), goto next
li $v0, 5	#lettura
syscall
addi $t1, $v0, 0
add $t2, $t2, $t1
addi $t0, $t0, 1
j for	#jump for
next:
li $v0, 1	#print
syscall