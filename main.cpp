#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	const char* fname1 = argv[1];
	const char* fname2 = argv[2];

	uint32_t n1;
	uint32_t n2;

	fp1 = fopen(fname1, "rb");
	fp2 = fopen(fname2, "rb");

	if (fp1 == NULL or fp2 == NULL)
	{
		perror("Error!!! file open\n");
		fclose(fp1);
		fclose(fp2);
		return -1;
	}	

	fread(&n1, sizeof(n1), 1, fp1);
	n1 = htonl(n1);
	//printf("file1 값: %d\n", n1);
	
	fread(&n2, sizeof(n2), 1, fp2);
	n2 = htonl(n2);
	//printf("file2 값: %d\n", n2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);

	fclose(fp1);
	fclose(fp2);
}
