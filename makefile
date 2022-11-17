execute:
	@gcc shell.c -o shell
	@gcc date.c -o date
	@gcc cat.c -o cat
	@gcc ls.c -o ls
	@gcc mkdir.c -o mkdir
	@gcc rm.c -o rm
	@./shell
	@rm rm mkdir ls cat date shell