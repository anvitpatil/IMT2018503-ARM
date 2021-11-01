	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY


__main  FUNCTION
	MOV R0, #0x20000000
	MOV R4, #10				
	MOV R7, #06
	
BRANCH1	SUBS R4, R4, #01
		
		CMP R4, #00
		STR R7, [R0]
		ADD R7, #01
		ADD R0, #04
		
		BNE BRANCH1

		MOV R0, #0x20000000
		LDR R1, [R0]
		MOV R4, #05	

	

B1		ADD R0,R0,#0x4
        LDR R3,[R0] ;next element
		CMP R2,R3
		BGT B2
		MOV R2,R3  ;update R2
		
B2   	SUBS R1,R1,#01  
		CMP R1,#00
		BNE B1
		MOV R0,R2
		BL printMsg
		
stop    B stop 
	 ENDFUNC
	 END