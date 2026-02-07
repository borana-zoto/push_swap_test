/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzoto <bzoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:55:25 by bzoto             #+#    #+#             */
/*   Updated: 2026/02/07 18:58:07 by bzoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(char *s)
{
	while (*s)
		write(1, &*s, 1);
	s++;
}

void free_stack(t_stack **lst)
{
	t_stack *c;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		c = (*lst)->next;
		free(*lst);
		*lst = c;
	}
	*lst = NULL;
}

void print_error_and_exit(t_stack **a, t_stack **b)
{
	if (!a || *a)
		free_stack(a);
	if (!b || *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long int ft_atoi(const char *s)
{
	long int n;
	int sign;

	n = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n * sign);
}