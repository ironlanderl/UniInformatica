#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void trova_parola(char* frase, char* parola){
    int index2 = 0;
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] == parola[index2]){
            index2++;
        }
        else{
            index2 = 0;
        }

        if (index2 == strlen(parola)){
            printf("Parola %s trovata alla posizione %d\n", parola, i - index2 + 1);
            return;
        }
    }

    printf("Parola %s non trovata\n", parola);
}

int main() {
    char frase1[] = "Hello, world!";
    char parola1[] = "world";
    trova_parola(frase1, parola1); // Expected output: "Found 'world' in 'Hello, world!'"

    char frase2[] = "I like to eat pizza.";
    char parola2[] = "burger";
    trova_parola(frase2, parola2); // Expected output: "Did not find 'burger' in 'I like to eat pizza.'"

    char frase3[] = "The quick brown fox jumps over the lazy dog.";
    char parola3[] = "the";
    trova_parola(frase3, parola3); // Expected output: "Found 'the' in 'The quick brown fox jumps over the lazy dog.'"

    char frase4[] = "Programming is fun.";
    char parola4[] = "Programming";
    trova_parola(frase4, parola4); // Expected output: "Found 'Programming' in 'Programming is fun.'"

    char frase5[] = "";
    char parola5[] = "empty";
    trova_parola(frase5, parola5); // Expected output: "Did not find 'empty' in ''"

    char frase6[] = "abcde";
    char parola6[] = "bcd";
    trova_parola(frase6, parola6); // Expected output: "Found 'bcd' in 'abcde'"

    char frase7[] = "OpenAI is revolutionizing AI.";
    char parola7[] = "openai";
    trova_parola(frase7, parola7); // Expected output: "Did not find 'openai' in 'OpenAI is revolutionizing AI.'"

    char frase8[] = "I love ice cream!";
    char parola8[] = "cream";
    trova_parola(frase8, parola8); // Expected output: "Found 'cream' in 'I love ice cream!'"

    char frase9[] = "12345";
    char parola9[] = "2";
    trova_parola(frase9, parola9); // Expected output: "Found '2' in '12345'"

    char frase10[] = "Programming";
    char parola10[] = "programming";
    trova_parola(frase10, parola10); // Expected output: "Did not find 'programming' in 'Programming'"

    return 0;
}