#include "./Word.h"
#include <iostream>
int main(){
    char text[] = "Hello world";
    Word word = Word();
    word.setText(text);
    word.show();
}
