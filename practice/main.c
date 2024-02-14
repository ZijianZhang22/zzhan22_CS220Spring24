#include <stdio.h>
#include <string.h>
void find(int i){
    if(i==0){
        return;
    }
    int n =i%8;
    i=i/8;
    find(i);
    printf("%1d",n);

}
int main() {
    int k =99;
    find(99);
    return 0;
}
