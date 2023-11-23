/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:11:46 by mloureir          #+#    #+#             */
/*   Updated: 2023/07/23 11:32:26 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int ft_strlen(char *str);

int main()
{
	int cont = 0;
	char teste[] = "ABCDE12345632521536724187633265";
	cont = ft_strlen(teste);
	printf("Tamanho da string: %d", cont);
	return (0);
}*/
int fixI(int i)
{
	if(i <= 0)
		return (0);
	else
		return (i);
}

int ft_checkI(int i)
{
	if(i > 0)
		return (i);
	else
		return (fixI(i));
}

int checkstr(char *str)
{
	if(!str)
		return (0);
	return (1);
}

int 	ft_strlen(char *str)
{
	int i = 0;
	int checks = 0;

	if(checkstr(str) == 1)
		checks = 1;
	while(str[i] != '\0' && checks == 1)
		i++;
	i = ft_checkI(i);
	return (i);
}
