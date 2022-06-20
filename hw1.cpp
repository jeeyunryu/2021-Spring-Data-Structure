#include <iostream>


void my_sort(int s[], int n) {

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			
			int temp;
			if (s[j] > s[j + 1]) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			
			}
			
			
		}

	}
	
}

int main() {
	int list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
	int i;
	
	my_sort(list, 10);
	for (i = 0; i < 10; i++)
		std::cout << list[i] << "\n";
	return 0;
}