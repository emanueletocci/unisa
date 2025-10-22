# i=$t0
# num = $t1
# x = $t2
# smag = $t3
# smin = $t4
# val =$t5

	li $t3, 0			#smag = 0
	li $t4,0			#smin = 0

	li $v0, 5			#scanf("%d",&val);
	syscall
	move $t5, $v0

do:
	li $v0, 5			#scanf("%d",&num);
	syscall
	move $t1, $v0
	bgt $t1, 1000, do 		#branch to do if(num>1000)
	blt $t1, $zero, do 		#branch to do if(num<0)
	
	li $t0, 0			#i=0
while:
	bge $t0, $t1, next_2		#branch to next if(i>=num)
	li $v0, 5			#scanf("%d",&x);
	syscall
	move $t2, $v0
	blt $t2, $t5, else		#branch to else if(x<val)
	add $t3, $t3, $t2		#smag=smag+x
	j next
else:
	add $t4, $t4, $t2		#smin=smin+x
next: 	
	addi $t0, $t0, 1		#i++
	j while
	
next_2:
	li $v0, 1			#printf("%d",smag)
	move $a0, $t3
	syscall
	li $v0, 1			#printf("%d",smin)
	move $a0, $t4
	syscall

	
	
	
	
	
