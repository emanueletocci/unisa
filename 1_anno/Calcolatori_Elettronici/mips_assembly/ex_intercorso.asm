Tradurre nel linguaggio assembler del MIPS il seguente frammento di codice in linguaggio C in modo che gli
indirizzi delle variabili a, b e min vengano caricati nei registri $s0, $s1,
$s2, rispettivamente. 


int i=0
int a,b, min;
scanf ("%$d", &a);
scanf ("%$d", &b);
if (a<=b)
    min = a;
else 
    min = b;
printf("%d",min);

________________________________________________________________________________________________________________________

            .data 
        i:      .word 0
        a:      .space 4
        b:      .space 4
            
            .text
        la $s0, a
        la $s1, b
        la $s2, min
        lw $t4,i    #i=0

        li $v0, 5   #syscall read a
        syscall
        move $t0, $v0   #salvo il valore letto in un registro del processore

        li $v0, 5   #syscall read b
        syscall
        move $t0, $v0   #salvo il valore letto in un registro del processore

if:     bgt $t0, $t1, else
        move $t2, $t0
        sw $v0, ($s0)
        j next       
else:   move $t2, $t1
next:

        li $v0, 1
        move a0, $t2
        syscall
        

        sw $t0, 0($s0)  #salvo i tre valori in memoria
        sw $t1, 0($s1)
        sw $t2, 0($t2)

        li $v0, 10
        syscall


