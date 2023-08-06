#include <stdio.h>
#include <string.h>
int deleteSpace(char a[],int *p){

   for(int i = 0; i < *p; i++){
        if( a[0] == ' '){ //delete spaces at head
            for(int j = i; j < *p; j++){
                a[j] = a[j+1];
            }
            a[*p-1] = '\0';
            i--;

        }
        if( a[i] == a[i+1] && a[i] == ' '){ //delete spaces at mid
            for(int j = i; j < *p-1; j++){
                a[j] = a[j+1];
            }
            a[*p-1] = '\0';
            i--;

        }
        if( a[*p-1] == ' '){ // delete spaces at last
            a[*p-1] = '\0';
        }
    }
}
void up(char *q){
    if(*q > 'a' && *q < 'z'){
        *q = *q - 32;
    }
}
void down(char *q){
    if(*q > 'A' && *q < 'Z'){
        *q = *q + 32;
    }
}
int main(){
    FILE *f;
    f = fopen("file22.txt","r");
    fseek( f, 0, SEEK_END);
    int n = ftell(f);
    rewind(f);
    char array[n];
    for(int i = 0; i < n; i++){// read file
        fscanf(f, "%c", &array[i]);
    }

    deleteSpace(array,&n);
    for(int i = 0; i < n; i++){
        if(i == 0 || array[i-1] == ' '){
            up(&array[i]);
        }
        else{
            down(&array[i]);
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        printf("%c", array[i]);
        if(array[i] == ' '){
            count++;
        }
    }

    printf("\n number of word %d", count);
}
