/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:32:07 by elel-yak          #+#    #+#             */
/*   Updated: 2022/06/30 20:32:09 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

int	is_operator(char c)
{
	char	*operators;
	int		i;

	operators = "+-*/%";
	i = 0;
	while (operators[i])
	{
		if (operators[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	operator(int x, char *op, int y)
{
	int		result;
	int		i;
	char	*actions;
	int		(*operator[5])(int, int);

	actions = "+-*/%";
	operator[0] = &ft_add;
	operator[1] = &ft_sub;
	operator[2] = &ft_mul;
	operator[3] = &ft_div;
	operator[4] = &ft_mod;
	result = 0;
	i = 0;
	while (i < 5)
	{
		if (op[0] == actions[i])
		{
			result = (operator[i])(x, y);
			break ;
		}
		i++;
	}
	return (result);
}

void	do_op(char *v1, char *op, char *v2)
{
	int	i;
	int	x;
	int	y;
	int	result;

	i = 0;
	result = 1;
	x = ft_atoi(v1);
	y = ft_atoi(v2);
	if (!(is_operator(op[0])))
		write (1, "0", 1);
	else if (op[0] == '/' && y == 0)
		write (1, "Stop : division by zero", 23);
	else if (op[0] == '%' && y == 0)
		write (1, "Stop : modulo by zero", 21);
	else
	{
		result *= (operator(x, op, y));
		ft_putnbr(result);
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(av[1], av[2], av[3]);
	return (0);
}
