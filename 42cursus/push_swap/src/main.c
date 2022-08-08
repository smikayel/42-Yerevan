/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:23:57 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/08 12:36:17 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*start;
	t_list	*next;

	while (stack && stack->a)
	{
		start = stack->a;
		next = stack->a;
		while (next->next)
		{
			start = next;
			next = next->next;
		}
		if (start == next)
		{
			free(stack->a);
			stack->a = NULL;
		}
		else
		{
			start->next = NULL;
			free(next);
		}
	}
	free(stack);
}

void	arg_err(void)
{
	put_msg("Error\n", 0);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_list	*a;
	t_list	*b;
	char	**test;
	int		i;

	i = 0;
	if (argc == 1)
		arg_err();
	stack = malloc(sizeof(t_stack));
	a = malloc(sizeof(*a));
	b = NULL;
	stack->a = a;
	stack->b = b;
	valid_check(argv);
	test = valid_args(argv, argc);
	fill_stack(stack, test);
	push_swap(stack);
	while (test[i])
		free(test[i++]);
	free(test);
	free_stack(stack);
	free(a);
	return (0);
}
