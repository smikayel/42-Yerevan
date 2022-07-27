/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:17:59 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/11 12:46:10 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	tmp;
	int	min_index;

	min_index = 0;
	i = 0;
	while (i < size)
	{
		tmp = tab[i];
		min_index = i;
		k = i + 1;
		while (k < size)
		{
			if (tab[k] < tab[min_index])
			{
				min_index = k;
			}
			k++;
		}
		tab[i] = tab[min_index];
		tab[min_index] = tmp;
		i++;
	}
}
