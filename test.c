#include <stdio.h>
#include <stdlib.h>

// 写一个函数返回参数二进制中 1 的个数
// 比如: 15  0000 1111    4 个 1 

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
		n &= n - 1;// 每&一次 消一个1 => 数 1 的个数
		count++;
	}
	return count;
}

int count_1(int n){
	// 数 1 操作
	//     奇数位上的 1  +  偶数位上的 1 = 两位两位地数 对应的两位上有几个1
	n = (n & 0x55555555) + (n >> 1 & 0x55555555);// 0101 
	//  看每 4 位上有几个1
	n = (n & 0x33333333) + (n >> 2 & 0x33333333);// 0011
	// 每 8 位上有几个 1
	n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);// 0000 1111
	// 看 16 位上有几个 1
	n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);// 0000 0000 1111 1111
	// 看 32 位上有几个 1
	n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);// 0000 0000 0000 0000 ...
	
	return n;
}
int main(){
	int n = 310879183;

	printf("%d\n", count_1(n));// 16个1

	system("pause");
	return 0;
}