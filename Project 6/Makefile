worldcup: worldcup.o country.o
  gcc -Wall -o worldcup worldcup.c country.c
worldcup.o: country.h worldcup.c
  gcc -c worldcup.c
country.o: country.c country.h
  gcc -c country.c
clean:
  rm worldcup.o country.o worldcup