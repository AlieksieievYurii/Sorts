#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double timerExecuting(clock_t end);
void Executing(int *Array, int n, int modeOfSort);
void generationNumber(int * Array, int n, char argArray);
void printArray(int * Array, int n);
void writeToFile(int modeOfSort, int argArray,int n, double time);
void writeModeInfAboutArrayToFile(int modeOfSort, int argArray);

void InsertionSortFunction(int * Array, int n);
void ShellSortFunction(int * Array, int n);
void SelectionSortFunction(int * Array, int n);
void QuickSortFunction(int * Array, int n);
void BubbleSortFunction(int * Array, int n);
void BubbleSortFlagFunction(int * Array, int n);

FILE *InsertionSort;
FILE *ShellSort;
FILE *QuickSort;
FILE *SelectionSort;
FILE *BubbleSort;
FILE *BubbleSortFlag;

int main(void)
{
	int startPoint,endPoint,step,modeOfSort = 0;//modeOfSort has 0 it means first mode of sorting
	int argArray = 0;//It means mode of already sort
	double timeEnd;

	srand((unsigned)time(NULL));


	printf("[*] Enter start number:");scanf("%d",&startPoint);
	printf("[*] Enter end number:");scanf("%d",&endPoint);
	printf("[*] Enter step:");scanf("%d",&step);

	InsertionSort = fopen("Files/InsertionSort.txt","w");//ModeOfSort must be 0
	ShellSort = fopen("Files/ShellSort.txt","w");//ModeOfSort must be 1
	SelectionSort = fopen("Files/SelectionSort.txt","w");//ModeOfSort must be 2
	QuickSort = fopen("Files/QuickSort.txt","w");//ModeOfSort must be 3
	BubbleSort = fopen("Files/BubbleSort.txt","w");//ModeOfSort must be 4
	BubbleSortFlag = fopen("Files/BubbleSortFlag.txt","w");//ModeOfSort must be 5

	while(modeOfSort <= 5)//Count of type sorts
	{
		
		printf("Mode of sotr:%d\n",modeOfSort);

		while(argArray < 3)//Count of type ready sorts for array
		{
			printf("  -- Array with mode:%d\n",argArray);
			writeModeInfAboutArrayToFile(modeOfSort,argArray);

			for(int n = startPoint; n <= endPoint; n+= step)
			{
				int *Array = malloc(sizeof(int)*n);
				generationNumber(Array,n,argArray);

				clock_t begin = clock();
					Executing(Array,n,modeOfSort);
				timeEnd = timerExecuting(begin);

				printf("\nFor %d --> %f\n",n,timeEnd);

				writeToFile(modeOfSort,argArray,n,timeEnd);

				free(Array);
			}
			argArray++;
		}
		argArray = 0;
		switch(modeOfSort)
		{
			case 0:fclose(InsertionSort);break;
			case 1:fclose(ShellSort);break;
			case 2:fclose(SelectionSort);break;
			case 3:fclose(QuickSort);break;
			case 4:fclose(BubbleSort);break;
			case 5:fclose(BubbleSortFlag);break;
		}
		modeOfSort++;
	}
}

void writeModeInfAboutArrayToFile(int modeOfSort, int argArray)
{
	switch(modeOfSort)
	{
		case 0:
			switch(argArray)
			{
				case 0:fprintf(InsertionSort,"\n  -I- Array with mode:%d(All numbers are created by random)\n\n",argArray);break;
				case 1:fprintf(InsertionSort,"\n  -I- Array with mode:%d(All numbers are created and already sorted)\n\n",argArray);break;
				case 2:fprintf(InsertionSort,"\n  -I- Array with mode:%d(All numbers can be only 0,1 or 2)\n\n",argArray);break;
			}
		break;

		case 1:
			switch(argArray)
			{
				case 0:fprintf(ShellSort,"\n  -S- Array with mode:%d(All numbers are created by random)\n\n",argArray);break;
				case 1:fprintf(ShellSort,"\n  -S- Array with mode:%d(All numbers are created and already sorted)\n\n",argArray);break;
				case 2:fprintf(ShellSort,"\n  -S- Array with mode:%d(All numbers can be only 0,1 or 2)\n\n",argArray);break;
			}
		break;
		case 2:
			switch(argArray)
			{
				case 0:fprintf(SelectionSort,"\n  -SE- Array with mode:%d(All numbers are created by random)\n\n",argArray);break;
				case 1:fprintf(SelectionSort,"\n  -SE- Array with mode:%d(All numbers are created and already sorted)\n\n",argArray);break;
				case 2:fprintf(SelectionSort,"\n  -SE- Array with mode:%d(All numbers can be only 0,1 or 2)\n\n",argArray);break;
			}
		break;
		case 3:
			switch(argArray)
			{
				case 0:fprintf(QuickSort,"\n  -Q- Array with mode:%d(All numbers are created by random)\n\n",argArray);break;
				case 1:fprintf(QuickSort,"\n  -Q- Array with mode:%d(All numbers are created and already sorted)\n\n",argArray);break;
				case 2:fprintf(QuickSort,"\n  -Q- Array with mode:%d(All numbers can be only 0,1 or 2)\n\n",argArray);break;
			}
		break;
		case 4:
			switch(argArray)
			{
				case 0:fprintf(BubbleSort,"\n  -B- Array with mode:%d(All numbers are created by random)\n\n",argArray);break;
				case 1:fprintf(BubbleSort,"\n  -B- Array with mode:%d(All numbers are created and already sorted)\n\n",argArray);break;
				case 2:fprintf(BubbleSort,"\n  -B- Array with mode:%d(All numbers can be only 0,1 or 2)\n\n",argArray);break;
			}
		break;
		case 5:
			switch(argArray)
			{
				case 0:fprintf(BubbleSortFlag,"\n  -B- Array with mode:%d(All numbers are created by random)\n\n",argArray);break;
				case 1:fprintf(BubbleSortFlag,"\n  -B- Array with mode:%d(All numbers are created and already sorted)\n\n",argArray);break;
				case 2:fprintf(BubbleSortFlag,"\n  -B- Array with mode:%d(All numbers can be only 0,1 or 2)\n\n",argArray);break;
			}
		break;
	}		
}

double timerExecuting(clock_t begin)
{
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	return time_spent;
}

void writeToFile(int modeOfSort, int argArray,int n, double time)
{
	switch(modeOfSort)
	{
		case 0:
			fprintf(InsertionSort, "%d  %f\n",n,time);
		break;

		case 1:
			fprintf(ShellSort, "%d  %f\n",n,time);
		break;

		case 2:
			fprintf(SelectionSort, "%d  %f\n",n,time);
		break;
		
		case 3:
			fprintf(QuickSort, "%d  %f\n",n,time);
		break;

		case 4:
			fprintf(BubbleSort, "%d  %f\n",n,time);
		break;

		case 5:
			fprintf(BubbleSortFlag, "%d  %f\n",n,time);
		break;
	}
}

void generationNumber(int * Array, int n,char argArray)
{	

	switch(argArray)
	{
		case 0:
			for(int i = 0; i < n; i++)
			{
				Array[i] = rand()*rand();
			}
		break;

		case 1:
			for(int i = 0; i < n;i++)
			{
				Array[i] = i;
			}
		break;

		case 2:
			for(int i = 0; i < n; i++)
			{
				Array[i] = rand()%3;
			}
		break;

		default:
			printf("[!] Wrong mode for alread sort array!\n");
			exit(1);
		break;
	}
}


void Executing(int *mass, int n, int modeOfSort)
{

	switch(modeOfSort)
	{
		case 0:
			InsertionSortFunction(mass,n);
		break;

		case 1:
			ShellSortFunction(mass,n);
		break;

		case 2:
			SelectionSortFunction(mass,n);
		break;

		case 3:
			QuickSortFunction(mass,n);
		break;

		case 4:
			BubbleSortFunction(mass,n);
		break;

		case 5:
			BubbleSortFlagFunction(mass,n);
		break;

		default:
			printf("[!] Wrong mode for alread sort array!\n");
			exit(2);
	}
}

//######################################################################
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
 //######################################################################
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void QuickSortFunction(int * Array, int n)
{
	quickSort(Array, 0, n-1);
}

void ShellSortFunction(int * Array, int n)
{
	for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = Array[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
                Array[j] = Array[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            Array[j] = temp;
        }
    }
}

void InsertionSortFunction(int * Array, int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = Array[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && Array[j] > key)
       {
           Array[j+1] = Array[j];
           j = j-1;
       }
       Array[j+1] = key;
   }
}

void SelectionSortFunction(int * Array, int n)
{
	/* a[0] to a[n-1] is the array to sort */
	int i,j;

	/* advance the position through the entire array */
	/*   (could do j < n-1 because single element is also min element) */
	for (j = 0; j < n-1; j++)
	{
	    /* find the min element in the unsorted a[j .. n-1] */

	    /* assume the min is the first element */
	    int iMin = j;
	    /* test against elements after j to find the smallest */
	    for (i = j+1; i < n; i++)
	    {
	        /* if this element is less, then it is the new minimum */
	        if (Array[i] < Array[iMin])
	        {
	            /* found new minimum; remember its index */
	            iMin = i;
	        }
	    }

	    if (iMin != j) 
	    {
	        int buffer = Array[j];
	        Array[j] = Array[iMin];
	        Array[iMin] = buffer;
	    }
	}
}

void BubbleSortFunction(int * Array, int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (Array[j] > Array[j+1])
             {
              swap(&Array[j],&Array[j+1]);
             }
         
}

void BubbleSortFlagFunction(int * Array, int n)
{
   int i, j;
   int flag = 1;
   for (i = 0; i < n-1 && flag; i++)
   {
   	   // Last i elements are already in place
   	   flag = 0;   
       for (j = 0; j < n-i-1; j++) 
           if (Array[j] > Array[j+1])
             {
              swap(&Array[j],&Array[j+1]);
              flag = 1;
             }
   }      
}

void printArray(int * Array, int n)
{
	printf("\n\n");

	for(int i = 0; i < n; i++)
	{
		printf("%d ", Array[i]);
	}

	printf("\n\n");
}
