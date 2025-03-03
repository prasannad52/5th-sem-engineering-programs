#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(8080), INADDR_ANY};
    char buf[1024] = {0}, fname[100];

    connect(s, (struct sockaddr *)&addr, sizeof(addr));
    printf("Enter file name: ");
    scanf("%s", fname);
    send(s, fname, strlen(fname), 0);
    while (read(s, buf, sizeof(buf))) printf("%s", buf);
    close(s);
}