#pragma region linear regression
// least Squares?
int leastSquares(v2f arr[], int n, float* slope, float* intercept, float* r) {
	float sx = 0.0, sy = 0.0, sx2 = 0.0, sy2 = 0.0, sxy = 0.0;
	for (int i = 0; i < n; i++) {
		float d = arr[i].x;
		sx += arr[i].x;
		sx2 += (arr[i].x * arr[i].x);
		float o = (arr[i].x * arr[i].x);
		sy += arr[i].y;
		sy2 += arr[i].y * arr[i].y;
		sxy += arr[i].x * arr[i].y;
	}

	float denominator = n * sx2 - sx * sx;
	if (denominator == 0)
		return INFINITY; // can't solve the problem
	
	*slope = (n * sxy - sx * sy) / denominator;
	*intercept = (sy * sx2 - sx * sxy) / denominator;
	*r = (sxy - sx * sy / n) / 
		sqrt((sx2 - sx * sx / n)* 
		(sy2 - sy * sy / n));

}
#pragma endregion