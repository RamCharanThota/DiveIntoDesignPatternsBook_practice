#include<iostream>

class DataBase{
    static DataBase* db_reference;
    int data_;
    DataBase(){
        data_=0;
    }

    public:
    static DataBase* getInstance(){
        if(!db_reference){
            db_reference=new DataBase;
        }
         return db_reference;
    }

    int getData(){
        return this-> data_;
    }
    void setData(int data){
        this->data_=data;
    }
    ~DataBase(){
        delete db_reference;
    }
    

};

DataBase *DataBase::db_reference=0;

int main(){
   DataBase *db=db->getInstance();
   db->setData(10);
   std::cout<<" the assigned value is "<<db->getData()<<std::endl;

   DataBase *cg=cg->getInstance();
   std::cout<<" the assigned value is "<<cg->getData()<<std::endl;



}