bool symmetrical() const {
  bool symetrique = false;
  for (int i = 0; i < _nlines; i++) {
    for (int j = 0; j < _mcolumns; j++) {
      if (*this[i][j] == *this[j][i])
        symetrique = true;
    }
  }
}

void Matrix::productMatrix(const Matrix&B, Matrix & C) {
  for (int i = 0; i < _nlines; i++) {
    for (int j = 0; j < _mcolumns; j++) {
      C[i][j] = 0;
      for (int k = 0; k < _mcolumns; k++) {
        C[i][j] = C[i][j] + B[i][k] * *this[k][j];
      }
    }
  }
}

void Matrix::afficherMatrice() const {
  for (int i = 0; i < _nlines; i++) {
    for (int j = 0; j < _mcolumns; j++) {
      std::cout << *this[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Matrix::solveTriL(const std::vector<double> & b, std::vector<double> &x) {
  double somme;
  for (int i = 0; i < _nlines; i++) {
    somme = 0;
    for (int j = 0; j < i-1; j++) {
      somme = somme + b[i][j] * x[j];
    }
    x[i] = (b[i] - somme) / b[i][i];
  }
}

void solveTriU(const std::vector<double> & b, std::vector<double> &x) {
  double somme;
  for (int i = 0; i < _nlines; i++) {
    somme = 0;
    for (int j = 0; j < i+1; j++) {
      somme = somme + b[i][j] * x[j];
    }
    x[i] = (b[i] - somme) / b[i][i];
  }
}
