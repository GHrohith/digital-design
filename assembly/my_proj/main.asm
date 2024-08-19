ldi r17, 0b00111100
out DDRD, r17

Start:
ldi r16, 0b10101010
ldi r17, 8
ldi r18, 1

loop:
	ldi r19, r16
	and r19, r18
	bne one

	ldi r20 0b00000000
	b end
one:
	ldi r20, 0b00000100
end:
	out PortD, r20

	call wait
	
	dec r17
	bne loop

	rjmp Start

wait:
	ldi r21, 0xFF
waitlp:
	dec r21
	brne waitlp
	ret
