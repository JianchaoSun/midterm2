#include <iostream>
#include<vector>
class Human{
private:
    std::string name;
    int age;
    char sex;
    Human(){

    };
protected:
    Human(std::string n,int a,char s){
        age = a;
        sex = s;
        name = n;
    }
  //  virtual ~Human(){

 //   };
public:
    void printInfo(Human h);
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Human::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Human::age = age;
    }

    char getSex() const {
        return sex;
    }

    void setSex(char sex) {
        Human::sex = sex;
    }
};

class Child : public Human{
private:
    friend class Parent;
    std::string momName;
    std::string dadName;
    int allowance;
    Child():Human("name",10,'f'){

    }
public:
    Child(std::string n,int a, char s,std::string mn,std::string dn):Human(n,a,s),momName(mn),dadName(dn){
        allowance = 0;
    }
    int getAllowance() const{
       // std::cout<<"allowance is : "<<allowance;
        return allowance;
    }
    void printParents(){
        std::cout<<"Father name "<<dadName<<std::endl;
        std::cout<<"Mother name "<<momName<<std::endl;
    }

};

class Parent: public Human{
private:
    std::vector<Child> children;
    Parent():Human("name",10,'m'){

    }
public:
    Parent(std::string n,int a, char s):Human(n,a,s){

    }
    void printChild(){
        for (int i = 0; i < children.size(); ++i)
            std::cout << children[i].getName() << ",";
        std::cout<<"\n";
    }
    void setChild(Child c){
        children.push_back(c);
    }
    void setChildAllowance(int a, Child *c){
        for (int i = 0; i < children.size(); ++i){
            if(children[i].getName().compare(c->getName()) ==0){
                c->allowance = a;
            }
        }
    }


};
void printInfo(Human h){
    std::cout<<"Name"<<h.getName()<<"\n";
    std::cout<<"Age"<<h.getAge()<<"\n";
    std::cout<<"Sex"<<h.getSex()<<"\n";
}


int main() {
    Parent Homer("Homer",36,'M');
    Parent March("March",34,'F');
    Child Lisa("Lisa",12,'F',"Homer","March");
    Child Bart("Bart",10,'M',"Homer","March");
    Child Maggie("Maggie",3,'F',"Homer","March");
    Homer.setChild(Lisa);
    Homer.setChild(Bart);
    Homer.setChild(Maggie);
    March.setChild(Lisa);
    March.setChild(Bart);
    March.setChild(Maggie);
    std::cout<<"Bart's allowance: "<<Bart.getAllowance()<<std::endl;
    Homer.setChildAllowance(5,&Bart);
    std::cout<<"Bart's allowance: "<<Bart.getAllowance()<<std::endl;
    Bart.printParents();
    printInfo(March);
    printInfo(Lisa);

    return 0;
}