#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

void quicksort(int *a,int l, int r );
void bubblesort(int *a, int n);
void SelectionSort(int *a, int n);
void MergeSort(int*a, int l, int r);
void InsertionSort(int *a, int n);
void InterchangeSort(int *a, int n);
void BinaryInsertionSort(int *a, int n);
void ShakerSort(int *a, int n);
void CountingSort(int *a, int n);
void HeapSort(int *a, int n);
void shellSort(int *a, int n);
void RadixSort(int *a, int n) ;
void Menu()
{
	cout << "\n\n------------MENU------------\n\n";
	cout << "1. Selection Sort" << endl;
	cout << "2. Interchange Sort" << endl; 
	cout << "3. Insertion sort" << endl;
	cout << "4. Binary Insertion sort" << endl; 
	cout << "5. Bubble sort" << endl;
	cout << "6. Shake/Shaker sort" << endl; 
	cout << "7. Counting Sort" << endl;
	cout << "8. Quick Sort" << endl;
	cout << "9. Merge Sort" << endl;
	cout << "10. Heap Sort " << endl;
	cout << "11. Shell Sort" << endl; 
	cout << "12. Radix Sort" << endl;
}


void generate_Array(int *a, int n)
{
	// random trong [a,b]
	//a + rand() % (b-a+1)
	srand(time(NULL));
	int rd;
	for(int i=0;i<n;i++)
	{
		rd = -10000 + rand() % (20001);
		a[i]=rd;
	}
		
}

void output(int *a, int n)
{
	for(int i=0;i<n ;i++)
		cout << a[i] << " ";
}
int main()
{
	int n ;
	char c;
	cout << "Amount of array: ";
	cin >> n;
	int *a = new int[n];
	int choose;
	do
	{
	generate_Array(a, n);
	Menu();
	cout << "Choose an algorithms: ";
	cin >> choose;
	clock_t start = clock();
	switch (choose)
	{
		case 1:
			SelectionSort(a,n);
			output(a,n); cout << endl << endl;
			break;	
		case 2:
			InterchangeSort(a,n);
			output(a,n); cout << endl << endl;			
			break;
		case 3:
			InsertionSort(a,n);	
			output(a,n); cout << endl << endl;			
			break;
		case 4:
			BinaryInsertionSort(a,n);
			output(a,n); cout << endl << endl;			
			break;
		case 5:
			bubblesort(a,n);
			output(a,n); cout << endl << endl;			
			break;
		case 6:
			ShakerSort(a, n);
			output(a,n); cout << endl << endl;
			break;
		case 7:
			CountingSort(a,n);
			output(a,n); cout << endl << endl;
			break;
		case 8:
			quicksort(a,0,n-1);
			output(a,n); cout << endl << endl;
			break;
		case 9:
			MergeSort(a, 0, n-1);
			output(a,n); cout << "\n\n";
			break;
		case 10:
			HeapSort(a,n);
			output(a,n); cout << "\n\n";
			break;
		case 11:
			shellSort(a,n);
			output(a,n); cout << "\n\n";
			break;
		case 12:
			RadixSort(a,n);
			output(a,n); cout << "\n\n";
			break;			
	}
	clock_t end = clock();
	cout << "\nTime:" << (double) (end-start) / CLOCKS_PER_SEC  << "s" << endl;
	cout << "Do you want to continue choose? (Y/N)\n";
	cin >> c ;
	if(c != 'Y' && c != 'y')
		break;
	}	while(1);

}


//sort
void quicksort(int *a,int l, int r )
{
	int m, x;
	x = a[(l+r)/2]; // gia tri truc
	int i=l, j=r;
	while(i <= j) // khi i chua vuot qua j
	{
	
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <=	 j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}

	}
	if(l < j) 
		quicksort(a,l,j);
	
	if(i < r ) 
		quicksort(a,i,r);

}


//Bubble Sort
void bubblesort(int *a, int n)
{
	for(int i =0; i<n;i++)
		for(int j=0;j<n-1;j++)
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
}

//SelectionSort
void SelectionSort(int *a, int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min =i;
		for(int j=i+1;j<n;j++)
			if(a[min] > a[j])
				swap(a[min], a[j]);} 
}

//interchange sort
void InterchangeSort(int *a, int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}
// merge sort
void Merge(int *a, int m, int l, int r)
{
	int nb = m-l+1, nc = r-m;
	int *b = new int[nb];
	int *c = new int[nc];
	for(int i=0;i<nb;i++)
		b[i] = a[l+i];
	for(int j=0;j < nc;j++)
		c[j] = a[m+1+j];
		
	int i=0, j=0, k=l;
	while(i <nb && j < nc)
	{
		if(b[i] <= c[j])
		{
			a[k] = b[i];
			i ++;
			k++;
		}
	
		if(b[i] > c[j])
		{
			a[k] = c[j];
			j++;
			k++;
		}
	
	}
	
	while(i < nb)
	{
		a[k] = b[i];
		i++;
		k++;
	}
	
	while(j < nc)
	{
		a[k] = c[j];
		j++;
		k++;
	}
}

//sap xep tron
void MergeSort(int *a, int l, int r)
{
	int m;
	if(l < r)
	{
		m = (l+r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		Merge(a,m,l,r);
	}
}


//Insertion sort
void InsertionSort(int *a, int n)
{
	for(int i =1; i<n;i++)
	{
		int x = a[i];
		int j=i-1;
		for( j;j>=0 && x < a[j];j--)
			a[j+1]= a[j];
		a[j+1] = x;
	}
}

//binary Insertion Sort
void BinaryInsertionSort(int *a, int n)
{
	
	for(int i=1;i<n;i++)
	{
		int l =0, r = i-1;
		int x = a[i];
		while(l <= r)
		{
			int m = (l+r)/2;
			int k = a[m];	
			if(x >= k) 
				l = m +1;
			if(x < k) 
				r = m-1;
			
		}
		int j = i-1;
		for( j;j>= l ;j--)
		{
			if(x < a[j])
				a[j+1] = a[j];	
		}
		a[l] = x;
	}
		
}


//shaker sort
void ShakerSort(int *a, int n)
{
	int l =0, r = n-1;
	int k;
	while(l<r)
	{
		int i = l;
		for(i;i<r;i++)
		{
			if(a[i] > a[i+1])
			{
				swap(a[i],a[i+1]);
				k = i;
			}	
		}
		r = k;
		
		int j=r;
		for( j;j>l;j--)
		{
			if(a[j] < a[j-1])
			{
				swap(a[j], a[j-1]);
				k = j;
			}	
				
		}
		l =k;
	}
	
	
}

//couting sort
//source code: https://www.geeksforgeeks.org/radix-sort/ - lay phan countsort

void CountingSort(int* a, int n) {
    int min_val = a[0], max_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        else if (a[i] > max_val) {
            max_val = a[i];
        }
    }
    int k = max_val - min_val + 1;
    int* count = new int[k];
    for (int i = 0; i < k; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[a[i] - min_val]++;
    }
    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }
    int* temp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        temp[count[a[i] - min_val] - 1] = a[i];
count[a[i] - min_val]--;
}
for (int i = 0; i < n; i++) {
a[i] = temp[i];
}
delete[] count;
delete[] temp;
}


//Heap sort
//source copy code: //funix.edu.vn/chia-se-kien-thuc/gioi-thieu-ve-thuat-toan-heap-sort/

void heapify(int *a, int n, int i )
{
	int largest = i;
	int left = 2*i +1;
	int right = 2*i + 2;
	if(left < n && a[left] > a[largest])
		largest = left;
	if(right < n && a[right] > a[largest])
		largest = right;
	if(largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a,n,largest);
	}
	
}

void HeapSort(int *a, int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(int i=n-1;i>=0;i--)
	{
		swap(a[0], a[i]);
		heapify(a,i,0);
	}
}

// Shell Sort
// source code : https://www.geeksforgeeks.org/shellsort/
void shellSort(int *a, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
            int j;            
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

// Radix sort
// source code: https://www.geeksforgeeks.org/radix-sort/
int getMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
 
void countSort(int *a, int n, int exp)
{
    int *output = new int[n]; // output array
    int i, count[10	] = { 0 };

    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
	{
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
 
void RadixSort(int *a, int n)
{

    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp =exp* 10)
        countSort(a, n, exp);
}

