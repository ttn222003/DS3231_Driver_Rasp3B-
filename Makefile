cc = gcc

compile: DS3231_user.c
	$(cc) DS3231_user.c -L. -lDS3231 -o DS3231_user
	sudo ./DS3231_user