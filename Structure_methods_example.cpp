
#include<eosiolib/eosio.hpp>
#include<eosiolib/print.hpp>
#include<print>

using namespace eosio;
using namespace std;
using std::string;


namespace employeeDatas{
class employee: public contract{
        using contract::contract;

        public:
                employee(account_name self):
                        contract(self){}


         //@abi action
        void addtask(account_name _name,string _tas,string _dead){
        _task tasks(_self,_self);

        auto iter = tasks.find(_name);

        if(iter == tasks.end()){

                tasks.emplace(_self,[&](auto& tas){

                tas._name = _name;
                tas._tks = _tas;
                tas._dead = _dead;

  
                });
        }else{


                print("The task is already pending");
        }



        }


        //@abi action
        void delt(account_name _name){

        _task tasks(_self,_self);

        auto iter = tasks.find(_name);

        if(iter != tasks.end()){

                tasks.erase(iter);
	} else{

        print("The required task holder is not available");
        }
        }


        //@abi action
        void updation(account_name _name,string _ts,string _dead){

        _task tasks(_self,_self);

        auto iter = tasks.find(_name);
        if(iter != tasks.end()){
                tasks.modify(iter,_self,[&](auto& tas){


                tas._tks = _ts;
                tas._dead = _dead;
                });
        }
        else{
                print("We cant update because the todo row is not exsist");
        }
        }

        ///@abi table tasks i64

        struct tasks{

        account_name _name;
        string _tks;
        string _dead;
        uint64_t primary_key() const{return _name;}

        EOSLIB_SERIALIZE(tasks,(_name)(_tks)(_dead));
        };

        typedef multi_index<N(tasks),tasks> _task;
};
EOSIO_ABI(employee,(addtask)(delt)(updation))

}



