#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int ascii;
    int freq;
} CharFreq;

int compare(const void *a, const void *b) {
    CharFreq *cf1 = (CharFreq *)a;
    CharFreq *cf2 = (CharFreq *)b;

    if (cf1->freq != cf2->freq) {
        return cf1->freq - cf2->freq;
    } else {
        return cf2->ascii - cf1->ascii;
    }
}

int main() {
    char line[1002];
    int any_previous_output = 0;

    while (fgets(line, sizeof(line), stdin)) {  // Fixed the missing closing parenthesis here
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        int freq[128] = {0};

        for (int i = 0; i < len; i++) {
            unsigned char c = line[i];
            freq[c]++;
        }

        CharFreq list[128];
        int count = 0;

        for (int i = 32; i <= 127; i++) {
            if (freq[i] > 0) {
                list[count].ascii = i;
                list[count].freq = freq[i];
                count++;
            }
        }

        qsort(list, count, sizeof(CharFreq), compare);

        if (count > 0) {
            if (any_previous_output) {
                printf("\n");
            }
            any_previous_output = 1;

            for (int i = 0; i < count; i++) {
                printf("%d %d\n", list[i].ascii, list[i].freq);
            }
        }
    }

    return 0;
}
