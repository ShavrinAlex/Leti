#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/vfs.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <libcpuid/libcpuid.h>


#define COUNT_TITLE_SYMB 75

void title(char title_text[]){
	int count = (COUNT_TITLE_SYMB - sizeof(title_text)/sizeof(char))/2;
	for (int i = 0; i < count; i++){
		printf("\033[31m-");
	}
	printf("%s", title_text);
	for (int i = 0; i < count; i++){
		printf("-");
	}
	printf("\033[0m\n");
}

void system_information(){
//-------------------------system information--------------------------------------
	title("SYSTEM INFORMATION");
	struct utsname sys_buffer;
	int success = uname(&sys_buffer);
	if (success != 0) {
	    perror("uname");
	    exit(EXIT_FAILURE);
	}
	printf("\033[36mSystem name:\033[0m\t%s\n", sys_buffer.sysname);
	printf("\033[36mNode name:\033[0m\t%s\n", sys_buffer.nodename);
	printf("\033[36mDomain name:\033[0m\t%s\n", sys_buffer.__domainname);
	printf("\033[36mRelease OS:\033[0m\t%s\n", sys_buffer.release);
	printf("\033[36mVersion OS:\033[0m\t%s\n", sys_buffer.version);
	printf("\033[36mMachine architecture:\033[0m\t%s\n", sys_buffer.machine);

	struct sysinfo si;
	if (sysinfo(&si) != 0) {
	    perror("sysinfo");
	    exit(EXIT_FAILURE);
	}
	printf("\033[36mUptime:\033[0m\t%ld sec | %ld min | %ld h\n", si.uptime, si.uptime/60, si.uptime/3600);
	printf("\n\n");
}

void processor_information(){
//------------------------processor information------------------------------------
	title("PROCESSOR INFORMATION");
	long processors = sysconf(_SC_NPROCESSORS_ONLN);
	long ticks_per_sec = sysconf(_SC_CLK_TCK);
	long page_size = sysconf(_SC_PAGESIZE);
    long max_files = sysconf(_SC_OPEN_MAX);
	
	printf("\033[36mNumber of processors:\033[0m\t%ld\n", processors);
	printf("\033[36mClock ticks per second:\033[0m\t%ld\n", ticks_per_sec);
    printf("\033[36mPage size:\033[0m\t%ld bytes\n", page_size);
    printf("\033[36mMax number of open files:\033[0m\t%ld\n", max_files);
    printf("\n\n");

}

void limit_information(){
//------------------------limit information----------------------------------------
	title("LIMIT INFORMATION");
    	struct rlimit rlim;

	if (getrlimit(RLIMIT_NOFILE, &rlim) == -1) {
		fprintf(stderr, "Error: Unable to get resource limits\n");
		return 1;
	}
	printf("\033[36mCurrent soft limit on number of open files:\033[0m\t%lu\n", rlim.rlim_cur);
	printf("\033[36mCurrent hard limit on number of open files:\033[0m\t%lu\n", rlim.rlim_max);
	printf("\n\n");
}

void memory_information(){
//-------------------------memory information--------------------------------------
	title("MEMORY INFORMATION");
	struct sysinfo si;
	if (sysinfo(&si) != 0) {
	    perror("sysinfo");
	    exit(EXIT_FAILURE);
	}
	long page_size_kb = sysconf(_SC_PAGESIZE) / 1024;
	long long used_kb = (long long)(si.totalram - si.freeram) * page_size_kb;
	long long free_kb = (long long)si.freeram * page_size_kb;
	printf("\033[36mTotal RAM:\033[0m\t%lld MB\n", si.totalram / 1024 / 1024);
	printf("\033[36mFree RAM:\033[0m\t%lld MB\n", si.freeram / 1024 / 1024);
	printf("\033[36mUsed RAM:\033[0m\t%lld MB\n", used_kb / 1024);
	printf("\033[36mFree disk space:\033[0m\t%lld MB\n", free_kb / 1024);
	printf("\033[36mTotal swap space:\033[0m\t%ld bytes\n", si.totalswap);
    printf("\033[36mFree swap space:\033[0m\t%ld bytes\n", si.freeswap);
    printf("\n\n");
}

void disk_information(){
//---------------------------disks information-----------------------------------------
	title("DISK INFORMATION");
	struct statfs stat;
	if (statfs("/", &stat) != 0) {
	    perror("statfs");
	    exit(EXIT_FAILURE);
	}
	long long block_size = (long long)stat.f_bsize;
	long long total_blocks = (long long)stat.f_blocks;
	long long free_blocks = (long long)stat.f_bfree;
	printf("\033[36mBlock size:\033[0m\t%lld\n", block_size);
	printf("\033[36mTotal blocks:\033[0m\t%lld\n", total_blocks);
	printf("\033[36mFree blocks:\033[0m\t%lld\n", free_blocks);
	printf("\033[36mTotal disk space:\033[0m\t%lld MB\n", (total_blocks * block_size) / 1024 / 1024);
	printf("\033[36mFree disk space:\033[0m\t%lld MB\n", (free_blocks * block_size) / 1024 / 1024);
	printf("\n\n");
}

void cpu_information(){
//---------------------------cpu information-----------------------------------------
	title("CPU INFORMATION");
	struct cpu_raw_data_t raw;
    struct cpu_id_t data;

    if (cpuid_get_raw_data(&raw) < 0) {
    	perror("Failed to get raw CPU data");
    	return -1;
    }

    if (cpu_identify(&raw, &data) < 0) {
    	perror("Failed to identify CPU");
    	return -1;
    }

	printf("\033[36mCPU vendor:\033[0m\t%s\n", data.vendor_str);
    printf("\033[36mCPU model:\033[0m\t%s\n", data.brand_str);
	printf("\033[36mCPU code name:\033[0m\t%s\n", data.cpu_codename);
	printf("\n\n");
}

int main(){
	system_information();
	processor_information();
	limit_information();
	memory_information();
	disk_information();
	cpu_information();
	return 0;
}
