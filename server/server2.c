/*
** server2.c for  in /home/zegher_a/Modules/Sys_Unix/PSU_2015_minitalk
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Wed Feb 10 13:13:37 2016 alexis zeghers
** Last update Sun Feb 21 15:48:21 2016 alexis zeghers
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int		power(int nb, int power);
void		sig_handler(int sign);
void		client_pid(int sign);
void		display(void);

void		put_nbr(int nb)
{
  char		c;

  if (nb >= 10)
    put_nbr(nb / 10);
  c = (nb % 10) + '0';
  if ((write(1, &c, 1)) == -1)
    exit(2);
}

void		my_exit(int type)
{
  if (type == 0)
    {
      write(2, "Can\'t catch SIGUSR\n", 18);
      exit(0);
    }
  else
    {
      write(2, "Kill failed\n", 12);
      exit(1);
    }
}
