#a0 = indirizzo reg controller
driver:
            lb $t0, 0($a0)          #carico il reg controller
            ori $t0, $t0, 1         #asserisco EN
            sb $t0, 0($a0)          

#busy waiting
loop:       lb $t1, 0($a0)          #carico il reg controller
            andi $t2, $t1, 0x80     #check ready bit
            beq $t2, $zero, loop

#end busy waiting
            lb $v0, 1($a0)          #carico in $v0 il valore letto dalla periferica
            andi $t1, $t1, 0xFE     #deasserisco EN 
            sb $t1, 0($a0)          #carico il registro ripristinato in memoria
            jr $ra

#1.caricare in $t0 il controller register                           CARICARE
#2.asserire EN                                                      ASSERIRE
#3.sovrascrivere controller register in memoria                     SOVRASCRIVERE

#4.caricare il registro in memoria (inizio busy waiting)            CARICARE
#5.check ready                                                      CHECK
#6.branch                                                           BRANCH
#7.caricare valore letto dalla periferica                           CARICARE
#8.deasserire EN                                                    DEASSERIRE
#9.caricare in memoria il registro ripristinato                     CARICARE


#CASCCBCDC