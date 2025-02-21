#include <stdio.h>
#include <unistd.h>

int global_var = 10;

int main(){
    int local_var = 20;
    pid_t pid = fork();

    if(pid == 0){
        printf("Proces dziecko: global_var = %d, local_var = %d\n", global_var, local_var);
        global_var = 100;
        local_var = 200;
        printf("Proces dziecko (po zmienie): global_var %d, local_var = %d\n", global_var, local_var);
    }else{
        printf("Proces rodzic: global_var = %d, local_var = %d\n", global_var, local_var);
    }
    return 0;
}