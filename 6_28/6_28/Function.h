#pragma once

int Add(int x, int y, int result);
int Min(int x, int y, int result);
int Mul(int x, int y, int result);
int Div(int x, int y, int result);

int Add(int x, int y,int result) {
	result = x + y;

	return result;
}

int Min(int x, int y, int result) {
	result = x - y;

	return result;
}

int Mul(int x, int y, int result) {
	result = x * y;

	return result;
}

int Div(int x, int y, int result) {
	result = x / y;

	return result;
}