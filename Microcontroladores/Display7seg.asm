list p=16f84				;busca en su base de datos el modelo de pic
include <P16F84A.inc>		;carga la libreria de pic
__CONFIG		_CP_OFF & _WDT_OFF & _PWRTE_ON & _XT_OSC

TIEMPO 		EQU	0X0C
TIEMPO2		EQU	0X0D

			org 0x00		 ;vector de inicio, indica al pic con el org que tiene que empezar a trabajar de la posicion 0
			
			bsf STATUS,RP0	 ;voy a trabajar en el banco 1 de memoria del pic
			clrf TRISB		 ;pongo todos los bits del puerto B en cero, es decir como salidas
			clrf TRISA
			bcf STATUS,RP0	 ;voy a trabajar en el banco 0 de memoria del pic
			
;XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
INICIO					 ;etiqueta para indicar a donde empieza el programa


			movlw 0x40	
			movwf TRISB
			movlw 0x1
			movwf TRISA	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x79	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x24	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x30	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x19	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x12	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x02	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0xf8	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x00
			movlw 0x2
			movwf TRISA	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			movlw 0x18	
			movwf TRISB	
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			call Retardo_200ms
			
			
			
			goto INICIO	;vuelvo a la etiqueta indicada anteriormente para generar el loop
RETARDO			
			movlw D'255'
			movwf TIEMPO
DEC			decfsz TIEMPO	;decrementa en uno la variable y si es cero se salta una instruccion
			goto DEC1
			return
			
DEC1			movlw D'255'
			movwf TIEMPO2
DEC2			decfsz TIEMPO2	;decrementa en uno la variable y si es cero se salta una instruccion
			goto DEC2
			goto DEC
			
include <retardos.inc>
END