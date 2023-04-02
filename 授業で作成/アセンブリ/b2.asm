		.data
	 hoge:	.word	1 4 1 4 2 1 3 5
	 newline:	.asciiz "\n"
			.text
			.align	2
	                .globl	main
			.ent	main
      main:
			subu	$sp, 16
			sw	$31, 12($sp)
	                li      $8, 0
	                li      $9, 0
			li	$16, 0	
			la	$17, hoge	# $17に，hoge[0]のアドレ
      loop:
	                subu    $sp,$sp,32
			sw      $ra,20($sp)
			sw	$fp, 16($sp)
	                addu    $fp,$sp,32
	                lw      $a0,0($17)
	                jal     func
	                lw      $ra,20($sp)
			lw      $fp,16($sp)
			addu    $sp,$sp,32
	                add     $16,$16,1
	                add     $17,$17,4
	                slt     $10,$16,8
	                bgtz    $10,loop
			move	$2, $0
			lw	$31, 12($sp)
			addu	$sp, 16
			j	$31
		.end

   func:
	                subu $sp,$sp,32
			sw $ra,20($sp)
			sw $fp,16($sp)
			addu $fp,$sp,32
			li  $v0,1
	                syscall
	                la   $4, newline
	                li $v0,4
	                syscall
	                lw $ra,20($sp)
	                lw $fp,16($sp)
			addu $sp,$sp,32
			jr $ra
	                
	
