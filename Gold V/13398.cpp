/*
* https://www.acmicpc.net/problem/13398
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<limits.h>

#define MAX(A,B) (A)>(B)?(A):(B)

typedef long long ll;

int data[100005] = { 0, };
ll sum[100005] = { INT_MIN, };
ll sum_zero[100005] = { INT_MIN, };
ll max_data = INT_MIN;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &data[i]);
	}

	sum[1] = sum_zero[1] = data[1];

	for (int i = 1; i <= N; i++)
	{
		sum[i] = MAX(data[i], sum[i - 1] + data[i]);
		sum_zero[i] = MAX(sum[i-1], sum_zero[i - 1] + data[i]);
		max_data = MAX(max_data, MAX(sum[i], sum_zero[i]));
	}

	printf("%lld\n", max_data);

	return 0;
}
