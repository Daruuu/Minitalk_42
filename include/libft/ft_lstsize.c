/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:30:19 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/03 14:32:34 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int ft_lstsize(t_list *lst)
{
	int	i;

	i =0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
int	main()
{
	t_list	*lista;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
    t_list	*node4;

	lista = NULL; 

	node1 = (t_list *) malloc(sizeof(t_list));
	node1->content = "First";
	node1->next = NULL;
	lista = node1;

	node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = "second";
	node2->next = NULL;
	node1->next = node2;

	node3 = (t_list *) malloc(sizeof(t_list));
	node3->content = "third";
	node3->next = NULL;
	node2->next = node3;

    node4 = (t_list *) malloc(sizeof(t_list));
    node4->content = "fourth";
    node4->next = NULL;
    node3->next = node4;

	// testing here
	int	size = ft_lstsize(lista);
	printf("length of lista is: %d\n", size);

	return (0);
}
*/