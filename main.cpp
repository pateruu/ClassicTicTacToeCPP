#include <iostream>

class board{
   private:
       int board_positions[9];
       int size;

   public:
       board();
       ~board();
       void display_board();
       bool set_board_positions(int pos, int value);
       bool check_winner();
};

//Board Constructor
board::board(){
   size = 9;
  
   //Set all board positions to 0
   for(int i = 0; i < size; i++){
       board_positions[i] = 0;
   }
}

//Board Destructor
board::~board(){
   size = 9;

   //Set all board positions to 0
   for(int i = 0; i < size; i++){
       board_positions[i] = 0;
   }
}

//Set board position and return true or false if we successfully set a position
bool board::set_board_positions(int pos, int value){
   if((value == 1) && (board_positions[pos] == 0)){ //if player 1, and position is not taken.
       board_positions[pos] = 1;
       return true;
   } else if((value == 2) && (board_positions[pos] == 0)){ //if player 2, and position is not taken.
       board_positions[pos] = 2;
       return true;
   } else{
       std::cout << "CANT PICK THIS ONE" << std::endl; //if position is taken.
       return false;
   }
}

//Checker for if the player wins or not
bool board::check_winner(){

   //Rows
   if ((board_positions[0] != 0 && board_positions[0] == board_positions[1] && board_positions[1] == board_positions[2]) ||
       (board_positions[3] != 0 && board_positions[3] == board_positions[4] && board_positions[4] == board_positions[5]) || 
      (board_positions[6] != 0 && board_positions[6] == board_positions[7] && board_positions[7] == board_positions[8])){  
       return true;
   }
   //Columns
   if ((board_positions[0] != 0 && board_positions[0] == board_positions[3] && board_positions[3] == board_positions[6]) ||
       (board_positions[1] != 0 && board_positions[1] == board_positions[4] && board_positions[4] == board_positions[7]) || 
       (board_positions[2] != 0 && board_positions[2] == board_positions[5] && board_positions[5] == board_positions[8])){  
       return true;
  }
   //Diagonals
   if ((board_positions[0] != 0 && board_positions[0] == board_positions[4] && board_positions[4] == board_positions[8]) || 
       (board_positions[2] != 0 && board_positions[2] == board_positions[4] && board_positions[4] == board_positions[6])){  
       return true;
   }
   return false; //Did not find winner.
}

//Function to print the board to the user.
void board::display_board(){

   for(int i = 0; i < size; i++){
       //If not edges then we figure out which sign to print.
       if((i != 2) && (i != 5) && (i != 8) && (board_positions[i] == 0)){
           std::cout << "* ";
       } else if((i != 2) && (i != 5) && (i != 8) && (board_positions[i] == 1)){
           std::cout << "X ";
       } else if((i != 2) && (i != 5) && (i != 8) && (board_positions[i] == 2)){
           std::cout << "O ";
       }

       if((i == 2) || (i == 5) || (i == 8) ){ //If edges then we need to make it an endl to get the correct format.
           if(board_positions[i] == 0){
               std::cout << "* \n";
           } else if(board_positions[i] == 1){
               std::cout << "X \n";
           } else if(board_positions[i] == 2){
               std::cout << "O \n";
           }
       }
   }
}


int main(){

   board main_board; //Instance of the class
   bool game_end = false; //initialize game end to be false to continue looping until game ends.
   int playertag = 0; //to switch between players when playing.
   int pick = 0; //Each players board positon pick.

   std::cout << "Welcome to Tic-Tac-Toe" << std::endl;

   while(game_end == false){ //while game has not ended.

       if((playertag % 2) == 0){ //Player 1's turn (X)
           std::cout << "Player 1's Turn (X):" << std::endl;
           std::cout << "Enter a Valid Open Board Position. (1-9) " << std::endl;
           std::cin >> pick;

           if((pick < 1) || (pick > 9)){ //If pick is out of range
               std::cout << "INVALID RANGE" << std::endl;
               continue;
           }

           if(main_board.set_board_positions(pick-1, 1) == false){ //If player1 did not pick an empty position.
               continue;
           }
           main_board.display_board(); //Display the board to the user
          
           if(main_board.check_winner()){ //check if player1 has won
               std::cout << "PLAYER 1 WINS" << std::endl;
               game_end = true;
           }

           playertag += 1; //increment player tag to switch to next player


       } else{ //Player 2's turn (O)
           std::cout << "Player 2's Turn (O):" << std::endl;
           std::cout << "Enter a Valid Open Board Position. (1-9) " << std::endl;
           std::cin >> pick;

           if((pick < 1) || (pick > 9)){ //If pick is out of range
               std::cout << "INVALID RANGE" << std::endl;
               continue;
           }

           if(main_board.set_board_positions(pick-1, 2) == false){ //If player2 did not pick an empty position.
               continue;
           }
           main_board.display_board(); //Display the board to the user

           if(main_board.check_winner()){ //check if player2 has won
               std::cout << "PLAYER 2 WINS" << std::endl;
               game_end = true;
           }

           playertag +=1; //increment player tag to switch to next player
       }
   }
}
