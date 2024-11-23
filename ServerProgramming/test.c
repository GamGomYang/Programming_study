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



// atexit() 와 exti() , on_exit()함수의 활용
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
        perror("pork");
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

*/