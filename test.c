#include <stdio.h>
#include <stdlib.h>

// дһ���������ز����������� 1 �ĸ���
// ����: 15  0000 1111    4 �� 1 

int count_1Easy(int n){
	
	int count = 0;

	int i;
	for (i = n; i; i /= 2){
		count += i % 2;
	}
	return count;

}

int count_1Normal(int n){

	int count = 0;
	while (n){
		n &= n - 1;// ÿ&һ�� ��һ��1 => �� 1 �ĸ���
		count++;
	}
	return count;
}

int count_1(int n){
	// �� 1 ����
	//     ����λ�ϵ� 1  +  ż��λ�ϵ� 1 = ��λ��λ���� ��Ӧ����λ���м���1
	n = (n & 0x55555555) + (n >> 1 & 0x55555555);// 0101 
	//  ��ÿ 4 λ���м���1
	n = (n & 0x33333333) + (n >> 2 & 0x33333333);// 0011
	// ÿ 8 λ���м��� 1
	n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);// 0000 1111
	// �� 16 λ���м��� 1
	n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);// 0000 0000 1111 1111
	// �� 32 λ���м��� 1
	n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);// 0000 0000 0000 0000 ...
	
	return n;
}
int main(){
	int n = 310879183;

	printf("%d\n", count_1(n));// 16��1

	system("pause");
	return 0;
}