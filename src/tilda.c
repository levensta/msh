#include "msh.h"

void	parse_tilda(char **s)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (s && s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '~' && !is_slash(s[i], j - 1))
			{
				value = env_get_val("HOME");
				replace_by(&(s[i]), j, 1, value);
				j += ft_strlen(value);
			}
			else if (s[i][j] == '~' && is_slash(s[i], j - 1))
				s[i] = remove_from(s[i], j - 1);
			else
				j++;
		}
		i++;
	}
}