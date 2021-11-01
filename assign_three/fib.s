	
	AREA     appcode, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg
	ENTRY 

__main FUNCTION
		MOV R6, #10 ; Fibonacci of 1st 10 numbers
		MOV R1, #01 
		MOV R2, #00 

loop    CMP R6, #00
		SUB R6, #01
		BLE finish        
		MOV R3, R2 ; store value of R2 in R3
		ADD R2, R2, R1 ; R2 = R2 + R1 
		MOV R5, R2  ; 
		MOV R0, R2
		BL printMsg
		MOV R2, R5
		MOV R1, R3
		
		B loop       

finish
	ENDFUNC
	END