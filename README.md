Gauss elemination with partial pivotation.
===

This code is (another) an implementation of the Gaussian Elimination for solving linear equations.

You can build the software using
  make

The first input is the number of variables of the system folowed by the matrix elements from left to right, up to down.
The next input is the vector that will be used to make the argumented matrix.

The file gauss_symbolic.c uses a symbolic naming for rows,
so that just the names are swapped and not the whole line, thus improving efficiency.
