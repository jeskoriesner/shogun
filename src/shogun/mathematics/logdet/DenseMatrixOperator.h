/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Written (W) 2013 Soumyajit De
 */

#ifndef DENSE_MATRIX_OPERATOR_H_
#define DENSE_MATRIX_OPERATOR_H_

#include <shogun/lib/config.h>

#ifdef HAVE_EIGEN3
#include <shogun/mathematics/logdet/MatrixOperator.h>

namespace shogun
{
template<class T> class SGVector;
template<class T> class SGMatrix;

/** @brief Class that represents a dense-matrix linear operator.
 * It computes matrix-vector product \f$Ax\f$ in its apply method,
 * \f$A\in\mathbb{C}^{m\times n},A:\mathbb{C}^{n}\rightarrow \mathbb{C}^{m}\f$
 * being the matrix operator and \f$x\in\mathbb{C}^{n}\f$ being the vector.
 * The result is a vector \f$y\in\mathbb{C}^{m}\f$.
 */
template<class T> class CDenseMatrixOperator : public CMatrixOperator<T>
{
/** this class has support for complex64_t */
typedef bool supports_complex64_t;

public:
	/** default constructor */
	CDenseMatrixOperator();

	/** 
	 * constructor
	 *
	 * @param op the dense matrix to be used as the linear operator
	 */
	CDenseMatrixOperator(SGMatrix<T> op);

	/** destructor */
	~CDenseMatrixOperator();

	/** 
	 * method that applies the dense-matrix linear operator to a vector
	 *
	 * @param b the vector to which the linear operator applies
	 * @return the result vector
	 */
	virtual SGVector<T> apply(SGVector<T> b) const;

	/**
	 * method that sets the main diagonal of the matrix
	 *
	 * @param diag the diagonal to be set
	 */
	virtual void set_diagonal(SGVector<T> diag);

	/**
	 * method that returns the main diagonal of the matrix
	 *
	 * @return the diagonal
	 */
	virtual SGVector<T> get_diagonal() const;

	/** @return the dense matrix operator */
	SGMatrix<T> get_matrix_operator() const;

	/** @return object name */
	virtual const char* get_name() const
	{
		return "DenseMatrixOperator";
	}

private:
	/** the dense matrix operator */
	SGMatrix<T> m_operator;

	/** initialize with default values and register params */
	void init();

};

}

#endif // HAVE_EIGEN3
#endif // DENSE_MATRIX_OPERATOR_H_
