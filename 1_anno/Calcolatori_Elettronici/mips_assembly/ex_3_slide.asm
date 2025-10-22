#ESERCIZIO N.3 NOSTACK
#int vet1[]={1,7,2,5,8,3,6,4}; 
#int riemp1=8;
#int vet2[10];
#int riemp2;

#void vetprint(int v[], int n);

#int main(){
#int i,n1,n2;
#n1=riemp1;
#n2=0;
#for(i=0;i<n1;i++)
#if(vet1[i]%2==1){
#vet2[n2]=vet1[i];
#n2=n2+1;
#}
#riemp2=n2;
#vetprint(vet2,riemp2);
#exit(0);
#}

#void vetprint(int v[], int n){
#int i;

#for(i=0; i<n; i++)
#printf("%d\n", v[i]);

#return;
#}

#________________________________________________________________________________________________________________________

            .data
vet1:       .word 1,7,2,5,8,3,6,4
vet2:       .space 40			#array di word
nl:	    .asciiz "\n"

            .text

main:
            li $t0, 8                  #riemp1 = 8
            move $s1, $t0              #n1 = riemp1
            li $s2, 0                  #n2 = 0
            li $t3, 0                  #i = 0
            la $s4, vet1               #carico l'indirizzo di vet1
            la $s5, vet2               #carico l'indirizzo di vet2

for:        bge $t3, $s1, endfor
            lw $t1, 0($s4)             #carico elemento array
            addi $s4, $s4, 4           #punto all'elemento successivo di vet1
            andi $t6, $t1, 1           #vet1[i]%2
            
if:         bne $t6, 1, then
            sw $t1, 0($s5)             #vet2[n2]=vet1[i]
            addi $s2, $s2, 1           #n2++
            addi $s5, $s5, 4           #punto all'elemento successivo di vet2

then:       
            addi $t3, $t3, 1           #i++
            j for

endfor:     move $s3, $s2              #riemp2=n2

            move $a0, $s3              #preparo i parametri effettivi "riemp2"
            la $a1, vet2               #passo l'indirizzo di vet2
            jal vetprint

            li $v0, 10                 #exit
            syscall


vetprint:
            move $t1, $a0               #t1 = riemp2 = n
            move $t3, $a1               #indirizzo base di vet2
            li $t2, 0                   #i=0
for2:       bge $t2, $t1, forend
            lw $t4, 0($t3)              #carico l'elemento del vettore
            addi $t3, $t3, 4            #punto all'elemento successivo dell'array
            li $v0, 1                   #print_int
            move $a0, $t4               #print v[i]
            syscall
            addi $t2, $t2, 1
            li $v0, 4
            la $a0, nl
            syscall
            j for2         

forend:
            jr $ra 









