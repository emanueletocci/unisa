
        .text
        li $s0, 0xffff0000		#indirizzo registro RS

main:

#busy waiting
looprs:
        lb $t0, 0($s0)                  #carico il contenuto del registro RS
        andi t1, 0x80                   #check ready bit
        beq $t1, $zero, looprs          #itera finché ready = 0

        lh $t1, 4($s0)                  #carico il dato letto dal registro RD

        li $v0, 10                      #exit
        syscall


