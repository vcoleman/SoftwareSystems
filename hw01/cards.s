	.file	"cards.c"
	.section	.rodata
.LC0:
	.string	"Enter the card_name: "
.LC1:
	.string	"%2s"
	.align 8
.LC2:
	.string	"I don't understand that value!"
.LC3:
	.string	"Current count: %i\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, -24(%rbp)
	jmp	.L2
.L12:
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %eax
	leaq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$0, -20(%rbp)
	movzbl	-16(%rbp), %eax
	movsbl	%al, %eax
	subl	$65, %eax
	cmpl	$23, %eax
	ja	.L3
	movl	%eax, %eax
	movq	.L7(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L7:
	.quad	.L4
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L5
	.quad	.L5
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L5
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L13
	.text
.L5:
	movl	$10, -20(%rbp)
	jmp	.L8
.L4:
	movl	$11, -20(%rbp)
	jmp	.L8
.L3:
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jle	.L9
	cmpl	$10, -20(%rbp)
	jle	.L8
.L9:
	movl	$.LC2, %edi
	call	puts
	jmp	.L2
.L8:
	cmpl	$2, -20(%rbp)
	jle	.L10
	cmpl	$6, -20(%rbp)
	jg	.L10
	addl	$1, -24(%rbp)
	jmp	.L11
.L10:
	cmpl	$10, -20(%rbp)
	jne	.L11
	subl	$1, -24(%rbp)
.L11:
	movl	$.LC3, %eax
	movl	-24(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	jmp	.L2
.L13:
	nop
.L2:
	movzbl	-16(%rbp), %eax
	cmpb	$88, %al
	jne	.L12
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
