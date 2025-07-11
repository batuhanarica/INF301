CFLAGS=-g -Wall -Wextra -Werror -gdwarf-4 -fsanitize=address
LDFLAGS=-fsanitize=address

EXEC=client-introduction client-tutoriel client-interactif client-tutorielFort client-projetX client-crypteMove client-planB crypteMove client-BayOfPigs crypteSeq Northwoods

# Utilisé uniquement si exécution sur Caseine.
# Pour changer le programme lancé par Caseine, modifiez la ligne ci-dessous
MAIN=client-introduction

all: $(EXEC)

client-interactif: client-interactif.o client.o

client-tutoriel: client-tutoriel.o client.o

client-tutorielFort: client-tutorielFort.o client.o

client-introduction: client-introduction.o client.o

client-projetX: client-projetX.o client.o

client.o: client.c client.h

client-crypteMove: client-crypteMove.o client.o

client-planB: client-planB.o client.o

crypteMove: crypteMove.o client.o

client-BayOfPigs: client-BayOfPigs.o client.o

crypteSeq: crypteSeq.o client.o

Northwoods: Northwoods.o client.o

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)

main: $(MAIN)
	cp $< $@

.PHONY: clear clean main
