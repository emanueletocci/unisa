#Tradurre in Assembly MIPS il seguente programma C
#int vet1[]={1,7,2,5,8,3,6,4}; 
#int riemp1=8;

#int main(){
#int i,n1,np;
#n1=riemp1;
#np=0;
#for(i=0;i<n1;i++)
#if(vet1[i]%2==0)
#np=np+1;
#}
#printf("Numero pari: ");
#printf("%d",np);
#printf("\n");
#exit(0);
#}

		.data
vet:		.word 1,7,2,5,8,3,6,4
riemp1:		.word 8
np0:		.word 0
i:		.word 0
prompt:		.asciiz "Numero pari: "
nl:		.asciiz "\n"

		.text
main:	
		la $t0, vet 		#indirizzo base del vettore
		lw $t1, riemp1
		lw $t3, i
		move $t4, $t1		#n1 = riemp1
		lw $t2, np0		#np=0
for:		bge $t3, $t4, endfor
		lw $t5, 0($t0)		#carico l'elemento del vettore
		andi $t6, $t5, 1	#vet1[i]%2
		bne $t6, $zero, then
		addi $t2, $t2, 1	#np+=1
then:		
		addi $t3, $t3, 1	#i++
		addi $t0, $t0, 4	#punto all'elemento successivo del vettore
		j for
endfor:		
		li $v0, 4		#print_string
		la $a0, prompt		#print "numero pari"
		syscall
		
		li $v0, 1		#print_int
		move $a0, $t2		#print np
		syscall
		
		li $v0, 4		#print_string
		la $a0, nl		#print \n
		syscall
		
		li $v0, 10		#exit
		syscall	
		
		
		 