#ifndef SCORELIB_H
#define SCORELIB_H
#define NOMTAM 3
#define BOARDTAM 10


struct Score
{
	int sco;
	char nom[NOMTAM];
};
class MugettiSimpleScoreLib
{
	Score _ScoreTable[BOARDTAM];
	/* \brief Private funcion to sort positions in the board after a change has been made.*/
	bool Sort(Score actual);
public:
	MugettiSimpleScoreLib();
	/* \brief Takes a score and a name and records them as an entry in the scoreboard and returns true, returns false if the score is smaller or equal than the smallest already recorded.*/
	bool RecordCurrentScore(int score, char name[NOMTAM]);
	/* \brief Returns the name and score of the best position in the table.*/
	void GetMaxScore(int& score, char* name[NOMTAM]);
	/* \brief Use this to find the position held by a certain score, returns false if the score is not found.*/
	bool GetPlayerPositionByScore(int score, int& position);
	/* \brief Use this to find the position held by a certain name, returns false if the name is not found.*/
	bool GetPlayerPositionByName(char name[NOMTAM], int& position);
	/* \brief Use this to find the score and name at a given position, returns false if the position is not found.*/
	bool GetPositionScore(int position, int&score, char* name[NOMTAM]);
	/* \brief Returns the scoreboard's ammount of positions.*/
	int GetScoreBoardSize() { return BOARDTAM; }
	~MugettiSimpleScoreLib();
};
#endif // !SCORELIB_H

