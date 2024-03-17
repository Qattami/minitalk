/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:50:49 by iqattami          #+#    #+#             */
/*   Updated: 2024/03/17 01:42:00 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}
int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		{
			write(1, "(null)", 6);
			return (6);
		}
	while (s[i])
	{
		write(1, &s[i],1);
		i++;
	}
	return (i);
}
int	ft_putnbr(long long n)
{
	unsigned int	nb;
	int				nbr;

	nbr = 0;
	nb = n;
	if (n < 0)
	{
		nbr += ft_putchar('-');
		nb = -n;
	}
	if (nb < 10)
		nbr += ft_putchar(nb + 48);
	else
	{
		nbr += ft_putnbr((nb / 10));
		nbr += ft_putnbr((nb % 10));
	}
	return (nbr);
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}