#include "pch.h"
#include "matrice.h"
#include <iostream>
#include <assert.h>
using namespace std;

matrice::matrice(int nb_colonne,int nb_ligne)
{
	 this->nb_colonne = nb_colonne;
	 this->nb_ligne   = nb_ligne;
	 Matrice = new int* [nb_ligne];
	 for (int i = 0; i < nb_ligne ;  i++)
	 {
		 Matrice[i] = new int [nb_colonne];
	 }
}
matrice::~matrice()
{
	if (Matrice)
	{
		for (int j = 0; j < nb_ligne; j++)
		{
			delete[] Matrice[j];
			Matrice[j] = 0;
		}
		delete[] Matrice;
		Matrice = 0;
	}
}
/*la saisie au clavier des valeur*/
void matrice::remplir()
{
	for (int i = 0 ; i < nb_ligne ; i++)
	{
		for (int j = 0; j < nb_colonne; j++)
		{
			 cout << " Entrer Matrice[" << i << "]" << "[" << j << "] : ";
			 cin  >> Matrice[i][j];
		}
	}
}
void matrice::print() const
{
	for (int i = 0; i < nb_ligne; i++)
	{
		for (int j = 0; j < nb_colonne; j++)
		{
			cout <<" Matrice[" << i << "]" << "[" << j << "]" << " = " << Matrice[i][j] << endl << endl;
		}
	}
}

matrice& matrice::operator+(const matrice& M) const
{
	///les deux matrice doivent avoir meme dimension 
	assert(M.nb_ligne == nb_ligne && M.nb_colonne == nb_colonne);
	matrice* mat = new matrice(M.nb_colonne, M.nb_ligne);
	for (int i = 0; i < nb_ligne; i++)
	{
		for (int j = 0; j < nb_colonne; j++)
		{
			mat->Matrice[i][j] = Matrice[i][j] + M.Matrice[i][j];
		}
	}
	return *mat;
}

matrice& matrice::operator-(const matrice& M) const
{
	assert(M.nb_ligne == nb_ligne && M.nb_colonne == nb_colonne);
	matrice* mat = new matrice(M.nb_colonne, M.nb_ligne);
	for (int i = 0; i < nb_ligne; i++)
	{
		for (int j = 0; j < nb_colonne; j++)
		{
			mat->Matrice[i][j] = Matrice[i][j] - M.Matrice[i][j];
		}
	}
	return *mat;
}

matrice& matrice::operator*(const matrice& M) const
{
	assert(M.nb_ligne == nb_ligne && M.nb_colonne == nb_colonne);
	matrice* mat= new matrice(M.nb_colonne, M.nb_ligne);

	for (int j = 0; j < nb_ligne; j++)
	{
		for (int k = 0; k < nb_ligne; k++)
		{
			mat->Matrice[j][k] = 0;  //initialisation à 0
			for (int n = 0; n < nb_colonne; n++)
			{
				mat->Matrice[j][k] += Matrice[j][n] * M.Matrice[n][k];
			}
			
		}
	}
	return  *mat;
}

matrice& matrice::transposer() const
{
	matrice* transpose = new matrice(nb_ligne,nb_colonne);
	for (int k = 0; k < nb_ligne; k++)
	{
		for (int j = 0; j < nb_colonne; j++)
		{
			transpose->Matrice[j][k] = Matrice[k][j];
		}
	}
	return *transpose;
}
