		.data
	 input: 	.asciiz	"Input a number:"
         output:	.asciiz   "Output:" 
	 newline:	.asciiz "\n"
			.text
			.align	2
	                .globl	main
			.ent	main
	 main:
			subu	$sp, 16
			sw	$31, 12($sp)
	                li      $8,  0
	                li      $9,  0
	                li      $10, 1
	                li      $12, 0
	                la      $4, input
	                li      $v0, 4
	                syscall
			li      $v0, 5
	                syscall
	                add     $8, $8, $v0
	                add     $9, $9, $v0
		#	la	$4, newline
		#	li	$v0, 4
		#	syscall
                loop:                     	# 改行を画面に表示
	                mul     $10,$10, $9
			sub	$9, $9, 1	# i--	# i < 8 ?
	                sltu    $11,$12,$9 
			bgtz	$11, loop
	                la      $4,  output
	                li      $v0, 4
	                syscall
                     	li      $a0, 0
	                add     $a0,$a0, $10
	                li      $v0, 1
	                syscall
	                la      $4,  newline
	                li      $v0, 4
                syscall                  # i < 8ならばloopへジャンプ
			move	$2, $0
			lw	$31, 12($sp)
			addu	$sp, 16
			j	$31
		.end
