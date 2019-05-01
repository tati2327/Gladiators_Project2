#include "GeneticEvolution.h"

GeneticEvolution::GeneticEvolution() {
    this->generationCount = 0;
    this->crossingmask1 = "0111001011";
    this->crossingmask2 = "1010101010";
    this->crossingmask3 = "101011110";

}
void GeneticEvolution::applyEvolution() {
    /*! Primero seleccionamos los 6 con el fitness mas alto y los cruzamos*/

}

void GeneticEvolution::mutation(Gladiator gladiator) {
    int randomMutation = rand() % 4;

    if(randomMutation==0) {
        int value = gladiator.getUpperTrunckStrenght();
        int data = changeValue(value);
        gladiator.setUpperTrunckStrenght(data);
        cout<<"Se muto UTS"<<endl;
    }
    if(randomMutation==1) {
        int value1=gladiator.getLowerTrunckStrenght();
        int data=changeValue(value1);
        gladiator.setLowerTrunckStrenght(data);
        cout<<"Se muto LTS"<<endl;
    }
    if(randomMutation==2) {
        int value2=gladiator.getAnger();
        int data=changeValue(value2);
        gladiator.setAnger(data);
        cout<<"Se muto Anger"<<endl;
    }
    if(randomMutation==3) {
        int value5=gladiator.getSelfControl();
        int data=changeValue(value5);
        gladiator.setSelfcontrol(data);
        cout<<"Se muto SC"<<endl;
    }
    if(randomMutation==4) {
        int value6=gladiator.getPhysicalCondition();
        int data=changeValue(value6);
        gladiator.setPhysicalCondition(data);
        cout<<"Se muto PC"<<endl;
    }
}

int GeneticEvolution::changeValue(int value) {
    if(value==0) return 1;
    else if(value==1) return 0;
    else if (value>=16) return value;

    long long binary=decimalToBinary(value);
    string binary_str = to_string(binary);

    int size= binary_str.length();
    size=size-1;

    int random= rand() % size;
    if ("0" == string(1, binary_str[random])) {
        binary_str=binary_str.erase(random,1);
        binary_str=binary_str.insert(random,"1");
    }else{
        binary_str=binary_str.erase(random,1);
        binary_str=binary_str.insert(random,"0");
    }

    binary= atol(binary_str.c_str());
    int decimal_value= binaryToDecimal(binary);
    return decimal_value;
}

long long GeneticEvolution::decimalToBinary(int n){
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0){
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

int GeneticEvolution:: binaryToDecimal(long long n){
    if(n==0) return 0;
    if(n==1) return 1;

    int decimalNumber = 0, i = 0, remainder;
    while (n!=0){
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

void GeneticEvolution::crossover(Army army,int index1, int index2, int idCount) {
    Gladiator son;
    Gladiator parent1=army.gladiators.getNode(index1)->getValue();
    Gladiator parent2=army.gladiators.getNode(index2)->getValue();

    for (int i = 1; i <= 5; i++) {

        if (i == 1) {
            int trait1= parent1.getUpperTrunckStrenght();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getUpperTrunckStrenght();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000";
            son.setUpperTrunckStrenght(makeExchange(stringTrait1, stringTrait2, sonGene));

        }else if (i == 2) {
            int trait1= parent1.getLowerTrunckStrenght();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getLowerTrunckStrenght();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000";
            son.setLowerTrunckStrenght(makeExchange(stringTrait1, stringTrait2, sonGene));


        }else if (i == 3) {
            int trait1= parent1.getAnger();
            string stringTrait1=convertToString(trait1,2);
            int trait2=parent2.getAnger();
            string stringTrait2=convertToString(trait2,2);
            string sonGene="00000";
            son.setAnger(makeExchange(stringTrait1, stringTrait2, sonGene));

        }else if (i == 4) {
            int trait1= parent1.getSelfControl();
            string stringTrait1=convertToString(trait1,2);
            int trait2=parent2.getSelfControl();
            string stringTrait2=convertToString(trait2,2);
            string sonGene="00000";
            son.setAnger(makeExchange(stringTrait1, stringTrait2, sonGene));


        }else if (i == 5) {
            int trait1= parent1.getPhysicalCondition();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getPhysicalCondition();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000";
            son.setPhysicalCondition(makeExchange(stringTrait1, stringTrait2, sonGene));
        }
    }

    /*! Se asignan a son1, son2, son3 los atributos que son de "calcular" y los que no se heredan de sus padres.*/
    son.setId(20 + generationCount+idCount);
    son.setEmotionalInt(son.calculateEmotionalInt());
    son.setResistance(son.calculateResistance());

    int randomMutation = rand() % 100 + 1;
    if (randomMutation < 5) {
        mutation(son);
        son.setEmotionalInt(son.calculateEmotionalInt());
        son.setResistance(son.calculateResistance());
        cout <<"Se aplico mutacion en 5 a la generacion "<<generationCount<< endl;
    }
    /*! Se asigna tmp1 y tmp2 al gladiador menos apto y el segundo menos apto respectivamente*/
    army.gladiators.getNode(0)->setData(son);
    cout << "El nuevo valor del mansote 0 es: " << army.gladiators[0].getResistance() << endl;

    /*! Se ordena la lista de gladiadores*/
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);

}
int GeneticEvolution::convertToDecimal(string trait) {
    int value=0;
    for(int i=0; i<=9; i++){
        if("1" == string(1, trait[i])){
            value++;
        }
    }return value;
}

string GeneticEvolution::convertToString(int trait,int type) {
    string base;
    if(type==1){
        base="00000000000";
    }else{
        base="000000";
    }

    for(int i=trait; i>=1; i--){
        int random;
        if(type==1) random = rand() % 10;
        else random= rand() % 5;

        if ("1" == string(1, base[random])){
            while("1" == string(1, base[random])){
                if(type==1) random = rand() % 10;
                else random= rand()%5;
            }
            base=base.erase(random,1);
            base=base.insert(random,"1");
        }else{
            base=base.erase(random,1);
            base=base.insert(random,"1");
        }

    }if(type==1) base=base.erase(10,1);
    else base=base.erase(5,1);
    return base;
}

int GeneticEvolution::makeExchange(string parent1, string parent2,string son) {
    string mask;
    int randomMask=rand() % 3 +1;
    if (randomMask == 1) mask =crossingmask1;
    else if(randomMask==2) mask =crossingmask2;
    else if(randomMask==3) mask =crossingmask3;
    cout<<"mascara: "<<mask<<endl;
    for(int i=0; i<=9;i++){
        if("1" == string(1, mask[i])){
            son=son.erase(i,1);
            son=son.insert(i,string(1, parent1[i]));
        }else{
            son=son.erase(i,1);
            son=son.insert(i,string(1, parent2[i]));
        }
    }cout<<son<<endl;
    return convertToDecimal(son);
}


