#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	FILE* out = fopen("Output Metrics", "w");
	if(out == NULL) {
		fprintf(stderr, "Some error occured. Exiting\n");
		exit(EXIT_FAILURE);
	}

	puts("Enter elapsed time");
	float etime;
	scanf("%f", &etime);

	puts("Enter unique bytes transferred");
	float nbytes;
	scanf("%f",&nbytes);

	puts("Enter total bytes transferred");
	float total;
	scanf("%f",&total);

	puts("Enter throughput");
	int throughput;
	scanf("%d", &throughput);

	puts("Enter average RTT");
	float rtt;
	scanf("%f",&rtt);

	puts("Enter baseline RTT");
	float base;
	scanf("%f",&base);

	fprintf(out, "Unique Bytes transferred = %d (%.2f MB)\n", (int)nbytes, (nbytes/1024)/1024);
	fprintf(out, "Elapsed time = %.2f seconds (%.2f minutes)\n", etime, etime/60);
	fprintf(out, "Throughput = %d Bps\n", throughput);
	fprintf(out, "TCP Efficiency = %.2f%%\n", ((total - (total - nbytes))/total)*100);
	fprintf(out, "Buffer Delay = %.2f%% [ Baseline RTT %.2f ms ]\n", ((rtt - base)/base)*100, base);
	
	return 0;
}
