#include <stdio.h>
#include <string.h>

// Function to find LCS and print the LCS string
void printLCS(char *X, char *Y, int m, int n) {
    int dp[m+1][n+1];

    // Build the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }

    // Length of LCS
    int lcs_length = dp[m][n];

    // Create an array to store the LCS string
    char lcs[lcs_length + 1];
    lcs[lcs_length] = '\0'; // Null terminate

    // Backtrack to find the LCS string
    int i = m, j = n, index = lcs_length - 1;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index] = X[i - 1]; // Store character in LCS
            i--; j--; index--;     // Move diagonally up-left
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--; // Move up
        else
            j--; // Move left
    }

    // Print the LCS length and string
    printf("Length of LCS: %d\n", lcs_length);
    printf("LCS String: %s\n", lcs);
}

// Driver code
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printLCS(X, Y, m, n);

    return 0;
}
