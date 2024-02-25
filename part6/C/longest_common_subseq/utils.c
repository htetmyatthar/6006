#include "utils.h"

int longest_common_subseq_iterative(char *A, char *B, int A_length, int B_length)
{
	// initialized the results matrix.
	int** results = malloc(sizeof(int*) * (A_length + 1));
	if(results == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating resultss.\n");
		exit(1);
	}
	for(int i = 0; i < A_length + 1; i++)
	{
		results[i] = calloc(B_length + 1, sizeof(int));
		if(results[i] == NULL)
		{
			fprintf(stderr, "ERROR: not enough memory for creating results matrix.\n");
			exit(1);
		}
	}

	for(int i = A_length - 1; i >= 0; i--)
	{
		for(int j = B_length - 1; j >= 0; j--)
		{
			if(A[i] == B[j])
			{
				results[i][j] = results[i + 1][j + 1] + 1;
			}
			else
			{
				// finding maximum
				int largest_one = results[i + 1][j];
				if(results[i][j + 1] > largest_one)
				{
					largest_one = results[i][j + 1];
				}
				results[i][j] = largest_one;
			}
		}
	}

	int result = results[0][0];
	for(int i = 0; i < A_length + 1; i++)
	{
		free(results[i]);
	}
	free(results);
	return result;
}

int lcs_recursive(char *A, char *B, int i, int j, int A_length, int B_length, int **results) {
    // Base case: if either of the strings is empty, return 0
    if (i == A_length || j == B_length)
        return 0;

    // If the values were already computed, return the result
    if (results[i][j] != -1)
        return results[i][j];

    // If characters match
    if (A[i] == B[j])
        return results[i][j] = 1 + lcs_recursive(A, B, i + 1, j + 1, A_length, B_length, results);
    // If characters don't match
    else
        return results[i][j] = (lcs_recursive(A, B, i + 1, j, A_length, B_length, results) > lcs_recursive(A, B, i, j + 1, A_length, B_length, results)) ?
                               lcs_recursive(A, B, i + 1, j, A_length, B_length, results) :
                               lcs_recursive(A, B, i, j + 1, A_length, B_length, results);
}

int longest_common_subseq_recursive(char *A, char *B, int A_length, int B_length) {
    // Create and initialize the results matrix
    int **results = malloc(sizeof(int *) * (A_length + 1));
    if (results == NULL) {
        fprintf(stderr, "ERROR: not enough memory for creating results.\n");
        exit(1);
    }
    for (int i = 0; i < A_length + 1; i++) {
        results[i] = malloc(sizeof(int) * (B_length + 1));
        if (results[i] == NULL) {
            fprintf(stderr, "ERROR: not enough memory for creating results matrix.\n");
            exit(1);
        }
        // Initialize with -1 to indicate that the value has not been computed yet
        for (int j = 0; j < B_length + 1; j++)
            results[i][j] = -1;
    }

    // Call the recursive function
    int result = lcs_recursive(A, B, 0, 0, A_length, B_length, results);

    // Free dynamically allocated memory
    for (int i = 0; i < A_length + 1; i++)
        free(results[i]);
    free(results);

    return result;
}
