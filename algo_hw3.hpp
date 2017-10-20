// change this to your id
static const char* student_id = "0416001";


// do not edit prototype
void LCS(int *, int*, int*);

// X,Y are input strings, C is answer string
//
// data structure :
// length of array X is m+1, length of array Y is n+1, length of array C is m+n
// X[0] = m+1, Y[0] = n+1,
// all element of C are "-1"
// other datas are in [0,255] means the symble in ASCII or ANSI table


// you only allow declare a table with size (m+1)*(n+1)
//
// do your homework here
//

void print_lcs_improved(int ** c, int * ans, int * x, int * y, int i, int j, int length)
{
	if (i == 0 || j == 0)
		return;
	else if (x[i] == y[j])
	{
		ans[length] = x[i];
		print_lcs_improved(c, ans, x, y, i - 1, j - 1, length - 1);
		return;
	}
	else if (c[i][j - 1] > c[i - 1][j])
	{
		print_lcs_improved(c, ans, x, y, i, j - 1, length);
		return;
	}
	else
	{
		print_lcs_improved(c, ans, x, y, i - 1, j, length);
	}
	return;
}

void LCS(int* X, int* Y, int* C)
{
	int x_size = X[0];
	int y_size = Y[0];

	//initiate table value to 0
	int **c_table = new int *[x_size];
	for (int i = 0; i < (x_size); i++)
		c_table[i] = new int[y_size];

	for (int i = 0; i < x_size; i++)
		c_table[i][0] = 0;
	for (int j = 1; j < y_size; j++)
		c_table[0][j] = 0;

	//In O(m*n) way
	for (int i = 1; i < x_size; i++)
		for (int j = 1; j < y_size; j++)
		{
			if (X[i] == Y[j])
			{
				c_table[i][j] = c_table[i - 1][j - 1] + 1;
			}
			else if (c_table[i][j - 1] > c_table[i - 1][j])
			{
				c_table[i][j] = c_table[i][j - 1];
			}
			else
			{
				c_table[i][j] = c_table[i - 1][j];
			}
		}
	int k_length = c_table[x_size - 1][y_size - 1];
	print_lcs_improved(c_table, C, X, Y, x_size - 1, y_size - 1, k_length - 1);
	delete c_table;
}