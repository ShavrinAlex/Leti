// hellocof.s
// ???????쭠? ?p??p????, ?뢮????? ᮮ?饭?? "Hello world"
// ??? ???????樨 ? ??p???? ??p???? COFF, ?ᯮ??㥬?? FreeBSD
//
// ??????????:
// as -o hellocof.o hellocof.s
// ??????????:
// FreeBSD
// ld -s -o hellocof.bsd /usr/lib/crt0.o hellocof.o -lc
//
//
	.text
.globl _main
_main:
	pushl	$message
	call	_puts
	popl	%ebx
	ret
	.data
message:
	.ascii	"Hello world\0"
