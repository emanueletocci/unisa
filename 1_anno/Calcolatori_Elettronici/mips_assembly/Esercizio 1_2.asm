#TRADUCI IN ASSEMBLY
# int vet[100];
# int riemp;
#int main(){
	#int i,n;
	#do{
		#printf("Numero elementi");
		#scanf("%d",&n);
	#}
	#while(n<0 || n>100);

	#for(i=0;i<n;i++){
		#printf("Elemento %d: ",i);
		#scanf("%d",&vet[i]);
	#}
	#riemp = n;
	#exit(0);
#}

# $t0 = i
# $t1= n
# $t2 = &vet
# $t3 = riemp

	 .data 
prompt:	 .asciiz "Numero elementi: \t "
prompt_2:.asciiz "Elemento "
newline: .asciiz "\n"
vet: 	 .space 400
riemp:	 .space 4

	.text	
do:	
	li $v0, 4 		#print_string
	la $a0, prompt		#printf("Numero elementi: ");
	syscall
	
	li $v0, 4 		#print_string
	la $a0, newline		#printf("\n ");
	syscall
	
	li $v0, 5		#read_int
	syscall			#scanf("%d",&n);
	
	move $t1, $v0
	blt $t1, $0, do
	bgt $t1, 100, do
	
	li $t0, 0		#i=0
for:	bge $t0, $t1, endfor	#while(i<n)
	li $v0, 4 		#print_string
	la $a0, prompt_2	#printf("Elemento: ");
	syscall
	
	li $v0, 1 		#print_int
	move $a0, $t0		
	syscall			#printf ("%d",i), stampa del contatore
	
	li $v0, 4 		#print_string
	la $a0, newline		#printf("\n ");
	syscall
	
	la $t2, vet		#$t2=&vet
	li $v0, 5		#read_int
	syscall			#scanf("%d",&vet[i]);
	
	sw $v0, ($t2)		#salva il contenuto di v0 nell indirizzo presente in $t2	
	addiu $t0, $t0, 1	#i++
	addiu $t2, $t2, 4	#incremento l'indirizzo dell'array per raggiungere il secondo dato 
	j for

endfor:
	move $t3, $t1		#riemp=n
	li $v0, 10
	syscall
	
	
	
 
