#define LOCAL_SIZE 16 // Размер локального буфера

__kernel void multiply(
    __global int* A,
    __global int* B,
    __global int* C,
    const int size
) {
    // Индексы для текущего рабочего элемента
    unsigned int global_col = get_global_id(0); // Индекс столбца в глобальной матрице C
    unsigned int global_row = get_global_id(1); // Индекс строки в глобальной матрице C
    
    // Локальные индексы
    unsigned int local_col = get_local_id(0); 
    unsigned int local_row = get_local_id(1);
    
    // Локальные буферы для хранения подматриц A и B
    __local int localA[LOCAL_SIZE][LOCAL_SIZE];
    __local int localB[LOCAL_SIZE][LOCAL_SIZE];

    int result = 0;

    // Блочное умножение
    for (unsigned int k = 0; k < size / LOCAL_SIZE; k++) {
        const unsigned int tiled_col = k * LOCAL_SIZE + local_col;
        const unsigned int tiled_row = k * LOCAL_SIZE + local_row;

        // Загружаем подматрицы из глобальной памяти в локальную
        localA[local_row][local_col] = A[global_row * size + tiled_col];
        localB[local_row][local_col] = B[tiled_row * size + global_col];

        // Синхронизация рабочих элементов, чтобы локальные буферы были загружены
        barrier(CLK_LOCAL_MEM_FENCE);

        // Перемножаем локальные подматрицы
        for (unsigned int i = 0; i < LOCAL_SIZE; i++) {
            result += (localA[local_row][i] * localB[i][local_col]);
        }

        // Синхронизация рабочих элементов перед загрузкой новых данных
        barrier(CLK_LOCAL_MEM_FENCE);
    }
    
    // Записываем результат в глобальную память
    C[global_row * size + global_col] = result;
}