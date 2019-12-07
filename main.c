#include <nfp.h>
#include <stdlib.h>


void cls_benchmark(){
    __declspec(cls) int old[100];
    __declspec(cls) int curr_time[8];
    __declspec(cls) int time_handle[8];

    int i, size;
    
    curr_time[__ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    curr_time[__ctx()] = timestamp_stop(time_handle[__ctx()]);
}


void ctm_benchmark(){
    __declspec(ctm) int old[100];
    __declspec(ctm) int curr_time[8];
    __declspec(ctm) int time_handle[8];

    int i, size;
    
    curr_time[__ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    curr_time[__ctx()] = timestamp_stop(time_handle[__ctx()]);
}

void imem_benchmark(){
    __declspec(imem) int old[100];
    __declspec(imem) int curr_time[8];
    __declspec(imem) int time_handle[8];

    int i, size;
    
    curr_time[__ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    curr_time[__ctx()] = timestamp_stop(time_handle[__ctx()]);
}

void emem_benchmark(){
    __declspec(emem shared) int old[100];
    __declspec(emem shared) int curr_time[8];
    __declspec(emem shared) int time_handle[8];

    int i, size;
    
    curr_time[__ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    curr_time[__ctx()] = timestamp_stop(time_handle[__ctx()]);
}

int main (){
    ctm_benchmark();
     cls_benchmark();
     imem_benchmark();
     emem_benchmark();
    return 0;
}