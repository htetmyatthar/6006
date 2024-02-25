#include "utils.h"

int main(void)
{
	printf("hello, world\n");
	char A[] = {'h', 'i', 'e', 'r', 'o', 'g', 'l', 'y', 'p', 'h', 'o', 'l', 'o', 'g', 'y'};
	char B[] = {'m', 'i', 'c', 'h', 'a', 'e', 'l', 'a', 'n', 'g', 'e', 'l', 'o'};
	int A_length = sizeof(A) / sizeof(A[0]);
	int B_length = sizeof(B) / sizeof(B[0]);
	printf("Length of the longest common subsequence is %d\n", longest_common_subseq_iterative(A, B, A_length, B_length));
	printf("Length of the longest common subsequence is %d\n", longest_common_subseq_recursive(A, B, A_length, B_length));
}
