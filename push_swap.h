/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:56:34 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/24 12:58:08 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_list
{
	int				nnumb;
	struct s_list	*next;
}					t_list;

typedef struct s_stuff
{
	t_list			*stacka;
	t_list			*stackb;
	int				sizea;
	int				sizeb;
	int				thirda;
	int				thirdb;
	int				max;
	int				min;
	int				ssize;
	char			**lst;
}					t_stuff;

size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *s);
char				**ft_split(char const *s, char c, t_stuff *stuff);
char				*ft_strchr(const char *str, int c);
int					ft_strlen(const char *str);
void				newav(char **av, t_stuff *stuff);
void				ft_free_split(char **lst);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				newav(char **av, t_stuff *stuff);
void				arrange5(t_stuff *stuff);
int					*bestwowmove2(int *best, int *numnow);
bool				alreadystraight(t_list *tmp);
int					pnode(t_list *stackx, int value, int sizex);
bool				boopnode(t_list *stackx, int value, int sizex);
int					stackarot(t_stuff *stuff, int n);
int					*bigret(t_stuff *stuff, int n);
int					*bestwowmove(int *best, int *numnow);
void				todomove(t_stuff *stuff);
void				laststrach(t_stuff *stuff, int *com);
void				exemover(t_stuff *stuff, int n, void (*f)(t_stuff *, int),
						int dajeroma);
void				exemoverr(t_stuff *stuff, int n, bool check);
void				bempy(t_stuff *stuff);
void				arrange3(t_stuff *stuff);
int					ft_lstsize(t_list *lst);
void				phase1(t_stuff *stuff);
void				inizializer(t_stuff *stuff);
void				free_list(t_list *top);
t_list				*createlist(int ac, char **av);
int					ope(int ret);
int					err(int ret);
int					ft_strcmp(char *s1, char *s2);
long long int		ft_atol(const char *str);
int					checker(int ac, char **av, int i, int j);
int					stackainita(int ac, char **av, t_list **stacka);
int					stackainitb(int ac, t_list *stackb);
void				freestacka(t_list **stacka);
void				sa(t_stuff *stuff, int op);
void				sb(t_stuff *stuff, int op);
void				ss(t_stuff *stuff);
void				pa(t_stuff *stuff);
void				pb(t_stuff *stuff);
void				ft_ra(t_stuff *stuff, int op);
void				ft_rb(t_stuff *stuff, int op);
void				ft_rr(t_stuff *stuff);
void				ft_rra(t_stuff *stuff, int op);
void				ft_rrb(t_stuff *stuff, int op);
void				ft_rrr(t_stuff *stuff);

#endif