


            .data 

vet1:       .word 1,7,2,5,8,3,6,4
riemp1:     .word 8
vet2:       .space 40                   #array di word

            .text
main:
            lw $t0, riemp1              #carico riemp in un registro
            la $s0, vet1                #carico l'indirizzo del vettore 1
            la $s1, vet2                #carico l'indirizzo del vettore 2
            move $t1, $t0               #n1 = riemp
            move $a0, $s0               #passo &vet1 al sottoprogramma
            move $a1, $s1               #passo &vet2 al sottoprogramma
            move $a2, t0                #passo riemp1 al sottoprogramma
            jal contadisp
            move $s3, $v0               #salvo il valore di ritorno n2, riemp2 = n2

            move $a0, $s1               #passo &vet2 al sottoprogramma
            move $a1, $s3               #passo riemp2 al sottoprogramma
            jal vetprint
            li $v0, 10                  #exit
            syscall


contadisp:
            move $t2, $a0               #&v1
            move $t3, $a1               #&v2
            move $t4, $a2               #n1
            li $t5, 0                   #n2 = 0
            li $t6, 0                   #i = 0

for:        bge $t6, $t4, endfor
            lw $t7, 0($t2)              #carico il x elemento del vettore
            andi $t8, $t7, 1            #vet[i]%2

if:         bne $t8, 1, then  
            lw $t9, 0($t3)              #carico x elemento di vet2
            sw $t7, 0($t3)              #vet2[n2] = vet1[i]
            addi $t5, $t5, 1            #n2 ++        

then:
            addi $t2, $t2, 4            #punto all'elemento successivo del vet1
            addi $t2, $t2, 4            #punto all'elemento successivo del vet2
            addi $t6, $t6, 1            #i++
            j for

endfor:
            move $v0, $t5               #passa n2 al chiamante
            jr $ra                      #torna al main


vetprint:
            move $t0, $a0               #&vet2
            move $t1, $a1               #riemp2 = n
            li $t2, 0                   #i = 0

for2:       bge $t2, $t1, endfor2
            lw $t3, 0($t0)              #carico l'elemento del vettore
            li $v0, 1                   #print_int
            move $a0, $t3
            syscall
            addi $t2, $t2, 1            #i++
            addi $t0, $t0, 4            #punto all'elemento successivo del vettore  
            j for2

endfor2:
            jr $ra
