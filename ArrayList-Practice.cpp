#include <iostream>
using namespace std;
class TEST{
private:
    int data[10] = {1,5};
    int length = 0;
    int p = 0;
    int preCount(){
        for(p;p<10;p++){
            if(data[p] != NULL) length++;
            else ;
        }
        //cout<<"COUNT:"<<length<<endl;
        return length;
    }

public:
    void insertValue(int value,int index){
        preCount();
        if(length>=index) {
            for(int i = length;i > index;i--){
                data[i] = data[i-1];
            }
            data[index] = value;
        }
        else data[length] = value;
        length++;
    }
    int valueFinder(int value){
        preCount();
        for(int i = 0;i < length;i++){
            if (data[i] != value);
            if(data[i] == value) return i;
        }
    }
    void changeValue(int oldValue,int newValue){
        int j = valueFinder(oldValue);
        if(oldValue != newValue && j != -1)
        {
            data[j] = newValue;
        }
    }
    void removeValue(int value){
        preCount();
        int j = valueFinder(value);
        data[j] = NULL;
        for(int i = j;i < length;i++){
            data[i] = data[i+1];
        }
        for(int i = 0;i<length;i++){
            if(data[i] == NULL) length--;
        }
    }
    void outputValue(){
        preCount();
        for(int i = 0;i < length;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    TEST a;
    a.outputValue();//1,5
    a.insertValue(99,2);
    a.outputValue();//1,5,99
    a.changeValue(99,27);
    a.outputValue();//1,5,27
    a.insertValue(8,9);
    a.outputValue();//1,5,27,8
    a.changeValue(8,3);
    a.outputValue();//1,5,27,3
    a.removeValue(8);
    a.outputValue();//1,5,27,3
    a.insertValue(8,0);
    a.outputValue();//8,1,5,27,3
    a.removeValue(8),a.removeValue(5),a.removeValue(27);
    a.outputValue();//1,3
}