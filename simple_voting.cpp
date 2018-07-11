#include<employeeD.hpp>

using namespace eosio;
using namespace std;

namespace employeeDatas{
class employee: public contract{
        using contract::contract;

        public:
                employee(account_name self):
                        contract(self){}


         //@abi action
              void addcan(account_name _nam,uint64_t _ex){

                _cantabs cantabs(_self,_self);

                auto iter = cantabs.find(_nam);

                if(iter == cantabs.end()){
                        cantabs.emplace(_self,[&](auto& can){ 

                        can._name = _nam;
                        can.exp = _ex;
                        });
                } else{
                        print("The Polician already exsists");
                }

                }



        //@abi action
        void canvot(account_name _name){


                 _cantabs cantabs(_self,_self);

                auto iter = cantabs.find(_name);


                         if(iter == cantabs.end()){

                                print("just modified");
                }else{

                cantabs.modify(iter,_self,[&](auto& cant){


                cant.tot = cant.tot + 1;

                });


                }       


        }




                ///@abi table cantabs i64

              struct cantabs{

                account_name _name;
                uint64_t exp;
                uint64_t tot = 0;

                uint64_t primary_key() const {return _name;}

                EOSLIB_SERIALIZE(cantabs,(_name)(exp)(tot));

                }; 

                typedef multi_index<N(cantabs),cantabs> _cantabs;
};

EOSIO_ABI(employee, (addcan)(canvot));
}






