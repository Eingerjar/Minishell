# Minishell

This project goal is implementation of shell program. This is for making better understanding about multi processing and multi thread.

## 1. Outline

- 2022-05-15 Minishell Project start
- 2022-05-17 First official team meet-up
- 2022-05-20 Minishell Master branch init and branch strategy applied.
- 2022-05-23 Second official team meet-up

## 2. Common Instructions

This project comply with common rules of 42 Seoul on C programming.

## 3. Mandatory part

This shell can work like following indications.

- Not interpret unclosed quotes or unspecified special characters like \ or;.
- Not use more than one global variable, think about it and be ready to explain why
  you do it.
- Show a prompt when waiting for a new command.
- Have a working History.
- Search and launch the right executable (based on the PATH variable or by using
  relative or absolute path)
- It must implement the builtins:
  - `echo` with option `-n`
  - `cd` with only a `relative or absolute path`
  - `pwd` with no options
  - `export` with no options
  - `unset` with no options
  - `env` with no options or arguments
  - `exit` with no options
- ’ inhibit all interpretation of a sequence of characters.
- " inhibit all interpretation of a sequence of characters except for $.
- Redirections:
  - `<` should redirect input.
  - `>` should redirect output.
  - `<<` read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
  - `>>` should redirect output with append mode.
- Pipes | The output of each command in the pipeline is connected via a pipe to the
  input of the next command.
- Environment variables ($ followed by characters) should expand to their values.
- $? should expands to the exit status of the most recently executed foreground
  pipeline.
- ctrl-C ctrl-D ctrl-\ should work like in bash.
- When interactive: - `ctrl-C` print a new prompt on a newline. - `ctrl-D` exit the shell. - `ctrl-\` do nothing.
  Anything not asked is not required.
  For every point, if you have any doubt take bash as a reference.

## 4. Bonus part

- If the Mandatory part is not perfect don’t even think about bonuses
- `&&`, `||` with parenthesis for priorities.
- the wilcard \* should work for the current working directory.
