#include <stdio.h>
#include <stdbool.h>

float d = 1.2f;

float ff() {
   return 1.5f;
}

int main() {
   printf("%f", d / ff());
}