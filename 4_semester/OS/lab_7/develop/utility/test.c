#include <stdio.h>
#include <cpuid/cpuinfo.h>

int main() {
    cpu_raw_data_t raw;
    cpu_id_t data;

    if (cpuid_get_raw_data(&raw) < 0) {
        perror("Failed to get raw CPU data");
        return -1;
    }

    if (cpu_identify(&raw, &data) < 0) {
        perror("Failed to identify CPU");
        return -1;
    }

    printf("CPU model: %s\n", data.brand_str);
    
    return 0;
}
