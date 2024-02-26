#include "utils.h"

int main(void)
{
	printf("hello, world\n");
	char seq[] = {'c', 'a', 'r', 'b', 'o', 'h', 'y', 'd', 'r', 'a', 't', 'e'};
	int length = sizeof(seq) / sizeof(seq[0]);
	printf("The length of increasing subsequence is %d\n", longest_increasing_subseq_iterative(seq, length));
}
