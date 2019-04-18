/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:05:29 by rsmith            #+#    #+#             */
/*   Updated: 2019/04/17 22:01:16 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

char	*ft_strcut(char *src, unsigned int i)
{
	unsigned int	n;
	char			*newstr;

	n = 0;
	newstr = 0;
	if (i > 0)
	{
		i++;
		newstr = ft_strnew(ft_strlen(src) - i);
		if (i >= ft_strlen(src))
			return (src);
		while (src[i])
		{
			newstr[n] = src[i];
			i++;
			n++;
		}
	}
	return (newstr);
}

t_list	*mind_stone(int vision, t_list **scarlet_witch)
{
	t_list *tmp;

	tmp = *scarlet_witch;
	if (!*scarlet_witch)
		return ((*scarlet_witch = ft_lstnew("", vision)));
	while (tmp)
	{
		if ((int)tmp->content_size == vision)
			return (tmp);
		tmp = tmp->next;
	}
	ft_lstadd(scarlet_witch, (tmp = ft_lstnew("", vision)));
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*page;
	char			swole[BUFF_SIZE + 1];
	int				i;

	page = mind_stone(fd, &list);
	if (!ft_strchr(page->content, '\n'))
	{
		while ((i = read(fd, &swole, BUFF_SIZE)) > 0)
		{
			swole[i] = '\0';
			page->content = ft_strjoin(page->content, swole);
			if (ft_strchr(swole, '\n'))
				break ;
		}
		if (i < 1)
			return (i);
	}
	i = 0;
	while (((char *)page->content)[i] && ((char *)page->content)[i] != '\n')
		i++;
	*line = ft_strnew(i);
	ft_strncpy(*line, page->content, i);
	page->content = ft_strcut(page->content, i);
	return (1);
}