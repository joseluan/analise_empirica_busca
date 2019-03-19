CC=g++
.DEFAULT_GOAL=analise

bsearch.o: ../include/bsearch.h ../src/bsearch.cpp
	$(CC) ../src/bsearch.cpp -c

rbsearch.o: ../include/rbsearch.h ../src/rbsearch.cpp
	$(CC) ../src/rbsearch.cpp -c

tsearch.o: ../include/tsearch.h ../src/tsearch.cpp
	$(CC) ../src/tsearch.cpp -c

rtsearch.o: ../include/rtsearch.h ../src/rtsearch.cpp
	$(CC) ../src/rtsearch.cpp -c

jsearch.o: ../include/jsearch.h ../src/jsearch.cpp
	$(CC) ../src/jsearch.cpp -c

fsearch.o: ../include/fsearch.h ../src/fsearch.cpp
	$(CC) ../src/fsearch.cpp -c

lnsearch.o: ../include/lnsearch.h ../src/lnsearch.cpp
	$(CC) ../src/lnsearch.cpp -c

analise: ../src/main.cpp bsearch.o rbsearch.o tsearch.o rtsearch.o jsearch.o fsearch.o
	$(CC) ../src/main.cpp bsearch.o rbsearch.o tsearch.o rtsearch.o jsearch.o fsearch.o -o analise

analise_41: ../src/main_41.cpp jsearch.o lnsearch.o
	$(CC) ../src/main_41.cpp jsearch.o lnsearch.o -o analise_41

analise_42: ../src/main_42.cpp bsearch.o rbsearch.o 
	$(CC) ../src/main_42.cpp bsearch.o rbsearch.o -o analise_42

analise_42_passos: ../src/main_42_passos.cpp bsearch.o rbsearch.o
	$(CC) ../src/main_42_passos.cpp bsearch.o rbsearch.o -o analise_42_passos

analise_43: ../src/main_43.cpp bsearch.o tsearch.o fsearch.o
	$(CC) ../src/main_43.cpp bsearch.o tsearch.o fsearch.o -o analise_43

analise_44: ../src/main_44.cpp bsearch.o lnsearch.o
	$(CC) ../src/main_44.cpp bsearch.o lnsearch.o -o analise_44

analise_45: ../src/main_45.cpp fsearch.o
	$(CC) ../src/main_45.cpp fsearch.o -o analise_45

limpar: 
	rm *.txt
	rm *.o
	rm analise
	rm analise_41
	rm analise_42
	rm analise_43
	rm analise_44
	rm analise_45