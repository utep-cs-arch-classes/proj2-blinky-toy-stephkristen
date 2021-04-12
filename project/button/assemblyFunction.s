	.arch  msp430g2553
	.p2align 1,0
	.text

	.global assembly_buzzerInit

assembly_buzzerInit:
	call #buzzer_init

