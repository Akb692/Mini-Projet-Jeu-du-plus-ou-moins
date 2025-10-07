#include <iostream>
#include <cstdlib>





int GenerateRandomNumber(int min, int max)
{
	int rdm = 1 + rand() % max;

	return rdm;
}

int GetPlayerGuess()
{
	int guess = 0;

	if (guess < 1 or guess > 100);
	{
		std::cout << "choisir entre 1 et 100 : ";
		std::cin >> guess;
	} 
	  return guess;

}



int CheckGuess(int guess, int mysteryNumber)
{
	if (guess < mysteryNumber)
	{
		return -1;
	}
	else if (guess > mysteryNumber)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int choosedifficulty()
{
	int difficulte = 0;
	std::cout << "choisir le niveau de difficulte (1 : facile, 2 : moyen, 3 : difficile) : " << std::endl;
	std::cin >> difficulte;

	return difficulte;

}

int calculateScore(int attemptsleft, int difficulty)
{
	int score = 0;
	if (difficulty == 1)
	{
		score = (int)attemptsleft * 10; 
	}
	if (difficulty == 2)
	{
		score = (int)attemptsleft * 20;
	}
	if (difficulty == 3)
	{
		score = (int)attemptsleft * 30;
	}
	if (score > 300)
	{
		std::cout << "Score maximal (300) depasse !! " << std::endl;
	}
	return score;
}

int AskToPlayAgain()
{
	int play = 0;
	std::cout << "Voulez-vous rejouer ? (1 : Oui, 0 : Non) :" << std::endl;
	std::cin >> play;

	if (play == 1)
	{
		play = 1;
	}
	if (play == 0)
	{
		play = 0;
	}
	if (play > 1 and play < 0)
	{
		std::cout << "choix invalide" << std::endl;
		std::cout << "Voulez-vous rejouer ? (1 : Oui, 0 : Non) :" << std::endl;
		std::cin >> play;
	}
	return play;
}








int PlayGame()
{
	int tentative;
	int hazard = GenerateRandomNumber(0, 100);
	int resultat = 0;

	int diff = choosedifficulty();
	if (diff == 1)
	{
		tentative = 8;
	}
	if (diff == 2)
	{
		tentative = 5;
	}
	if (diff == 3)
	{
		tentative = 3;
	}

	while (tentative > 0)
	{
		int player_guess = GetPlayerGuess();
		int resultat = CheckGuess(player_guess, hazard);
		tentative--;
		
		if (resultat == 1)
		{
			std::cout << "trop haut ! " << std::endl;
		}

		if (resultat == -1)
		{
			std::cout << "trop bas ! " << std::endl;
		}
		if (resultat == 0)
		{
			std::cout << "vous avez trouver ! " << std::endl;
			std::cout << "votre score ! : " << calculateScore(tentative, diff) << std::endl;
			break;
		}	

		if (tentative == 0)
		{
			std::cout << "votre score ! : " << calculateScore(tentative, diff) << std::endl;
		}

		

	}	
	while (AskToPlayAgain() == 1)
	{
		PlayGame();
	}



	return 0;
}


int main()
{
	srand(time(NULL)); 
	PlayGame();
	AskToPlayAgain();
	return 0;
}