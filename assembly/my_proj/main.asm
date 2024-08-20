.include "m328Pdef.inc"

ldi r17, 0b00111100
out DDRD, r17

Start:
ldi r16, 0b01010111
ldi r17, 8
call disp
ldi r16, 0b00111
ldi r17, 5
call disp

end:
	rjmp Start


disp:
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
	breq ret_disp

	lsl r18
	jmp loop
ret_disp:
	ret


wait:
	push r21
	push r22
	push r23
	ldi r21, 0xFF
	ldi r22, 0xFF
	ldi r23, 0xFF
waitlp:
	dec r21
	brne waitlp
	dec r22
	brne waitlp
	dec r23
	brne waitlp

	pop r23
	pop r22
	pop r21
	ret

