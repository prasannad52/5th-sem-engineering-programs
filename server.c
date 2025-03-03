#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0), c;
    struct sockaddr_in addr = {AF_INET, htons(8080), INADDR_ANY};
    char buf[1024] = {0};

    bind(s, (struct sockaddr *)&addr, sizeof(addr));
    listen(s, 1);
    printf("Connection established successfully\n");
    c = accept(s, NULL, NULL);
    read(c, buf, sizeof(buf));
    
    FILE *f = fopen(buf, "r");
    if (f) {
        while (fgets(buf, sizeof(buf), f)) {
            send(c, buf, strlen(buf), 0);
        }
        printf("file sent to client");
    }
 else 
   {
        send(c, "File not found\n", 15, 0);
    }

    fclose(f);
    close(c);
    close(s);

    return 0;
}