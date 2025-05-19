all:
	cc -o launcher launcher.c
	cc -o hello hello.c

clean:
	rm -f launcher hello
