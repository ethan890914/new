// A Dynamic Programming based C++ program to find minimum 
// number operations to convert str1 to str2 
// #include <bits/stdc++.h>
#include <stdio.h> 
#include <string.h>
// using namespace std;


// Utility function to find the minimum of three numbers 
int min(int x, int y, int z) 
{ 
	if(x < y && x < z)
		return x;
	if(y < z)
		return y;
	return z;
	 
} 

int editDistDP(char str1[], char str2[], int m, int n) 
{ 
	// Create a table to store results of subproblems 
	int dp[m + 1][n + 1]; 

	// Fill d[][] in bottom up manner 
	for (int i = 0; i <= m; i++) { 
		for (int j = 0; j <= n; j++) { 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i == 0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j == 0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (str1[i - 1] == str2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
								dp[i - 1][j], // Remove 
								dp[i - 1][j - 1]); // Replace 
		} 
	} 
	for(int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	return dp[m][n]; 
} 

// Driver program 
int main() 
{ 
	// your code goes here 
	char str1[] = "sunday"; 
	char str2[] = "saturday"; 

	printf("%d", editDistDP(str1, str2, strlen(str1),strlen(str2))); 

	return 0; 
} 
