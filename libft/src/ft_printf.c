/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:54:04 by mprokope          #+#    #+#             */
/*   Updated: 2025/11/13 06:13:45 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_px(unsigned long num)
{
	char		*set;
	char		hex[17];
	int			len;
	int			i;

	hex[16] = '\0';
	i = 16;
	len = 0;
	set = "0123456789abcdef";
	if (!num)
		return (write(1, "0", 1));
	while (num > 0)
	{
		hex[--i] = set[num % 16];
		num /= 16;
		len++;
	}
	ft_putstr_fd(&hex[i], 1);
	return (len);
}

static int	print_p(void *ptr)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	if (!addr)
		return (write(1, "(nil)", 5));
	ft_putstr_fd("0x", 1);
	return (print_px(addr) + 2);
}

int	print_e(char *str)
{
	ft_putstr_fd(str, 2);
	return (ft_strlen(str));
}

static int	parse(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar_fd(((char)va_arg(args, int)), 1), 1);
	else if (*format == 's')
		return (print_s(va_arg(args, char *)));
	else if (*format == 'd' || *format == 'i')
		return (print_d(va_arg(args, int)));
	else if (*format == 'u')
		return (print_u(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (print_x(va_arg(args, unsigned int), 1));
	else if (*format == 'X')
		return (print_x(va_arg(args, unsigned int), 2));
	else if (*format == 'p')
		return (print_p(va_arg(args, void *)));
	else if (*format == 'e')
		return (print_e((char *)va_arg(args, char *)));
	else
		return (write(1, "%", 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;

	written = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && !format[1])
			return (-1);
		if (*format == '%' && format[1])
		{
			written += parse(++format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			written++;
		}
		format++;
	}
	va_end(args);
	return (written);
}
