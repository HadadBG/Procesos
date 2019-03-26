cc=g++
cFLAGS=-I include
run:bin/prog src/prog.cpp src/lista.cpp include/lista.h include/dato.h src/dato.cpp obj/dato.o obj/lista.o
	bin/prog
obj/lista.o:src/lista.cpp include/lista.h include/dato.h src/dato.cpp
	$(cc) -c $< -o $@ $(cFLAGS)
obj/dato.o:src/dato.cpp include/dato.h
	$(cc) -c $< -o $@ $(cFLAGS)
bin/prog:src/prog.cpp src/lista.cpp include/lista.h include/dato.h src/dato.cpp obj/dato.o obj/lista.o
	$(cc) $< obj/lista.o obj/dato.o -o $@ $(cFLAGS)
clean:
	rm bin/*
	rm obj/*
