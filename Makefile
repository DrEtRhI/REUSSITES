
.SUFFIXES:
.SUFFIXES: .c .o 

DIR = /home/c/carrierf/LIB_REUSSITES
INCL = ${DIR}/include
LIB = ${DIR}/lib

TasACompleter.o : TasACompleter.c
	gcc -g -c TasACompleter.c

.c.o :
	gcc -Wall -g -ansi -c -I${INCL} $<

ReussiteQLL.e: ${LIB}/libmachine_trace.a Alea.o TasACompleter.o AfficherTas.o QLL.o InteractionQLL.o ReussiteQLL.c
	gcc  -g -I${INCL} -o ReussiteQLL.e ReussiteQLL.c ${LIB}/graphlib_w.o InteractionQLL.o QLL.o TasACompleter.o AfficherTas.o Alea.o -L${LIB} -lmachine_trace -L/usr/X11R6/lib -lX11 -lm

ReussiteR7.e: ${LIB}/libmachine_trace.a Alea.o TasACompleter.o AfficherTas.o R7.o InteractionR7.o ReussiteR7.c
	gcc  -g -I${INCL} -o ReussiteR7.e ReussiteR7.c InteractionR7.o R7.o TasACompleter.o AfficherTas.o Alea.o -L${LIB} -lmachine_trace -L/usr/X11R6/lib -lX11 -lm

ReussiteC4.e: ${LIB}/libmachine_trace.a Alea.o TasACompleter.o AfficherTas.o C4.o InteractionC4.o ReussiteC4.c
	gcc  -g -I${INCL} -o ReussiteC4.e ReussiteC4.c ${LIB}/graphlib_w.o InteractionC4.o C4.o TasACompleter.o AfficherTas.o Alea.o -L${LIB} -lmachine_trace -L/usr/X11R6/lib -lX11 -lm

Reussites.e: ${LIB}/libmachine_trace.a Alea.o TasACompleter.o AfficherTas.o QLL.o C4.o QLL.o InteractionToutes.o Reussites.c
	gcc  -g -I${INCL} -o Reussites.e Reussites.c ${LIB}/graphlib_w.o InteractionToutes.o QLL.o C4.o QLL.o TasACompleter.o AfficherTas.o Alea.o -L${LIB} -lmachine_trace -L/usr/X11R6/lib -lX11 -lm

clean:
	rm -f AfficherTas.o Alea.o InteractionQLL.o QLL.o

