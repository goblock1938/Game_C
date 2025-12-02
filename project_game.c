#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#if defined(_WIN32)
#include <io.h>
#else
#include <unistd.h>
#endif

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define MAX_SOAL 20
#define MAKS 100
#define MAX_INPUT 100

typedef struct {
    char soal[MAKS];
    char jawaban[MAKS];
    char alasan[MAKS];
} QA;

QA kuis_data[MAX_SOAL];

void lowerCase(char *str) {
    if (str == NULL) return;
    
    while (*str != '\0') {
        *str = (char)tolower((unsigned char)*str);
        str++;
    }
}

void swap_qa(QA *a, QA *b) {
    QA temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle_questions(QA *arr, int count) {
    if (count > 1) {
        for (int i = count - 1; i > 0; i--) {
            int j = rand() % (i + 1); 

            swap_qa(&arr[i], &arr[j]);
        }
    }
}

void inisialisasi_soal() {
    
    // Soal 1
    strcpy(kuis_data[0].soal, "kucing kalo tidur kakinya ada\n\" e _ _ _ _ \"\n");
    strcpy(kuis_data[0].jawaban, "emang");
    strcpy(kuis_data[0].alasan, "kucing kalo tidur \"emang\" ada kakinya");

    // Soal 2
    strcpy(kuis_data[1].soal, "saat membuka tabungan di bank, kita mendapatkan nomor\n\" _ e _ _ _ _ _ _ \"\n");
    strcpy(kuis_data[1].jawaban, "bedabeda");
    strcpy(kuis_data[1].alasan, "kalo nomor rekeningnya sama semua gimana bedainnya??");

    // Soal 3
    strcpy(kuis_data[2].soal, "sebelum menjalin hubungan kerja sama yang resmi, harus pake surat\n\" _ _ _ _ _ a _ \"\n");
    strcpy(kuis_data[2].jawaban, "suratan");
    strcpy(kuis_data[2].alasan, "kalo mau komunikasi ya harus surat - \"suratan\" dulu dong");

    // Soal 4
    strcpy(kuis_data[3].soal, "saat kita mengirim surat lewat kantor pos, harus pakai\n\" _ _ _ _ _ _ _ _ \"\n");
    strcpy(kuis_data[3].jawaban, "namakita");
    strcpy(kuis_data[3].alasan, "kalo pake nama orang lain gimana nyampeinnya??");

    // Soal 5
    strcpy(kuis_data[4].soal, "kangguru adalah hewan yang memiliki kaki panjang, ekor panjang, dan punya ....\n\" _ _ n _ _ _ _ \"\n");
    strcpy(kuis_data[4].jawaban, "sendiri");
    strcpy(kuis_data[4].alasan, "kalo punya orang lain gak asik dong");

    // Soal 6
    strcpy(kuis_data[5].soal, "orang - orang yang lahir di 22 juni - 22 juli berzodiak ....\n\" _ a _ _ _ _ \"\n");
    strcpy(kuis_data[5].jawaban, "samaan");
    strcpy(kuis_data[5].alasan, "kan sama - sama cancer");

    // Soal 7
    strcpy(kuis_data[6].soal, "salah satu superhero yang sebelum beraksi berganti kostum namanya ....\n\" s _ _ _ _ _ _ _\"\n");
    strcpy(kuis_data[6].jawaban, "siapsiap");
    strcpy(kuis_data[6].alasan, "sebelum beraksi harus siap - siap dulu dong");

    // Soal 8
    strcpy(kuis_data[7].soal, "pesulap yang tampilnya jarang ngomong ....\n\" _ _ _ _ a _\"\n");
    strcpy(kuis_data[7].jawaban, "haaaah");
    strcpy(kuis_data[7].alasan, "kalo pesulap jarang tampil ya pasti ngomong \"haaaah\"(sambil pusing dan bingung)");

    // Soal 9
    strcpy(kuis_data[8].soal, "saat ban motor kita bocor harus di ....\n\" t _ _ _ _ _\"\n");
    strcpy(kuis_data[8].jawaban, "tunggu");
    strcpy(kuis_data[8].alasan, "setiap mau nambalin ban ya harus ditunggu, kalo gk nanti hilang motornya");

    // Soal 10
    strcpy(kuis_data[9].soal, "penjara bisa heboh kalo semua napinya ....\n\" _ a _ _ _\"\n");
    strcpy(kuis_data[9].jawaban, "batuk");
    strcpy(kuis_data[9].alasan, "kalo semua napinya batuk polisinya pasti heboh");

    // Soal 11
    strcpy(kuis_data[10].soal, "lengkapi kata berikut ini :\n\"pak tani menanam padidi _ _ _ a _\"\n");
    strcpy(kuis_data[10].jawaban, "lewat");
    strcpy(kuis_data[10].alasan, "pak tani menanam, pa(k)didi lewat");

    // Soal 12
    strcpy(kuis_data[11].soal, "ular yang bisa membesar selain ular anakonda adalah ular .....\n\" _ i _ _ _ _\"\n");
    strcpy(kuis_data[11].jawaban, "dizoom");
    strcpy(kuis_data[11].alasan, "ular kalo dizoom pasti jadi besar dong");

    // Soal 13
    strcpy(kuis_data[12].soal, "untuk membuka pintu rumah kita perlu ....\n\" _ u n _ _\"\n");
    strcpy(kuis_data[12].jawaban, "punya");
    strcpy(kuis_data[12].alasan, "kalo gak \"punya\" pintu gimana mau buka pintu??\n kalo gk \"punya\" kunci gimana mau buka pintu??\n kesimpulannya harus \"punya\" dong");

    // soal 14
    strcpy(kuis_data[13].soal, "host acara \"ini talkshow\" biasanya adalah sule dan ....\n\" _ _ d _ _\"\n");
    strcpy(kuis_data[13].jawaban, "hadir");
    strcpy(kuis_data[13].alasan, "kalo host nya gk hadir terus acaranya gimana??");

    // soal 15
    strcpy(kuis_data[14].soal, "saat mendaki gunung orang biasanya mendirikan ....\n\" t _ _ _ _\"\n");
    strcpy(kuis_data[14].jawaban, "tubuh");
    strcpy(kuis_data[14].alasan, "kalo gk mendirikan tubuh, masa mendaki harus ngesot??");

    // soal 16
    strcpy(kuis_data[15].soal, "dini hari tadi disebut ....\n\" _ u _ _ _\"\n");
    strcpy(kuis_data[15].jawaban, "sudah");
    strcpy(kuis_data[15].alasan, "\"dini hari tadi\" disebut?, sudah dong");

    // soal 17
    strcpy(kuis_data[16].soal, "oleh - oleh dari jogja ....\n\" _ _ _ _ _ a _\"\n");
    strcpy(kuis_data[16].jawaban, "dibawa");
    strcpy(kuis_data[16].alasan, "namanya oleh - oleh ya harus dibawa, kalo gk dibawa bukan oleh - oleh namanya");

    // soal 18
    strcpy(kuis_data[17].soal, "yang bisa bersuara meong ....\n\" _ _ _ i _ _ \"\n");
    strcpy(kuis_data[17].jawaban, "kalian");
    strcpy(kuis_data[17].alasan, "kalian udah pasti bisa ngomong meong dong, gk cuman kucing aja");

    // soal 19
    strcpy(kuis_data[18].soal, "salah satu bagian dari sapi yang bisa dijadikan sop ....\n\" _ u _ _ _ _ \"\n");
    strcpy(kuis_data[18].jawaban, "hurufs");
    strcpy(kuis_data[18].alasan, "kan \'s\' nya sop, bagian dari s-a-p-i");

    // soal 20
    strcpy(kuis_data[19].soal, "pohon yang ada di malam natal pasti ....\n\" _ _ _ a _ _ \"\n");
    strcpy(kuis_data[19].jawaban, "terang");
    strcpy(kuis_data[19].alasan, "\"dini hari tadi\" disebut?, sudah dong");
}

static void normalize_for_compare(const char *src, char *dst, size_t dst_sz) {
    if (!src || !dst || dst_sz == 0) return;
    size_t di = 0;
    for (size_t i = 0; src[i] != '\0' && di + 1 < dst_sz; ++i) {
        unsigned char c = (unsigned char)src[i];
        if (isalnum(c)) {
            dst[di++] = (char)tolower(c);
        }
    }
    dst[di] = '\0';
}
static void trim(char *str) {
    if (!str) return;
    char *start = str;
    while (*start && isspace((unsigned char)*start)) start++;
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }
}
int main() {
    inisialisasi_soal();
    /* seed RNG once */
    srand((unsigned)time(NULL));
    int score = 0;
    
    // 1. Acak urutan soal
    shuffle_questions(kuis_data, MAX_SOAL);
    /* check terminal support for color: if stdout is a tty, enable colors */
#if defined(_WIN32)
    int use_color = _isatty(_fileno(stdout));
#else
    int use_color = isatty(fileno(stdout));
#endif

    const char *C_RED = use_color ? ANSI_COLOR_RED : "";
    const char *C_GREEN = use_color ? ANSI_COLOR_GREEN : "";
    const char *C_BLUE = use_color ? ANSI_COLOR_BLUE : "";
    const char *C_CYAN = use_color ? ANSI_COLOR_CYAN : "";
    const char *C_RESET = use_color ? ANSI_COLOR_RESET : "";

    printf("==========================================\n");
    printf("%s          Kuis Receh Dimulai! \n%s", C_BLUE, C_RESET);
    printf("  (Semua jawaban akan dikonversi ke huruf kecil)\n");
    printf("==========================================\n\n");

    // 2. Loop kuis
    for (int i = 0; i < MAX_SOAL; i++) {
        char user_input[MAX_INPUT];
        
        printf("Soal %d/%d:\n", i + 1, MAX_SOAL);
        printf("%s\n", kuis_data[i].soal);
        printf("Masukkan Jawaban Anda: ");

        if (fgets(user_input, MAX_INPUT, stdin) == NULL) {
            break;
        }
        
          user_input[strcspn(user_input, "\n")] = '\0';
          trim(user_input);

          char usr_norm[MAKS];
          char corr_norm[MAKS];
          normalize_for_compare(user_input, usr_norm, sizeof usr_norm);
          normalize_for_compare(kuis_data[i].jawaban, corr_norm, sizeof corr_norm);

                    if (usr_norm[0] != '\0' && strcmp(usr_norm, corr_norm) == 0) {
                        printf("%s **BENAR!**%s\n", C_GREEN, C_RESET);
                        printf("%sAlasan: %s%s\n", C_CYAN, kuis_data[i].alasan, C_RESET);
            score++;
        } else {
            printf("%s**SALAH!**%s\n", C_RED, C_RESET);
            printf("Jawaban yang benar adalah: \"%s\"\n", kuis_data[i].jawaban);
            printf("%sAlasan: %s%s\n", C_CYAN, kuis_data[i].alasan, C_RESET);
        }
        printf("\n---\n\n");
    }

    printf("==========================================\n");
    printf("\t\t Kuis Selesai! \n");
    printf("\t Skor Akhir Anda: %d/%d\n", score, MAX_SOAL);
    printf("==========================================\n");

    return 0;
}