#include <unistd.h>
#include <stdio.h>
int main() {
	pid_t id = getpid();
	printf("donothing starting, my pid is %d\n", (int) id);
        while (1) {}
}
