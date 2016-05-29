


validate_info.o: validate_info.c
	gcc -c -o validate_info.o validate_info.c

size.o: size.c
	gcc -c -o size.o size.c

process_internal.o: process_internal.c
	gcc -c -o process_internal.o process_internal.c

main.o: main.c
	gcc -c -o main.o main.c

str_util.o: str_util.c
	gcc -c -o str_util.o str_util.c

all: size.o main.o str_util.o validate_info.o process_internal.o
	gcc -o vft size.o main.o str_util.o validate_info.o process_internal.o

clean:
	rm -f size.o main.o str_util.o validate_info.o process_internal.o
	rm vft
