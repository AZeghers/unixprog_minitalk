/*
** server.c for  in /home/zegher_a/Modules/Sys_Unix/PSU_2015_minitalk
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Wed Feb 10 13:13:23 2016 alexis zeghers
** Last update Sun Feb 21 15:47:36 2016 alexis zeghers
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int		g_let[4] =
  {
    0,
    0,
    0,
    0
  };

int		power(int nb, int power);
void		put_nbr(int nb);
void		my_exit(int type);

void		client_pid(int sign)
{
  if (g_let[0] != 16)
    {
      if (sign == SIGUSR1)
	++g_let[0];
      if (sign == SIGUSR2)
	{
	  g_let[2] = g_let[2] + power(2, g_let[0]);
	  ++g_let[0];
	}
    }
  if (g_let[0] == 16)
    {
      g_let[3] = 1;
      g_let[0] = 0;
    }
}

void		display(void)
{
  unsigned char	c;

  c = g_let[1];
  if (c == 4)
    {
      if ((kill(g_let[2], SIGUSR1)) == -1)
	my_exit(1);
      g_let[2] = 0;
      g_let[3] = 0;
    }
  else
    write(1, &c, 1);
}

void		sig_handler(int sign)
{
  if (g_let[3] == 0)
    client_pid(sign);
  else
    {
      if (sign == SIGUSR1)
	++g_let[0];
      if (sign == SIGUSR2)
	{
	  g_let[1] = g_let[1] + power(2, g_let[0]);
	  ++g_let[0];
	}
      if (g_let[0] == 8)
	{
	  display();
	  g_let[0] = 0;
	  g_let[1] = 0;
	}
    }
  usleep(15);
  if (g_let[3] == 1)
    if ((kill(g_let[2], SIGUSR1)) == -1)
      my_exit(1);
}

int		main()
{
  if (((signal(SIGUSR1, &sig_handler)) == SIG_ERR) ||
      ((signal(SIGUSR2, &sig_handler)) == SIG_ERR))
    my_exit(0);
  put_nbr((int)getpid());
  write(1, "\n", 1);
  while (1)
    pause();
}
