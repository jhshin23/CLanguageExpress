#include <stdio.h>


void set_pointer(char** q);
void set_pointer2(char** q);

// 함수 밖에서 포인터에 주소를 저장하려면 포인터(=주소)의 주소를 전달
// =>매개변수에 이중 포인터를 선언해서 주소의 주소를 받음
void set_pointer(char** q) {  //문자 포인터의 '주소' 받음
	*q = "All that glister is not gold.";  //문자 포인터에 텍스트세그먼트 첫째 칸 주소 대입연산
}
void set_pointer2(char** q) {  //문자 포인터의 '주소' 받음
	static char cha[] = "All that glister is gold.";
	*q = cha;  //이것도 됨
}
//void set_pointer_double(double** dp[]) {
//	double da1[2] = { 1.1, 2.2 };
//	double da2[2] = { 4.4, 8.8 };
//
//	*dp = da1;
//	*(dp + 1) = da2;
//}

int main() {
	char* p = "초기화";
	set_pointer(&p);  
	printf("%s\n", p);

	set_pointer2(&p);
	printf("%s\n", p);
	//double *dp[2];
	//set_pointer_double(&dp);
	//printf("%f\n%f\n%f\n%f\n", *(*dp), *(*(dp)+1), **(dp+1), *(*(dp + 1)+1));

	return 0;
}

// 2025/01/22 저녁