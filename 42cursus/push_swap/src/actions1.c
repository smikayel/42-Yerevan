/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:22:39 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/08 12:22:42 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list *lst)
{
	int	tmp;

	if (!lst->next)
		return (-1);
	tmp = lst->n;
	lst->n = lst->next->n;
	lst->next->n = tmp;
	return (0);
}

int	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	tmp = *src;
	if ((*src)->next)
		*src = (*src)->next;
	ft_lstadd_front(dst, tmp);
	if ((*src)->next == NULL)
		*src = 0x0;
	return (0);
}

int	ft_pb(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	if (!stack->b)
		stack->b = tmp;
	else
		ft_lstadd_front(&stack->b, tmp);
	return (0);
}

int	ft_pa(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	if (!stack->a)
		stack->a = tmp;
	else
		ft_lstadd_front(&stack->a, tmp);
	return (0);
}

int	p_all(t_stack *stack, t_mode mod)
{
	if (mod != A && mod != B)
		return (-1);
	if (stack->b != NULL && mod == A)
	{
		if (ft_pa(stack) < 0)
			return (-1);
		put_msg("pa\n", 1);
	}
	else if (stack->a != NULL && mod == B)
	{
		if (ft_pb(stack) < 0)
			return (-1);
		put_msg("pb\n", 1);
	}
	else
	{
		put_msg("Error in sort (pa or pb)\n", 2);
		return (-1);
	}
	return (0);
}
