#include <nfp.h>
#include <stdlib.h>

__declspec(ctm32 export scope(global)) int emem_runtime[50];
__declspec(ctm32 export scope(global)) int imem_runtime[50];
__declspec(imem0 export scope(global)) int global_imem[100];
__declspec(emem0 export scope(global)) int global_emem[100];


void global_imem_benchmark(){
    if(__ctx() == 0){
        __declspec(local_mem shared) int time_handle;
        __declspec(local_mem) int i;

        imem_runtime[__island()] = -1;
        time_handle = timestamp_start();

        for(i = 1;i < 100; i++) {
            global_imem[i] = i;
        }
        imem_runtime[__island()] = timestamp_stop(time_handle);
    }
}

void global_emem_benchmark(){
    if(__ctx() == 0){
        __declspec(local_mem shared) int time_handle;
        __declspec(local_mem) int i;

        emem_runtime[__island()] = -1;
        time_handle = timestamp_start();

        for(i = 1;i < 100; i++) {
            global_emem[i] = i;
        }

        emem_runtime[__island()] = timestamp_stop(time_handle);
    }
}

int main (){
    global_imem_benchmark();
    global_emem_benchmark();
    return 0;
}