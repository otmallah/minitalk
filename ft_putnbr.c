/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:26 by otmallah          #+#    #+#             */
/*   Updated: 2021/12/18 15:27:27 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr(int t)
{
	if (t < 0)
	{
		ft_putchar('-');
		t *= -1;
	}
	if (t >= 10)
	{
		ft_putnbr(t / 10);
		ft_putnbr(t % 10);
	}
	else if (t >= 0)
		ft_putchar(t + 48);
}
