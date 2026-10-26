#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char password[100];

   
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

   
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
        len--;
    }

   
    bool has_min_length = (len > 8); // أكثر من 8 أحرف
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_numbers = false;
    bool has_symbols = false;

   
    for (size_t i = 0; i < len; i++) {
        char ch = password[i];

        if (ch >= 'A' && ch <= 'Z') {
            has_uppercase = true;
        } else if (ch >= 'a' && ch <= 'z') {
            has_lowercase = true;
        } else if (ch >= '0' && ch <= '9') {
            has_numbers = true;
        } else {
            has_symbols = true;
        }
    }

   
    int score = 0;
    int total_checks = 5;

    if (has_min_length) score++;
    if (has_uppercase)  score++;
    if (has_lowercase)  score++;
    if (has_numbers)    score++;
    if (has_symbols)    score++;

    
    float score_percentage = ((float)score / total_checks) * 100.0f;

    
    printf("\n--- Password Analysis ---\n");
    printf("Password Length: %zu (More than 8? %d)\n", len, has_min_length);
    printf("Contains Uppercase: %d\n", has_uppercase);
    printf("Contains Lowercase: %d\n", has_lowercase);
    printf("Contains Numbers: %d\n", has_numbers);
    printf("Contains Symbols: %d\n", has_symbols);
    printf("Score: %d / %d (%.2f%%)\n", score, total_checks, score_percentage);

    
    if (score == 5) {
        printf("Password Strength: Very Strong\n");
    } else if (score >= 3) {
        printf("Password Strength: Moderate\n");
    } else {
        printf("Password Strength: Weak\n");
    }

    return 0;
}