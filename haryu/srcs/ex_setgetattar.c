#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(void)
{
	/* 터미널 옵션 제어 */
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	//c_lflag 안의 옵션들은 모두 on되어있는 상태이고 엔드연산자로 off를 시킨다.
	term.c_lflag &= ~ICANON; // 이 플래그가 on되어있으면 정규모드 off면 비정규모드이다.
	// 정규모드 : 터미널 기본입력모드로 한줄씩 받는것이다. 비정규모드 : 한글자씩 받는것이다.
	term.c_lflag &= ~ECHO; // off하면 반향되지않는다. 즉 입력받지 않음 abc입력해도 안뜸
	term.c_cc[VMIN] = 1; // 한글자를 받을때까지
	term.c_cc[VTIME] = 0; // 한무대기
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	int c = 0;

	while (read(0, &c, sizeof(c)) > 0)
	{
		printf("keycode: %d\n", c);
       		c = 0; // flush buffer
	}
}