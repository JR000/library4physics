#pragma region Differentiation using Lagrange's interpolational polynom
float lagrange_inter_dif(float xi, float x[], float y[], int n) {
	float s1 = 0;
	for (int i = 0; i < n; i++) {
		float s2 = 0;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			float p = 1;
			for (int k = 0; k < n; k++)
				if (k != j && k != i)
					p *= (xi - x[k]) / (x[i] - x[k]);
			s2 += p / (x[i] - x[j]);
		}
		s1 += y[i] * s2;
	}
	return s1;
}
#pragma endregion