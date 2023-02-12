GradientDescent
Ce projet comprend une classe GradientDescent ainsi qu'une fonction gradDescent.

Classe GradientDescent
La classe GradientDescent peut être utilisée pour minimiser une fonction en utilisant la descente de gradient. Elle comprend les fonctions suivantes:

grad(f, x, n) : calcule le gradient d'une fonction f en utilisant les variables x et le nombre de variables n.
run(f, x0, n, eps, alpha) : effectue la descente de gradient sur une fonction f en utilisant un vecteur de variables initial x0, le nombre de variables n, une condition d'arrêt eps, et un taux d'apprentissage alpha.
Fonction gradDescent
La fonction gradDescent peut être utilisée pour minimiser une fonction en utilisant la descente de gradient. Les paramètres sont les suivants :

f : la fonction à minimiser
x0 : vecteur de variables initiales
n : nombre de variables
eps : condition d'arrêt (lorsque tous les termes du gradient sont inférieurs à eps)
alpha : taux d'apprentissage (taille du pas)
Utilisation
Téléchargez ou clonez le projet.
Incluez le fichier gradient_descent.cpp dans votre projet.
Créez une instance de la classe GradientDescent ou utilisez la fonction gradDescent pour minimiser votre fonction.
c
Copy code
#include "gradient_descent.cpp"

int main()
{
    // utilisation de la classe GradientDescent
    GradientDescent gradientDescent;
    const double x0[] = {1, 2};
    const unsigned int n = 2;
    const double eps = 1e-6;
    const double alpha = 0.1;
    const double *result = gradientDescent.run(f, x0, n, eps, alpha);
    
    // utilisation de la fonction gradDescent
    const double *result2 = gradDescent(f, x0, n, eps, alpha);
    
    return 0;
}
Notez que la fonction f doit être définie en dehors de la classe et de la fonction.