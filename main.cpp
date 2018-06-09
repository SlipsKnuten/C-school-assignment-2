#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int cards[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
int cards2[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
string colors[4] = {"Spades", "Hearts", "Diamonds", "Clubs"}; //The order of the colors in the array is essential since it decides the one who holds the highest value for the comparison.
string colors2[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
int randomCard, randomCard2;
string randomcolor, randomcolor2;
int usr2score, usrscore = 0;
char answer = 'y';
int usrround, usr2round;

void deckandscore(){
    while(usrscore != 2 && usr2score !=  2){ //This loop breaks if the both users score is 2.
            randomCard = cards[rand()%13]; //Randomizes both card and color for both players.
            randomcolor = colors[rand()%4];
            randomCard2 = cards2[rand()%13];
            randomcolor2 = colors2[rand()%4];
        if (randomCard == 14){ //Prints out ace, king, queen or jack instead of 11, 12, 13 or 14.
            cout << "Player 1 result was Ace of " << randomcolor << endl;
        }
        else if (randomCard == 13){
            cout << "Player 1 result was King of " << randomcolor << endl;
        }
        else if (randomCard == 12){
            cout << "Player 1 result was Queen of " << randomcolor << endl;
        }
        else if (randomCard == 11){
            cout << "Player 1 result was Jack of " << randomcolor << endl;
        }
        else {
            cout << "Player 1 result was " << randomCard << " of " << randomcolor << endl; //If the card value is not 11, 12, 13 or 14 print out the default card value and color.
        }
        if (randomCard2 == 14){ //Same function here because I could not integrate this function with the one above.
            cout << "Player 2 result was Ace of " << randomcolor2 << endl;
        }
        else if (randomCard2 == 13){
            cout << "Player 1 result was King of " << randomcolor2 << endl;
        }
        else if (randomCard2 == 12){
            cout << "Player 2 result was Queen of " << randomcolor2 << endl;
        }
        else if (randomCard2 == 11){
            cout << "Player 2 result was Jack of " << randomcolor2 << endl;
        }
        else {
            cout << "Player 2 result was " << randomCard2 << " of " << randomcolor2 << endl;
        }
        if (randomCard > randomCard2){ //If the card from player 1 has higher value then player 2 player wins this round.
            usrscore++;
            cout << endl << "The serie score is " << usrscore << " for player 1" << endl << "The serie score is " << usr2score << " for player 2" << endl << endl << "Player 1 won this serie!  " << endl << endl;
        }
        else {
            usr2score++; //Else player 2 wins.
            cout << endl << "The serie score is " << usrscore << " for player 1" << endl << "The serie score is " << usr2score << " for player 2" << endl << endl << "Player 2 won this serie!" << endl << endl;
        }
        if (randomCard == randomCard2){ //If the cards holds the same value compare the color value instead.
            if(randomcolor < randomcolor2){ //Compares the colors, if player 1's color holds higher value then player 2s, player 1 wins this round.
                usrscore++;
            }
            else{ //Else player 2 wins.
                usr2score++;
            }
        }
        if (randomCard == randomCard2 && randomcolor == randomcolor2){//Since the cards they draw does not disappear, it's completely randomized from an array, they can draw the same card. The rule in this game is that if they do draw the same card with the same value and color player 1 wins.x
            usrscore++;
            cout <<  endl << "The score was even but player 1 wins because he's the one" << endl;
        }
    }
}
void roundscore(){
if(usrscore == 2){ //Delegates the score of the rounds between the 2 players.
    usrround++;
    cout << "Player 1's round score is " << usrround << endl << "Player 2's round score is " << usr2round << endl;
}
else {
    usr2round++;
    cout << "Player 1's round score is " << usrround << endl << "Player 2's round score is " << usr2round << endl;
}
}
void replay(){
if (usrscore == 2 || usr2score == 2){ //If either of the users score are 2 score then ask if they want to play again.
    cout << endl << "Do you want to play again? Type 'Y' for yes and any other character for no. Then hit enter!" << endl;
    cin >> answer;
}
if (answer == 'y'){ //If the answer is yes reset the series score.
    cout << "Let's play again!" << endl;
    usrscore = 0;
    usr2score = 0;
}
if (answer != 'y'){
    if (usrround > usr2round){ //Decides which player wins the game.
        cout << endl << "The winners was player 1 with the score of " << usrround << "!" << endl;
    }
    else {
        cout << endl << "The winner was player 2 with the score of " << usr2round << "!" << endl;
    }
}
}
void Goodbye(string textToPrint = "Goodbye!") { cout << textToPrint << endl; }//Manages input from the replay function.
int main(){
    cout << "Welcome the card duel! The player with the highest cards wins as simple as that!Press enter to continue." << endl;
    cin.get();
    cout << "Cards are being shuffled and dealt!" << endl << endl;;
while(answer == 'y'){
deckandscore();
roundscore();
replay();
Goodbye();
}
}
