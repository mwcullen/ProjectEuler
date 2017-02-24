#include <stdio.h>
#include <string.h>

long long int ArrayProduct13(int []);
int * StringToArray(char *, size_t);

int main() {
	char inputString[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	size_t stringSize = strlen(inputString);
	long long int largestproduct=0;
	long long int tempproduct=0;
	int * numArray;

	int i;
	for(i=0; i<stringSize-13; i++) {
		numArray = StringToArray(&inputString[i], 13);
		tempproduct= ArrayProduct13(numArray);
		if (tempproduct> largestproduct)
			largestproduct=tempproduct;
	}

	printf("%lld\n", largestproduct);

	return 0;
}

long long int ArrayProduct13 (int array[]){
	long long int product = 1;
	int i;

	for(i = 0; i<13; i++) {
		if (array[i] == 0)
			return 0;
		product *= array[i];
	}

	return product;
}

int * StringToArray(char * string, size_t string_length) {
	static int numArray[13];
	int i;
	
	for(i=0; i<= string_length; i++) {
		numArray[i] = string[i] - '0';
	}
	
	return numArray;
}

