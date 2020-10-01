// C++ program to implement Rabin-Karp string pattern
// matching algorithm

#include <bits/stdc++.h>
using namespace std;

void searchPattern(char text[], char pattern[], int q) {

	int d = 256;
	int n = strlen(text), m = strlen(pattern);
	int p = 0;	// to store hash value of pattern
	int t = 0;	// to store hash value of text
	int i, j;
	int h = 1;

	for (i=0; i<m-1; i++)
		h = (h * d);
	h = h % q;

	// calculate initial hash values of pattern and text of size m
	for(i=0; i<m; i++) {
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
	}

	// slide pattern over text one by one
	for (i = 0; i <= n-m; i++) {
		// iff p is equal to t
		// then check the characters one by one
		if (p == t) {
			for (j = 0; j < m; j++) 
				if (pattern[j] != text[i+j])
					break;

			if (j == m)
				cout << "Pattern found in the text at index: " << i << endl;
		}

		// move to the next substring of length m
		if (i < n-m) {
			// this line of code removes the higher order character
			// and adds the lower order character
			t = (d * (t - h * text[i]) + text[i + m]) % q;

			if (t < 0)
				t = t + q;
		}
	} 

}

int main() {
	char text[] = "abcdacbcabcabcbabcdeaca";
	char pattern[] = "abc";
	int prime = 101;
	searchPattern(text, pattern, prime);

	return 0;
} 