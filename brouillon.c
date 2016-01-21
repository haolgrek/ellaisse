/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:16:59 by rluder            #+#    #+#             */
/*   Updated: 2016/01/21 19:44:22 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main()
	check arguments (options? dir?)
	si options, save options
	si dir, changepath
	si multi dir, save paths
	opendir
	readdir
		while files:
			recup stat
			recup lstat
			recup time
			recup getpwuid getgrgid
			affichage
	return (0);
