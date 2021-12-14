#pragma once
namespace Alg
{
	template<class T>
	class Matrix
	{
		private:
			unsigned int line; 
			unsigned int cols;
			T** Mat;

		public:
			Matrix(unsigned int line = 0, unsigned int cols = 0);
			Matrix(Matrix&) = delete;
			Matrix& operator=(const Matrix&) = delete;
			Matrix& operator+(Matrix& M) const;
			~Matrix();
	};
}

using namespace Alg;

template<class T>
Alg::Matrix<T>::Matrix(unsigned int line, unsigned int cols)
{
	assert(line >= 0 && cols >= 0);
	this->Mat = new T* [line];
	this->line = line;
	this->cols = cols;

	if (this->Mat)
		for (int index = 0; index < line; index++)
		{
			this->Mat[index] = new T[cols];
			for (int indexj = 0; indexj < cols; indexj++)
				this->Mat[index][indexj] = 0;
		}
}

template<class T>
Matrix<T>& Alg::Matrix<T>::operator+(Matrix& M) const
{
	Matrix* Mres = new Matrix(this->line, this->cols);
	for (int indexi = 0; indexi < this->line; indexi++)
		for (int indexj = 0; indexj < this->cols; indexj++)
			Mres->Mat[indexi][indexj] = this->Mat[indexi][indexj] + M.Mat[indexi][indexj];

	return *Mres;
}

template<class T>
Alg::Matrix<T>::~Matrix()
{
	if (this->Mat)
	{
		for (int indexi = 0; indexi < this->line; indexi++)
		{
			delete[] this->Mat[indexi];
			this->Mat[indexi] = 0;
		}
		delete[] this->Mat;

		this->Mat = 0;
	}
}


