#driver password 
#Scrivere un programma che simuli la lettura di una 
#password, acquisendo dalla tastiera (ricevitore) un 
#carattere e scrivendo corrispondentemente sul display 
#(trasmettitore) un '*'. La lettura della password termina 
#con il carattere '\n'. I caratteri letti siano memorizzati su 
#un buffer in area dati, curando che al termine dei 
#caratteri letti sia inserito il terminatore di stringa '\0'

		.data

star:  	.ascii "*"
buffer: .space 200
term:	.ascii "\0"
nl:		.ascii "\n"

		.text

			li $t0, 0xffff0000		#registro ctrl ricevitore (tastiera)
			li $t1, 0xffff0004		#registro dati ricevitore (tastiera)
			li $t2, 0xffff0008  	#registro ctrl trasmettitore (schermo)
			li $t3, 0cffff000c  	#registro dati trasmettitore (schermo)
			la $s2, buffer			#carico l'indirizzo del buffer
			lb $t5, star			#carico * in un registro 
			lb $t6, nl
			lb $t7, term

main:
#check ricevitore - busy waiting
looprx:		lw $s0, 0($t0)			#carico il registro ctrl del ricevitore
			andi $t4, $s0, 1		#check ready bit 
			beq $t4, 0, looprx		#itera quando ready = 0
			lb $s1, 0($t1)			#carico il dato trasmesso dalla periferica (il carattere)
			
#scrittura nel buffer 
			beq $s1, $t6, exit	    #se il dato é \n non salvarlo nel buffer
			sb $s1, ($s2)			#salvo il dato tramesso nel buffer
			addi $s2, $s2, 1		#punto al byte successivo nel buffer

#check trasmettitore - busy waiting
looptx:		lw $s0, 0($t2)			#carico il registro ctrl del trasmettitore
			andi $t4, $s0, 1		#check ready bit 
			beq $t4, 0, looptx		#itera quando ready = 0

#scrittura su terminale
			sb $t5, ($t3)			#scrivo * nel registro dati del trasmettitore
			j main					#Ripeti la procedura ed ottieni il prossimo valore

exit:		sw $t7, 1($s2)			#Concatena \0 alla fine della passaword

			li $v0, 10
			syscall

