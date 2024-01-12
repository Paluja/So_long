/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:44:48 by pjimenez          #+#    #+#             */
/*   Updated: 2023/05/31 13:44:13 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	first_node = ft_lstnew(f(lst->content));
	if (!first_node)
		return (ft_lstclear(&first_node, del), NULL);
	node = first_node;
	node = node->next;
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!first_node)
		{
			ft_lstclear(&first_node, del);
		}
		ft_lstadd_back(&first_node, node);
		lst = lst->next;
	}
	return (first_node);
}
