/*
** client.c for  in /home/zegher_a/Modules/Sys_Unix/PSU_2015_minitalk
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Wed Feb 10 13:12:49 2016 alexis zeghers
** Last update Sun Feb 21 15:46:19 2016 alexis zeghers
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void		my_exit(int type);

int		get_nbr(char *str)
{
  int		i;
  int		ret;
  int		s;

  i = -1;
  s = 1;
  ret = 0;
  if (str[0] == '-')
    {
      s = -s;
      ++i;
    }
  while (str[++i] >= '0' && str[i] <= '9')
    {
      ret = ret * 10;
      ret = ret + str[i] - '0';
    }
  return (s * ret);
}

void		send_pid(char *serv)
{
  int		pid;
  int		i;

  i = 16;
  pid = (int)getpid();
  while (i > 0)
    {
      usleep(10000);
      if ((kill(get_nbr(serv), ((pid % 2) == 1) ? SIGUSR2 : SIGUSR1)) == -1)
	my_exit(1);
      pid = pid >> 1;
      --i;
    }
}

void		sig_handler()
{
  return ;
}

void		message_in_a_bottle(char **argv, int i, int j, unsigned char n)
{
  send_pid(argv[1]);
  while (argv[2][i])
    {
      n = argv[2][i];
      while (j > 0)
	{
	  usleep(15);
	  if ((kill(get_nbr(argv[1]), (n % 2 == 1) ? SIGUSR2 : SIGUSR1)) == -1)
	    my_exit(1);
	  pause();
	  n = n >> 1;
	  --j;
	}
      ++i;
      j = 8;
    }
  n = 4;
  while (--j >= 0)
    {
      usleep(15);
      if ((kill(get_nbr(argv[1]), ((n % 2) == 1) ? SIGUSR2 : SIGUSR1)) == -1)
	my_exit(1);
      pause();
      n = n >> 1;
    }
}

int		main(int argc, char **argv)
{
  int		i;
  int		j;
  unsigned char	n;

  j = 8;
  i = 0;
  n = 0;
  if (((signal(SIGUSR1, &sig_handler)) == SIG_ERR) ||
      ((signal(SIGUSR2, &sig_handler)) == SIG_ERR))
    return (0);
  if (argc != 3)
    {
      write(2, "Usage : [PID] [STRING] \n", 24);
      return (-1);
    }
  else
    message_in_a_bottle(argv, i, j, n);
  return (0);
}
