/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:53:47 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/06 10:40:39 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *changed_element;

    if (!lst || !*f || !del)
        return (NULL);

    new_list = NULL;
    new_list = (t_list *) malloc(sizeof(t_list));
    while (lst)
    {
        changed_element = ft_lstnew(lst->content);
        if (!changed_element)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, changed_element);
        lst = lst->next;
    }
    return (new_list);
}
