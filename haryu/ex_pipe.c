#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define  BUFF_SIZE   1024

int main()
{
	int		pipes_parent[2];
	int		pipes_child[2];
	char	buff[BUFF_SIZE];
	int		counter  = 0;
	pid_t	pid;

	if ( -1 == pipe(pipes_parent))
	{
		perror("파이프 생성 실패");
		exit(1);
	}
	if ( -1 == pipe(pipes_child))
	{
		perror("파이프 생성 실패");
		exit(1);
	}
	pid   = fork();
	switch (pid)
	{
		case -1 :
		{
			printf( "자식 프로세스 생성 실패\n");
			return -1;
		}
		case 0 :
		{// 자식 프로세스입니다.
			while (1)
			{
				sprintf(buff, "자식 보냄: %d", counter++); //buff 에 넣을 메시지를 입력한다.
				write(pipes_child[1], buff, strlen(buff)); //지정한 fd에 값을 쓴다. 
				memset(buff, 0, BUFF_SIZE); // buff 라는 변수의 공간을 청소하는 역할을 함
				read(pipes_parent[0], buff, BUFF_SIZE); //부모 프로세스의 출구에서 값을 받아온다. 
				printf("자식 프로세스: %s\n", buff); // 통신된 결과를 읽어낸다. 
				sleep(1);
			}
		}
		default  : // 부모 프로세스입니다.
		{
			while( 1)
			{
				sprintf(buff, "부모 보냄: %d", counter--);
				write(pipes_parent[1], buff, strlen(buff));
				memset(buff, 0, BUFF_SIZE);
				read(pipes_child[0], buff, BUFF_SIZE);
				printf("부모 프로세스: %s\n", buff);
				sleep(1);
			}
		}
	}
}