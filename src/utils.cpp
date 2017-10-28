#include "utils.h"

double dRand()
{
    return ((double)(rand() % 200 - 101 ) / 10.0);
}

double** create_matrix(const size_t m_size, const bool _type)
{
    assert(m_size >= 2);

    double **mat = new double*[m_size];
    for (size_t i = 0; i < m_size; i++)
        mat[i] = new double[m_size];

    if (_type)
    {
        //top-triangular
        for (size_t i = 0; i < m_size; i++)
            for (size_t j = 0; j < m_size; j++)
            {
                if (i > j)
                    mat[i][j] = 0.0;
                else
                    mat[i][j] = dRand();
            }
    }
    else
    {
        //symmetric
        for (size_t i = 0; i < m_size; i++)
            for (size_t j = i; j < m_size; j++)
            {
                mat[i][j] = dRand();
                mat[j][i] = mat[i][j];
            }
    }
    return mat;
}

void write_to_file(const double *lin_mat, const size_t elems_count, const std::string &file_name)
{
    assert(lin_mat != NULL && elems_count > 0);

    std::ofstream of(file_name);
    if (!of.is_open())
        throw std::runtime_error("File '" + file_name + "' dot't was created.\n");
    for (size_t i = 0; i < elems_count; i++)
        of << lin_mat[i] << " ";
    of.close();
}
