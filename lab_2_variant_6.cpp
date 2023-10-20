// Задана символьная матрица размером NxM.
// Определить количество различных элементов матрицы (т.е. повторяющиеся элементы считать один раз).

#include <iostream>
#include <ctime>

int main()
{
    // Seed
    std::srand(std::time(nullptr));

    // The matrix size
    int N, M;
    std::cout << "N: ";
    std::cin >> N;
    std::cout << "M: ";
    std::cin >> M;

    // Check the matrix size
    if (N <= 0 || M <= 0)
    {
        std::cout << "Wrong size!";
        return 1;
    }

    // Create the matrix
    char** A = new char*[N];
    for (int i = 0; i < N; ++i)
    {
        A[i] = new char[M];
    }

    // Fill the matrix with randomly selected letters A-Z
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            A[i][j] = static_cast<char>(std::rand() % 26 + 65);

    // Print the matrix
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            std::cout << A[i][j];
        std::cout << '\n';
    }

    // Find different elements and count them
    char* different_elements_array = new char[N * M];
    int different_count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char current_element = A[i][j];
            bool is_different = true;

            for (int k = 0; k < different_count; ++k)
            {
                if (different_elements_array[k] == current_element)
                {
                    is_different = false;
                    break;
                }
            }

            if (is_different)
            {
                different_elements_array[different_count] = current_element;
                ++different_count;
            }
        }
    }

    std::cout << "Number of different elements: " << different_count;

    // Delete the matrix and temp
    for (int i = 0; i < N; ++i)
    {
        delete[] A[i];
    }
    delete[] A;
    delete[] different_elements_array;

    return 0;
}