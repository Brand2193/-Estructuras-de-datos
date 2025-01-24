#include "dynStack.h"

class BALANCER{
    private: 
        STACK<char> stack_1, stack_2;
        char *sample;
        int length;
        string text;   

        void initializeArray(){
            this->sample = new char[6];
            this->sample[0] = '('; this->sample[1] = '[';
            this->sample[2] = '{'; this->sample[3] = ')'; 
            this->sample[4] = ']'; this->sample[5] = '}';
        }

    public: 
        BALANCER(){}

        BALANCER(string text){
            this->stack_1.~STACK();
            this->stack_2.~STACK();
            this->text = text;
            this->length = this->text.length();
            initializeArray();
        }

        bool checkBalance(){
            for(int j=0; j<3; j++){
                for(int i=0; i<this->length; i++){
                    if(this->text[i] == this->sample[j])
                        this->stack_1.push(this->sample[j]);
                    else if(this->text[i] == this->sample[j+3])
                        this->stack_2.push(this->sample[j+3]);
                }
                if(this->stack_1.dataAmount() != this->stack_2.dataAmount())
                    return(false);
            }
            return(true);
        }
};