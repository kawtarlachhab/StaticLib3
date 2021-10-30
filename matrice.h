#pragma once


	class matrice
	{
	public:
		matrice(int nb_colonne = 0, int nb_ligne = 0);
		~matrice();
		void remplir();
		void print() const;
		matrice& operator+(const matrice& M) const;
		matrice& operator-(const matrice& M) const;
		matrice& operator*(const matrice& M) const;
		matrice& transposer()const;
	private:
		int nb_colonne;
		int nb_ligne;
		int** Matrice; ///double pointeur;
	};



