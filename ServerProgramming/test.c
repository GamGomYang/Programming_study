/*
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("현재 디렉터리 :%s\n", cwd);

    //시험 : 코드가 주어졌을때 잘못된부분찾기
// 명령어 자주 타이핑 해보기
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




read 함수
read (파일기술자fd, 데이터저장 메모리영역,버퍼크기);
read함수의 특징

int main(){

    int fd, n;
    char buf[10];

    fd = open("linux.txt",O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(1);
    }

    n = read(fd,buf,5);
    if(n == -1){
        perror("read");
        exit(1);
    }

    buf[n]='\0';
    printf("n=%d,buf=%s",n,buf);
    close(fd);
}

파일쓰기



#include<stdio.h>
#include<sys/sysinfo.h>

int main(){


    struct sysinfo info;
    sysinfo(&info);

}

getpi 함수 호출한 프로세스의 pid를 리턴
ppid 부모프로세스 pid를 리턴

#include<stdio.h>
#include<unistd.h>

int mian(){

    printf("PID, %d\n:, (int)getpid());
    printf("ppi %d\n",(int)getppid());


}

프로세스 그룹
PGID
- 프로세스 그룹 리더
- 프로세스 그룹을 구성하는 프로세스 중 하난가 그룹의 리더가 된다.
- 프로세스 그룹 리더는 변경가능

현재 프로세스의 그룹 pid = getpgrp();
특정 프로세스의 그룹 pid = getpgid(pid);
프로세스 그룹 변경 pid = setpid(pid, pgid);

프로세스 실행시간 구성 - 시스템 실행시간 + 사용자 실행시간
커널코드를 수행한시간 + 사용자 모드에서 프로세스를 실행한 시간


--9강 공부 --

// system명령어 사용법

#include <stdio.h>
#include <stdlib.h>

int main() {

    int ret;
    ret = system("ps -ef| grep sshd > sshd.txt");
    // 프로세스 모두 출력하되 sshd만 필터링(grep) 해서 sshd.txt에 저장

    printf("return value: %d\n", ret);
}



// fork함수 응용

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    switch (pid = fork()) {

    case -1:
        perror("fork");
        exit(1);
        break;
    case 0:
        printf("child porcess pid : %d  parents pid %d\n", (int)getpid(), getppid());

        break;

    default:
        printf("parent process pid:%d parents pid %d\n", (int)getpid(), (int)getppid());
        break;
    }

    // getpid() 할때 꼭 ()를 하자
    printf("end of fork\n");

    return 0;
}



// atexit() 와 exit() , on_exit()함수의 활용
// on_exit()는 인자를 전달할 수 있다.

#include <stdio.h>
#include <stdlib.h>

void cleanup1() {
    printf("cleanup 1 called\n");
}
void cleanup2(int status, void *arg) {

    printf("cleanup 2 clalled %ld \n", (long)arg);
}

int main() {

    atexit(cleanup1);
    on_exit(cleanup2, (void *)20);

    exit(0);
}

// execlp()가 실행되어지면 아예 프로세스가 달라지기 때문에 이후의 명령은 사라진다.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    printf("--> before exec function \n");

    if (execlp("ls", "ls", "-a", (char *)NULL) == -1) {
        perror("execlp");
        exit(0);
    }

    printf("--> after exec function\n"); // exec함수 실행후 명령은 실행되지 않는다. -> 프로세스가 전환되었기 때문
}


// execv 함수를 이요하여 argv명령인자로 실행해보기
// execlp는 명령 인자를 다쳤지만 execv함수는 arg로 명령인자를 보낼수 있다.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *argv[3];

    printf("before -- exec function\n");

    argv[0] = "ls";
    argv[1] = "-a";
    argv[2] = NULL; // 마지막 NULL 명령이 끝났음을 알려야한다.

    if (execv("/bin/ls", argv) == -1) {

        perror("execv");
        exit(0);
    }

    printf("after -- execv function\n");
}



// fork 함수와 execlp함수 동시에 사용해보기

#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    pid_t pid;
    switch (pid = fork()) {
    case -1:
        perror("fork");
        exit(1); // error 은 1이다 error -> exit(1); 로 처리
        break;

    case 0:
        printf("child porcess -- \n");
        if (execlp("ls", "ls", "-a", (char *)NULL) == -1) {
            perror("execlp");
            exit(1);
        }
        exit(0);
        break;

    default:
        printf("parents process -- \n");
        printf("parent porcess pid %d \n", (int)getpid());
        break;
    }

    return 0;
}

고아 프로세스와 좀비 프로세스
좀비 프로세스 자식 프로세스는 종료되었지만 자식프로세스의 종료상태를 가져가지 않아서 프로세스 테이블에 자식테이블이 존재하는경우
- wait를 통해서 자식 프로세스가 종료되도록 기다려주고 좀비프로세스 방지
고아 프로세스 부모 프로세스 보다 자식 프로세스가 먼저 종료되어서 운영체제가 자동으로 처리




// 프로세스 동기화 wait()함수사용하기

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;
    pid_t pid;

    switch (pid = fork()) {

    case -1:

        perror("fork");
        exit(1);
        break;

    case 0:
        printf(" -- child process\n");
        printf("my pid = %d parents pid = %d\n", (int)getpid(), (int)getppid());
        sleep(2);
        exit(2);
        break;

    default: // default 일때는 그냥 case default가 아니라 default로 써야한다.
        while (wait(&status) != pid) {
            continue;
        }
        printf("-- parents process\n");
        printf("my pid is %d\n", getpid());
        printf("status %d  %x\n", status, status);
        printf("real status >> 8 %d\n", status >> 8); // 자식프로세스의 전달값은 왼쪽으로 한바이트 이동해 전달한다.
        // 그러므로 오른쪽으로 8비트 이동시켜야한다.

        break;
    }
}




// waitpid()함수 사용해보기

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork error pid<0\n");
        exit(1);
    }

    if (pid == 0) {
        printf("child process\n");
        sleep(3);
        exit(3); // 종료코드 3
    }

    printf("-- parents process\n");
    while (waitpid(pid, &status, WNOHANG) == 0) {
        printf("parent still wait\n");
        sleep(1);
    }
    printf("child exit status %d\n", status >> 8);
}

--10강 공부--
파이프 -빨대 같은것
부모프로세스에서 보낸 데이터를 자식프로세스가 수행한다.
한쪽에서 데이터를 넣고 다른쪽에서 데이터를 처리하는방식



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fp;

    fp = popen("wc -l", "w");
    if (fp == NULL) {

        fprintf(stderr, "popen failed \n");
        exit(1);
        // 파일 포인터가 에러가 발생하면 에러코드는 -1이 아니라 NULL값이다.
    }

    for (int a = 0; a < 100; a++) {
        fprintf(fp, "testline\n");
    }
    // fprintf -- 파이프에 데이터를 쓰는 역할임

    pclose(fp);
}



// 10_3 pipe() 로 file descripter통신

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd[2];
    pid_t pid;
    char buf[257];
    int len, status;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }
    switch (pid = fork()) {
    case -1:
        perror("fork");
        exit(1);
        break;

    case 0:
        close(fd[1]);
        write(1, "childe process: ", 15);
        len = read(fd[0], buf, 256);
        write(1, buf, len);
        close(fd[0]);
        break;

    default:
        close(fd[0]);
        write(fd[1], "test massege\n", 14);
        close(fd[1]);
        waitpid(pid, &status, 0);
        break;
    }
}



// pipe() 함수로 명령 실행하기

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd[2];

    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");

        exit(1);
    }
    switch (pid = fork()) {
    case -1:
        perror("fork");
        exit(1);
        break;

    case 0:

        close(fd[1]);

        if (fd[0] != 0) {
            dup2(fd[0], 0);
            close(fd[0]);
        }

        execlp("grep", "grep", "ssh", (char *)NULL);
        exit(1);
        break;

    default:
        // parent

        close(fd[0]);
        if (fd[1] != 1) {
            dup2(fd[1], 1);
            close(fd[1]);
        }

        execlp("ps", "ps", "-ef", (char *)NULL);
        wait(NULL);
        break;
    }
}



// pipe를 이용하여서 양방향 통신하기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd1[2];
    int fd2[2];
    pid_t pid;

    char buf[257];
    int len, status;
    if (pipe(fd1) == -1) {
        perror("fd1");

        exit(1);
    }
    if (pipe(fd2) == -1) {
        perror("fd2");
        exit(1);
    }

    switch (pid = fork()) {

    case -1:
        perror("fork");
        exit(1);
        break;

    case 0:
        close(fd1[1]);
        close(fd2[0]); // 항상 안쓰는 fd는 닫아야 한다.

        len = read(fd1[0], buf, 256);
        write(1, "child process:", 15);
        write(1, buf, len);
        strcpy(buf, "good\n");
        write(fd2[1], buf, strlen(buf));
        break;

    default:
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1], "hello\n", 6);
        len = read(fd2[0], buf, 256);
        write(1, "parent process", 15);
        // 여기에서 1은 표준출력 1을 뜻한다
        write(1, buf, len);
        waitpid(pid, &status, 0);
        break;
    }
}



// fifio파일을 만드려면 - mkfifo, mknod()함수를 사용하면 된다.

// fifo파일 생성하기

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

       if (mknod("HAN-FIFO", S_IFIFO | 0644, 0) == -1) {
            perror("mknod");
            exit(1);
        }

    if (mkfifo("BIT-FIFO", 0644) == -1) {
        perror("mkfifo");
        exit(1);
    }
}

//thread -> pthread
thread 생성 -> pthread_create()
thread끝날때 까지 기다려주고 반환값 받기 -> pthread_join()
thread 안기다리고 자동으로 리소스 해제 -> pthread_detach()




#include <pthread.h>
#include <stdio.h>

void *threadfunc(void *vargp);

void *threadfunc(void *vargp) {

    sleep(1);
    printf("hello world\n");
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, threadfunc, NULL);
    printf("main function\n");
    pthread_join(thread, NULL);

    printf("main2\n");
    sleep(2);
    return 0;
}



// 쓰레드 자원경쟁
// pthread_mutex의 중요성

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREAD 20

void *t_func(void *data);

void *t_func(void *data) {
    int *count = (int *)data;
    pthread_t thread_id = pthread_self();

    for (int i = 0; i < 10000; i++) {

        *count = *count + 1;
    }
}
int main(int argc, char **argv) {
    pthread_t thread_id[MAX_THREAD];

    int i = 0;
    int count = 0;
    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_create(&thread_id[i], NULL, t_func, (void *)&count);
    }

    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_join(thread_id[i], NULL);
    }

    printf("main thread %d\n", count);
    return 0;
}



// mutex 활용 예제 -> <<다시 한번 타이핑 해보기>>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TRHEAD 20

pthread_mutex_t m_lock;

void *t_func(void *data) {
    int *count = (int *)data;
    pthread_t thread_id = pthread_self(); // qusetion point -> 이걸 왜하는건지? pthread_self()는 무엇인지?
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&m_lock);
        *count = *count + 1;
        pthread_mutex_unlock(&m_lock);
    }
}

int main(int argc, char **argv)
// question point -> 왜 argv에 **가 붙는지? -> 원래argv[]는 배열이지만 여기에서 그냥 변수로 받음
{

    pthread_t thread_id[MAX_TRHEAD];
    int i = 0;
    int count = 0;

    if (pthread_mutex_init(&m_lock, NULL) != 0) {
        perror("mutex");
        exit(1);
    }

    for (int i = 0; i < MAX_TRHEAD; i++) {
        pthread_create(&thread_id[i], NULL, t_func, (void *)&count);
    }

    for (int i = 0; i < MAX_TRHEAD; i++) {
        pthread_join(thread_id[i], NULL);
    }

    pthread_mutex_destroy(&m_lock);
    printf("mutex를 이용한 thread연산 : %d\n", count);
}




// 쓰레드 동기화 cond

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void *f(void *data) {
    printf("before wait\n");
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("after wait\n");

    pthread_mutex_unlock(&mutex);

    return 0;
}

int main(int argc, char **argv) {

    int res = 0;

    pthread_t thread;

    res = pthread_mutex_init(&mutex, NULL);
    res = pthread_cond_init(&cond, NULL);

    pthread_create(&thread, NULL, f, NULL);

    sleep(2);
    pthread_cond_signal(&cond);
    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

tcp와udp의 차이점



// 호스트명 읽어오기

#include <netdb.h>
#include <stdio.h>

int main() {
    struct hostent *hent;

    sethostent(0);

    while ((hent = gethostent()) != NULL) {
        printf("Name = %s\n", hent->h_name);
    }

    endhostent();
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    char *cwd;
    char wd1[BUFSIZ]; // stdio에 있는 BUFSIZE
    char wd2[10];

    getcwd(wd1, BUFSIZ); // getcwd -> 현재 디렉터리의 위치 출력
    printf("wd = %s\n", wd1);

    cwd = getcwd(NULL, BUFSIZ); // cwd null 이라면 자동적으로 할당해준다(malloc)

    printf("cwd1 = %s\n", cwd);

    free(cwd); // malloc을 했지 떄문에 cwd를 free해야한다.

    cwd = getcwd(NULL, 0);
    printf("cwd2 %s\n", cwd);
    free(ced);
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE

int main() {

    char *cwd;
    cwd = get_current_dir_name(); // getcwd, get_current_dir_name() : 주소출력
    printf("%s\n", cwd);
    free(cwd);
}


// rename을 이용한 디렉터리 이름 바꾸기

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {

    if (mkdir("han", 0755) == -1) {
        perror("han");
        exit(1);
    }

    if (rename("han", "bit") == -1) {
        perror("rename");
        exit(1);
    }
}



// chdir로 디렉터리 이동하기

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *cwd;

    cwd = getcwd(NULL, BUFSIZ);
    printf("cwd1 = %s\n", cwd);

    chdir(cwd, "bit"); // chdir 디렉터리 이동
    cwd = getcwd(NULL, BUFSIZ);

    printf("cwd2 = %s\n", cwd);

    free(cwd);
}


// file descripter를 이용한 fchdir을 이용하여 디렉터리 이동예제

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

    char *cwd;
    int fd;

    cwd = getcwd(NULL, BUFSIZ);
    printf("current directery %s\n", cwd);

    fd = open("bit", O_RDONLY);

    chdir(fd);

    cwd = getcwd(NULL, BUFSIZ);
    printf("current2 directery %s \n", cwd);

    free(cwd);
    close(fd);
}

// 디렉터리 내용읽기 - opendir, closedir, readdir

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    DIR *dp;
    struct dirent *dent;
    while ((dent = readdir(dp))) {
        printf("name %s", dent->d_name);
        printf("inode %d\n", (int)dent->d_ino);
    }

    closedir(dp);
}

파일 정보 검색 stat
stat를 이용하여 파일의 정보를 검색한다.





// 간단하게 stat를 이용하여 파일의 정보를 읽어보기

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

    struct stat stat_t;
    stat("linux.txt", &stat_t);

    // stat를 이용하여 linux의 파일정보 읽어보기 stat("linux.txt",&stat_t);

    printf("inode = %d", (int)stat_t.st_ino);

    return 0;
}




// 1. 파일의 경로로 파일정보 출력 stat
// 2. 파일디스크립터로 파일정보 출력 fstat

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int fd;

    struct stat stat_t;

    fd = open("linux.txt", o_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fstat(fd, &stat_t);

    printf("ino = %d\n", (int)stat_t.st_ino);

    return 0;
}



// access를 이용한 점근권한 이용하기

#include <stdio.h>
#include <sys/errno.h>
#include <unistd.h>

extern int errno;

int main() {

    int perm;

    if (access("linux.txt", F_OK) == -1 && errno == ENOENT) {
        printf("linux.bak :file not exist\n");
    }

    perm = access("linux.txt", R_OK);

    if (perm == 0) {

        printf("read ok\n");

    } else if (perm == -1 && errno == EACCES) {
        printf("read not ok\n");
    }
}




// fd 에서 excl플래그 -> 있으면 파일 있다고 보내는것

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    int fd;
    fd = open("linux.txt", O_CREAT | O_EXCL, 0644);

    if (fd == -1) {
        perror("create");
        exit(1);
    }

    close(fd) // ** fd파일 디스크립터를 열었으면 꼭꼭!! 닫기 close(fd)
}


// 파일 읽기 파일을 읽을때는 일단 열고 읽는다 read

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int fd;
    char buf[10];

    fd = open("linux.txt", O_RDONLY);

    if (fd == -1) {
        perror("create");

        exit(1);
    }

    int n;
    n = read(fd, buf, 5); // read함수는 read(fd,버퍼,크기)이렇게 지정한다. read(fd, buf, 5);

    if (n == -1) {
        perror("read");
        exit(1);
    }

    buf[n] = '\0'; // read에서는 \0이 아니기 때문에 무적권 백슬래시 영을 해야한다.

    printf("n = %d buf = %s", n, buf);

    close(fd);
}


// 파일 쓰기 write()

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int rfd, wfd, n;
    int buf[10];

    rfd = open("linux.txt", O_RDONLY);

    wfd = open("linux.bak", O_WRONLY | O_CREAT | O_TRUNC);

    if (rfd == -1) {
        perror("open");
        exit(1);
    }

    if (wfd == -1) {
        perror("write");
        exit(1);
    }

    while ((n = read(rfd, buf, 6)) > 0) { // 0보다 클때 성공적으로 읽고 있음
        if (write(wfd, buf, n) != n) {
            perror("write")
        }
    }

    if (n == -1) {
        perror("read");
    }

    close(wfd);
    close(rfd);
}


파일 오프셋은 lseek로 지정한다.
set 시작점
cur 현재
end 끝점

// 파일 오프셋 지성 -- lssek

int main(){
    int fd , n;

    off_t start, cur;

    char buf[256];

    fd = open("linux.txt",O_RDONLY);

    if(fd == -1){

        perror("fd");
        exit(1);
    }

    start = lseek(fd,0,SEEK_CUR);
    n = read(fd,buf,255);
    printf("offset = %d n = %d read = %s,(int)start,n,buf");

    cur = lseek(fd, 0 , seek_cur);

    start = lseek(fd,6,SEEK_SET);


}

//exec함수군 사용

if(execlp("ls","ls","-a",(char*)NULL)== -1){
    perror("execlp");
    exit(1);
}

char * argv[3];
argv[0] = "ls";
argv[1] ="-a";
argv[2] = NULL;
if(execv("/bin/ls"),argv);

좀비 프로세스 방지법 wait사용하지

int main(){

    int status;
    pid_t pid;

    switch(pid = fork()){
        case -1:
        perror("fork");
        exit(1);
        case 0 :
        sleep(2);
        exit(2);
        default:
        while(wait(&status)!=pid){
            continue;
        }

    }
}

파일은 크게 일반파일 특수파일 디렉터리로 구성되어져 있다
디렉터리도 파일로 생각을 한다.


일반 파일 텍스트 파일 실행파일 라이브러리 이미지 등 리눅스에서 사용하는 대부분의 파일
데이터 블록에 텍스트나 바이너리 형태로 데이터 저장
데이터 블록->텍스트 바이너리 형태저장
텍스트 편집기 eg vi 컴파일러나 다른 응용프로그램을 이용해 생성가능
라이브러리 실행파일 이미지 txt 일반파일이다.

특수파일
통신을 하거나 터미널 또는 디스크 장치를 사용하기 위한파일
장치관련 특수파일을 장치 파일
즉 특수파일 터미널 디스크장치를 사용하는 파일 특수파일중 하나 장치파일
장치 파일은 데이터 블록을 사용하지 않는다.
장치의 종류를 나타내는 장치 번호를 inode에 저장
즉 장치파일은 일반 파일과 다르게 블록을 사용하지 않음

블록장치파일은 블록단위로 데이터를 읽고 쓴다
문자 장치파일 하드디스크인 경우 섹터단위로 읽고 쓴다
즉 장치파일 블록단위 문자단위 블록 블록 문자 섹터단위로 읽고 쓴다.

디렉터리 디렉터리도 파일로 취급
디렉터리와 연관된 블록은 해당 디렉터리에 속한 파일의 목록과 inode저장

inode
사용자가 파일에 접근할때 파일명과 inode가 반드시 있어야한다.
파일명 지정 주의 사항
파일명과 디렉터리명에 사용하는 알파벳은 대소문자 구분
파일명과 디렉터리명이 . 라면 숨김파일로 간주


fchdir 을 이용한 파일 이동

int main(){
    char *cwd;
    int fd;

    cwd = getcwd(NULL,BUFSIZ);
    printf("%s\n",cwd);

    fd = open("bit",O_RDONLY);

    fchdir(fd);

    cwd = getcwd(NULL,BUFSIZ);
    printf("%s\n",cwd);

    free(cwd);
    close(fd); // filedescripter는 무적권 닫아야한다.

}


int fd , n;
char buf[10];

fd = open("linux.txt",O_RDONLY);

if(fd == -1){
    perror("open");
}

n = read(fd,buf,5);
if(n == -1){
    perror("read");


}

buf[n] = '\0' // read후 항상 마지막에 \0이 없기 때문에 read시 붙여주기

int fd , wfd, n;
char buf[10];

fd = open("linux.txt",O_RDONLY);
if(fd == -1){

    perror("open");

}

n = read(fd,buf,10);
if(n == -1){
    perror("read");


}

while((n = read(fd,buf,6))>0){
    if(wfd = write(fd,buf,n)!=n){
        perror("write");
    }
}



close(fd);
close(wfd);


lseek fd의 오프셋 설정
set cur end

offset lseek 사용
stat 는 &사용
chmod -> 권한 부여
chdir -> 디렉터리이동
fchdir -> fd를 이용하여 디렉터리 이동
int fd , n;
off_t start, cur;
char buf[256];
fd = open("linux.txt",O_RDONLY);
if(fd == -1){
    perror("open");
}
start = lseek(fd,0,SEEK_CUR);
n = read(fd,buf,255);
cur = lssek(fd,n,SEEK_CUR);
start = lseek(fd,6,SEEK_SET);

int fd , n;
off_t start,cur;
char buf[256];

fd=open("linux.txt",O_RDONLY);
if(fd == -1){
    perror("open linux.txt");
    exit(1);
}
start = lseek(fd,0,SEEK_CUR);
n = read(fd,buf,255);
buf[n]='\0'; // read 에서 \0은 항상 기억하자
cur = lseek(fd,0,SEEKCUR);

파일 기술자 복사 dup();
fd를 복사하는것 dup
dup2(old,new);

int main(){
    int fd,fd1;
    fd = open("linux.aaa",O_CREAT | O_WRONLY | O_TRUNC,0644);
    if(fd == -1){
        perror("open");
    }

close(1);

fd1 = dup(fd);
printf("DUP FD =%d",fd1);

close(fd);
}


dup2 사용
결국 dup은 filedeiscriptor 즉 fd를 복사하는 함수 dup -> fd복사

int fd;
fd = opne("linux.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);

if(fd == -1){
    perror("fd");
}

dup2(fd,1);
printf("dup2 %s");

close(fd);


fcntl 파일 기술자 제어
파일 기술자가 가리키는 파일에 명령 수행
fcntl
dup 파일기술자 복사


int main(){
    int fd, flags;

    fd = open("linux.txt", O_RDWR);
    if(fd == -1){
        perror("open");    }

    if((flags = fcntl(fd,F_GETFL))==-1){
        perror("fcntl");
    }
    flags |=O_APPEND;

    if(fcntl(fd,F_SETFL)==-1){
        perror("fcntl")// fcntl fd 파일 기술자 명령어 시행
    }

    if(write(fd,"habit academy\n",15)!=15){
        perror("write");
    }

    close(fd);// 파일 기술자 fd 닫기

//저수준 파일기술자 fd에는 read와 write가 있었다면
//고수준 파일 포인터에 FP에는 get()put()이있다.

//fget , fput을 fp로 사용

FILE *fp,*wfp;
int c;

if((rfp = fopen("linux.txt","r"))==NULL){
    perror("fopen");//fopen에는 -1이 아닌 NULL이다.

}

while((c = fgetc(rfp))!=EOF){
    fput(c,wfp);
}

fclose(fp);
fclose(rfp);

if((rfp = fopen("linux.txt",'r))==NULL){
    perror("fopne");
}

if((wfp = fopen("linux.out","w")==NULL)){
    perror("fopen");
}

while((c=fget(rfp))!=EOF){
    fput(c,wft)
}

fclose(wfp);
fclose(rfp);

fget fput - > 문자기반 입출력
fread fwrite -> 버퍼기반 입출력
    }


int main(){
    FILE *rfp;
    char buf[BUFSIZ];

    int n;

    if((rfp =fopen("linux.txt","r"))==NULL){
        perror("fopen");


    }

    while((n = fread(buf,sizeof(char)*2,4,rfp))>0){
        buf[8] = '\0' // 여기에서 fread도 \0조건을 항상 만족해야한다.

            }

            fclose(rfp); // close 파일포인터
}

FILE *rfp , *wfp;
char buf[BUFSIZ];
int n;

if((rfp = fopen("linux.txt","r"))==NULL){
    perror("open");
}

if((wfp = fopen("linux.out","w"))==NULL){
    perror("open");


}

while((n = fread(buf,sizeof(char)*2,4,rfp)>0){
    fwrite(buf,sizeof(char)*2,n,wfp);
}

fclose(wfp);
fclose(rfp);

}

형식 기반 입출력 - fscanf scanf printf fprintf

fscanf를 이용한 파일내용 읽기

int main(){

    FILE *rfp;
    int id, s1,s2,s3,s4,n;

if((rfp = fopen("linux.txt","r"))==NULL){
    perror("fopen");
    exit(1);
}


printf("학번 평균\n");
while((n = fscanf(rfp,%d %d %d %d %d),&id,&s1,&s2,&s3,&s4))!=EOF){
    printf("%d: %d\n",id,(s1+s2+s3+s4)/4);
}


fclose(rfp);


}

출력

int main(){
    FILE *rfp,*wfp;
    int id ,s1,s2,s3,s4;

    if((rfp = fopen("linux.txt","r"))==NULL){
        perror("fopen");
        exit(1);
    }

    if((wfp = fopen("linux.scr","w"))==NULL){
        perror("fopen");
    }

    fprintf(wfp,"학번평균");
   while( (n=fscanf(rfp,"%d%d%d%d%d%d"),&id,&s1,&s2,&s3,&s4))!=EOF){
    fprintf(wfp,"%d : %d");

    //일반적일 파일 입출력 형식 기반 입출력의 형식

    fprintf(filepointer,"Text");

    fclose(wfp);
    fclose(rfp);


   }


}


파일포인터의 오프셋 읽기
fseek ftell rewind

FILE *fp;
int n;
long cur;
char buf[BUFSIZ];

if((fp = fopen("linux.txt","r"))==NULL){
    perror("open");
    exit(1);
}

cur = ftell(fp);
printf("current offset %d\n",(int)cur);

n = fread(buf,sizeof(char),5,fp);
buf[n]='\0';

printf("read str%s\n",buf);

fseek(fp,SEEK_CUR);

cur=ftell(fp);
printf("offset")




// pipe를 이용한 함수 통신

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

    int fd[2];
    pid_t pid;
    char buf[257];
    int len, status;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    switch (pid = fork()) {
    case -1:
        perror("fork()");
        exit(0);
        break;

    case 0:
        close(fd[1]);
        write(1, "child process", 15);
        len = read(fd[0], buf, 256);

        close(fd[0]);
        break;

    default:
        close(fd[0]);
        write(fd[1], "test message", 14);
        close(fd[1]);
        waitpid(pid, &status, 0);
        break;
    }
}



// 11_2 getservent() 함수로 포트정보 읽어오기

#include <netdb.h>
#include <stdio.h>

int main() {

    struct servent *port;

    int n;

    setservent(0);

    for (n = 0; n < 5; n++) {
        port = ("name %s port %d\n", port->s_name, port->s_port);
    }

    endservent();
}



#include <netdb.h>
#include <stdio.h>

int main() {
    struct hostent *hent;

    sethostent(0); //

    while ((hent = gethostent()) != NULL) {
        printf("%s", hent->h_name);
    }

    endhostent();
}



// 11_2 getservent() 함수로 포트 정보 읽어오기

#include <netdb.h>
#include <stdio.h>

int main() {

    struct servent *port;

    setservent(0);

    for (int i = 0; i < 5; i++) {

        port = getservent();
        printf("name %s port %d", port->s_name, port->s_port);
    }

    endservent();
}

소켓 프로그래밍
소켓의 종류 1. af_unix 유닉스 도메인 소켓(시스템 네부) 2.af_inet 인터넷 소켓(네트워크를 이용한 통신)

sock_stream sock_dgram
소켓의 통신방식

HBO NBO 호스트 네트워크 순서 네트워크 바이트 순서

ip주소 변환
문자열일 ip주소를 숫자로 변환한다.
inet_addr;
inet_ntoa 구조체 ip주소를 문자열로 변환

11_3 ip주소 변환하기



#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main() {

    in_addr_t addr; // ip주소를 저장 - 정수로
    struct hostent *hp;
    struct in_addr in; // ip주소를 변환 정수 문자열

    if ((addr = inet_addr("8.8.8.8")) == (int_addr_t)-1) {
        perror("inet_addr 8 8 8 8");
    }

    hp = gethostbyaddr((char *)&addr, 4, AF_INET) // 4바이트ip4를 쓰는 ip주소로 호스트의 이름정보 검색

        if (hp == NULL) {
        printf("host information");
    }

    printf("name %s", hp->h_name);
    memcpy(&in.s_addr, *hp->addr_list, sizeof(in.s_addr));

    printf("ip = %s", inet_ntoa(in));
}



// 11_4 유닉스 도메인 소켓 구현해보기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

// 소켓 네임 정의

#define SOCKET_NAME "hbsocket"

int main() {

    char buf[256];
    struct sockaddr_un ser, cli // unix소켓을 사용 도메인 주소 구조체
        int sd,
        nsd, len, den;

    if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // 주소 초기화 및 바인딩 bind
    memset((char *)&ser, 0, sizeof(struct sockaddr_un));
    ser.sun_family = AF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);
    len = sizeof(ser.sun_family) + strlen(ser.sun_path);

    // 연결대기 listen

    if (listen(sd, 5) < 0) {
        perror("listen");
    }

    printf("wating...\n");

    if ((nsd = accept(sd, (struct sockaddr *)&cli, &len)) == -1) {
        perror("accept");
        exit(1);
    }

    if (recv(nsd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
    }

    printf("reseive massege %s\n", buf);

    close(nsd);
    close(sd);
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

// 소켓 네임 정의

#define SOCKET_NAME "hbsocket"

int main() {
    char buf[256];
    struct sockaddr_un ser, cli;

    int sd, nsd, len, den;

    if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&ser, 0, sizeof(struct sockaddr_un));
    ser.sun_family = AF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);

    if (bind(sd, (struct sockaddr *)&ser, len)) {
        perror("bind");
        exit(1);
    }

    if (listen(sd, 5) < 0) {
        perror("listen");
    }

    printf("wating..");

    if ((nsd == accept(sd, (struct sockaddr *)&cli, &den)) == -1) {
        perror("acce[t]");
    }

    if (recv(nsd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
    }

    printf("message %s\n", buf);
    close(nsd);
    close(sd);
}

int main(){
    int pd,n;
    char msg[] = "hello fifo";

    printf("server =======\n");

    if(mkfifo("./HAN-FIFO",0644)==-1){
        perror("mkfifo");
        exit(1);
    }

    if((pd = open("HAN-FIFO",O_WRONLY))==-1){
        perror("open");
        exit(1);
    }

    printf("to client :");

    n = write(pd,msg,strlen(msg)+1);
    if(n==-1){
        perror("write");
        exit(1);
    }

    close(pd);
}

//client에서 읽어야함

int main(){

    int pd,n;
    char inmsg[80];

    if((pd = open("HAN-FIFO",O_RDONLY))==-1){
        perror("open");
        exit(1);
    }

    printf("client=======");
    write(1,"from server",13);


    while((n = read(pd,inmsg,80))>0){
        write(1,msg,n);
    }

    if(n == -1){
        perror("read");
    }

    wirte("1,"\n",1);
    close(pd);
}

pipe를 이용한 양방향 통신

int main(){
    int fd1[2],fd2[2];
    pid_t pid;
    char buf[257];
    int len ,status;

    if(pipe(fd1)==-1){
        perror("pipe");
    }

    if(pipe(fd2)==-1){
        perror("pipe");
    }

    switch(pid = fork()){

        case -1:
        perror("fork");
        exit(1);

        case 0:
        close(pd1[1]);
        close(pd[2]);

        len = read(fd1[0],buf,256);
        write(1,"child process",15);
        write(1,buf,len);

        strcpy(buf,"good\n");

        write(fd2[1],buf,strlen(buf));

        break;

        case 1:
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1],"hello\n",6);
        len = read(fd2[0],buf,256);
        write(1,"parent process",15);
        write(1,buf,len);
        waitpid(pid, &status,0);//fork pid 대기시켜줘야함 waitpid
        }
}
    }
}

시스템 호출
시스템이 제공하는 서비스를 프로그램에서 이용할 수 있도록 지원하는 인터페이스

간단한 프로그램을 제외하고 대부분 시스템 호출

유닉스 오픈소스이다.

표준 ansic표준
c언어의 명세 문법 등 정의

posix유닉스에 기반으로두고 있는 표준 운영체제 인터페이스

xopen개방 시스템에 관한 표준정의와 보급을 목적
이식성을 높이는것이 목표

단일 유닉스 명세sus

유닉스 이름을 사용하기 위해 지켜야하는 표준

시스템 호출

리턴값 = 시스템 호출명
시스템 호출명은 함수명처럼 사용할 이름정의
시스템 호출명은 함수명처럼 사용할 이름 정의

라이브러리 함수
시스템 호출 라이브러리 함수
라이브러리 함수
라이브러리 미리 컴파일된 함수를 묶어서 제공하는 특수한 형태의 파일
정적 라이브러리는 컴파일시 같이 적재되어 실행파일 구성
공유라이브러리는 실행파일에 포함되어지지않는다
정적은 실행파일에 포함 공유라이브러리는 실행파일에 포함되어지지 않음
man페이지 명령이나 함수 등 시스템의 다양한 서비스에 대한 메뉴얼
메뉴얼은 항목의 종류에 따라 섹션이 구분되어 있음
일반적인 명령에 대한 설명 1
2 시스템 호출 3 라이브러리 함수

man명령으로 검색시 색션번호가 낮은것 부터 출력
man명령의 결과를 출력하는 형식은 리눅스와 유닉스에서 차이가 있다.
man명령의 결과를 출력하는 형식은 리눅스 와 유닉스의 차이가 있음

man페이지 섹션번호
리눅스와 유닉스에서 open함수 검색시 opne(2)로 나오는데 명령과 함수의 이름이 같은경우
명령과 함수명이 같다면? 섹션1에대한 설명만 볼 수 있다.

man -s 2 uname 을 사용하면 섹션 2에 대한 man을 볼 수 있음
즉 uname을 사용해야함
12중 1만나왔어 2를 보고싶어
man -s 2 uname
이렇게 해야함

access()함수의 리턴값검사 -1은 오류
access()함수에서 발생하는 오류코드로는 EACCES, ELOOP ,ENODIR이 있다.
errno어느 값이 어느 섹션인지 알려줌

컴파일이란 프로그램 시스템이 이해할 수 있는 기계어로 변환하는과정
프로그램 시스템이 이해할 수 있는 기계어로 변환하는 과정

컴파일 과정 + 라이브러리 링크과정

makefile 과 make
makefile 컴파일 명령 소스파일을 컴파일 하는 방법
링크할 파일 실행 파일명을 설정하는 파일

make make를 읽고 이 파일에서 지정한대로 컴파일을 실행해 실행파일을 생성

malloc 할당받을 메모리 크기 지정한 메모리를 할당하는데 성공하면
메모리의 시작주소 리턴
실패시 NULL포인터 리턴
메모리 크기는 바이트 단위
어떤 형태의 데이터도 저장할수 있따.
할당된 메모리를 초기화하지 않는다.

malloc calloc realloc free
동적 할당 메모리 동적할당 메모리 배열 할당 메모리 추가 해제


getopt함수로 옵션 처리하기

int main(int argc, char *argv[]){
    int n;
    extern char *optarg;
    extern int optind;

    while((n = getopt(argvc,argv, "abc"))==-1){
        switch (n){
            case 'a;
            printf("option a");
            break;
        }
    }
}


디렉터리 일반 특수
파일 구성 파일명 파일에 접속할 때 사용
inode 소유자나 크기등 정부와 실제 데이터를 저장하고 있는 데이터 블록을 나타내는 주소를 정장

디렉터리 리눅스에서 파일로 취급
데이터 블록과 해당 디레토리에 속한파일 inode저장


장치 파일은 데이터 블록을 사용하지 않고 장치에 관한 정보를 inode에 저장한다.

혖재 작업 디렉터리 검색
cwd = getswd(sys,BUFSIZ);

cwd = getcwd(NULL,BUFSIZ);


getcwd, get_cur_dir_name -> 이것들은 free(cwd가 필요하다)

int main(){
    char *cwd;
    cwd = get_current_dir_name();
    printf("gwd = %s\n");
    free(cwd);
}

rename; 이름변경
if(rename("han","bit")==-1)
{perror("han");}

fchdir -> 디렉터리 이동하기

int fd;
fd= open("bit", O_RDONLY);

fchdir(fd);

fchdir(fd)로 사용한다.
chdir(path)라고 한다.

디렉터리 오픈 읽기 닫기
opendir closedir readdir

int main(){
    DIR *dp;
    struct dirent *dent;-> open dir 일때 1 *dp dir 선언 2. 구조체 dirnet *dent선언
    dp = opendir(".");
    while((dent = readdir(dp))){

        printf("name %s", dent -> d_name);

    }
}

파일 정보 검색 stat구조체 stat함수로 검색한 inode 정보는 stat구조체에 저장되어서 리턴

stat fstat(fd, &buf);
struct stat buf 구조체 선언 중요
opendir때도 struct dirent *dent DIR *dp이렇게 선언이 중요하듯이 STAT구조체 즉 파일정보 검색
구조체도 dirent구조체가 중요하다.

stat의 구조체 에서 timespec이라는것도 있는데 초와 나노초를 저장하는 구조체이다.

tv_sec tv_nsec나노초
st_mode의 구조

struct stat buf;

stat("linux",&buf);

printf("inod %s\n", buf->(int)buf.st_ino);

stat -> st_ino 이렇게 한다.

mode_t 는 unsigned int로 정의 되어진다.
실제로는 16비트 사용
비트 구조로 저장된 값과 상수간의 and연산 값 사용


fstat예제
int main(){
    int fd;
    struct dirent buf;

  if(open("linux.txt",O_RDONLY)==-1){
    perror("open");
  }

  fstat(fd,&buf);

  printf("inode %d\n",buf.st_ino);

}

16비트 unsigned는 st_mode의 mode_t이다.

and연산으로 파일 접근제한 추출

S_IFMT를 사용한다.

파일의 종류는 처음 4비트이니까 s_ifmt를 쓰면 된다.

mode_t를 이용하여 파일 종류 검색하기
파일 종류 검색이랑 파일 권한 검사하기가 있음

int main(){
    struct stat buf;
    int kind;

    printf("mode = %s\n",(unsigned int)stat.st_mode);

    kint =stat.st_mode & S_IFMT(and연산으로 파일 종류 검사)
    kind = stat.st_mode & S_IFMT;


    stat("linux.txt", &statbuf);

    if((statbuf.st_mode&(S_IREAD))!=0);
    if((statbuf.st_mode&(S_IREAD>>3))!=0){
        group permission;
    }
    }

    access 파일의 경로 접근 권한

    access("linux.bak",F_OK)==-1 && errno == ENOENT)
    printf("linux.bak : file exit");

    chmod("linux.txt",S_IRWXU|S_IRGRP);

    buf.st_mode  |= s_iwgrp;
    buf.st_mod &= ~(s_iroth);

    chmod(buf.st_mod);

    pipe 이름없는 파이프

    popen() 함수

int main(){

    FILE *FP;
    char buf[256];

    fp = popen("linux.txt","r");

    if(fp == NULL){
        fprintf(stderr,"popen error");
    }

    if(fgets(buf,sizeof(buf),fp)==NULL ){
        fprintf(stderr , "error");
    }

printf("line %s\n",buf);

pclose(fp);


}


FIFO 특수파일 mknod mkfifo
mknod fifo파일 뿐만 아니라 특수 파일도 생성할수 있다.

-m 옵션은 새로 생성되는 fifo파일의접근권한



mkfifo -m 0644 BIT_FIFO

FIFO예제

int main(){

    if(mknod("HAN-FIFO",S_FIFO|0644,0)==-1){
        perror("mknod");
    }

    if(mkfifo("BIT_FIFO",0644)==-1){
        perror("mkfifo");
    }
}


fifo를 이용한 서버 클라이언트
fifo는 말 그대로 이름없는 파이프를 파일형식이다.
popen fp를 사용한거

int mian(){
    int fd , n;

    char mst[]="hello fifo";

    if(mkfifo("HAN-FIFO",0644)==-1){
        perror("fifo");
    }

   if(pd = open("./HAN-FIFO",O_WRONLY));
   피포파일을 파일 디스크립터로 연다.
   pd = open("./HAN-FIFO",O_WRONLY);

   printf("to client %s",msg);

   n = write(pd,msg,strlen(msg)+1);

close(pd);
}

int main(){

    int pd, n;
    char inmsg[80];

    if((pd = open("HAN-FIFO",O_RDONLY)));

    while((n == read(pd, inmsg, 80))>0){
        write(pd, inmsg,n);

    }
}


쓰레드의 장점

빠른 실행이 가능하고 데이터 공유 그리고 cpu를 효육적으로 사용가능
빠른 실행 데이터가 공유되어지고 cpu가 효율적으로 사용가능

장점 대용량 데이터 처리에 유용
cpu자원을 효율적으로 사용
데이터 교환이 쉬움

프로그래밍 난이도 상승
디버깅 힘듬
구현힘듬
대용량 데이터 다루기 좋다
빠른 실행이 가능하고 데이터 공유 가능

pthread를 이용한 hello world출력

int main(){
    pthread_t thread;
    pthread_create(&thread, NULL, threadfunc,NULL);
    printf("main");
    pthread_create(&thread,NULL,thread_func,NULL);

    pthread_join(thread,NULL);

}


int main(){
    pthread_t tid[MAX_THREAD];
    int i=0;
    int count =0;

for(int i=0; i<MAX_THREAD,i++){
    pthread_create(&tid[i], NULL,t_func,(void*)&count);
    }

for(int i=0l i<MAX_THREAD;i++){
    pthread_join(tid[i],NULL);
}
}


void *t_func(void data){
    int *coutn = (int)
}
}



// 쓰레드 예제 실제 적용해보기
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREAD 20

pthread_mutex_t mutex;

void *t_func(void *data) {
    int *count = (int *)data;
    int i;
    pthread_t thread_id = pthread_self();

    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex);
        *count = *count + 1;

        pthread_mutex_unlock(&mutex);
    }

    int main() {

        pthread_t tid[MAX_THREAD];
        int i = 0;
        int count = 0;

        if ((pthread_mutex_init(&mutex, NULL)) != 0) {
            perror("MUTEX");
        }

        for (int i = 0; i < MAX_THREAD; i++) {
            pthread_create(&pid, NULL, func_t, (voic *)&count);
        }

        for (int i = 0; i < MAX_THREAD; i++) {
            pthread_join(&pid, NULL, func_t, (voic *)&count);
        }
        pthread_mutex_destroy(&mutex)
    }
}




// 쓰레드 동기화 예제
// pthread_cond_wait / pthread_cond_signal

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void *f(void *data) {
    printf("before wait\n");

    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond);

    printf("after wait\n");

    pthread_mutex_unlock(&mutex);

    return 0;
}

int main(int argc char *argv[]) {
    int res = 0;
    res = pthread_mutex_init(&mutex);
    res = pthred_cond_init(&cond);

    ptherad_t therad;
    pthread_create(&thread, NULL, f, NULL);

    sleep(2);
    pthread_cond_siganl(&cond);
    pthread_join(&thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    retrun 0;
}


문제 1번

1. x
2. o
3. o
4. o
5. o

2번
fd
쓰기 파일디스크립터닫기
읽기 파일디스크립터 닫기

문제 3.
mkfifo("HAN-FIFO",0644);
mknod(S_FIFO,"HAN-FIFO|0644",0);

read write

문제4

 Recived : HELLO FIFO

 문제 5
 1.x //쓰레드는 새로운 프로세스를 생성하지 않는다.
 2.o
 3.o
 4.x
 5.x
 문제 6
 &tid thread_func
 &tid //pthread_join(tid);// join에서는 &tid이렇게 안한다 예외
 문제 7
 여러개의 쓰레드들이 하나의 자원을 두고 경쟁을 하며 함수연산을 실행하기때문에
 정확하게 갱신이 되어지지않는다.
 문제 8.
 1.x //뮤텍스는 여러 프로세스의 데이터를 보호하는것이 아니라
 하나의 프로세스의 데이터를 보호한다.
 2.x
 3. o
 4. o mutex는 하나의 쓰레드만 잠금가은
 뮤텍스 하나의 프로세스를 보호
 하나의 쓰레드만 락가능
 문제9
 &cond &mut
 pthread_cond_wait(&cond,&mut)

 &cond

 문제 10
 pipe_fd[0] pipe_fd[1]

  tcpip는
  응용 전송 네트워크 네트워크접속 하드웨어 계증
  응용 전송 네트워크 네트워크접속 하드웨어 계층
  응용 전송 네트워크 네트워크전송 하드웨어 계층

소켓 인터페이스 - 응용계층과 전송계층의 기능을 사용할 수 있는 api

ip주소 및 이름 가저오기
struct hostent







#include <netdb.h>
#include <stdio.h>

int main() {

    struct hostent *hent;
    sethostent(0);

    while ((hent = gethostent()) != NULL) {
        printf("name", hent->h_name);
    }

    endhostent();



}

gethostent sethostent endhostet

hent = gethostent();

hostent -> 호스트 이름 번호 들고오기
포트번호 이름 들고오기 - servent struct사용





// 함수의 포트정보 읽어오기

#include <stdio.h>
#include <stdlib.h>

int main() {

    struct servent *port;
    int n;

    setservent(0);

    while ((port = getservent()) != NULL) {
        printf(" port number", port->s_name, port->s_port);
    }

    endservent();
}

소켓의 종류 -> AF_INET AF_UNIX 이렇게 2개가 있다.
SOCK_STREAM SOCK_DGRAM 이렇게 소켓의 통신방식

소켓의 통신방식은 tcpudp이렇게 2개가 있고
소켓의 종류는 unix inet이렇게 2개가 있다

소켓 구조체 struct sockaddr

빅엔디언 리틀엔디안
hbo nbo이렇게 있고
바이트 순서함수

inet_addr ip주소를 숫자로 변환
inet_ntoa ip주소를 문자열로 변환

int main(){

    in_addr_t addr;
    struct hostent *hent;
    struct in_addr in;

    if((addr = inet_addr("8.8.8.8"))==(in_addr_t)-1){

    }

    hent = gethostent()
}

O
O
X
X
X
O
TCP
속도
네트워크
AF_UIX
???
AF_UNX
send로 전송된 데이터를 받아오는 역할
bind실패시 불러와야할것?

문자로 표시


#define PORTNUM 9000

int main(){

    int sd;
    char buf[256];
    struct sockaddr_in sin;

    if((sd = socket(AF_INET, SOCK_STREAM,0))==-1){
        perror;
    }

    서버 소켓 연결했으면 초기화

    memset((char*)&sin , '\0',sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("192.168.147.129");

    if(connect(sd,(struct sockaddr *)&sin,sizeof(sin))){
        perror
    }

    if(recv(sd,buf,sizeof(buf),0)==-1){
        perror;
    }

    close(sd);


}

서버
소켓 만들고 서버주소 초기화및 설정 바인딩 리슨 액셉트 센드

#define PORTNUM 9000;

int main(){

    char buf[256];
    struct sockaddr_in sin, cli;

int sd, ns,clientlen = sizeof(len);

if((sd = socket(AF_INET,SOCK_STREAM,0))==-1){
   perror("socket");

}

memset((char *)&sin,'\0',sizeof(sin));

sin.sin_family = AF_INET;
sin.sin_port = htons(PORTNUM);
sin.sin_addr.s_addr = inet_addr("192.123.123.13");

if(bind(sd,(struct sockaddr*)&sin,sizeof(sin)));
}

if(listen(sd,5))

ns = accept(sd, (struck sockaddr*)&cli,&clientlen);
ns = accept(sd, (struct sockaddr*)&cli,&clientlen);

if(send(ns,buf,strlen(buf+1),0))


close(sd);
close(ns);

int main(){
    struct sockaddr_un ser,cli;

    // unix버전은 struct sockaddr_un을 사용하는구망..
int sd, nsd,len,clean;

if((sd=socket(AF_UNIX,SOCK_STREAM,0)==-1)){
    perror;
}

서버 주소 초기화

memset((char*)&ser, '\0',sizeof(ser));
ser.sun_family = AF_UNIX;
strcpy(ser.sun_path ,SOCKET_NAME);
소켓 정의
유닉스는 sun이넹
인터넷은 sin이고

strcpy(ser.sun_path,SOCKET_NAME);

if(bind(sd,(struct sock_addr*)&ser,len));
}

listne(sd,5);

if(nsd =accept(sd,(struct sockaddr*)&cli,sizeof(cli)));

if(recv(nsd,buf,sizeof(buf),p));

close(nsd);
close(sd);

소켓인터페이스 함수
send recv sendto recvfrom


o
o
x
o
16
모르겠음
0~약 65550
sethostent
gethostent
endhostent
tcp는 전송이되었는지 확인을하고 보다신뢰있는 통신이 가능하다
upt는 전송이 되었는지 확인하지 않고 빠른통신을 위해 확인하지 않으며 전송한다.

x
o
x
x

inet_addr

반복 서버
동시동작 서버




// 동시동작서버

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORTNUM 9002
// 동시 동작서버 exec함수 사용한것

int main() {

    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);

    // 1. 소켓 생성

    if (sd = socket(AF_INET, SOCK_STREAM, 0) == -1) {
        perror("socket");
        exit(1);
    }

    // 2 서버 주소 초기화 및 설정
    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = INADDR_ANY;

    if (bind(sd, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        if ((ns = accept(sd, (sockaddr_in *)&cli, clientlen)) == -1) {
            perror("accep");
            continue;
        }

        switch (fork()) {

        case 0:
            close(sd);
            dup2(ns, STDIN_FILENO);
            dup2(ns, STDOUT_FILENO);

            // sd를 닫고 ns를 표준 입출력으로 dup2
            close(ns);

            execl("./han", "han", (char *)0);

        default:
            close(ns);
        }
    }
    close(sd);
    return 0
}



// udp 프로그래밍

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define PORTNUM 9005;

int main() {

    // udp프로그래밍 - accept필요없음

    // 1. socket설정

    if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
    }

    // 2. server 초기화 및 설정
    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = INADDR_ANY;

    // 3 바인딩

    if (bind(sd, (struct sockaddr *)&sin, sizeof(sin)) == -1)
        perror("binding");
    // bind 공식 bind(sd,(struct sockaddr*)&sin,sizeof(sin));

    while (1) {
        if ((recvfrom(sd,buf, 255, 0, (struct_addr *)&cli, &clilen)) == -1) {
            perror("recevefrom");
        }

        printf("from to client");

        strcpy(buf, "hello client");

        if ((sendto(sd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&cli, sizeof(cli))) == -1) {
            perror("sendto");
            continue;
        }
    }
}



// udp 프로그래밍 클라이언트

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define PORTNUM 9005;

int main() {
    int sd, n;
    int buf[256];
    struct sockaddr_in sin;

    if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buf, "i am client");

    if ((sendto(sd, buf, strlen(buf) + 1, (struct sockaddr *)&cli, sizeof(cli))) == -1) {
        perror("send to");
    }

    if ((n = recvfrom(sd, buf, sizeof(buf), 0, NULL, NULL)) == -1) {
        perror(recvfrom);
        eixt(1);
    }

    buf[n] = '0';
    printf("%s", buf);
}


#define SOCKET_NAME "hbsocket";

int main(){

char buf[256];

struct sockaddr_un sun,cli;
int  sd , nsd , clen;

if(sd = socket(AF_UNIX,SOCK_STREAM,0)==-1){
    perror();
}

memset((char*)&sun, '\0', sizeof(struct sockaddr_un));
sun.sun_family = AF_UNIX;
strcpy(sun.sun_path,SOCKET_NAME);
//strcpy(sun.sun_path, SOCKET_NAME);


if(bind(sd, (struct sockaddr_un *)&sun,len))

if(listen(sd,5));

if((nsd = accept(sd,(struct sockaddr_un*)&cli,&clen)));


if(recv(nsd,buf,sizeof(buf)))

printf("%s",buf);
}

int main(){

    int sd ,nsd;
    char buf[256];

    struct sockaddr_un ser;

    if((sd = socket(AF_UNIX,SOCK_STREAM,0))==-1){
        perror("socket");
    }

    memset((char *)&ser, '\0', sizeof(ser));
    ser.sun_family = IF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);
    len = sizeof(ser.sun_family)+strlen(ser.sun_path);

    if(connet(sd,(struct sockaddr_un*)&ser,len))

    strcpy(buf, "unix domain soket");

    if(send(sd,buf,sizeof(buf)))
    close(sd);

    unlink(socket)->address already in use일 때 사용

//인터넷 소켓 클라이언트

#define PORTNUM 9000

int main(){

int sd;
char buf[256];
struct sockaddr_in sin;

if((sd = socket(AF_INET,SOCK_STREAM,0)))

memset((char*)&sin,'\0',sizeof(sin));

sin.sin_family = AF_INET;
sin.sin_port = htons(PORTNUM);
sin.sin_addr.s_addr = inet_addr("192.168.147.129");
}

if(connet(sd, (struct sockaddr_in*)&sin, sizeof(sin)))

if(recv(sd,buf,sizeof(buf),0))

close (sd)
}

char *val;

if(val == NULL){

    printf("term no exist");

    exit(1);
}


val = getenv("term");

putenv("term = vt100");

printf("term %s\n",val);



환경변수
프로세스가 실행되는 기본환경을 설정하는 함수
로그인 셸 터미널 언어 로그인명
env명령 사용


반복서버
동시동작 서버
반복서버는 직접 모든 프로세스처리
동시동작서버는 자식 프로세스가 클라이언트와 연결




int main() {

    char buf[256];
    struct scoket_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);

    memset((char *)&ser, '\0', sizeof(ser));

    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = INADDR_ANY;

    if (sd = socket(AF_INET, SOCK_STREAM, 0))

        perror("socket");
    exit(1);

    if (bind(sd, (struct sockaddr_in *)&sin, sizeof(sin)))

    if (listen(sd, 5))

    while (1) {

    if ((ns = accept(sd, (struct sockeaddr *)&cli, &clientlen)))

    if (send(ns, buf, sizeof(buf)))

    if (recv(ns, buf, sizeof(buf)))




            }
}


*/