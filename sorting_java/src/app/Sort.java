package app;

class Sort
{
    static void merge(int array[], int left, int mid, int right) 
    { 
        int n1 = mid - left + 1; 
        int n2 = right - mid; 
        
        int Left[] = new int [n1]; 
        int Right[] = new int [n2]; 
        
        for (int i=0; i<n1; ++i)
        {
            Left[i] = array[left + i];
        } 

        for (int j=0; j<n2; ++j)
        {
            Right[j] = array[mid + 1+ j];
        } 
  
        int i = 0, j = 0; 
        int k = left;

        while (i < n1 && j < n2) 
        { 
            if (Left[i] <= Right[j]) 
            { 
                array[k] = Left[i]; 
                i++; 
            } 
            else
            { 
                array[k] = Right[j]; 
                j++; 
            } 
            k++; 
        } 
  
     
        while (i < n1) 
        { 
            array[k] = Left[i]; 
            i++; 
            k++; 
        } 
  
        while (j < n2) 
        { 
            array[k] = Right[j]; 
            j++; 
            k++; 
        } 
    } 

    static void mergesort(int array[], int left, int right) 
    { 
        if (left < right) 
        { 
            int mid = (left+right)/2; 
            mergesort(array, left, mid); 
            mergesort(array , mid+1, right); 
            merge(array, left, mid, right); 
        } 
    }

    static void bubbleSort(int array[]) 
    { 
        int n = array.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (array[j] > array[j+1]) 
                {  
                    int temp = array[j]; 
                    array[j] = array[j+1]; 
                    array[j+1] = temp; 
                } 
    } 
}