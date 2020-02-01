/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:31:21 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/31 18:22:25 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 32
# define FD_SIZE 4092

typedef struct		s_lst
{
	char			*first;
	int				a;
	int				b;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
char				*ft_strchr(const char *s, int c);
void				ps(t_lst **lista, t_lst **listb);
void				lst_print_ab(t_lst *list, char ab);

int					lst_size(t_lst *list);
void				ft_putllnbr(long long int n);
void				ft_putchar(char c);
void				ft_swap(int *a, int *b);

void				lst_print_ab(t_lst *list, char ab);
void				free_elem(t_lst *list);
void				lst_clear(t_lst **begin_list);
void				lst_delboth(t_lst **lsta, t_lst **lstb);

void				sa_swap_a(t_lst *list);
void				sb_swap_b(t_lst *list);
void				ss_sa_sb(t_lst *a, t_lst *b);
void				ra_rotate_a(t_lst **stack);
void				rb_rotate_b(t_lst **stack);
void				pa_push_a(t_lst **lsta, t_lst **lstb);
void				pb_push_b(t_lst **lstb, t_lst **lsta);
void				rr_ra_rb(t_lst **lista, t_lst **listb);
void				rra_revrotate_a(t_lst **list);
void				rrb_revrotate_b(t_lst **list);
void				rrr_rra_rrb(t_lst **lista, t_lst **listb);

void				lst_pushback(t_lst **list, t_lst **toadd);
void				lst_popfront(t_lst **list);
void				lst_popback(t_lst **list);

void				lst_pushback_a(t_lst **list, int i);
void				lst_pushback_b(t_lst **list, int i);

void				size_3(t_lst **lista);
void				size_3_5(t_lst **lista, t_lst **listb1);
void				size_6_more(t_lst **lista, t_lst **listb1);

t_lst				*lst_new_a(int i);
t_lst				*lst_new_b(int i);

t_lst				*lst_copy_a(t_lst *list);

long int			ft_atol(char *str);
int					ft_strcmp(char *s1, char *s2);
void				push_ch_front(t_lst **list, char *s);

int					is_number(int ac, char **av);
int					is_duplicate(int ac, char **av);
int					is_integer(int ac, char **av);

int					lowest(t_lst *listb);
void				case_3(t_lst **list);
int					biglowin_a(t_lst *lista, int n);
int					is_top_a(t_lst *lista, int n);
int					lowest_a(t_lst *lista);
int					highest_af_a(t_lst *lista, int n);
int					is_top(t_lst *listb, int n);
int					biggest(t_lst *listb);
int					distance_til(t_lst *listb, int n);
int					is_lower(t_lst *listb, int n);
int					lowest_bef(t_lst *listb, int n);
int					is_a_sorted(t_lst *list);
int					biglowin(t_lst *listb, int n);

int					if_rev_sorted_a(t_lst **list);
int					error_check(int ac, char **av);
int					is_sorted(t_lst *list);

void	push_li_front(t_lst **list, long int s);

#endif
