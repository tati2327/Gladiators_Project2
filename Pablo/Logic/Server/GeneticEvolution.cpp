#include "GeneticEvolution.h"

GeneticEvolution::GeneticEvolution() {
    this->generationCount = 0;
    this->crossingmask1 = "0111001011";
    this->crossingmask2 = "1010101010";
    this->crossingmask3 = "101011110";
    this->lastId=20;

}
void GeneticEvolution::applyEvolution() {
    /*! Primero seleccionamos los 6 con el fitness mas alto y los cruzamos*/

}

void GeneticEvolution::mutation(Gladiator gladiator) {
    int randomMutation = rand() % 4;

    if(randomMutation==0) {
        int value = gladiator.getUpperTrunckStrenght();
        cout<<"En la mutacion el int final es: "<<value<<endl;
        string data=convertToString(value,1);
        int newValue=changeValue(data,1);
        gladiator.setUpperTrunckStrenght(newValue);
        cout<<"Se muto UTS"<<endl;
    }
    if(randomMutation==1) {
        int value = gladiator.getLowerTrunckStrenght();
        cout<<"En la mutacion el int final es: "<<value<<endl;

        string data=convertToString(value,1);
        int newValue=changeValue(data,1);
        gladiator.setLowerTrunckStrenght(newValue);
        cout<<"Se muto LTS"<<endl;
    }
    if(randomMutation==2) {
        int value = gladiator.getAnger();
        cout<<"En la mutacion el int final es: "<<value<<endl;

        string data=convertToString(value,2);
        int newValue=changeValue(data,2);
        gladiator.setAnger(newValue);
        cout<<"Se muto Anger"<<endl;
    }
    if(randomMutation==3) {
        int value = gladiator.getSelfControl();
        cout<<"En la mutacion el int final es: "<<value<<endl;

        string data=convertToString(value,2);
        int newValue=changeValue(data,2);
        gladiator.setSelfcontrol(newValue);
        cout<<"Se muto SC"<<endl;
    }
    if(randomMutation==4) {
        int value = gladiator.getPhysicalCondition();
        cout<<"En la mutacion el int final es: "<<value<<endl;

        string data=convertToString(value,1);
        int newValue=changeValue(data,1);
        gladiator.setPhysicalCondition(newValue);
        cout<<"Se muto PC"<<endl;
    }
}

int GeneticEvolution::changeValue(string value, int type) {
    int random;
    if(type==1){
        random=rand()% 9;
    }else{
        random=rand()% 4;
    }
    cout<<"En la mutacion el string inicial es: "<<value<<endl;
    if ("0" == string(1, value[random])) {
        value=value.erase(random,1);
        value=value.insert(random,"1");
    }else{
        value=value.erase(random,1);
        value=value.insert(random,"0");
    }
    cout<<"En la mutacion el string final es: "<<value<<endl;
    int newValue=convertToDecimal(value,type);
    cout<<"En la mutacion el int final es: "<<newValue<<endl;
    return newValue;
}


void GeneticEvolution::crossover(Army army,int index1, int index2) {
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
            son.setUpperTrunckStrenght(makeExchange(stringTrait1, stringTrait2, sonGene,1));

        }else if (i == 2) {
            int trait1= parent1.getLowerTrunckStrenght();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getLowerTrunckStrenght();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000";
            son.setLowerTrunckStrenght(makeExchange(stringTrait1, stringTrait2, sonGene,1));


        }else if (i == 3) {
            int trait1= parent1.getAnger();
            string stringTrait1=convertToString(trait1,2);
            int trait2=parent2.getAnger();
            string stringTrait2=convertToString(trait2,2);
            string sonGene="00000";
            son.setAnger(makeExchange(stringTrait1, stringTrait2, sonGene,2));

        }else if (i == 4) {
            int trait1= parent1.getSelfControl();
            string stringTrait1=convertToString(trait1,2);
            int trait2=parent2.getSelfControl();
            string stringTrait2=convertToString(trait2,2);
            string sonGene="00000";
            son.setAnger(makeExchange(stringTrait1, stringTrait2, sonGene,2));


        }else if (i == 5) {
            int trait1= parent1.getPhysicalCondition();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getPhysicalCondition();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000";
            son.setPhysicalCondition(makeExchange(stringTrait1, stringTrait2, sonGene,1));
        }
    }

    /*! Se asignan a son1, son2, son3 los atributos que son de "calcular" y los que no se heredan de sus padres.*/
    son.setId(lastId+1);
    son.setEmotionalInt(son.calculateEmotionalInt());
    son.setResistance(son.calculateResistance());
    lastId=son.getId();

    int randomMutation = rand() % 100 + 1;
    if (randomMutation < 6) {
        mutation(son);
        son.setEmotionalInt(son.calculateEmotionalInt());
        son.setResistance(son.calculateResistance());
        cout <<"Se aplico mutacion en 5 a la generacion "<<generationCount<< endl;
    }
    /*! Se asigna tmp1 y tmp2 al gladiador menos apto y el segundo menos apto respectivamente*/
    army.gladiators.getNode(0)->setData(son);
    cout << "El nuevo valor del mansote 0 es: " << army.gladiators[0].getResistance() << endl;
    cout << "El upper: " << army.gladiators[0].getUpperTrunckStrenght() << endl;
    cout << "El lower: " << army.gladiators[0].getLowerTrunckStrenght() << endl;
    cout << "El Emotional: " << army.gladiators[0].getEmotionalInt() << endl;
    cout << "El mi edad: " << army.gladiators[0].getAge() << endl;
    cout << "El id: " << army.gladiators[0].getId() << endl;

    /*! Se ordena la lista de gladiadores*/
    army.insertionSort(army.gladiators);
    army.printArray(army.gladiators, army.armySize);

}
int GeneticEvolution::convertToDecimal(string trait, int type) {
    int size;
    if (type==1)size=9;
    else size=4;

    int value=0;
    for(int i=0; i<=size; i++){
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

int GeneticEvolution::makeExchange(string parent1, string parent2,string son,int type) {
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
    return convertToDecimal(son, type);
}

void GeneticEvolution::updateAge(Army army) {
    for(int i=0;i<=19;i++){
        army.gladiators.getData(i).setAge(army.gladiators.getData(i).getAge()+1);
        army.gladiators.getData(i).setResistance(army.gladiators.getData(i).calculateResistance());
        army.gladiators.getData(i).setFitness(army.gladiators.getData(i).calculateFitness());
        /*! Falta volver a calcular la prob de supervivencia y las genExpec*/
    }
    army.insertionSort(army.gladiators);
}
