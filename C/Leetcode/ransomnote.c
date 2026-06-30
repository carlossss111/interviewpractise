#include <stdio.h>

bool canConstruct(const char* ransomNote, const char* magazine) {
    int magazine_letters[256] = {0};

    while (*magazine != '\0'){
        magazine_letters[*magazine]++;
        magazine++;
    }

    while (*ransomNote != '\0'){
        magazine_letters[*ransomNote]--;
        if (magazine_letters[*ransomNote] < 0){
            return false;
        }
        ransomNote++;
    }
    return true;
}

int main(int argc, char** argv) {
    printf("%d\n", canConstruct("aa", "aba"));
    return 0;
}

