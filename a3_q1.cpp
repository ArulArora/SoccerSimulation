/*
To test my program I ran it 10 times. Each time I ran it, the outcome was completely
different than any other time I ran it meaning that the randomness of this program
is correct. I also determined the statistics were correct by reading the commentary 
and calculating the statistics manually. I checked if my values matched the outputted
results each time and this is how I determined they were correct.
*/

#include <iostream>
#include <ctime>
#include <windows.h> 
using namespace std;

void generate_events(int events[], int number_of_events);
// PURPOSE: generate numbers between 1-6 that corresponds to a specific event and store it in the events array
// INPUT: events[] - array that stores the type of event
//		  number_of_events - number of events that will occur in the game
// OUTPUT: nothing; variables are passed by reference

void team_a_shot(int& a_goals, int& a_shots_on, int& b_blocked_shots, int& a_shots_off);
// PURPOSE: team a shoots the ball and the outcome is determined randomly
// INPUT: corresponding integer references for statistics
// OUTPUT: nothing; variables are passed by reference

void team_b_shot(int& b_goals, int& b_shots_on, int& a_blocked_shots, int& b_shots_off);
// PURPOSE: team b shoots the ball and the outcome is determined randomly
// INPUT: corresponding integer references for statistics
// OUTPUT: nothing; variables are passed by reference

void team_a_freekick(int& a_goals, int& a_shots_on, int& b_blocked_shots, int& a_shots_off, int& b_yellowcards, int& b_redcards);
// PURPOSE: team a gets a free kick and the outcome is determined randomly
// INPUT: corresponding integer references for statistics
// OUTPUT: nothing; variables are passed by reference

void team_b_freekick(int& b_goals, int& b_shots_on, int& a_blocked_shots, int& b_shots_off, int& a_yellowcards, int& a_redcards);
// PURPOSE: team b gets a free kick and the outcome is determined randomly 
// INPUT: corresponding integer references for statistics
// OUTPUT: nothing; variables are passed by reference

void team_a_penalty(int& a_goals, int& a_shots_on, int& b_blocked_shots, int& a_shots_off, int& b_yellowcards, int& b_redcards);
// PURPOSE: team a gets a penalty shot and the outcome is determined randomly
// INPUT: corresponding integer references for statistics
// OUTPUT: nothing; variables are passed by reference

void team_b_penalty(int& b_goals, int& b_shots_on, int& a_blocked_shots, int& b_shots_off, int& a_yellowcards, int& a_redcards);
// PURPOSE: team b gets a penalty shot and the outcome is determined randomly
// INPUT: corresponding integer references for statistics
// OUTPUT: nothing; variables are passed by reference

void first_half(int events[], int first_half_events, int& a_goals, int& b_goals, int& a_shots_on, int& b_shots_on, int& a_shots_off, int& b_shots_off, int& a_blocked_shots,
				int& b_blocked_shots, int& a_fouls, int& b_fouls, int& a_yellowcards, int& b_yellowcards, int& a_redcards, int& b_redcards);
// PURPOSE: go through the first half events and output the corresponding commentary
// INPUT: events[] - array that stores the type of event
//		  first_half_events - the number of events that will occur in the first half
//		  corresponding integer references for statistics
// OUTPUT: nothing; output is to the console

void second_half(int events[], int second_half_events, int& a_goals, int& b_goals, int& a_shots_on, int& b_shots_on, int& a_shots_off, int& b_shots_off, int& a_blocked_shots,
				 int& b_blocked_shots, int& a_fouls, int& b_fouls, int& a_yellowcards, int& b_yellowcards, int& a_redcards, int& b_redcards);
// PURPOSE: go through the second half events and output the corresponding commentary
// INPUT: events[] - array that stores the type of event
//		  second_half_events - the number of events that will occur in the second half
//		  corresponding integer references for statistics
// OUTPUT: nothing; output is to the console

void start_soccer_simulation();
// PURPOSE: runs each step of the program
// INPUT: nothing
// OUTPUT: nothing; output is to the console

void generate_events(int events[], int number_of_events) {
	// step1. iterate between 0 to the number of events 
	for (int index = 0; index < number_of_events; index++) {
		
		//step2. store a random number between 1 to 6 which will correspond to a specific event and store it in the events array
		events[index] = rand() % 6 + 1;
	}
}

void team_a_shot(int &a_goals, int &a_shots_on, int &b_blocked_shots, int &a_shots_off) {
	// [setup]: declare and initialize variables
	int shot = rand() % 4;
	bool scored = false, saved = false, off_shot = false, blocked = false;

	// step1. determine the outcome of the shot
	scored = shot == 0;
	saved = shot == 1;
	off_shot = shot == 2;
	blocked = shot == 3;

	// step2. use the outcome of the shot to update the statistics and output the corresponding commetary
	if (scored) {
		a_shots_on += 1;
		a_goals += 1;
		cout << "Team A takes a shot on net... They have scored an absolutley beautiful goal!" << endl;
	}
	else if (saved) {
		a_shots_on += 1;
		b_blocked_shots += 1;
		cout << "Team A takes a shot on net... It was saved by the keeper!" << endl;
	}
	else if (off_shot) {
		a_shots_off += 1;
		cout << "Team A takes a shot... Oh no it was off target!" << endl;
	}
	else if (blocked) {
		a_shots_on += 1;
		b_blocked_shots += 1;
		cout << "Team A takes a shot... It was blocked by a defender!" << endl;
	}
}

void team_b_shot(int& b_goals, int& b_shots_on, int& a_blocked_shots, int& b_shots_off) {
	// [setup]: declare and initialize variables
	int shot = rand() % 4;
	bool scored = false, saved = false, off_shot = false, blocked = false;

	// step1. determine the outcome of the shot
	scored = shot == 0;
	saved = shot == 1;
	off_shot = shot == 2;
	blocked = shot == 3;

	// step2. use the outcome of the shot to update the corresponding statistics and output the corresponding commetary
	if (scored) {
		b_shots_on += 1;
		b_goals += 1;
		cout << "Team B takes a shot on net... What a fantastic goal!" << endl;
	}
	else if (saved) {
		b_shots_on += 1;
		a_blocked_shots += 1;
		cout << "Team B takes a shot on net... Great dive by the keeper to save it!" << endl;
	}
	else if (off_shot) {
		b_shots_off += 1;
		cout << "Team B takes a shot... Oops that wasn't close to the net!" << endl;
	}
	else if (blocked) {
		b_shots_on += 1;
		a_blocked_shots += 1;
		cout << "Team B takes a shot... It was blocked by a defender!" << endl;
	}
}

void team_a_freekick(int& a_goals, int& a_shots_on, int& b_blocked_shots, int& a_shots_off, int& b_yellowcards, int& b_redcards) {
	// [setup]: declare and initialize variables
	int shot = rand() % 4;
	int card = rand() % 3;
	bool scored = false, saved = false, off_shot = false, blocked = false, yellow = false, red =  false, no_card = false;

	// step1. detrmine the card that the player will get for the foul
	no_card = card == 0;
	yellow = card == 1;
	red = card == 2;

	// step2. use the outcome of the card given to update the corresponding statistic and output the corresponding commetary
	if (no_card) {
		cout << "Team B is offside. Team A gets a free kick!" << endl;
	}
	else if (yellow) {
		b_yellowcards += 1;
		cout << "Team B touched the ball with their hand. Yellow Card! Team A gets a free kick!" << endl;
	}
	else if (red) {
		b_redcards += 1;
		cout << "Team B kicked a team A player in the face. Red card! Team A gets a free kick!" << endl;
	}

	// step3. determine the outcome of the shot
	scored = shot == 0;
	saved = shot == 1;
	off_shot = shot == 2;
	blocked = shot == 3;

	// step4. use the outcome of the shot to update the corresponding statistics and output the corresponding commetary
	if (scored) {
		a_shots_on += 1;
		a_goals += 1;
		cout << "Team A takes their free kick... They have scored! What an insane shot!" << endl;
	}
	else if (saved) {
		a_shots_on += 1;
		b_blocked_shots += 1;
		cout << "Team A takes their free kick... It was saved by the keeper!" << endl;
	}
	else if (off_shot) {
		a_shots_off += 1;
		cout << "Team A takes their free kick... Oh no it was off target!" << endl;
	}
	else if (blocked) {
		a_shots_on += 1;
		b_blocked_shots += 1;
		cout << "Team A takes their free kick... It was blocked by a defender!" << endl;
	}
}

void team_b_freekick(int& b_goals, int& b_shots_on, int& a_blocked_shots, int& b_shots_off, int& a_yellowcards, int& a_redcards) {
	// [setup]: declare and initialize variables
	int shot = rand() % 4;
	int card = rand() % 3;
	bool scored = false, saved = false, off_shot = false, blocked = false, yellow = false, red = false, no_card = false;

	// step1. detrmine the card that the player will get for the foul
	no_card = card == 0;
	yellow = card == 1;
	red = card == 2;

	// step2. use the outcome of the card given to update the corresponding statistic and output the corresponding commetary
	if (no_card) {
		cout << "Team A is offside. Team B gets a free kick!" << endl;
	}
	else if (yellow) {
		a_yellowcards += 1;
		cout << "Team A is grabbing a Team B player. Yellow Card! Team B gets a free kick!" << endl;
	}
	else if (red) {
		a_redcards += 1;
		cout << "Team A pushed a Team B player from behind. Red card! Team B gets a free kick!" << endl;
	}

	// step3. determine the outcome of the shot
	scored = shot == 0;
	saved = shot == 1;
	off_shot = shot == 2;
	blocked = shot == 3;

	// step4. use the outcome of the shot to update the corresponding statistics and output the corresponding commetary
	if (scored) {
		b_shots_on += 1;
		b_goals += 1;
		cout << "Team B takes their free kick... They scored from the kick!" << endl;
	}
	else if (saved) {
		b_shots_on += 1;
		a_blocked_shots += 1;
		cout << "Team B takes their free kick... The keeper caught it!" << endl;
	}
	else if (off_shot) {
		b_shots_off += 1;
		cout << "Team B takes their free kick... Oops that was way off target!" << endl;
	}
	else if (blocked) {
		b_shots_on += 1;
		a_blocked_shots += 1;
		cout << "Team B takes their free kick... It was blocked by a defender!" << endl;
	}
}

void team_a_penalty(int& a_goals, int& a_shots_on, int& b_blocked_shots, int& a_shots_off, int& b_yellowcards, int& b_redcards) {
	// [setup]: declare and initialize variables
	int shot = rand() % 3;
	int card = rand() % 3;
	bool scored = false, saved = false, off_shot = false, yellow = false, red = false, no_card = false;

	// step1. detrmine the card that the player will get for the foul
	no_card = card == 0;
	yellow = card == 1;
	red = card == 2;

	// step2. use the outcome of the card given to update the corresponding statistic and output the corresponding commetary
	if (no_card) {
		cout << "Team B touched the ball with their hand near A's net. Team A gets a penalty shot!" << endl;
	}
	else if (yellow) {
		b_yellowcards += 1;
		cout << "Team B tripped team A near their net. Yellow Card! Team A gets a penalty shot!" << endl;
	}
	else if (red) {
		b_redcards += 1;
		cout << "Team B kicked team A's goalie. Red card! Team A gets a penalty kick!" << endl;
	}

	// step3. determine the outcome of the shot
	scored = shot == 0;
	saved = shot == 1;
	off_shot = shot == 2;

	// step4. use the outcome of the shot to update the corresponding statistics and output the corresponding commetary
	if (scored) {
		a_shots_on += 1;
		a_goals += 1;
		cout << "Team A takes their penalty shot... They score in the top right corner! What a shot!" << endl;
	}
	else if (saved) {
		a_shots_on += 1;
		b_blocked_shots += 1;
		cout << "Team A takes their penalty... It was saved by the keeper!" << endl;
	}
	else if (off_shot) {
		a_shots_off += 1;
		cout << "Team A takes their penalty shot... Oh no it was off!" << endl;
	}
}

void team_b_penalty(int& b_goals, int& b_shots_on, int& a_blocked_shots, int& b_shots_off, int& a_yellowcards, int& a_redcards) {
	// [setup]: declare and initialize variables
	int shot = rand() % 3;
	int card = rand() % 3;
	bool scored = false, saved = false, off_shot = false, yellow = false, red = false, no_card = false;

	// step1. detrmine the card that the player will get for the foul
	no_card = card == 0;
	yellow = card == 1;
	red = card == 2;

	// step2. use the outcome of the card given to update the corresponding statistic and output the corresponding commetary
	if (no_card) {
		cout << "Team A touched the ball with their hand near B's net. Team B gets a penalty shot!" << endl;
	}
	else if (yellow) {
		a_yellowcards += 1;
		cout << "Team A slide tackled team B near their net. Yellow Card! Team B gets a penalty shot!" << endl;
	}
	else if (red) {
		a_redcards += 1;
		cout << "Team A punched a team B player near the net. Red card! Team B gets a penalty kick!" << endl;
	}

	// step3. determine the outcome of the shot
	scored = shot == 0;
	saved = shot == 1;
	off_shot = shot == 2;

	// step4. use the outcome of the shot to update the corresponding statistics and output the corresponding commetary
	if (scored) {
		b_shots_on += 1;
		b_goals += 1;
		cout << "Team B takes their penalty shot... They score in the bottom left corner! What a goal!" << endl;
	}
	else if (saved) {
		b_shots_on += 1;
		a_blocked_shots += 1;
		cout << "Team B takes their penalty... It was saved by the keeper!" << endl;
	}
	else if (off_shot) {
		b_shots_off += 1;
		cout << "Team B takes their penalty shot... Oops it was off target!" << endl;
	}
}

void first_half(int events[], int first_half_events, int &a_goals, int &b_goals, int &a_shots_on, int &b_shots_on, int &a_shots_off, int &b_shots_off, int &a_blocked_shots,
				int &b_blocked_shots, int &a_fouls, int &b_fouls, int &a_yellowcards, int &b_yellowcards, int &a_redcards, int &b_redcards) {
	// [setup]: declare and initialize variables
	bool a_shot = false, b_shot = false, b_foul_freekick = false, a_foul_freekick = false, b_foul_penalty = false, a_foul_penalty = false;
	int current_event = 0;

	// step1. iterate between the first half events
	for (int index = 0; index < first_half_events; index++) {

		// step2. pause the program for 2-3 seconds
		Sleep(rand() % 2000 + 1000);
		
		// step3. set the current_event variable to the current event in the array
		current_event = events[index];
		
		// step4. determine what the event is
		a_shot = current_event == 1;
		b_shot = current_event == 2;
		b_foul_freekick = current_event == 3;
		a_foul_freekick = current_event == 4;
		b_foul_penalty = current_event == 5;
		a_foul_penalty = current_event == 6;

		// step5. call the corresponding event function
		if (a_shot) {
			team_a_shot(a_goals, a_shots_on, b_blocked_shots, a_shots_off);
		}
		else if (b_shot) {
			team_b_shot(b_goals, b_shots_on, a_blocked_shots, b_shots_off);
		}
		else if (b_foul_freekick) {
			team_a_freekick(a_goals, a_shots_on, b_blocked_shots, a_shots_off, b_yellowcards, b_redcards);
		}
		else if (a_foul_freekick) {
			team_b_freekick(b_goals, b_shots_on, a_blocked_shots, b_shots_off, a_yellowcards, a_redcards);
		}
		else if (b_foul_penalty) {
			team_a_penalty(a_goals, a_shots_on, b_blocked_shots, a_shots_off, b_yellowcards, b_redcards);
		}
		else if (a_foul_penalty) {
			team_b_penalty(b_goals, b_shots_on, a_blocked_shots, b_shots_off, a_yellowcards, a_redcards);
		}
	}

	// step6. pause the prgram for 2 seconds
	Sleep(2000);

	// step7. output the halftime statistics 
	cout << "Half time! Here are the current stats of the game:" << endl <<
		"TEAM A  \t" << a_goals << "\t\t\t\t" << b_goals << "\t   TEAM B" << endl <<
		"\t" << a_shots_on << "\t\t SHOTS ON TARGET\t\t" << b_shots_on << "\t" << endl <<
		"\t" << a_shots_off << "\t\tSHOTS OFF TARGET\t\t" << b_shots_off << "\t" << endl <<
		"\t" << a_blocked_shots << "\t\t  BLOCKED SHOTS\t\t\t" << b_blocked_shots << "\t" << endl <<
		"\t" << a_fouls << "\t\t      FOULS\t\t\t" << b_fouls << "\t" << endl <<
		"\t" << a_yellowcards << "\t\t  YELLOW CARDS\t\t\t" << b_yellowcards << "\t" << endl <<
		"\t" << a_redcards << "\t\t    RED CARDS\t\t\t" << b_redcards << "\t" << endl;

	// step8. pase the program for 5 seconds
	Sleep(5000);
}

void second_half(int events[], int second_half_events, int& a_goals, int& b_goals, int& a_shots_on, int& b_shots_on, int& a_shots_off, int& b_shots_off, int& a_blocked_shots,
		  	   	int& b_blocked_shots, int& a_fouls, int& b_fouls, int& a_yellowcards, int& b_yellowcards, int& a_redcards, int& b_redcards) {
	// [setup]: declare and initialize variables
	bool a_shot = false, b_shot = false, b_foul_freekick = false, a_foul_freekick = false, b_foul_penalty = false, a_foul_penalty = false;
	int current_event = 0;

	// step1. iterate between the second half events
	for (int index = 0; index < second_half_events; index++) {
		
		// step2. pause the program for 2-3 seconds
		Sleep(rand() % 1000 + 2000);

		// step3. set the current_event variable to the current event in the array
		current_event = events[index];

		// step4. determine what the event is
		a_shot = current_event == 1;
		b_shot = current_event == 2;
		b_foul_freekick = current_event == 3;
		a_foul_freekick = current_event == 4;
		b_foul_penalty = current_event == 5;
		a_foul_penalty = current_event == 6;

		// step5. call the corresponding event function
		if (a_shot) {
			team_a_shot(a_goals, a_shots_on, b_blocked_shots, a_shots_off);
		}
		else if (b_shot) {
			team_b_shot(b_goals, b_shots_on, a_blocked_shots, b_shots_off);
		}
		else if (b_foul_freekick) {
			team_a_freekick(a_goals, a_shots_on, b_blocked_shots, a_shots_off, b_yellowcards, b_redcards);
		}
		else if (a_foul_freekick) {
			team_b_freekick(b_goals, b_shots_on, a_blocked_shots, b_shots_off, a_yellowcards, a_redcards);
		}
		else if (b_foul_penalty) {
			team_a_penalty(a_goals, a_shots_on, b_blocked_shots, a_shots_off, b_yellowcards, b_redcards);
		}
		else if (a_foul_penalty) {
			team_b_penalty(b_goals, b_shots_on, a_blocked_shots, b_shots_off, a_yellowcards, a_redcards);
		}
	}

	// step6. pause the prgram for 2 seconds
	Sleep(2000);

	// step7. output the halftime statistics 
	cout << "The game is over! Here are the overall stats of the game:" << endl <<
		"TEAM A  \t" << a_goals << "\t\t\t\t" << b_goals << "\t   TEAM B" << endl <<
		"\t" << a_shots_on << "\t\t SHOTS ON TARGET\t\t" << b_shots_on << "\t" << endl <<
		"\t" << a_shots_off << "\t\tSHOTS OFF TARGET\t\t" << b_shots_off << "\t" << endl <<
		"\t" << a_blocked_shots << "\t\t  BLOCKED SHOTS\t\t\t" << b_blocked_shots << "\t" << endl <<
		"\t" << a_fouls << "\t\t      FOULS\t\t\t" << b_fouls << "\t" << endl <<
		"\t" << a_yellowcards << "\t\t  YELLOW CARDS\t\t\t" << b_yellowcards << "\t" << endl <<
		"\t" << a_redcards << "\t\t    RED CARDS\t\t\t" << b_redcards << "\t" << endl;

	// step8. pase the program for 5 seconds
	Sleep(5000);
}


void start_soccer_simulation() {
	// [setup]: declare and initalize variables
	srand(time(0));
	int number_of_events = rand() % 20 + 1;
	int first_half_events = number_of_events / 2;
	int second_half_events = number_of_events - first_half_events;
	int events[20] = { 0 };
	int a_goals = 0, b_goals = 0, a_shots_on = 0, b_shots_on = 0, a_shots_off = 0, b_shots_off = 0, a_blocked_shots = 0, 
		b_blocked_shots = 0, a_fouls = 0, b_fouls = 0, a_yellowcards = 0, b_yellowcards = 0, a_redcards = 0, b_redcards = 0;

	// step1. output the starting messages 
	cout << "Welcome to the 2020 Soccer Championships!" << endl;
	Sleep(2000);
	cout << "The game will start in" << endl;
	Sleep(1000);
	cout << "3..." << endl;
	Sleep(1000);
	cout << "2..." << endl;
	Sleep(1000);
	cout << "1..." << endl;
	Sleep(1000);
	cout << "START!!!" << endl;

	// [INPUT] step2. generate numbers between 1-6 that corresponds to a specific event and store it in the events array
	generate_events(events, number_of_events);

	// [PROCESSING] and [OUTPUT] step3. go through the first half events and output the corresponding commentary
	first_half(events, first_half_events, a_goals, b_goals, a_shots_on, b_shots_on, a_shots_off, b_shots_off, a_blocked_shots, b_blocked_shots, a_fouls, b_fouls, a_yellowcards, b_yellowcards, a_redcards, b_redcards);

	// step4. output the second half starting messages
	cout << "The second half will start in" << endl;
	Sleep(1000);
	cout << "3..." << endl;
	Sleep(1000);
	cout << "2..." << endl;
	Sleep(1000);
	cout << "1..." << endl;
	Sleep(1000);
	cout << "START!!!" << endl;

	// [PROCESSING] and [OUTPUT] step5. go through the second half events and output the corresponding commentary
	second_half(events, first_half_events, a_goals, b_goals, a_shots_on, b_shots_on, a_shots_off, b_shots_off, a_blocked_shots, b_blocked_shots, a_fouls, b_fouls, a_yellowcards, b_yellowcards, a_redcards, b_redcards);

	// step6. output the closing messages
	cout << "What a game that was! I hope everyone enjoyed!";
}

int main() {
	start_soccer_simulation();
}

