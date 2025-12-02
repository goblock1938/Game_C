#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 5

int generate_random_number(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int generate_random_operator() {
    int op = rand() % 4;
    return op;
}

int main() {
    srand((unsigned int)time(NULL));
    printf("Selamat datang di game Matematika\n");
    int level;
    do {
        printf("Mau level berapa? (1-10): ");
        if (scanf("%d", &level) != 1) {
            int _c; while ((_c = getchar()) != '\n' && _c != EOF) { }
            level = 0;
            continue;
        }
        int _c; while ((_c = getchar()) != '\n' && _c != EOF) { }
    } while (level < 1 || level > 10);
    typedef struct {
        int a;
        int b;
        int op;
        int expected;
        int answer;
        int correct;
    } Question;

    Question quiz[MAX_QUESTIONS];

    for (int q = 0; q < MAX_QUESTIONS; ++q) {
        int lower = level > 5 ? level * 10 : level * 1;
        int upper = level > 5 ? level * 10 + level : level * 5;
        int nump1 = generate_random_number(lower, upper);
        int nump2 = generate_random_number(lower, upper);
        int operator = generate_random_operator();
        int result = 0, answer;
        puts("\n==============================");
        printf("Soal Nomor %d:\n", q + 1);
        switch (operator) {
            case 0:
                printf("Berapakah %d + %d ? ", nump1, nump2);
                result = nump1 + nump2;
                break;
            case 1:
                printf("Berapakah %d - %d ? ", nump1, nump2);
                result = nump1 - nump2;
                break;
            case 2:
                printf("Berapakah %d * %d ? ", nump1, nump2);
                result = nump1 * nump2;
                break;
            case 3:
                while(nump2 == 0) {
                    nump2 = generate_random_number(lower, upper);
                }
                if (nump1 < nump2) {
                    int temp = nump1;
                    nump1 = nump2;
                    nump2 = temp;
                }
                printf("Berapakah %d / %d ? (bulatkan ke bawah) ", nump1, nump2);
                result = nump1 / nump2;
                break;
        }
        scanf(" %d", &answer);
        printf("\n");
        int __tmpc;
        while ((__tmpc = getchar()) != '\n' && __tmpc != EOF) { }
        quiz[q].a = nump1;
        quiz[q].b = nump2;
        quiz[q].op = operator;
        quiz[q].expected = result;
        quiz[q].answer = answer;
        quiz[q].correct = (answer == result) ? 1 : 0;
    }

    /* print summary */
    int score = 0;
    printf("\nRingkasan kuis (%d soal):\n", MAX_QUESTIONS);
    for (int i = 0; i < MAX_QUESTIONS; ++i) {
        const char *opchar = (quiz[i].op == 0) ? "+" : (quiz[i].op == 1) ? "-" : (quiz[i].op == 2) ? "*" : "/";
        printf("%d) %d %s %d = %d, jawaban Anda = %d -> %s\n",
            i+1, quiz[i].a, opchar, quiz[i].b, quiz[i].expected,
            quiz[i].answer, quiz[i].correct ? "BENAR" : "SALAH");
        score += quiz[i].correct;
    }
    printf("\nTotal benar: %d/%d\n", score, MAX_QUESTIONS);
    return 0;
}