def count_long_subarray(A):
    '''
    Input:  A     | Python Tuple of positive integers
    Output: count | number of longest increasing subarrays of A
    '''
    count = 0
    current_length = 0
    dummy_length = 1
    length = len(A)
    # iterate through the tuple
    for i in range(length):
        try:
            # if the first item is lower than the second item
            if A[i] < A[i + 1]:
                dummy_length += 1
            else:
                if dummy_length > current_length:
                    current_length = dummy_length
                    count = 1
                elif dummy_length == current_length:
                    count += 1
                dummy_length = 1
        # if this is the last item
        except IndexError:
            if dummy_length == current_length:
                count += 1
    return count
