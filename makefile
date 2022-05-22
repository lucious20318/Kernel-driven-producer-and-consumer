all: p1 p2
	
p1: P.c 
	gcc P.c -o po

p2: C.c
	gcc C.c -o co


