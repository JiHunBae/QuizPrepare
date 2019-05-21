#include <stdio.h>

void run();
void input_String(char* string);
int calc_Sum_ASCII(char* string);

#define MAX_STRING_SIZE 21

int main() {
	run();
}

void run() {
	char string[MAX_STRING_SIZE] = { 0 }; // ���ڿ�
	input_String(string);
	int sum_ASCII_Value = calc_Sum_ASCII(string); // �ƽ�Ű �ڵ� �� ���
	printf("%d", sum_ASCII_Value); // �ƽ�Ű�ڵ� �� ���
}

void input_String(char* string) {
	fgets(string, MAX_STRING_SIZE, stdin);
}

int calc_Sum_ASCII(char* string) {
	int index_Of_String = 0; // ���ڿ��� �ε���
	int sum_Of_ASCII = 0; // �ƽ�Ű�ڵ��� ��
	
	while (string[index_Of_String] != 0) { // ���ڿ��� ������ NULL�� ����Ǿ������� �̿�
		sum_Of_ASCII += string[index_Of_String];
		++index_Of_String;
	}

	return sum_Of_ASCII;
}