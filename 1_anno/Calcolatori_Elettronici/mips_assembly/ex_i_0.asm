            .text

#suppongo che $a0 contenga l'indirizzo del reg. controller - $a0 address
getc:   
            lb $t0, ($a0)                       #carico il reg. controller
            andi $t0, $t0, 0xfc                 #imposto a 0 gli ultimi 2 bit
            addi $t0, $t0, 1                    #imposto ad 1 l'ultimo bit - Op2 =1
            sb $t1, ($a0)                       #salvo il registro modificato

#busy - waiting

loop:       lb $t0, ($a0)                       #carico il reg. controller
            andi $t1, $t0, 0x10                 #check bit R
            andi $t2, $t0, 0x20                 #check bit F
            bne $t2, $zero, fail                #se F=1 errore
            bne $t1, 1, fail                    #se R=0 errore
            lb $v0, 1($a0)                      #carico il dato dal reg. data
            jr $ra

#reset
fail:       ori $t0, $t0, 2                     #imposto Op1 a 1
            sb $t0, ($a0)                       #salvo il registro 
            j getc                              #ripeti la configurazione


