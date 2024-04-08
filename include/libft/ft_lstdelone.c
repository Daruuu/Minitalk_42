/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:11:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/06 20:39:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (lst)
    {
        del(lst->content);
        free(lst);
    }
}

/*
void    del(void *content)
{
    free(content);
}

int main()
{
    t_list  *lista;
    t_list  *node01;
    t_list  *node02;
    t_list  *node03;
    t_list  *node04;

    lista = NULL; 

    node01 = (t_list *) malloc(sizeof(t_list));
    node01->content = "node01";
    node01->next = NULL;
    lista = node01;

    node02 = (t_list *) malloc(sizeof(t_list));
    node02->content = "node02";
    node02->next = NULL;
    node01->next = node01;

    node03 = (t_list *) malloc(sizeof(t_list));
    node03->content = "node03";
    node03->next = NULL;
    node02->next = node03;

    node04 = (t_list *) malloc(sizeof(t_list));
    node03->content = "node03";
    node04->next = NULL;
    node03->next = node04;

    ft_lstdelone(node02, del);

    return (0);
}
*/
