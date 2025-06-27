#include <stdio.h>

struct point {
	int x;
	int y;
}p = {-10, -10};

int quadrant(struct point p);
char axis(struct point p);

int quadrant(struct point p) {
	int point_q;
	if (p.x * p.y < 0) // 하나는 음수, 하나는 양수, 무엇도 0은 아님 (6-4)/2
		return point_q = (p.x > 0) ? 4 : 2;
	else if (p.x * p.y > 0) // 둘 다 음수, 둘다 양수, 무엇도 0은 아님
		return point_q = (p.x > 0) ? 1 : 3;
	else 
		return 0;
	////x, y 따로 0보다 큰지 작은지 따지면 삼항연산자를 쓸 기회가 없다-->코드 길어짐
	//if (p.x > 0 && p.y > 0) //둘 다 양수, 무엇도 0은 아님 (3-2==1) * (3-2==1) 
	//	return 1;
	//else if (p.x > 0 && p.y < 0) // x양수, y음수, 무엇도 0은 아님
	// return 3;
	//else if (p.x < 0 && p.y > 0) //x음수, y양수, 무엇도 0은 아님
	// return 2;
	//else if (p.x < 0 && p.y < 0) //둘 다 음수 , 무엇도 0은 아님
	// return 4;
	//else return 0;
}

char axis(struct point p) {
	if (p.x == p.y)   // 적어도 하나는 0이고, 둘 다 0일 때
		return '\0';
	else if (p.x)  // 하나만 0인데 그게 p.x일 때
		return 'y';
	else  // 하나만 0인데 그게 p.y일 때
		return 'x';

}

int main() {
	if (quadrant(p))
		printf("(%d, %d)의 사분면 = %d\n", p.x, p.y, quadrant(p));
	else if (axis(p))
		printf("(%d, %d)은 %c축 위에 있습니다.\n", p.x, p.y, axis(p));
	else
		printf("(%d, %d)은 원점", p.x, p.y);
		

	return 0;
}

/*
프로그램 작성에 어려워하는 부분

발생한 오류의 원인

맞는 레벨이었는지?

푸는 시간
	2025/02/10 17:50~18:40 50분 (주석달면서 생각해보는 시간 30분)
	2025/02/13 22:10~22:20 10분 xor연산 대신 논리 연산자 사용. 가독성 상승
								삼항연산자 대신 else if return 사용.->함수 지역변수 삭제
*/