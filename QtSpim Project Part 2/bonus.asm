.data
	prompt: .asciiz "Enter the number: "

.text 
	Main:
	# Prompt the user to enter number.
	li $v0, 4
	la $a0, prompt
	syscall
	
	# Get the user's number
	li $v0, 5
	syscall
	
	# Store the number in $t0
	move $t0, $v0
	addi $s0, $zero, 2
	
	#multiply 2 by contents of register $t0 and store in register t0
	mul $t0, $t0, $s0
	
	# Print or show the number
	li $v0, 1
	add $a0, $zero, $t0
	syscall
	
	#pc counter will always add +4 to the pc and will keep doing this unless will tell it to EXIT FROM PROGRAM
	li $v0,10
	syscall