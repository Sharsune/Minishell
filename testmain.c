/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:50 by sharsune          #+#    #+#             */
/*   Updated: 2023/04/17 15:27:54 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void	signal_handler(int signum)
{
	printf("\n");
}

void	signal_quit(int signum)
{
	printf("\n");
	exit(0);
}

int	main(void)
{
	char	buffer[1024];
	int		n;

	if (signal(SIGINT, signal_handler) == SIG_ERR)
	{
		printf("Error installing signal handler\n");
		return (1);
	}
	if (signal(SIGQUIT, signal_quit) == SIG_ERR)
	{
		printf("Error installing signal handler\n");
		return (1);
	}

	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		n = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (n > 0)
		{
			buffer[n] = '\0';
			printf("You entered: %s", buffer);
		}
		else
		{
			printf("\n");
			return (0);
		}
	}
	return (0);
}
