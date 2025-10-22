#Tradurre nel linguaggio assembler del MIPS il seguente frammento di
#codice in linguaggio C in modo che nel main gli indirizzi base dei vettori siano caricati nei registri $s1 e $s2 e che il passaggio dei parametri con la procedura avvenga tramite
#lo stack
#come rappresentato nella figura riportata dopo il codice C.

#int fun(int v1[], int v2[], int size);

#void main(){
#    int a[5], b[5];
#    int r, dim=5
# ...............
#    r=fun(a,b,dim)
# ..............
#}

#int fun(int v1[], int v2[], int size){
#    int somma=0,i;
#    for (i=0, i<size, i++)
#        somma=somma+v1[i]-v2[i];
#    return somma;
#}

#--------------------------------------------------------------------------------------------

            .data
a:          .space 20               #riservo in memoria uno spazio di 20 byte (5 elementi dell' array)
b:          .space 20
dim:        .word 5
r:          .space 4

            .text

main:
            la $s1, a               #indirizzo base vettore "a"
            la $s2, b               #indirizzo base vettore "b"
            lw $t0, dim             #dim = 5

#chiamata sottoprogramma
            addi $sp, $sp, -16      #allocazione spazio stack
            sw $s1, 0($sp)          #caricamento indirizzo vettore a sullo stack
            sw $s2, 4($sp)          #caricamento indirizzo vettore b sullo stack
            sw $t0, 8($sp)          #caricamento dim sullo stack
            jal fun
            lw $s4, 12($sp)         #carico la somma in $s4
            la $t8, r               #carico l'indirizzo di var_r
            sw $s4, ($t8)           # salvo il parametro di ritorno della funzione in memoria
            addi $sp, $sp, 16      #dealloco lo spazio sullo stack
fun:
            li $t1, 0               #somma = 0
            lw $t2, ($sp)           #$t2 = &a
            lw $t3, 4($sp)          #$t3 = &b 
            lw $t4, 8($sp)          #$t4 = dim = size
            li $t5, 0               #i = 0
            
for:        bge $t5, $t4, endfor   
            lw $t6, ($t2)           #carico il x valore dell'array v1
            add $t2, $t2, 4         #punto all'elemento successivo dell'array v1
            lw $t7, ($t3)           #carico il x valore dell'array v2
            add $t3, $t3, 4         #punto all'elemento successivo dell'array v2

            add $t1, $t1, $t6       #somma = somma + v1[i]
            sub $t1, $t1, $t7       #somma = somma = v2[i]

            addi $t5, $t5, 1        #i++
            j for

endfor:     sw $t1, 12($sp)
            jr $ra



