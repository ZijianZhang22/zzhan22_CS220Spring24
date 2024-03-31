#include <stdio.h>
#include<wchar.h>//wide character
#include <locale.h>
int main(){
setlocale(LC_ALL,"");// MAKES THEc portable to all locales
printf("THE euro sybol is \xE2\x82\xAC\n");
printf("the euro symbol is â") ;
}

