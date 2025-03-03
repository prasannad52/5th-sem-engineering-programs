#include <stdio.h>
#include <string.h>

#define N strlen(g)  // Length of the generator polynomial

char t[128], cs[128], g[] = "10001000000100001";  // CRC-CCITT generator polynomial
int a, e, c;

void xor() {
    for (c = 1; c < N; c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}

void crc() {
    for (e = 0; e < N; e++) 
        cs[e] = t[e];

    do {
        if (cs[0] == '1') 
            xor();
        for (c = 0; c < N - 1; c++) 
            cs[c] = cs[c + 1];
        cs[c] = t[e++];
    } while (e <= a + N - 1);
}

int main() {
    printf("Enter data word: ");
    scanf("%s", t);
    printf("Generating Polynomial is: %s\n", g);
    
    a = strlen(t);
    for (e = a; e < a + N - 1; e++) 
        t[e] = '0';
    t[e] = '\0';  // Null-terminate modified input

    printf("Modified data word (with appended zeros): %s\n", t);
    
    crc();
    printf("Checksum is: %s\n", cs);
    
    // Append the checksum to the data word
    for (e = a; e < a + N - 1; e++) 
        t[e] = cs[e - a];
    t[e] = '\0';  // Null-terminate final codeword

    printf("Final Codeword is: %s\n", t);

    printf("Test Error detection 0(yes) 1(no)? ");
    scanf("%d", &e);
    
    if (e == 0) {
        printf("Enter position where error is to be inserted: ");
        scanf("%d", &e);
        if (e >= 0 && e < strlen(t)) {  // Check if position is within bounds
            t[e] = (t[e] == '0') ? '1' : '0';
            printf("Erroneous data: %s\n", t);
        } else {
            printf("Error position out of bounds.\n");
        }
    }

    crc();
    for (e = 0; (e < N - 1) && (cs[e] != '1'); e++);

    if (e < N - 1)
        printf("Error detected.\n");
    else
        printf("No Error Detected.\n");

    return 0;
}
