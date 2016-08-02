/*
Plundered From: http://stackoverflow.com/questions/10238699/dynamically-allocating-3d-array
*/


 arr = new int **[height](); //the () causes every field to be initialised with zeroes. (Calloc)
    for (i = 0; i < height; i++)
    {
        arr[i] = new int *[width];
        for (j = 0; j < width; j++)
            arr[i][j] = new int [depth](); //Allocate memory for every layer.
    }
