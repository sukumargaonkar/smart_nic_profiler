#include <nfp.h>
#include <stdlib.h>


void cls_benchmark(){
    __declspec(cls shared) int old[500];
    __declspec(cls shared) int curr_time[8];
    __declspec(cls shared) int time_handle[8];

    int i, size;
    
    curr_time[__ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 500; i++) {
        old[i] = i;
    }

    curr_time[__ctx()] = timestamp_stop(time_handle[__ctx()]);
}


void ctm_benchmark(){
    __declspec(ctm shared) int old[500];
    __declspec(ctm shared) int curr_time[8];
    __declspec(ctm shared) int time_handle[8];

    int i, size;
    
    curr_time[__ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 500; i++) {
        old[i] = i;
    }

    curr_time[__ctx()] = timestamp_stop(time_handle[__ctx()]);
}

int main (){
    ctm_benchmark();
     cls_benchmark();
    return 0;
}