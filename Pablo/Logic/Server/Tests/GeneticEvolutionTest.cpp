#include "GeneticEvolution.h"

GeneticEvolution::GeneticEvolution() {
    this->generationCount = 0;
    this->crossingMask1 = "1110010110110010110110101101001110101010";
    this->crossingMask2 = "1010111010101110010110101101001110101010";
    this->crossingMask3 = "1010110100111010101010101110101011100101";
    this->lastId=20;

}

void GeneticEvolution::mutation(Gladiator &gladiator) {
    int randomMutation = rand() % 4;

    if(randomMutation==0) {
        cout<<"upper strenght"<<endl;
        int value = gladiator.getUpperTrunckStrenght();
        cout<<"En la mutacion el int final es: "<<value<<endl;
        string data=convertToString(value,1);
        int newValue= mutateChromosome(data, 1);
        gladiator.setUpperTrunckStrenght(newValue);
        cout<<"Se muto UTS"<<endl;
    }
    if(randomMutation==1) {
        cout<<"lower strenght"<<endl;
        int value = gladiator.getLowerTrunckStrenght();
        cout<<"En la mutacion el int final es: "<<value<<endl;
        string data=convertToString(value,1);
        int newValue= mutateChromosome(data, 1);
        gladiator.setLowerTrunckStrenght(newValue);
        cout<<"Se muto LTS"<<endl;
    }
    if(randomMutation==2) {
        cout<<"anger"<<endl;
        int value = gladiator.getAnger();
        cout<<"En la mutacion el int final es: "<<value<<endl;
        string data=convertToString(value,2);
        int newValue= mutateChromosome(data, 2);
        gladiator.setAnger(newValue);
        cout<<"Se muto Anger"<<endl;
    }
    if(randomMutation==3) {
        cout<<"self control"<<endl;
        int value = gladiator.getSelfControl();
        cout<<"En la mutacion el int final es: "<<value<<endl;
        string data=convertToString(value,2);
        int newValue= mutateChromosome(data, 2);
        gladiator.setSelfcontrol(newValue);
        cout<<"Se muto SC"<<endl;
    }
    if(randomMutation==4) {
        cout<<"physical condi"<<endl;
        int value = gladiator.getPhysicalCondition();
        cout<<"En la mutacion el int final es: "<<value<<endl;
        string data=convertToString(value,1);
        int newValue= mutateChromosome(data, 1);
        gladiator.setPhysicalCondition(newValue);
        cout<<"Se muto PC"<<endl;
    }
}

void GeneticEvolution::invertion(Gladiator &gladiator) {
    int randomMutation = rand() % 4;
    if(randomMutation==0) {
        cout<<"upper strenght"<<endl;
        string data=convertToString(gladiator.getUpperTrunckStrenght(),1);
        int newValue= invertGene(data, 1);
        gladiator.setUpperTrunckStrenght(newValue);
        cout<<"Se muto UTS"<<endl;
    }

    if(randomMutation==1) {
        cout<<"lower strenght"<<endl;
        string data=convertToString(gladiator.getLowerTrunckStrenght(),1);
        int newValue= invertGene(data, 1);
        gladiator.setLowerTrunckStrenght(newValue);
        cout<<"Se muto LTS"<<endl;
    }
    if(randomMutation==2) {
        cout<<"el valor del anger: "<<gladiator.getAnger()<<endl;
        string data=convertToString(gladiator.getAnger(),2);
        int newValue= invertGene(data, 2);
        gladiator.setAnger(newValue);
        cout<<"Se muto Anger"<<endl;
    }
    if(randomMutation==3) {
        cout<<"el valor del selfControl: "<<gladiator.getSelfControl()<<endl;
        string data=convertToString(gladiator.getSelfControl(),2);
        int newValue= invertGene(data, 2);
        gladiator.setSelfcontrol(newValue);
        cout<<"Se muto SC"<<endl;
    }
    if(randomMutation==4) {
        cout<<"Physical condi"<<endl;
        string data=convertToString(gladiator.getPhysicalCondition(),1);
        int newValue= invertGene(data, 1);
        gladiator.setPhysicalCondition(newValue);
        cout<<"Se muto PC"<<endl;
    }
}

int GeneticEvolution::mutateChromosome(string value, int type) {
    int random;
    if(type==1){
        random=rand()% 19;
    }else{
        random=rand()% 9;
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

int GeneticEvolution::invertGene(string value, int type) {
    int size;
    int randomInitial;
    int randomFinal;
    if (type==1){
        randomInitial=rand()%17;
        size = 19-randomInitial;
        randomFinal = rand()% size + randomInitial;
    }
    else {
        randomInitial = rand()%7;
        size = 9 -randomInitial;
        randomFinal = rand()%size + randomInitial;
    }
    cout<<"El string inicial en la inversion es: "<<value<<endl;
    for(int i=randomInitial;i<=randomFinal;i++){
        if ("0" == string(1, value[i])) {
            value=value.erase(i,1);
            value=value.insert(i,"1");
        }else{
            value=value.erase(i,1);
            value=value.insert(i,"0");
        }
    }
    cout<<"El string final en la inversion es: "<<value<<endl;
    int newValue=convertToDecimal(value,type);
    return newValue;
}

bool GeneticEvolution::crossover(Army army,int index1, int index2) {
    if(index1 == index2)
        return false;

    Gladiator son;
    Gladiator parent1=army.gladiators.getNode(index1)->getValue();
    Gladiator parent2=army.gladiators.getNode(index2)->getValue();

    for (int i = 1; i <= 5; i++) {

        if (i == 1) {
            int trait1= parent1.getUpperTrunckStrenght();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getUpperTrunckStrenght();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000000000000000000000000000000000";
            son.setUpperTrunckStrenght(makeExchange(stringTrait1, stringTrait2, sonGene,1));

        }else if (i == 2) {
            int trait1= parent1.getLowerTrunckStrenght();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getLowerTrunckStrenght();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000000000000000000000000000000000";
            son.setLowerTrunckStrenght(makeExchange(stringTrait1, stringTrait2, sonGene,1));


        }else if (i == 3) {
            int trait1= parent1.getAnger();
            cout<<"parent1 del Anger"<<trait1<<endl;
            string stringTrait1=convertToString(trait1,2);
            int trait2=parent2.getAnger();
            cout<<"parent2 del Anger"<<trait2<<endl;
            string stringTrait2=convertToString(trait2,2);
            string sonGene="00000000000000000000";
            son.setAnger(makeExchange(stringTrait1, stringTrait2, sonGene,2));

        }else if (i == 4) {
            int trait1= parent1.getSelfControl();
            cout<<"parent1 del self"<<trait1<<endl;
            string stringTrait1=convertToString(trait1,2);
            int trait2=parent2.getSelfControl();
            cout<<"parent2 del self"<<trait2<<endl;
            string stringTrait2=convertToString(trait2,2);
            string sonGene="00000000000000000000";
            son.setSelfcontrol(makeExchange(stringTrait1, stringTrait2, sonGene,2));


        }else if (i == 5) {
            int trait1= parent1.getPhysicalCondition();
            string stringTrait1=convertToString(trait1,1);
            int trait2=parent2.getPhysicalCondition();
            string stringTrait2=convertToString(trait2,1);
            string sonGene="0000000000000000000000000000000000000000";
            son.setPhysicalCondition(makeExchange(stringTrait1, stringTrait2, sonGene,1));
        }
    }

    /*! Se asignan a son1, son2, son3 los atributos que son de "calcular" y los que no se heredan de sus padres.*/
    son.setId(lastId+1);
    son.setEmotionalInt(son.calculateEmotionalInt());
    son.setResistance(son.calculateResistance());
    son.setFitness(son.calculateFitness());
    lastId=son.getId();
    /*!En base a un 5% de probabilidad se realiza la mutacion y con un 3% de probabilidad se realiza la inversion */
    int randomMutation = rand() % 100 + 1;
    if (randomMutation < 6){
        mutation(son);
        if (randomMutation <4) {
            invertion(son);
            son.setEmotionalInt(son.calculateEmotionalInt());
            son.setResistance(son.calculateResistance());
            son.setFitness(son.calculateFitness());
        }else{
            son.setEmotionalInt(son.calculateEmotionalInt());
            son.setResistance(son.calculateResistance());
            son.setFitness(son.calculateFitness());
        }
    }

    /*! Se asigna tmp1 y tmp2 al gladiador menos apto y el segundo menos apto respectivamente*/
    newGladiators.add(son);
    cout << "El gladiador nuevo tiene una resistencia de: " << army.gladiators[0].getResistance() << endl;

    return true;
}

int GeneticEvolution::convertToDecimal(string trait, int type) {
    int size;
    if (type==1)size=39;
    else size=19;

    int value=0;
    for(int i=0; i<=size; i++){
        if("1" == string(1, trait[i])){
            value++;
        }
    }
    return value;
}

string GeneticEvolution::convertToString(int trait,int type) {
    string base;

    if(type==1){
        base="00000000000000000000000000000000000000000";

    }else{
        base="000000000000000000000";

    }

    for(int i=trait; i>=1; i--){
        int random;
        if(type==1) random = rand() % 40;
        else random= rand() % 20;

        if ("1" == string(1, base[random])){
            while("1" == string(1, base[random])){
                if(type==1) random = rand() % 40;
                else random= rand()%20;
            }
            base=base.erase(random,1);
            base=base.insert(random,"1");
        }else{
            base=base.erase(random,1);
            base=base.insert(random,"1");
        }

    }

    if(type==1) base=base.erase(40,1);
    else base=base.erase(20,1);
    return base;
}

int GeneticEvolution::makeExchange(string parent1, string parent2,string son,int type) {
    int size;
    if(type==1)size=39;
    else size=19;
    string mask;
    int randomMask=rand() % 3 +1;
    if (randomMask == 1) mask =crossingMask1;
    else if(randomMask==2) mask =crossingMask2;
    else if(randomMask==3) mask =crossingMask3;
    //cout<<"mascara: "<<mask<<endl;
    for(int i=0; i<=size;i++){
        if("1" == string(1, mask[i])){
            son=son.erase(i,1);
            son=son.insert(i,string(1, parent1[i]));
        }else{
            son=son.erase(i,1);
            son=son.insert(i,string(1, parent2[i]));
        }
    }//cout<<son<<endl;


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

void GeneticEvolution::addNewGladiators(List<Gladiator> newGladiators, Army army){
    int size = newGladiators.size();
    for(int i=0;i<=size-1;i++){
        army.gladiators.getNode(i)->setData(newGladiators.getData(i));
    }

}