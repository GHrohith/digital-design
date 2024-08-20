.include "m328Pdef.inc"

ldi r16, 0b00000101
out TCCR0B, r16

ldi r17, 0b00111100
out DDRD, r17

Start:
ldi r16, 0b11111010
; ldi r16, 0b11111111
ldi r17, 8
ldi r18, 1

loop:
	mov r19, r16
	and r19, r18
	brne one

	ldi r20, 0b00000000
	jmp sk1
one:
	ldi r20, 0b00000100
sk1:
	out PortD, r20

	call wait

	
	dec r17
	breq end

	lsl r18
	jmp loop

end:
	rjmp Start

wait:
	ldi r21, 0xFF
waitlp:
	dec r21
	ldi r22, 0xFF
waitlp2:
	dec r22
	ldi r23, 0xFF
waitlp3:
	dec r23
	brne waitlp3
	brne waitlp2
	brne waitlp
	ret
