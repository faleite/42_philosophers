/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:53:30 by faaraujo          #+#    #+#             */
/*   Updated: 2023/10/28 15:09:44 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * @brief Checks if "int c" is a decimal digit character
 * @param c Character to be checked
 * @return Returns zero if false, non-zero if true   
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief The atoi() function converts the initial portion of the string pointed
 * to by nptr to int representation.
 * @return The converted value.
*/
int	ft_atoi(const char *ptr)
{
	int	i;
	int	pn;
	int	nbr;

	i = 0;
	pn = 1;
	nbr = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			pn = -1;
		i++;
	}
	while (ptr[i] && ft_isdigit(ptr[i]))
	{
		nbr *= 10;
		nbr += ptr[i] - 48;
		i++;
	}
	return (nbr * pn);
}
