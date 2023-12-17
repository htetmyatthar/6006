package count_long_subarray

import "testing"

func Test_Count_long_subarray(t *testing.T) {
	testA := [][]int{
		{2, 2, 4, 1, 4},
		{2},
	}
	testB := [][]int{
		{7, 8, 5, 7, 7, 3, 2, 8},
		{3},
	}
	testC := [][]int{
		{7, 7, 9, 1, 2, 11, 9, 6, 2, 8, 9},
		{2},
	}
	testD := [][]int{
		{4, 18, 10, 8, 13, 16, 18, 1, 9, 6, 11, 13, 12, 5, 7, 17, 13, 3},
		{1},
	}
	testE := [][]int{
		{11, 16, 10, 19, 20, 18, 3, 19, 2, 1, 8, 17, 7, 13, 1, 11, 1, 18, 19, 9, 7, 19, 24, 2, 12},
		{4},
	}

	testCases := []struct {
		data [][]int
	}{
		{testA},
		{testB},
		{testC},
		{testD},
		{testE},
	}

	for _, testCase := range testCases {
		runTest(t, testCase.data)
	}
}

func runTest(t *testing.T, testData [][]int) {
	result := CountLongSubarray(testData[0])
	expected := testData[1][0]

	if result != expected {
		t.Errorf("%v returned %d, expected %d",testData[0], result, expected)
	}
}
