	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
      
__main  FUNCTION
	
	MOV R0,#0x20000000

	ADD R1, R0, #0x00000005
	ADD R2, R1, #0x00000005

	MOV R4, #010
	STR R4, [R0]
	MOV R5, #08
	STR R5, [R1]
	MOV R6, #04
	STR R6, [R2]

	LDR R4, [R0]
	LDR R5, [R1]
	CMP R4, R5
	BGT B1
	MOV R4, R5
	
B1	LDR R6, [R2]
	CMP R4, R6
	BGT B2
	MOV R4, R6
	
B2	MOV R0,R4
	BL printMsg

stop B stop
	ENDFUNC
	END