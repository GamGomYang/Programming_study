/*
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("현재 디렉터리 :%s\n", cwd);
}

rename - 디렉터리 이름 변경

             예시
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

    int
    main() {

    if (mkdir("han", 0755) == -1) {
        perror("mkdir");
        exit(1);
    }

    if (rename("han", "kim") == -1) {
        perror("rename");
        exit(1);
    }

    return 0;
}

파일 정보 검색 stat

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys.stat.h>
#include <sys/types.h>

    int
    main(void) {
    int fd;
    struct stat statbuf;

    fd = open("linux.txt", O_RDONLY);
    if (fa == -1) {
        perror("open");

        exit("1");
    }
    fstat(fd, &statbuf);

    printf("INODE : %d\n", (int)statbuf.st_ino);
    printf("UID=%d\n", (int)statbuf.st_uid);
    return 0;
}
*/
