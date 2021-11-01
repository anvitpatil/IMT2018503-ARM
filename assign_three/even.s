
	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
      
__main  FUNCTION


	MOV R0,#0x20000000
	MOV R8, #04
	MOV R9,#0x00000000	
	
	ADD R1, R0, #0x00000004 
	ADD R2, R1, #0x00000004
	ADD R3, R2, #0x00000004

	MOV R4, #012
	STR R4, [R0]
	MOV R5, #015
	STR R5, [R1]
	
	MOV R6, #017
	MOV R7, #022	
	STR R6, [R2]
	STR R7, [R3]

B1	LDR R4, [R0]
	TST R4,#01      
  	BNE B2
	ADD R9,#01

B2	ADD R0,R0,#0x4
	SUBS R8,R8,#01
	CMP R8,#00
	BNE B1
	MOV R0,R9
	
	BL printMsg

stop B stop  
	ENDFUNC
      END