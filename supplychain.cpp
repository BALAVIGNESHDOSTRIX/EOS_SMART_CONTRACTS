#include<employeeD.hpp>

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
        void fareg(account_name _name,uint64_t _age,string add_,uint64_t cont_){

        _faregis regis(_self,_self);

        auto iter = regis.find(_name);

        if(iter == regis.end()){

                regis.emplace(_self,[&](auto& reg){
                        reg._name = _name;
                        reg.age = _age;
                        reg.address_ = add_;
                        reg.contact_ = cont_;
                });
        }else{
                print("The name is already exsists");   
        }
        }

        //@abi action
        void addprobyfar(account_name _nam,string _proname,uint64_t _price,uint64_t _qty){

                _faregis regis(_self,_self);

                if(iter == regis.end()){
                        print("The name you should have to create");
                }else{
                        
                        _farmer farmers(_self,_self);

                        farmers.emplace(_self,[&](auto& farm){
                                
                                farm._name = _nam;
                                farm.proname = _proname;
                                farm.price = _price;
                                farm.qty = _qty;
                        });
                }
}


        //@abi action
        void supregis(account_name _name,uint64_t _exp,uint64_t _contact,string _add){

        _supreg supregis(_self,_self);

        auto iter = supregis.find(_name);
        
        if(iter == supregis.end()){
                 supregis.emplace(_self,[&](auto& sup){

        sup._name = _name;
        sup.exp = _exp;
        sup._cont = _contact;
        sup._address = _add;
        });

        }else{
                print("The name is already exsists");
                }
        }       

        //@abi action
        void supbuypro(account_name _supnm,string _farnam,string pronam_,uint64_t _price,uint64_t _qty){  
 _supreg supregis(_self,_self);

        auto iter = supregis.find(_name);

        if(iter == supregis.end()){
                print("The name is not exsists");
                }else{
                        _supbuy supbuys(_self,_self);

                        supbuys.emplace(_self,[&](auto& buy){

                                buy.supnam = _supnm;
                                buy.farmern = _farnam;
                                buy.proname = pronam_;
                                buy.price = _price;
                                buy.qty = _qty;
                        });


                }
        }
//@abi table farmerpro i64

        struct farmerpro{
        account_name _name;
        string proname;
        string price;
        uint64_t qty;
        
        uint64_t primary_key() const{return _name;}
        EOSLIB_SERIALIZE(farmerproduct, (_name)(proname)(price)(qty));
        };

        typedef multi_index<N(farmerpro),farmerpro> _farmer;  //farmer product details

        //@abi table fareg i64
        struct fareg{
        account_name _name;
        uint64_t age;
        string address_;
        uint64_t contact_;

        uint64_t primary_key() const{return _name;}
        EOSLIB_SERIALIZE(fareg,(_name)(age)(address_)(contact_));

        
        };

        typedef multi_index<N(fareg),fareg> _faregis; //farmer Registration

   //@abi table supreg i64
        struct supreg{
        account_name _name;
        uint64_t exp;
        uint64_t _cont;
        string _address;

        uint64_t primary_key() const{return _name;}

        EOSLIB_SERIALIZE(supreg,(_name)(exp)(_cont)(_address))


        };
        typedef multi_index<N(supreg),supreg> _supreg; //Supplier Registration

 //@abi table supbuy i64

        struct supbuy{


        account_name supnam;
        string farmern;
        string proname;
        uint64_t price;
        uint64_t qty;

        uint64_t primary_key() const{return supnam;}

        EOSLIB_SERIALIZE(supbuy,(supnam)(farmern)(proname)(price)(qty));
        };

        typedef multi_index<N(supbuy),supbuy> _supbuy;


        //@abi table farmdash i64

        struct farmdash{

                account_name _name;
                string _supname;
                string proname;
                uint64_t price_;
                uint64_t qty;
                uint64_t _date;

                uint64_t primary_key() const{return _name;}

                EOSLIB_SERIEALIZE(farmdash,(_name)(_supname)(proname)(price_)(qty)(_date));
        };

        typedef multi_index<N(farmdash),farmdash> _farmdash;

};
EOSIO_ABI(employee,(fareg)(addprobyfar)(supregis)(supbuypro))

}





