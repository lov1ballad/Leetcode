#define _CRT_SECURE_NO_WARNINGS 1
inline int partition(int* a, int l, int r) {
	int x = a[r], i = l - 1;
	for (int j = l; j < r; ++j) {
		if (a[j] <= x) {
			int t = a[++i];
			a[i] = a[j], a[j] = t;
		}
	}
	int t = a[i + 1];
	a[i + 1] = a[r], a[r] = t;
	return i + 1;
}

inline int randomPartition(int* a, int l, int r) {
	int i = rand() % (r - l + 1) + l;
	int t = a[i];
	a[i] = a[r], a[r] = t;
	return partition(a, l, r);
}

int quickSelect(int* a, int l, int r, int index) {
	int q = randomPartition(a, l, r);
	if (q == index) {
		return a[q];
	}
	else {
		return q < index ? quickSelect(a, q + 1, r, index)
			: quickSelect(a, l, q - 1, index);
	}
}

int findKthLargest(int* nums, int numsSize, int k) {
	srand(time(0));
	return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}