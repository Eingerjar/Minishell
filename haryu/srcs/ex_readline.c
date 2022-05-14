/* readline함수를 사용하기위한 헤더 */
#include <readline/readline.h>

/* add_history함수를 사용하기위한 헤더 */
#include <readline/history.h>

/* printf함수를 사용하기위한 헤더 */
#include <stdio.h>

/* free함수를 사용하기위한 헤더 */
#include <stdlib.h>

/* readline함수를 활용하여 간단한 프로그램 작성하기 */
int	main(void)
{
	char	*str;

	while (1)
	{
		str = readline("prompt : ");
		if (str)
			printf("%s\n", str);
		else
			break ;
		add_history(str);
		free(str);
	}
	return (0);
}
