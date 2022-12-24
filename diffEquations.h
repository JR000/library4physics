#pragma region euler
v2f* euler_v2f(float step, float n, float (*dif)(float, float), float x, float y) {
	for (int i = 0; i < n; i++) {
		y += step * dif(x, y);
		x += step;
	}
	v2f res = { x, y };
	return &res;
}

v2f* euler_v2f_arr(float step, float n, float (*dif)(float, float), float x1, float y1) {
	v2f* res = (v2f*)malloc(n);
	res[0] = { x1, y1 };
	for (int i = 0; i < n; i++)
		res[i] = { 
			res[i - 1].x + step,
			res[i - 1].y + step * dif(res[i - 1].x, res[i - 1].y)
		};
	return res;
}
#pragma endregion
