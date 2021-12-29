// OSII Project.cpp 
// Memory Allocation Simulator
// By: Amir Ayman Nabil 2019/12710
//     Remon Ibrahim Grees 2019/08077
//

#include <iostream>
using namespace std;

void start();
void firstfit();
void bestfit();
void worstfit();
void output(int blkNo, int blkSz[], int marks[], int alloc[], int prSz[]);


int main()
{
	//to start the simulator of memmory allocation
	start();
}

void start() {
	int alg;
	cout << "Enter the number of algorithm you want to use:\n";
	// to choose firstFit algorithm function
	cout << "1- First Fit ";
	// to choose bestFit algorithm function
	cout << ", 2- Best Fit ";
	// to choose worstFit algorithm function
	cout << ", 3- Worst Fit \n";
	while (true) {
		cin >> alg;
		if (alg == 1) {
			firstfit();
		}
		else if (alg == 2) {
			bestfit();
		}
		else if (alg == 3) {
			worstfit();
		}
		else {
			break;
		}

		// to choose firstFit algorithm function
		cout << "1- First Fit ";
		// to choose bestFit algorithm function
		cout << ", 2- Best Fit ";
		// to choose worstFit algorithm function
		cout << ", 3- Worst Fit ";
		// to choose to end the simulator
		cout << ", choose another number to end\n";
	}
	cout << "Thanks to use our simulator!! \n By: Amir Ayman 2019/12710 \n     Remon Ibrahim 2019/08077";


}

void firstfit() {
	cout << "Your choice is FirstFit Algorithm \n";

	int blkSz[200], prSz[200], blkNo, prNo, marks[200], alloc[200];

	for (int q = 0; q < 200; q++)
	{
		marks[q] = 0;
		alloc[q] = -1;
	}
	cout << "Enter No. of Blocks: ";
	cin >> blkNo;
	cout << endl;
	cout << "Enter Size for every block: \n";
	for (int q = 0; q < blkNo; q++)
		cin >> blkSz[q];

	cout << endl;
	cout << "Enter No. of Processes: ";
	cin >> prNo;

	cout << endl;
	cout << "Enter size for every process: \n";
	for (int q = 0; q < prNo; q++)
		cin >> prSz[q];

	for (int q = 0; q < prNo; q++) {         // bn7ot el processes f el blocks b fisrtfit
		for (int w = 0; w < blkNo; w++)
			if (marks[w] == 0 && blkSz[w] >= prSz[q]) /// marks to check the avalability of the block space
			{
				alloc[w] = q;
				marks[w] = 1;
				break;
			}
	}
	output(blkNo, blkSz, marks, alloc, prSz);
}
void bestfit() {
	cout << "Your choice is BestFit Algorithm \n";

	int blkSz[200], prSz[200], blkNo, prNo, marks[200], alloc[200];

	for (int q = 0; q < 200; q++)
	{
		marks[q] = 0;
		alloc[q] = -1;
	}
	cout << "Enter No. of Blocks: ";
	cin >> blkNo;
	cout << endl;
	cout << "Enter Size for every block: \n";
	for (int q = 0; q < blkNo; q++)
		cin >> blkSz[q];

	cout << endl;
	cout << "Enter No. of Processes: ";
	cin >> prNo;

	cout << endl;
	cout << "Enter size for every process: \n";
	for (int q = 0; q < prNo; q++)
		cin >> prSz[q];
	for (int q = 0; q < prNo; q++)
	{
		// Find the best fit block for current process
		int temp = 0, flag = -1;
		for (int w = 0; w < blkNo; w++)
		{
			if (marks[w] == 0)
			{
				if (prSz[q] == blkSz[w] || (prSz[q] <= blkSz[w] && (blkSz[w] <= temp || temp == 0))) {
					temp = blkSz[w];
					flag = w;
				}
			}
		}

		if (flag != -1)
		{
			// allocate block j to p[q] process
			alloc[flag] = q;
			marks[flag] = 1;

		}
		flag = -1;
		temp = 0;
	}
	output(blkNo, blkSz, marks, alloc, prSz);

}
void worstfit()
{
	cout << "Your choice is WorstFit Algorithm \n";

	int blkSz[200], prSz[200], blkNo, prNo, marks[200], alloc[200];

	for (int q = 0; q < 200; q++)
	{
		marks[q] = 0;
		alloc[q] = -1;
	}
	cout << "Enter No. of Blocks: ";
	cin >> blkNo;
	cout << endl;
	cout << "Enter Size for every block: \n";
	for (int q = 0; q < blkNo; q++)
		cin >> blkSz[q];

	cout << endl;
	cout << "Enter No. of Processes: ";
	cin >> prNo;

	cout << endl;
	cout << "Enter size for every process: \n";
	for (int q = 0; q < prNo; q++)
		cin >> prSz[q];

	for (int q = 0; q < prNo; q++)
	{
		// Find the best fit block for current process
		int temp = 0, flag = -1;
		for (int w = 0; w < blkNo; w++)
		{
			if (marks[w] == 0)
			{
				if (prSz[q] <= blkSz[w] && blkSz[w] >= temp) {
					temp = blkSz[w];
					flag = w;
				}
			}
		}

		if (flag != -1)
		{
			// allocate block j to p[q] process
			alloc[flag] = q;
			marks[flag] = 1;

		}
		flag = -1;
	}
	output(blkNo, blkSz, marks, alloc, prSz);
}

void output(int blkNo, int blkSz[], int marks[], int alloc[], int prSz[]) {
	cout << "\nBlock no.\tsize\t\tprocess no.\t\tsize";
	for (int q = 0; q < blkNo; q++)
	{
		cout << "\n" << q + 1 << "\t\t" << blkSz[q] << "\t\t";
		if (marks[q] == 1)
			cout << alloc[q] + 1 << "\t\t\t" << prSz[alloc[q]];
		else
			cout << "Not allocated";
	}
	cout << "\n\n\n";
}
