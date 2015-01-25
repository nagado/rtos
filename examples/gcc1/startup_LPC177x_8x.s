
	.equ    cfg_stack_size, 0x100

   	.macro  IRQ handler
    	.weak   \handler
    	.set    \handler, Default_Handler
    	.endm

	.global _myrtos_reset

 	.section ".isr_vector"
	.globl  __myrtos_interrupt_table
	.type   __myrtos_interrupt_table, %object

__myrtos_interrupt_table:
        .long   __stack                 /* Top of Stack                 */
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset
	.long	_myrtos_reset

	.section ".text"
