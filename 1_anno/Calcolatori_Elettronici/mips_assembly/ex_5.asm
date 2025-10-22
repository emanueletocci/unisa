#TRADUCI IN MIPS:

#include <stdio.h>

#int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

#main()
#{
# int i, acc;

# acc=0;
# i=0;
#  while (i<10)
#    {
#     acc = acc + a[i];
#      i++;
#    }
#  printf("%d\n", acc);
#}


------------------------------------------------------------------------------------

    .data

#inizializzazione array

vet:    .word 1,2,3,4,5,6,7,8,9,10
acc:    .word 0
i:      .word 0

    .text
        lw $t0, acc             #acc=0
        lw $t1, i               #i=0
        la $s0, vet

while:  
        bge $t1, 10, end
        lw $t4, 0($s0)          #caricamento elemento dell'array nel registro $s4
        addi $s0, $s0, 4        #punto al secondo elemtento dell'array
        add $t0, $t0, t4        #acc=acc+a[i]
        addi $t1, $t1, 1        #i++
        j while

end:
        li $v0, 1               #printf
        move $a0, $t0
        syscall

        li $v0, 10
        syscall                 #exit


