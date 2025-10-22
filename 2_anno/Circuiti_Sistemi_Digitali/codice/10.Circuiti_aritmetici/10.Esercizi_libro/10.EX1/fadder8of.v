/*E1 - Addizionatore ad 8 bit con overflow

Si realizzi un addizionatore ad otto bit mediante una descrizione HDL. L’ingresso del circuito
è costituito da due word di 8 bit. Il risultato della somma deve essere visualizzato, in esadeci-
male, su due display a sette segmenti. Le uscite del circuito saranno costituite da due insiemi
di sette segnali che pilotano i corrispondenti segmenti dei display. Qualora il risultato della
somma dia overflow dovranno illuminarsi i tre segmenti orizzontali dei due display (≡).
Le descrizione del circuito può essere realizzata gerarchicamente implementando a parte
il decoder per display a 7 segmenti ed istanziandolo due volte. Il test del circuito può essere
effettuato:
• in maniera esaustiva utilizzando un ciclo for la cui sintassi è al paragrafo 11.5.2.
Quanti vettori di test è necessario simulare in questo caso?
Quanto tempo impiega la simulazione?
• non esaustivo. In questo caso i vettori di test sono in numero ridotto. Si pensi ad un
insieme che sia in grado di verificare il funzionamento di tutti i LED ed i casi in cui si
ha una consistente propagazione del riporto nell’addizionatore. */

module fadder8of(A,B,Y0,Y1);
	input wire [7:0] A,B;
	output wire [6:0] Y0,Y1;		//pilotaggio display
	wire ov;
	wire [7:0] S;
	wire [7:0] Y0d, Y1d;

	assign {ov, S} = A+B;		//ov=1 in caso di overflow
	
	display7seg dig1(.A(S[3:0]), .Y(Y0d));
	display7seg dig2(.A(S[7:4]), .Y(Y1d));
	
	assign Y0 = (ov) ? 7'b0110110 : Y0d;	//ov=1 -> 3 linee sul display, altrimenti mostra uscita Y0i
	assign Y1 = (ov) ? 7'b0110110 : Y1d;
	
endmodule