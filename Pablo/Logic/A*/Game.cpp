#include "Game.h"

Game::Game() {
    this->rows = 10;
    this->columns = 10;
    this->board = Matrix<Field>(rows,columns);
}

void Game::newGame() {
    gE.generationCount=+1;
    army.createArmy(army.armySize);
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators,army.armySize);
    army.setFittest();
    cout<<"Fittest: " <<army.fittest.getResistance()<<endl;
    army.setSecondFittest();
    cout<<"secondFittest: "<<army.secondFittest.getResistance()<<endl;


}

void Game::play() {
    //La posibilidad de que se haga la mutacion es un 4%.
    int random=(rand() % 99) + 0;
    if(random==45 or random==8 or random==69 or random==27) {
        cout<<"se inicia la muteishon"<<endl;
        gE.mutation(army);
        army.insertionSort(army.gladiators);
        army.printArray(army.gladiators, army.armySize);
        army.setFittest();
        cout << "Fittest: " << army.fittest.getResistance() << endl;
        army.setSecondFittest();
        cout << "secondFittest: " << army.secondFittest.getResistance() << endl;
    }


    //Se hace el crossover.
    cout<<"se inicia el crossovereo"<<endl;
    gE.crossover(army);
    gE.generationCount=+1;
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);
    army.setFittest();
    cout<<"Fittest: " <<army.fittest.getResistance()<<endl;
    army.setSecondFittest();
    cout<<"secondFittest: "<<army.secondFittest.getResistance()<<endl;

}



