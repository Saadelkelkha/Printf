#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define TEST(...) \
	do { \
		int	r1; \
		int	r2; \
		printf("printf   : ["); \
		r1 = printf(__VA_ARGS__); \
		printf("]\n"); \
		printf("ft_printf: ["); \
		r2 = ft_printf(__VA_ARGS__); \
		printf("]\n"); \
		printf("return   : %d vs %d  %s\n\n", r1, r2, \
			(r1 == r2) ? "OK" : "<<< KO"); \
	} while (0)

int	main(void)
{
	int		x = 42;
	char	*np = NULL;

	setvbuf(stdout, NULL, _IONBF, 0);

	printf("===== plain text =====\n");
	TEST("hello world");
	TEST("");
	TEST("line\n");

	printf("===== %%c =====\n");
	TEST("%c", 'a');
	TEST("%c%c%c", 'a', 'b', 'c');
	TEST("[%c]", ' ');
	TEST("%c", '0');

	printf("===== %%s =====\n");
	TEST("%s", "hello");
	TEST("%s", "");
	TEST("%s %s", "hello", "world");
	TEST("%s", np);

	printf("===== %%p =====\n");
	TEST("%p", &x);
	TEST("%p", np);
	TEST("%p", (void *)1);

	printf("===== %%d / %%i =====\n");
	TEST("%d", 0);
	TEST("%d", 42);
	TEST("%d", -42);
	TEST("%i", 42);
	TEST("%i", -42);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN);
	TEST("%i", INT_MIN);

	printf("===== %%u =====\n");
	TEST("%u", 0);
	TEST("%u", 42);
	TEST("%u", -1);
	TEST("%u", UINT_MAX);
	TEST("%u", INT_MIN);

	printf("===== %%x / %%X =====\n");
	TEST("%x", 0);
	TEST("%x", 255);
	TEST("%x", 4096);
	TEST("%x", -1);
	TEST("%x", UINT_MAX);
	TEST("%X", 255);
	TEST("%X", 3735928559u);
	TEST("%X", -1);

	printf("===== %%%% =====\n");
	TEST("%%");
	TEST("100%%");
	TEST("%%%%%%");
	TEST("%c%%%c", 'a', 'b');

	printf("===== mixed =====\n");
	TEST("%c %s %d %i %u %x %X %%", 'a', "str", -5, 5, 5u, 255, 255);
	TEST("[%s] [%d] [%c] [%x]", "abc", 123, 'z', 48879);
	TEST("%d%d%d", 1, 2, 3);
	TEST("text %s text %d text", "mid", 7);
	TEST("%p %p", &x, np);



ft_printf("%u\n", 4294967295);
ft_printf("%x\n", 4294967295);
printf("abc%");
	return (0);
}
