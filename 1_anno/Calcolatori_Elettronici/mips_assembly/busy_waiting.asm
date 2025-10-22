#Implementazione del "busy waiting" in asm MIPS, driver periferica
        li $t0, 0xFFFF0000

loop:   lw $t1, 0($t0)
        andi $t1, $t1, 1        #check del ready bit
        beq $t1, $zero, loop    

lw $v0, 4($t0)ca