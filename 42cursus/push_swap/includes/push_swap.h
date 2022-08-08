/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:42:10 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/08 12:42:11 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				n;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		len;
}	t_stack;

typedef enum mode_e
{
	A,
	B,
	BOTH
}	t_mode;

int		s_all(t_stack *stack, t_mode mod);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		p_all(t_stack *stack, t_mode mod);
int		r_all(t_stack *stack, t_mode mod);
int		rr_all(t_stack *stack, t_mode mod);
char	**valid_args(char **argv, int argc);
int		fill_list(t_list **lst, int content);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	put_msg(char *str, int fd);
int		shift_rr(t_list **lst);
int		shift(t_list **lst);
int		swap(t_list *lst);
int		push(t_list **dst, t_list **src);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
int		validation(char **res);
int		fill_stack(t_stack *stack, char **res);
void	push_swap(t_stack *stack);
void	valid_check(char **argv);
void	selection_sort(int *arr, t_list *a);
void	swap_arr_sorting(int *xp, int *yp);
void	sort2(t_stack *stack);
void	sort3(t_stack *stack);
void	sort5(t_stack *stack);
void	push_min(t_stack *stack, int min);
int		matematikakan_hashvarkner(int sz);
void	push_to_b(t_stack *stack);
void	push_to_a(t_stack *stack);
int		sorted(t_list *a);
void	get_indexs(t_list *cursor);

#endif
