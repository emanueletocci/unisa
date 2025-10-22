#Scrivere un programma che realizzi e provi una funzione
#per la lettura di un intero in esadecimale (cifre 0..9A..F).
#La funzione acquisisca dalla tastiera (ricevitore) un
#carattere, calcoli il valore della cifra corrispondente e
#aggiorni il valore del numero. La lettura delle cifre
#termina con il carattere '\n'; il valore calcolato viene
#restituito in $v0. In $v1 si restituisce un codice relativo
#alla correttezza delle cifre inserite (0: input corretto; 1:
#input errato).

            .data
            
term:       .ascii "\n"
            .text

.main:  
loop:      li $a0, 0xffff0000                  #Indirizzo ctrl ricevitore (tastiera)
            lb $2, term                         #carico in un registro il terminatore
            jal looprx                          #chiamata alla funzione looprx
            move $s0, $v0                       #copia del dato dalla periferica

            move $a0, $s0                       #passo il dato alla funzione conv
            jal conv
            move $s4, $v0                       #conversione decimale
            move $s5, $v1                       #input_check
            #move $a0, $s4                       #passo al sottoprogrammam il dato convertito in decimale
            move $a0, $s0
            li $a1, 0xffff0008                  #Indirizzo ctrl trasmettitore (schermo)
            jal looptx
            bne $s0, $s2, loop                  #Itera finch? il dato ? diverso dal terminatore

exit:       li $v0, 10
            syscall

#receiver check - busy waiting
looprx:     move $t0, $a0                       #copia dell'indirizzo ctrl ricevitore
looprx_2:
            lw $t1, ($t0)                       #carico il contenuto del ctrl ricevitore
            andi $t2, $t1, 1                    #check ready bit
            beq $t2, $zero, looprx_2            #itera finch? ready = 0
            lb $v0, 4($t0)                      #carico il dato trasmesso dalla perifica e lo passo al chiamante
            jr $ra

#funzione conv, hex -> dec
conv:
            move $t2, $a0                       #copia del dato prelevato dalla periferica

#gestione hex compresi tra 0 e 9 | 0<= hex <= 9
            blt $t2, ,$zero, error              #se il numero inserito ? < 0 goto error
            bgt $t2, 9, check_char              #se il numero inserito ? > 10 goto check_char
            move $v0, $t2                       #restituisco il valore senza modificarlo
            li $v1, 0                           #il dato inserito ? corretto

#gestione hex compresi tra "a ed "f"| 10 <= hex <= 15
check_char:
            bgt $t2, 0x66, error                #se il dato supera "f" goto error
            beq $t2, 0x61, a                    #se il dato ? = a allora usa il valore 11
            beq $t2, 0x62, b 
            beq $t2, 0x63, c
            beq $t2, 0x64, d 
            beq $t2, 0x65, e
            beq $t2, 0x66, f 

a:          li $v0, 11
            li $v1, 0                            #il dato inserito ? corretto
            j end_check
b:          li $v0, 12
            li $v1, 0                            #il dato inserito ? corretto
            j end_check
c:          li $v0, 13
            li $v1, 0                           #il dato inserito ? corretto
            j end_check
d:          li $v0, 14
            li $v1, 0                           #il dato inserito ? corretto
            j end_check
e:          li $v0, 15
            li $v1, 0                           #il dato inserito ? corretto
            j end_check
f:          li $v0, 16
            li $v1, 0                           #il dato inserito ? corretto
            j end_check
error:      
            li $v1, 1                           #il dato inserito ? errato
end_check:
            jr $ra

#transmitter check - busy waiting
looptx:     move $t2, $a0                       #copia dato convertito in decimale
looptx_2:
            move $t3, $a1                       #copia indirizzo ctrl trasmettitore
            lw $t4, ($t3)                       #carico il contenuto del ctrl ricevitore
            andi $t5, $t4, 1                    #check ready bit
            beq $t5, $zero, looptx_2            #itera finch? ready = 0
            sb $t2, 4($t3)                      #salvo il dato convertito nel reg. dati del trasmettitore
            jr $ra
            



