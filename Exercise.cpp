#include <iostream>

class OldCoffeeMachine {
    public:
        void selectA(){
            std::cout<<"Coffee flavor A from old machine"<<"\n";
        }
        void selectB(){
            std::cout<<"Coffee flavor B from old machine"<<"\n";
        }
};

class CoffeeMachineInterface {
    public:
        void chooseFirstSelection(){
            std::cout<<"Coffee flavor A from new machine"<<"\n";
        }
        void chooseSecondSelection(){
            std::cout<<"Coffee flavor B from new machine"<<"\n";
        }
};

class CoffeeTouchscreenAdapter : public CoffeeMachineInterface {
    private:
        OldCoffeeMachine* oldVendingMachine;
    public:
        CoffeeTouchscreenAdapter(OldCoffeeMachine* oldMachine){
            oldVendingMachine = oldMachine;
        }
        void chooseFirstSelection(){
            oldVendingMachine->selectA();
        }
        void chooseSecondSelection(){
            oldVendingMachine->selectB();
        }
};

int main(){
    OldCoffeeMachine* oldVendingMachine = new OldCoffeeMachine;
    CoffeeMachineInterface* newMachine = new CoffeeMachineInterface;
    CoffeeTouchscreenAdapter* oldMachine = new CoffeeTouchscreenAdapter(oldVendingMachine);

    newMachine->chooseFirstSelection();
    newMachine->chooseSecondSelection();
    oldMachine->chooseFirstSelection();
    oldMachine->chooseSecondSelection();

    return 0;
}