#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#define LEN 1000
#define C 100
#define L 20


int cmp(const void *a, const void *b){
	const wchar_t* f = *(const wchar_t **)a;
	const wchar_t* s = *(const wchar_t **)b;
	return wcscasecmp(f, s);
}

int main(){
	setlocale(LC_ALL, "");

	//read all
	wchar_t *str = malloc(LEN*sizeof(wchar_t));
	fgetws(str, LEN, stdin);

	//def word
	wchar_t *dw = malloc(L*sizeof(wchar_t));
	wchar_t *reverse = malloc(L*sizeof(wchar_t));
	
	//arr wwords
	wchar_t **wwords = malloc(C*sizeof(wchar_t*));

	//ppartition
	wchar_t *pt; //pointer for wcstok
	wchar_t *w = wcstok(str, L" ", &pt);
	int len = 0;
	while (w){
		*(wwords+len++) = w;
		w = wcstok(NULL, L" ", &pt);
	}

	//get word
	dw = wwords[len-1];
	int lendw = wcslen(dw);
	//wprintf(L"%d-len\n", lendw);
	if (lendw<L-1)
		dw[lendw-1] = L'\0';

	//get reverse word
	for (int i = 0; i < lendw-1; i++){
		*(reverse + i) = *(dw+lendw-2-i);
	}
	//wprintf(L"dw=%ls\trev=%ls\n", dw, reverse);

	//bsearch
	wchar_t **pos1 = (wchar_t**)bsearch(&dw, wwords, len-1, sizeof(wchar_t*), cmp);
	wchar_t **pos2 = (wchar_t**)bsearch(&reverse, wwords, len-1, sizeof(wchar_t*), cmp);
	if (pos1 || pos2)
		wprintf(L"yes\n");
	else
		wprintf(L"no\n");

	return 0;
}
