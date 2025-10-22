#i=$t0, x=$t1, sp=$t2, sn=$t3, num=$t4
	li $t2, 0		#sp=0
	li $t3, 0		#sn=0
	li $v0, 5		#scanf("%d", &num)
	syscall
	move $t4, $v0		#copia
	li $t0, 0		#i=0
for: 	
	bge $t0, $t4, next	#branch to next if(i>=num) 
	li $v0, 5		#scanf("%d", &x)
	syscall
	move $t1, $v0 		#copia
	blt  $t1, $zero, else	#branch to else if (x<0)
	add $t2, $t2, $t1	#sp+=x
	addi $t0, $t0, 1	#i++
	j for
else: 	
	add $t3, $t3, $t1	#sn+=x
	addi $t0, $t0, 1	#i++
	j for			#goto for
next:
	li $v0,1		#printf("%d",sp)
	move $a0, $t2
	syscall
	li $v0,1		#printf("%d",sn)
	move $a0, $t3
	syscall
