#include <stdio.h> //pour pouvoir utiliser printf et scanf

int main(void){
	for (int i = 0, s = 0; i < 5; s += i, ++i) { 
		printf("%d, %d\n", i, s); 
	}	
}	

//out:
// 0, 0
// 1, 0
// 2, 1
// 3, 3
// 4, 6