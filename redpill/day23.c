#include <stdio.h>
#include <stdint.h>

char *myTokenizer(char *str, const char *delim){
    //현재 캐릭터
    static const char *current;
    //저장용
    static char token[64];
    if(str != NULL){
        current = str;
    }
    if(current  == NULL || *current == '\0'){
        return NULL;
    }
    int i =0;
    //현재 char가 delim이거나 주소에 \0일때 까지 루프
    while (*current != '\0' && *current != *delim)
    {
        if(i < 63){
            token[i++] = *current;
        }
        current++;
    }
    token[i] = '\0';
    if (*current == *delim)
        current++;

    return token;

}
int main(int argc, char const *argv[])
{
    const char input[] = "GPS,37.5665,126.9780,20260213";

    printf("=== Day 23: Safe String Tokenizer (static) ===\n\n");

    printf("Input Data: \"%s\"\n", input);
    printf("Delimiter : ','\n\n");

    char *token = myTokenizer(input, ",");

    int count = 1;

    while (token != NULL)
    {
        printf("Token %d: %s\n", count++, token);
        token = myTokenizer(NULL, ",");
    }

    printf("\n>> Original string check: \"%s\"\n", input);
    printf(">> (Original string remains unmodified)\n");

    return 0;
}
