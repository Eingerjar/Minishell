# Minishell

As beutiful as a shell

요약 : 이 프로젝트의 목적은 간단한 쉘을 만드는 것입니다. 그래요, 작은 bash나 zsh 같은거 말이에요. 당신은 여기서 파일 디스크립터와 프로세스에 대해 많이 배우게 될 겁니다.

## 1. Introduction

쉘의 존재는 IT의 존재와 매우 연결되어 있습니다. 모든 코더들은 컴퓨터와 소통하는데 사용되는 할당된 1/0의 스위치들에 대해 심각하게 화를 돋구는 놈들이라는 걸 동의합니다. 그들이 컴퓨터와 상호작용적 명령어 줄들로 소통하는 생각이 나온 것은 단적으로 논리적입니다.

Minishell 과 함께, 윈도우즈가 존재하지 않았던 때에 직면한 사람들의 문제로 여행을 가고, 되돌아 가볼 수 있을 것입니다.

## 2. Common Instructions

항상 쓰던 그것

## 3. Mandatory part

| Prorgram name | minishell |
| --- | --- |
| Turn in files |  |
| Makefile | Yes |
| Arguments |  |
| External functs. | readline, rl_on_new_line, rl_replace_line,  rl_redisplay, add_history, printf, malloc, free,  write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnem, tgetstr, tgoto, tputs |
| Libft authorized | Yes |
| Description | Write a shell |

당신의 쉘은 이를 수행해야 합니다.

- 닫히지 않은 인용구 혹은 지정되지 않은 특수 문자(예를 들면 \ or ;)은 해석되어선 안됩니다.
- 전역변수는 한개 이상 사용하지마십시오. 이에 대해 고민해보시고, 왜 그렇게 했는지를 설명할 준비하여 주십시오.
- 새로운 명령어를 위하여 기다릴 때는 프롬프트를 보여줍니다.
- 작동 히스토리를 갖고 있어야 합니다.
- 즉시 실행 가능한 것을 실행, 검색해야 합니다. (PATH 변수 기반, 혹은 상대 혹은 절대 경로를 사용함에 따라)
- 내부에 반드시 구현 해야 할 것
    - `echo` : -n 옵션과 함께
    - `cd` : 상대 혹은 절대 경로와 함께
    - `pwd` :  옵션이 없이 사용
    - `export` : 옵션 없이 사용
    - `unset` : 옵션 없이 사용
    - `env` : 옵션 없이 사용
    - `exit` : 옵션 없이 사용
- `‘` 는 일련의 문자의 해석을 방해합니다.
- `''` 는 일련의 문자열에서 $를 제외하고 해석을 방해합니다.
- 리디렉션
    - `<` : 입력으로 리다이렉트 해야 합니다.
    - `>` : 출력으로 리다이렉트 해야 합니다.
    - `<<` :  구분 기호만 포함하는 줄이 표시될 때까지 최근 소스로부터 입력을 읽습니다. 기록을 업데이트 할 필요 없습니다.
    - `>>` : append 모드로 출력을 리다이렉트 해야 합니다.
- Pipes | 파이프 라인에 각각의 커맨드의 출력물은 다음 커맨드의 입력으로 파이프를 통해 연결되어야 합니다.
- 환경변수들($ 문자열 다음으로 이어지는)은 그들의 값을 확장시켜야 합니다.
- $?는 가장 최근 실행된 전면의 파이프라인의 종료 상태로 확장되야 한다.
- `ctrl-C`, `ctrl-D`, `ctrl-\` 는 bash의 그것들 처럼 작동해야 합니다.
- 상호 작용에 할 때
    - ctrl-C 는 개행라인으로 새로운 프롬프트를 출력합니다.
    - shell 을 종료합니다.
    - 아무 작동도 하지 않습니다.

요청되지 않은 것들은 필요시 되지 않습니다.

모든 포인트들을 위해, 레퍼런스로써 bash를 참고하세요.

## 4. Bonus part

- 필수 파트를 완벽하지 않으면 보너스는 생각도 하지 마세요.
- 우선순위들을 위한 괄호와 함께 &&, ||
- 와일드카드 * 는 최근의 작업 경로를 위해 작동해야 합니다.
