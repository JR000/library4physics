#define max(a, b) (a > b ? a : b)

void swap(int arr[], int i, int j) {
	int c = arr[i];
	arr[i] = arr[j];
	arr[j] = c;
}

template <typename T>
void swap(T arr[], int i, int j) {
	T c = arr[i];
	arr[i] = arr[j];
	arr[j] = c;
}

#pragma region bubble
void bubble_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
}

template <typename T>
void bubble_sort(T* arr, T* n, bool (*cf)(T, T)) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (cf(arr[j], arr[j+1]))
				swap<T>(arr, j, j + 1);
}
#pragma endregion


#pragma region merge
void merge_sort(int l, int r, int in[], int out[]) {
	if (r <= l)
		return;

	int m = (l + r) / 2;
	merge_sort(l, m, in, out);
	merge_sort(m + 1, r, in, out);
	
	int l_p = l, r_p = m + 1;
	for (int k = l; k <= r; k++) {
		if (l_p == m + 1) {
			out[k] = in[r_p];
			r_p++;
		}
		else if (r_p == r + 1) {
			out[k] = in[l_p];
			l_p++;
		}
		else if (in[l_p] < in[r_p]) {
			out[k] = in[l_p];
			l_p++;
		}
		else {
			out[k] = in[r_p];
			r_p++;
		}
	}

	for (int i = l; i <= r; i++)
		in[i] = out[i];
}
#pragma endregion

#pragma region selection
void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int m_p = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[m_p])
				m_p = j;
		if (m_p != i) {
			swap(arr, i, m_p);
		}
	}
}
#pragma endregion insertion
void insertion_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			swap(arr, j, j - 1);
			j -= 1;
		}
	}
}
#pragma region 

#pragma region heap
void siftDown(int arr[], int i, int upper) {
	while (1) {
		int l_p = i * 2 + 1, r_p = i * 2 + 2;
		if (max(l_p, r_p) < upper)
		{
			if (arr[i] >= max(arr[l_p], arr[r_p]))
				break;
			if (arr[l_p] > arr[r_p])
			{
				swap(arr, l_p, i);
				i = l_p;
			}
			else {
				swap(arr, r_p, i);
				i = r_p;
			}
		}
		else if (l_p < upper) {
			if (arr[l_p] > arr[i]) {
				swap(arr, i, l_p);
				i = l_p;
			}
			else
				break;
		}
		else if (r_p < upper) {
			if (arr[r_p] > arr[i]) {
				swap(arr, i, r_p);
				i = r_p;
			}
			else
				break;
		}
		else
			break;
	}
}
void heap_sort(int arr[], int n) {
	// 1. heapify
	for (int i = (n - 2) / 2; i > -1; i--) {
		siftDown(arr, i, n);
	}

	// 2. sorting
	for (int i = n - 1; i > 0; i--) {
		swap(arr, 0, i);
		siftDown(arr, 0, i);
	}
}
#pragma endregion