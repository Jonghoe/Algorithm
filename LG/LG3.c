#include<stdio.h>
#include<string.h>
char Word[2][500000];
int kmp[500000] = { 0 };
int Len;
int KMP(){
	int i = 0,j=0;
	for (int i = 0; i < Len; ++i){
		if (Word[1][i] == Word[0][0]){
			for (j = 0; j < Len; ++j)
				if (Word[1][(i + j)%Len] == Word[0][j])
					kmp[(i + j)%Len] = j;
				else{
					i = i + j - 1;
					break;
				}
			if (j == Len)
				return i;
		}
		else
			kmp[i] = -1;
	}
	return -1;
}

int main(){
	int Case;
	FILE* IF = fopen("input.txt", "r");
	FILE* OF = fopen("output.txt", "w");
	fscanf(IF,"%d", &Case);
	while (Case--){
		int i;
		fscanf(IF,"%d", &Len);
		for (i = 0; i < 2; ++i)
			fscanf(IF,"%s", &Word[i]);
		fprintf(OF,"%d\n",KMP(Word[0], Word[1], Len, kmp));
	}
	fclose(IF);
	fclose(OF);
	return 0;

}