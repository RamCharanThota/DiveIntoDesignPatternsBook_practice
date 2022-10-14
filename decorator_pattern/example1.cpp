#include<iostream>
#include<vector>
#include<string>

class DataSource{
    public:
    virtual void writeData(std::string data)=0;
    virtual std::string readData()=0;
};

class FileDataSource:public DataSource{
    std::string filename_;
    std::string data_;

    public:
    FileDataSource(std::string filename){
        filename_=filename;
    }

    void writeData(std::string data){
        std::cout<<"writing data to a file from file  source "<<filename_<<std::endl;
        data_=data;

    }

    std::string readData(){
        std::cout<<"reading data from a filesource "<<filename_<<std::endl;
        return data_;
        
    }

};

// it is a base decorator claass for the decorators
class DataSourceDecorator:public DataSource{
    protected:
    DataSource* wrapee_;
    public:
    DataSourceDecorator(DataSource* source){
        wrapee_=source;
    }

    void writeData(std::string data){
        wrapee_->writeData(data);
    }
    std::string readData(){
        return wrapee_->readData();
    }
};

class EncryptionDecorator:public DataSourceDecorator{

    public:

    void writeData(std::string data){
        // encrypte the data here
        std::string data="encrypted"+data;

        wrapee_->writeData(data);
    }
    std::string readData(){
        std::string encry_data= wrapee_->readData();
        //decrypt the data
        std::string decrypt =encry_data+"decrypted";
        return decrypt;

    }
};

class CompressionDecorator:public DataSourceDecorator{

    public:
    void writeData(std::string data){
        // compress the data here
        std::string data="compressed"+data;

        wrapee_->writeData(data);
    }
    std::string readData(){
        std::string encry_data= wrapee_->readData();
        //extract the data
        std::string decrypt =encry_data+"extracted";
        return decrypt;

    }
};

int main(){
    FileDataSource source("my file.txt");
    source.writeData("salaryrecord");// data is written with plan data

    // write data with encrypted data
    CompressionDecorator cdata(&source);
    source.
}