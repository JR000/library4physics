double fabs(double);

#pragma region dychotomy
float dychotomy(float eps, float (*prf)(float), float x1, float x2, int N = 50) {
	float* x = (float*) malloc(N); // not quite the c-way, is it?
	x[0] = x1, x[1] = x2;
	for (int i = 2; i < N; i++)
		x[i] = 0;
	int n = 1;
	while (fabs(x[n] - x[n - 1]) > eps) {
		x[n + 1] = (x[n] + x[n - 1]) / 2;
		if (prf(x[n + 1]) * prf(x[n - 1]) < 0)
			x[n] = x[n - 1];
		else if (prf(x[n + 1]) == 0) {
			n += 1;
			break;
		}
		n += 1;
	}
	return x[n];
}
#pragma endregion

#pragma region newton
float newton(float eps, float (*prf)(float), float (*dif)(float), float k, float x1, int N = 50) {
	float* x = (float*)malloc(N);
	x[0] = x1;
	for (int i = 1; i < N; i++)
		x[i] = 0;
	int n;
	for (int i = 0; i < N; i++) {
		x[i + 1] = x[i] - prf(x[i]) / dif(x[i]);
		float f1_sq = prf(x[i]) * prf(x[i]);
		float f2_sq = prf(x[i + 1]) * prf(x[i + 1]);
		float t = (f1_sq + k * f1_sq) / (f1_sq + f1_sq);
		x[i + 1] = x[i] - t * prf(x[i]) / dif(x[i]);
	
		if (i >= 1 && fabs((x[i + 1] - x[i]) / (1 - (x[i + 1] - x[i]) / (x[i] - x[i - 1]))) < eps) 
			return x[i + 1];
	}
	return INFINITY;
}
#pragma endregion
