#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	main(void)
{
	const size_t	len = 1110UL;
	char			*str = calloc(len, sizeof(char));
	size_t			i;

	i = ~0UL;
	while (len > ++i)
	{
		char	curr = rand() % 128;

		if (isalpha(curr))
			str[i] = curr;
		else {
			while (!isalpha(curr))
				curr = rand() % 128;
			str[i] = curr;
		}
		printf("%lu: %d - %c\n", i + 1UL, curr, curr);
	}
	printf("s:\'%s\'\n", str);
	ft_printf("m:\'%s\'\n", str);
}
