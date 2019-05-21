#include <stdio.h>
/* 
 * �Է��� �� ù �ٿ� ���ڵ��� ������ �־�����. �� �� ���� �ٿ� ���ڵ��� �־�����.. �־��� ���� �� ���� ū ������ ���� ���� ��ġ�ϰ�, 
 * �� ���� ū ���� �������� ���� ��ġ�Ѵ�. �׸��� �� ��°�� ū ���� ���� ���� ��ġ�� ���� �����ʿ� ��ġ�Ѵ�. �� ��°�� ū ���� ������ ����
 * ��ġ�� ���� ���ʿ� ��ġ�Ѵ�. �̷������� ���� ������ �����ư��� ���� ��ġ�ϴٺ��� ���� ���� ���� ����� ��ġ�Ѵ�. �̷������� ���� �����غ���.
 * ���� ��� 10, 34, 54, 41, 28 �̶�� 5���� ���ڰ� ������, ���� ��İ� ���� ���ĵǸ� 54, 34, 10, 28, 41 �̷��� ���ĵȴ�.
 * �̷��� ���ĵ� ���� ����Ͽ� ����� ���ĉ���� Ȯ���غ���.
 * �ȶ��� �����е��̶�� �� ������ ���� �ذ� �� �� ���� ���̴�. 
 *
 * (����!) ���Ľɿ� �ϴ� �������� C������ �迭 ũ�� ������ �������� �̿��� ũ�� ������ �Ұ����� ���� �������.
 */

int input_Number_Of_Numbers();
void input_Array(int* array, int number_Of_Numbers);
void cross_Sort(int* array, int number_Of_Numbers);
void print_Array(int* array, int number_Of_Numbers);

int main() {
	int number_Of_Numbers = input_Number_Of_Numbers(); // ���ڵ��� ����
	int number_Array[30] = { 0 }; // �迭 ��� 0���� �ʱ�ȭ
	input_Array(number_Array, number_Of_Numbers);
	cross_Sort(number_Array, number_Of_Numbers);
	print_Array(number_Array, number_Of_Numbers);
	
	return 0;
}


int input_Number_Of_Numbers() { // �Է¹��� ���� ����
	int receive_Number_Of_Numbers;
	scanf("%d", &receive_Number_Of_Numbers);
	return receive_Number_Of_Numbers;
}

void input_Array(int* array, int number_Of_Numbers) { // �迭�� ���ڵ��� ����
	int input_Count = 0;
	while (input_Count < number_Of_Numbers) {
		scanf("%d", &array[input_Count]);
		++input_Count;
	}
}

void cross_Sort(int* array, int number_Of_Numbers) { // ��, ��� �����ư��� �����ϴ� �Լ�
	int max_Value; // �ִ� ��
	int max_Value_Index = 0;
	int distance_From_Edge = 0;
	int index;
	while (distance_From_Edge < ((number_Of_Numbers + 1) / 2)) {
		// ���� ����
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
		
		// ������ ����
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

void print_Array(int* array, int number_Of_Numbers) { // �迭 ���
	int print_Array_Index = 0;
	while (print_Array_Index < number_Of_Numbers) {
		printf("%d ", array[print_Array_Index]);
		++print_Array_Index;
	}
}