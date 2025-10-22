#TRADUCI IN ASM MIPS

#include <stdio.h>
#int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
#main()
#{
# int i, acc0, acc1;
# acc0=0;
# acc1=0;
# i=0;
#  while (i<10)
#    {
#      if ((i % 2) == 0)
#	acc0 = acc0 + a[i];
#      else
#	acc1 = acc1 + a[i];
#      i++;
#    }
#  printf("Pari:    %d\n", acc0);
#  printf("Dispari: %d\n", acc1);
#}

#------------------------------------------------------------------------------------------------------------

        .data
v:      .word 1,2,3,4,5,6,7,8,9,10
acc0:   .word 0
acc1:   .word 0
i:      .word 0
pari:   .asciiz "Pari: \n"
dis:    .asciiz "Dispari: \n"
nl:	.asciiz "\n"

        .text
main:
        la $t0, v               #carico l'indirizzo di base del vettore
        lw $t1, acc0            #acc1 = 0
        lw $t2, acc1            #acc2 = 0
        lw $t3, i               #i=0
        

while:  bge $t3, 10, endw
        andi $t4, $t3, 1        #i%2
        lw $s0, 0($t0)          #carico l'elemento dell'array in un registro
if:     bne $t4, $zero, else
        add $t1, $t1, $s0       #acc0 = acc0 + a[i];
        j endif
else:   add $t2, $t2, $s0       #acc1 = acc1 + a[i];
endif:  addi $t3, $t3, 1        #i++
        addi $t0, $t0, 4        #punto al prossimo elemento dell'array
        j while

endw:   li $v0, 4               #print_string
        la $a0, pari            #stampa stringa "pari"
        syscall
        
        li $v0, 4		#new_tab
        la $a0, nl
        syscall
        
        li $v0, 1               #print_int
        move $a0, $t1           #stampo acc1
        syscall
        	
        li $v0, 4		#new_tab
        la $a0, nl
        syscall
        
        li $v0, 4               #print_string
        la $a0, dis             #stampa stringa "dispari"
        syscall

        li $v0, 1               #print_int
        move $a0, $t2           #stampo acc1
        syscall

        li $v0, 10              #exit
        syscall
