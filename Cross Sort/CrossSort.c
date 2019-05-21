#include <stdio.h>
/* 
 * 입력의 맨 첫 줄에 숫자들의 개수가 주어진다. 그 후 다음 줄에 숫자들이 주어진다.. 주어진 숫자 중 가장 큰 수부터 왼쪽 끝에 위치하고, 
 * 그 다음 큰 수가 오른쪽의 끝에 위치한다. 그리고 세 번째로 큰 수가 왼쪽 끝에 위치한 수의 오른쪽에 위치한다. 네 번째로 큰 수는 오른쪽 끝에
 * 위치한 수의 왼쪽에 위치한다. 이런식으로 왼쪽 오른쪽 번갈아가며 수를 위치하다보면 가장 작은 수가 가운데에 위치한다. 이런식으로 수를 정렬해보자.
 * 예를 들면 10, 34, 54, 41, 28 이라는 5개의 숫자가 있을때, 위의 방식과 같이 정렬되면 54, 34, 10, 28, 41 이렇게 정렬된다.
 * 이렇게 정렬된 수를 출력하여 제대로 정렬됬는지 확인해보자.
 * 똑똑한 여러분들이라면 이 문제를 쉽게 해결 할 수 있을 것이다. 
 *
 * (참고!) 노파심에 하는 말이지만 C언어에서는 배열 크기 지정시 변수값을 이용해 크기 지정이 불가능한 것을 명심하자.
 */

int input_Number_Of_Numbers();
void input_Array(int* array, int number_Of_Numbers);
void cross_Sort(int* array, int number_Of_Numbers);
void print_Array(int* array, int number_Of_Numbers);

int main() {
	int number_Of_Numbers = input_Number_Of_Numbers(); // 숫자들의 개수
	int number_Array[30] = { 0 }; // 배열 모두 0으로 초기화
	input_Array(number_Array, number_Of_Numbers);
	cross_Sort(number_Array, number_Of_Numbers);
	print_Array(number_Array, number_Of_Numbers);
	
	return 0;
}


int input_Number_Of_Numbers() { // 입력받을 숫자 개수
	int receive_Number_Of_Numbers;
	scanf("%d", &receive_Number_Of_Numbers);
	return receive_Number_Of_Numbers;
}

void input_Array(int* array, int number_Of_Numbers) { // 배열에 숫자들을 저장
	int input_Count = 0;
	while (input_Count < number_Of_Numbers) {
		scanf("%d", &array[input_Count]);
		++input_Count;
	}
}

void cross_Sort(int* array, int number_Of_Numbers) { // 좌, 우로 번갈아가며 정렬하는 함수
	int max_Value; // 최대 값
	int max_Value_Index = 0;
	int distance_From_Edge = 0;
	int index;
	while (distance_From_Edge < ((number_Of_Numbers + 1) / 2)) {
		// 왼쪽 정렬
		index = distance_From_Edge + 1;
		max_Value = array[distance_From_Edge];
		while (index < (number_Of_Numbers - distance_From_Edge)) { 
			if (array[index] >= max_Value) {
				max_Value = array[index];
				max_Value_Index = index;
			}
			++index;
		}
		array[max_Value_Index] = array[distance_From_Edge];
		array[distance_From_Edge] = max_Value;
		
		// 오른쪽 정렬
		index = ((number_Of_Numbers - 1) - distance_From_Edge) - 1;
		max_Value = array[(number_Of_Numbers - 1) - distance_From_Edge];
		while (index > distance_From_Edge) {
			if (array[index] >= max_Value) {
				max_Value = array[index];
				max_Value_Index = index;
			}
			--index;
		}
		array[max_Value_Index] = array[(number_Of_Numbers - 1) - distance_From_Edge];
		array[(number_Of_Numbers - 1) - distance_From_Edge] = max_Value;
		++distance_From_Edge;
	}
}

void print_Array(int* array, int number_Of_Numbers) { // 배열 출력
	int print_Array_Index = 0;
	while (print_Array_Index < number_Of_Numbers) {
		printf("%d ", array[print_Array_Index]);
		++print_Array_Index;
	}
}