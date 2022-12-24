#pragma region squares
float squaresLeft_even(float l, float r, int n, float (*prf)(float)) {
	float step = (r - l) / n;
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += prf(l + i * step);
	return sum * step;
}

float squaresRight_even(float l, float r, int n, float (*prf)(float)) {
	float step = (r - l) / n;
	float sum = 0;
	for (int i = 1; i < n + 1; i++)
		sum += prf(l + i * step);
	return sum * step;
}

float squares_even(float l, float r, int n, float (*prf)(float)) {
	float step = (r - l) / n;
	float sum = (prf(l) + prf(r)) / 2;
	for (int i = 1; i < n; i++)
		sum += prf(l + i * step);
	return sum * step;
}

float squares(float l, float r, float* nodes, int n, float (*prf)(float)) {
	float res = 0;
	for (int i = 0; i < n; i++)
		res += prf((nodes[i] + nodes[i + 1]) / 2) * (nodes[i + 1] - nodes[i]);
	return res;
}

float squaresLeft(float l, float r, float* nodes, int n, float (*prf)(float)) {
	float res = 0;
	for (int i = 0; i < n; i++)
		res += prf(nodes[i]) * (nodes[i + 1] - nodes[i]);
	return res;
}

float squaresRight(float l, float r, float* nodes, int n, float (*prf)(float)) {
	float res = 0;
	for (int i = 1; i < n + 1; i++)
		res += prf(nodes[i]) * (nodes[i] - nodes[i - 1]);
	return res;
}
#pragma endregion

#pragma region simpson
float simpson(float l, float r, float (*prf)(float)) {
	return (r - l) / 6 * (prf(l) + prf(r) + 4 * prf((l + r) / 2));
}

// f'''' must exist
//float simpsonError_peano(float l, float r) {
//	return (r - l) * *5 / 2880 * fabs(max(f''''(x))), x in[a, b];
//}

float simpson_even(float l, float r, int n, float (*prf)(float)) {
	float step = (r - l) / n;
	float sum = prf(l) + prf(r) + 4 * prf(r - step);
	for (int i = 1; i < n / 2; i++)
		sum += 2 * prf(l + 2 * step * i) + 4 * prf(l + (2 * i - 1) * step);
	return step / 3 * sum;
}
#pragma endregion

#pragma region trapeces
float trapeces(float l, float r, int n, float (*prf)(float)) {
	float step = (r - l) / n;
	int prev = l, next = l + step;
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += step * (prf(prev) + prf(next)) / 2;
	}
	return res;
}

float trapeces(float* nodes, int n, float (*prf)(float)) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += (nodes[i + 1] - nodes[i]) * (prf(nodes[i]) + prf(nodes[i + 1])) / 2;
	}
	return res;
}
float trapeces_even(float l, float r, float n, float (*prf)(float)) {
	float step = (r - l) / n;
	float res = (prf(r) + prf(l)) / 2;
	for (int i = 1; i < n - 1; i++)
		res += prf(l + i * step);
	res *= step;
	return res;
}

// TODO: max_Err = (r - l) ** 3 / 12 * max(f''(x)), x in [l; r]
#pragma endregion

