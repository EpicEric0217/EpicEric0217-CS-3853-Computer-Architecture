.data
	prompt: .asciiz "Enter the number please..: "
.text
	main:
	#Prompt the user to enter the number
	li $v0, 4
	la $a0, prompt
	syscall
	
	#Grab the user's number..
	li $v0, 5
	syscall

	#Store the number in $t1
	move   $t1 ,$v0
	addi $s1, $zero, 2

	#multiply 2 by the contents of the register $t1 and store it in the register t1
	mul $t1, $t1, $s1

	#Now to print the number or show it...
	li $v0, 1
	add $a0, $zero, $t1 
	syscall

	#pc counter will always add +4 to pc amd will continue unless we tell it to exit from our program...
	li $v0, 10
	syscall