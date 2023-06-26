#include "cub.h"

void	ft_debug(char	*str, char	*str2, t_env	*env)
{
	printf("%s %s%s@%s\n%s", P_DEBUG, T_DEBUG, UNDERLINE, str2, NC);
	printf("%s--------------------------------------- %s%s\n", T_DEBUG, str, NC);
	if (env->mlx)
	{
		printf("%smlx			|%s ", T_DEBUG, NC);
		printf("%p\n", env->mlx);
	}
	if (env->window)
	{
		printf("%swin			|%s ", T_DEBUG, NC);
		printf("%p\n", env->window);
	}
	if (env->img)
	{
		printf("%simg			|%s ", T_DEBUG, NC);
		printf("%p\n", env->img);
	}
	if (env->img_addr)
	{
		printf("%simg_addr		|%s ", T_DEBUG, NC);
		printf("%s\n", env->img_addr);
	}
	if (env->map.bit_map)
	{
		int i = 0;
		printf("%smap			|%s \n", T_DEBUG, NC);
		while (env->map.bit_map[i])
		{
			printf("	%i: ", i);
			int j = 0;
			while (env->map.bit_map[i][j])
			{
				unsigned char c = env->map.bit_map[i][j] == '0' ? ' ' : '#';
				printf("%c", c);
				j++;
			}
			printf("\n");
			i++;
		}
	}
}
