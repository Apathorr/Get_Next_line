/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:24:37 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/10 16:29:41 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# define WRONG(x)   if (x) return (-1)
# define DONE(x)   if (x) return (i)
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
