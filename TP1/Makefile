CPP=g++
EDL=g++

CPPFLAGS=-Wall -Werror -g -ansi -DMAP
EDLFLAGS=
LIBS=-lm

EXEC=main
INT=Ensemble.h
REAL=$(INT:.h=.cpp) $(EXEC).cpp
OBJ=$(REAL:.cpp=.o)

.PHONY: target clean realclean

target: $(EXEC)

%.o: %.cpp
	echo ">> Compilation de <$<>"
	$(CPP) -o $@ -c $< $(CPPFLAGS)

$(EXEC): $(OBJ)
	echo ">> Edition de liens de <$(EXEC)>"
	$(EDL) $(EDLFLAGS) -o $(EXEC) $(OBJ) $(LIBS)
	
clean:
	rm -f *.o core
realclean: clean
	rm -f *~
