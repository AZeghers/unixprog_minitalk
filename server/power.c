/*
** power.c for  in /home/zegher_a/Modules/Sys_Unix/PSU_2015_minitalk
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Wed Feb 10 13:13:49 2016 alexis zeghers
** Last update Wed Feb 10 13:13:50 2016 alexis zeghers
*/

int	power(int nb, int power)
{
  int	n;

  n = 1;
  while (power > 0)
    {
      n = n * nb;
      --power;
    }
  return (n);
}
