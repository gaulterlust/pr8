#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 14

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

long long count_anagrams(char* word) {
    int length = strlen(word);
    int char_count[256] = {0};
    
    for (int i = 0; i < length; i++) {
        char_count[(int)word[i]]++;
    }

    long long total_anagrams = factorial(length);
    for (int i = 0; i < 256; i++) {
        if (char_count[i] > 1) {
            total_anagrams /= factorial(char_count[i]);
        }
    }

    return total_anagrams;
}

int main() {
    char word[MAX_LENGTH + 1];
    printf("Введіть слово (до 14 букв): ");
    scanf("%s", word);

    if (strlen(word) > MAX_LENGTH) {
        printf("Довжина слова перевищує дозволений максимум (14 букв)\n");
        return 1;
    }

    long long result = count_anagrams(word);
    printf("Кількість можливих анаграм: %lld\n", result);

    return 0;
}