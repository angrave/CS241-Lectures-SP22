
.PHONY: all
all:
	$(CC) bitpuzzle.c -o bitpuzzle
	$(CC) disposition.c -o disposition 
	$(CC) pendingexec.c -o pendingexec
	$(CC) pendingfork.c -o pendingfork
	$(CC) sigwaitdemo.c -o sigwaitdemo
	$(CC) takeovertheworld.c -o takeovertheworld
	$(CC) sigismember.c -o sigismember
	$(CC) noint.c -o noint
	javac MyApp.java

.PHONY: clean
clean:
	$(RM) noint bitpuzzle disposition pendingexec sigismember pendingfork sigwaitdemo takeovertheworld
	$(RM) MyApp.class MyApp\$$1.class
