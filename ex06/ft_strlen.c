/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mloureir <dvoort@student.codam.nl>             +#+                   */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:19:15 by dvoort        #+#    #+#                 */
/*   Updated: 2023/05/15 15:41:26 by dvoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <assert.h>

#define ONE_HUNDRED 100
#define NINE_TIMES_TEN_PLUS_ONE_TIMES_NINE 99

typedef size_t		(*t_very_fun)(const char *);
static jmp_buf		g_escape;
volatile size_t		g_i;

void	handler(int signum)
{
	(void)signum;
	longjmp(g_escape, 1);
}

size_t	l33tlen(const char *str)
{
	size_t				i;
	char				c;
	const size_t		kool_skore = g_i++;
	t_very_fun			many_fun[ONE_HUNDRED];

	i = 0;
	while (i < ONE_HUNDRED)
	{
		many_fun[i] = l33tlen;
		++i;
	}
	if (setjmp(g_escape) == 0)
	{
		c = *(str + kool_skore);
		if (c)
			return (many_fun[NINE_TIMES_TEN_PLUS_ONE_TIMES_NINE](str));
		else
			return (kool_skore);
	}
	else
		return (kool_skore);
}

size_t	ft_strlen(const char *str)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGSEGV, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}
	g_i = 0;
	return (l33tlen(str));
}

int	main(void)
{
	const char	*s = "Hello, 42";

	printf("Length: %zu\n", ft_strlen(s));
	printf("Length: %zu\n", strlen(s));
	return (0);
}
