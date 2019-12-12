#include <nfp.h>
#include <stdlib.h>

__declspec(ctm shared) int runtime[40];

void local_mem_benchmark(int idx){
    __declspec(local_mem) int old[100];
    //__declspec(ctm shared) int local_mem_curr_time[8];
    __declspec(local_mem shared) int time_handle[8];

    __declspec(local_mem) int i, size;

    runtime[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}


void cls_benchmark(int idx){
    __declspec(cls) int old[100];
    //__declspec(cls shared) int curr_time[8];
    __declspec(cls shared) int time_handle[8];

    __declspec(local_mem) int i, size;
    
    runtime[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}


void ctm_benchmark(int idx){
    __declspec(ctm) int old[100];
    // __declspec(ctm shared) int curr_time[8];
    __declspec(ctm shared) int time_handle[8];

    __declspec(local_mem) int i, size;
    
    runtime[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}

void imem_benchmark(int idx){
    __declspec(imem) int old[100];
    // __declspec(imem shared) int curr_time[8];
    __declspec(imem shared) int time_handle[8];

    __declspec(local_mem) int i, size;
    
    runtime[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}

void emem_benchmark(int idx){
    __declspec(emem) int old[100];
    // __declspec(emem shared) int curr_time[8];
    __declspec(emem shared) int time_handle[8];

    int i, size;
    
    runtime[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}

///////////////////////

__declspec(ctm shared) int runtime_shared[40];

void local_mem_benchmark_shared(int idx){
    __declspec(local_mem shared) int old[100];
    //__declspec(ctm shared) int local_mem_curr_time[8];
    __declspec(local_mem shared) int time_handle[8];

    __declspec(local_mem) int i, size;

    runtime_shared[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime_shared[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}


void cls_benchmark_shared(int idx){
    __declspec(cls  shared) int old[100];
    //__declspec(cls shared) int curr_time[8];
    __declspec(cls shared) int time_handle[8];

    __declspec(local_mem) int i, size;
    
    runtime_shared[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime_shared[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}


void ctm_benchmark_shared(int idx){
    __declspec(ctm shared) int old[100];
    // __declspec(ctm shared) int curr_time[8];
    __declspec(ctm shared) int time_handle[8];

    __declspec(local_mem) int i, size;
    
    runtime_shared[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime_shared[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}

void imem_benchmark_shared(int idx){
    __declspec(imem shared) int old[100];
    // __declspec(imem shared) int curr_time[8];
    __declspec(imem shared) int time_handle[8];

    __declspec(local_mem) int i, size;
    
    runtime_shared[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime_shared[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}

void emem_benchmark_shared(int idx){
    __declspec(emem shared) int old[100];
    // __declspec(emem shared) int curr_time[8];
    __declspec(emem shared) int time_handle[8];

    int i, size;
    
    runtime_shared[idx + __ctx()] = -1;
    time_handle[__ctx()] = timestamp_start();

    size = sizeof(old)/sizeof(int);
    for(i = 1;i < 100; i++) {
        old[i] = i;
    }

    runtime_shared[idx + __ctx()] = timestamp_stop(time_handle[__ctx()]);
}


int main (){
    //register_benchmark();
    int idx = 0;
    local_mem_benchmark(idx);
    local_mem_benchmark_shared(idx);
    idx += 8;
    ctm_benchmark(idx);
    ctm_benchmark_shared(idx);
    idx += 8;
    cls_benchmark(idx);
    cls_benchmark_shared(idx);
    idx += 8;
    imem_benchmark(idx);
    imem_benchmark_shared(idx);
    idx += 8;
    emem_benchmark(idx);
    emem_benchmark_shared(idx);
    return 0;
}