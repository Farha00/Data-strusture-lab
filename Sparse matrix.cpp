#include <iostream>
using namespace std;

class sparse_matrix
{

	// Maximum number of elements in matrix
	const static int MAX = 100;
	int** data;
	int row, col;
	int len;   // total number of elements in matrix

public:
	sparse_matrix(int r, int c)
	{
		row = r;
		col = c;
		len = 0;
		data = new int* [MAX];
		for (int i = 0; i < MAX; i++)
			data[i] = new int[3];
	}

	void insert(int r, int c, int val)
	{
		if (r > row || c > col)
		{
			cout << "Wrong entry";
		}
		else
		{
			data[len][0] = r;
			data[len][1] = c;
			data[len][2] = val;
			len++;
		}
	}

	void add(sparse_matrix b)
	{
		if (row != b.row || col != b.col)
		{
			cout << "Matrices can't be added";
		}

		else
		{
			int apos = 0, bpos = 0;
			sparse_matrix result(row, col);

			while (apos < len && bpos < b.len)
			{

				if (data[apos][0] > b.data[bpos][0] ||
					(data[apos][0] == b.data[bpos][0] &&
						data[apos][1] > b.data[bpos][1]))

				{
					result.insert(b.data[bpos][0],
						b.data[bpos][1],
						b.data[bpos][2]);

					bpos++;
				}

				else if (data[apos][0] < b.data[bpos][0] ||
					(data[apos][0] == b.data[bpos][0] &&
						data[apos][1] < b.data[bpos][1]))

				{
					result.insert(data[apos][0],
						data[apos][1],
						data[apos][2]);

					apos++;
				}

				else
				{
					int addedval = data[apos][2] +
						b.data[bpos][2];

					if (addedval != 0)
						result.insert(data[apos][0],
							data[apos][1],
							addedval);
					apos++;
					bpos++;
				}
			}
			while (apos < len)
				result.insert(data[apos][0],
					data[apos][1],
					data[apos++][2]);

			while (bpos < b.len)
				result.insert(b.data[bpos][0],
					b.data[bpos][1],
					b.data[bpos++][2]);

			result.print();
		}
	}

	sparse_matrix transpose()
	{
		sparse_matrix result(col, row);
		result.len = len;
		int* count = new int[col + 1];
		for (int i = 1; i <= col; i++)
			count[i] = 0;

		for (int i = 0; i < len; i++)
			count[data[i][1]]++;

		int* index = new int[col + 1];
		index[0] = 0;
		for (int i = 1; i <= col; i++)

			index[i] = index[i - 1] + count[i - 1];

		for (int i = 0; i < len; i++)
		{


			int rpos = index[data[i][1]]++;
			result.data[rpos][0] = data[i][1];
			result.data[rpos][1] = data[i][0];
			result.data[rpos][2] = data[i][2];
		}

		return result;
	}

	void print()
	{
		cout << "\nDimension: " << row << "x" << col;
		cout << "\nSparse Matrix: \nRow\tColumn\tValue\n";

		for (int i = 0; i < len; i++)
		{
			cout << data[i][0] << "\t " << data[i][1]
				<< "\t " << data[i][2] << endl;
		}
	}
};
int main()
{
	sparse_matrix a(4, 4);
	sparse_matrix b(4, 4);

	a.insert(1, 2, 10);
	a.insert(1, 4, 12);
	a.insert(3, 3, 5);
	a.insert(4, 1, 15);
	a.insert(4, 2, 12);
	b.insert(1, 3, 8);
	b.insert(2, 4, 23);
	b.insert(3, 3, 9);
	b.insert(4, 1, 20);
	b.insert(4, 2, 25);
	cout << "Addition: ";
	a.add(b);
	cout << "\nTranspose: ";
	sparse_matrix atranspose = a.transpose();
	atranspose.print();
}