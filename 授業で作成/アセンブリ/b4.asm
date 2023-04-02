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
	                subu    $sp,$sp,16
			sw      $ra,12($sp)
			sw	$fp, 8($sp)
	                addu    $fp,$sp,16
	                lw      $a0,0($17)
	                jal     func
			add $8,$8, $v0
	                lw      $ra,12($sp)
			lw      $fp,8($sp)
			addu    $sp,$sp,16
	                add     $16,$16,1
	                add     $17,$17,4
	                slt     $10,$16,8
	                bgtz    $10,loop
	                move    $a0, $8
	                li      $v0,1
	                syscall
			la      $4,newline
	                li       $v0,4
	                syscall
			move	$2, $0
			lw	$31, 12($sp)
			addu	$sp, 16
			j	$31
		.end

   func:
	                subu $sp,$sp,16
			sw $ra,12($sp)
			sw $fp,8($sp)
			addu $fp,$sp,16

                              	subu    $sp,$sp,16
	                        sw      $ra,12($sp)
	                        sw      $fp,8($sp)
				li      $18,2
	                        addu    $fp,$sp,16
				div     $a0,$18
	                        mfhi    $9
	                        bne     $9,$0,skip0 
	                        jal     cal1
                                skip0:
				beq      $9,$0,skip1
	                        jal     cal2
				skip1:	
	                        lw      $ra,12($sp)
        			lw      $fp,8($sp)
	                        addu    $sp,$sp,16

	                lw $ra,12($sp)
	                lw $fp,8($sp)
			addu $sp,$sp,16
			jr $ra
  cal1:
	                subu $sp,$sp,16
	                sw $ra,12($sp)
	                sw $fp,8($sp)
	                addu $fp,$sp,16

	                li $21,1
	                li $22,0
	                add $22,$22,$a0
         loop1:
	                mul $21,$21,$22
	                sub $22,$22,1
	                slt $23,$0,$22
	                bgtz $23,loop1
	                move $v0,$21

	                lw $ra,12($sp)
	                lw $fp,8($sp)
			addu $sp,$sp,16
	                        jr $ra
 cal2:	
                        subu $sp,$sp,16
	                sw $ra,12($sp)
	                sw $fp,8($sp)
	                addu $fp,$sp,16

	                li $18,0
	                li $19,1
                        loop2:
	                add $18,$18,$19
	                add $19,$19,1
	                slt $20,$19,$a0
	                bgtz $20,loop2
			add $18,$18,1
	                move $v0,$18

	                lw $ra,12($sp)
	                lw $fp,8($sp)
			addu $sp,$sp,16
	                jr $ra
	
