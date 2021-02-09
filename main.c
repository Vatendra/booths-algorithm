/*
Demonstration of Booth's Algorithm.
*/
#include<stdlib.h>
#include<stdio.h>
char* getBinary(int, int); // Takes a decimal number and bit size as input and returns binary vlaues in form of char array.
char* getComplement(char*, int); // Takes a char array of binary value and its length and returns its 2's complement.
char* stepOver(char*, char*, char*, char Q, int); // Takes m,q,accumulator,Q, n as input to perform solution.
int main(){
	int m,q,n,i;
	char Q='0'; // One bit register for storing Q(-1)
	char *binaryM, *binaryQ, *accumulator;
	printf("-----------Booth's Algorithm-----------\n");
	printf("Input Multiplicand: ");
	scanf("%d",&m);
	printf("Input Multiplier: ");
	scanf("%d",&q);
	printf("Input Bit Size: ");
	scanf("%d",&n);
	// Convert multiplicand and multiplier to binary
	binaryM = getBinary(m, n);
	binaryQ = getBinary(q, n);
	if(m<0){
		binaryM = getComplement(binaryM, n);
	}
	if(q<0){
		binaryQ = getComplement(binaryQ, n);
	}
	// Initilize accumulator
	accumulator = (char*) malloc(sizeof(char)*(n+1));
	for(i=0;i<n;i++){
		accumulator[i] = '0';
	}
	accumulator[n] = '\0';
	printf("Initial Values are...\n");
	printf("Multiplicand: %s\nMultiplier: %s\nBit Size: %d\n",binaryM, binaryQ, n);
	return 0;
}
char *getBinary(int a, int n){
	char *binaryValue;
	binaryValue = (char*) malloc(sizeof(char)*(n+1));
	binaryValue[n]='\0';
	while(n>0){
		n--;
		if(a%2==0){
			binaryValue[n]='0';
		}
		else{
			binaryValue[n]='1';
		}
		a=a/2;
	}
	return binaryValue;
}
char *getComplement(char *arr, int n){
        //First calculate 1's complement by inversion.
        int i, temp='1';
        printf("\nBefore: %s\n",arr);
        while(n>=0){
                n--;
                if(arr[n]=='0'){
                        arr[n]='1';
                }
                else{
                        arr[n]='0';
                }
                if(arr[n]=='0'){
                        arr[n]=temp;
                        temp='0';
                }
                else{
                        if(temp=='1'){
                                arr[n]='0';
                        }
                }
        }
        return arr;
}
char* stepOver(char *m, char *q, char *a, char Q, int n){
	if(n==0){ // base call
		return;
	}
}
