.data
vet1:   .word 1, 7, 2, 5, 8, 3, 6, 4
riemp1: .word 8
vet2:   .space 40  # Riserviamo spazio per 10 interi (10 * 4 byte)
riemp2: .word 0
nl:     .asciiz "\n"

.text
.globl main
.globl vetprint

main:
    # Inizializzazione dei registri
    li $t0, 0   # $t0 = i (indice del ciclo)
    lw $t1, riemp1   # $t1 = n1
    li $t2, 0   # $t2 = n2

loop:
    bge $t0, $t1, exit   # Se i >= n1, esci dal ciclo

    # Controllo se vet1[i] % 2 == 1
    lw $t3, vet1($t0)   # $t3 = vet1[i]
    andi $t4, $t3, 1    # $t4 = vet1[i] & 1
    bne $t4, $zero, store   # Se vet1[i] & 1 != 0, vai a store

    # Incremento i e ripeti il ciclo
    addiu $t0, $t0, 1
    j loop

store:
    # Memorizza vet1[i] in vet2[n2]
    lw $t5, vet1($t0)   # $t5 = vet1[i]
    sw $t5, vet2($t2)   # vet2[n2] = $t5

    # Incremento n2
    addiu $t2, $t2, 1

    # Incremento i e ripeti il ciclo
    addiu $t0, $t0, 1
    j loop

exit:
    # Memorizza n2 in riemp2
    sw $t2, riemp2

    # Chiamata a vetprint(vet2, riemp2)
    la $a0, vet2
    lw $a1, riemp2
    jal vetprint

    # Uscita dal programma
    li $v0, 10
    syscall

vetprint:
    # Prologo della funzione
    addiu $sp, $sp, -4   # Riserviamo spazio per il registro $ra
    sw $ra, ($sp)        # Salva $ra nello stack frame

    # Inizializzazione dei registri
    li $t0, 0   # $t0 = i (indice del ciclo)

loop_print:
    bge $t0, $a1, exit_print   # Se i >= n, esci dal ciclo

    # Stampa v[i]
    sll $t1, $t0, 2     # $t1 = i * 4 (per ottenere l'offset corretto nell'array)
    addu $t1, $t1, $a0  # $t1 = &v[i]
    lw $t2, ($t1)       # $t2 = v[i]
    li $v0, 1           # Carica il codice di syscall per la stampa intera
    move $a0, $t2       # Carica il valore da stampare
    syscall

    # Stampa un newline
    li $v0, 4           # Carica il codice di syscall per la stampa stringa
    la $a0, nl          # Carica l'indirizzo della stringa di newline
    syscall

    # Incremento i e ripeti il ciclo
    addiu $t0, $t0, 1
    j loop_print

exit_print:
    # Epilogo della funzione
    lw $ra, ($sp)       # Ripristina $ra dallo stack frame
    addiu $sp, $sp, 4   # Ripristina lo sp

    jr $ra              # Salta all'indirizzo di ritorno