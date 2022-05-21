#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./program directory_name\n");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    if ((dp = opendir(argv[1])) == NULL) {
        switch (errno) {
            case EACCES: printf("Permission denied\n"); break;
            case ENOENT: printf("Directory does not exist\n"); break;
            case ENOTDIR: printf("'%s' is not a directory\n", argv[1]); break;
        }
        exit(EXIT_FAILURE);
    }

    errno = 0;
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    if (errno != 0) {
        if (errno == EBADF)
            printf("Invalid directory stream descriptor\n");
        else
            perror("readdir");
    } else {
        printf("End-of-directory reached\n");
    }

    if (closedir(dp) == -1)
        perror("closedir");

    exit(EXIT_SUCCESS);
}

