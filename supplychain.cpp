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

        _faregis faregs(_self,_self);

        auto iter = faregs.find(_name);

        if(iter == faregs.end()){

                faregs.emplace(_self,[&](auto& reg){
                        reg._name = _name;
                        reg.age = _age;
                        reg.address_ = add_;
                        reg.contact_ = cont_;
                });
        }else{
                print("The name is already exsists");   
        }
}

        //@abi table faregis i64
        struct faregis{
        account_name _name;
        uint64_t age;
        string address_;
        uint64_t contact_;

        uint64_t primary_key() const{return _name;}
        EOSLIB_SERIALIZE(faregis,(_name)(age)(address_)(contact_));


};

typedef multi_index<N(faregis),faregis> _faregis; //farmer Registration


 //@abi action
  void addprobyfar(account_name _nam,string _proname,uint64_t _price,uint64_t _qty){

                _faregis regis(_self,_self);
                auto iter = regis.find(_nam);


                if(iter == regis.end()){
                        print("The name you should have to create");
                }else{

                        _farmer farmers(_self,_self);

                        farmers.emplace(_self,[&](auto& farm){

                                farm._name = _nam;
                                farm.proname.push_back(_proname);
                                farm.price = _price;
                                farm.qty = _qty;
                        });
                }
}


 //@abi table farmerpro i64
        struct farmerpro{
        account_name _name;
        vector<string> proname;
        string price;
        uint64_t qty;

        uint64_t primary_key() const{return _name;}
        EOSLIB_SERIALIZE(farmerpro, (_name)(proname)(price)(qty));
        };

typedef multi_index<N(farmerpro),farmerpro> _farmer; //farmer product details


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


//@abi action
        void supbuypro(account_name _supnm,uint64_t _time,account_name _farnam,string pronam_,uint64_t _price,uint64_t _qty){  
 _supreg supregis(_self,_self);

        auto iter = supregis.find(_supnm);

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

                        _farmdash farmdash(_self,_self);

                        farmdash.emplace(_self,[&](auto& farm){
                                farm._farmn =  _farnam;
                                farm._supname = _supnm;
                                farm._cropname = pronam_;
                        });

                        _farmdashi farms(_self,_self);

                        farms.emplace(_self,[&](auto& mrs){

                        mrs._farmnm = _farnam;
                        mrs._qty = _qty;
                        mrs._price = _price;
                        mrs._qty = _qty;
                        mrs._date = _time;
                        });
 }
}


            struct supbuy{


        account_name supnam;
        account_name farmern;
        string proname;
        uint64_t price;
        uint64_t qty;

        uint64_t primary_key() const{return supnam;}

        EOSLIB_SERIALIZE(supbuy,(supnam)(farmern)(proname)(price)(qty));
        };

typedef multi_index<N(supbuy),supbuy> _supbuy;

//@abi table farmdash i64

        struct farmdash{
                account_name _farmn;
                account_name _supname;
                string _cropname;

                uint64_t primary_key() const{return _farmn;}
                EOSLIB_SERIALIZE(farmdash,(_farmn)(_supname)(_cropname));
        };

     typedef multi_index<N(farmdash),farmdash> _farmdash;//farmaer dashboard information
 //@abi table farmdashi i64

        struct farmdashi{

                account_name _farmnm;
                uint64_t _qty;
                uint64_t _price;
                uint64_t _date;

               uint64_t primary_key() const{return _farmnm;} 
                EOSLIB_SERIALIZE(farmdashi,(_farmnm)(_qty)(_price)(_date));
        }; 

        typedef multi_index<N(farmdashi),farmdashi> _farmdashi; //Framer dashboard information


};

EOSIO_ABI(employee,(fareg)(addprobyfar)(supregis)(supbuypro))
}
