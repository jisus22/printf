/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printinteger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:55:06 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/01/26 11:55:07 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnum(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	if (nb == 0)
		count++;
	while (nb > 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

int	ft_printinteger(va_list arg)
{
	int	nb;
	int	count;

	nb = va_arg(arg, int);
	count = ft_countnum(nb);
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
		count = 11;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb *= -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb <= 9)
		ft_putchar(nb + 48);
	return (count);
}
