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
  void addprobyfar(account_name _nam,string farmn,account_name _proname,uint64_t _price,uint64_t _qty){

                _faregis regis(_self,_self);
                auto iter = regis.find(_nam);


                if(iter == regis.end()){
                        print("The name you should have to create");
                }else{

                        _farmer farmers(_self,_self);

                        auto iter = farmers.find(_proname);

                        if(iter == farmers.end()){
                        farmers.emplace(_self,[&](auto& farm){

                                farm.proname = _proname;
                                farm._farmern = farmn;
                                farm.price = _price;
                                farm._qty = _qty;

                        });
                        }else{
                                print(" The details are already exsists");
                        }



                }
}
 //@abi table farmerpro i64
        struct farmerpro{
        account_name proname;
        string _farmern;
        uint64_t price;
        uint64_t _qty;
    
        uint64_t primary_key() const{return proname;}
        EOSLIB_SERIALIZE(farmerpro,(proname)(_farmern)(price)(_qty));
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
        void supbuypro(account_name _supnm,string _supnmk,uint64_t _time,string _farnam,string pronam_,uint64_t _price,uint64_t _qty){  
        
        _supreg supregis(_self,_self);
 
        auto iter = supregis.find(_supnm);

        if(iter == supregis.end()){
                print("The name is not exsists");
                }else{
                        _supbuy supbuys(_self,_self);

                        auto iter = supbuys.find(_time);
                        if(iter == supbuys.end()){

                         supbuys.emplace(_self,[&](auto& buy){

                                buy._time = _time;
                                buy.farmern = _farnam;
                                buy.proname = pronam_;
                                buy.price = _price;
                                buy.qty = _qty;
                        });
        

                        _fardash dashs(_self,_self);

                        auto ite = dashs.find(_time);
                        if(ite == dashs.end()){

 dashs.emplace(_self,[&](auto& shs){

                                                shs._time = _time;
                                                shs._supname = _supnmk;
                                                shs._cropm = pronam_;
                                                shs.qty = _qty;
                                                shs.price = _price;
                                        });
                                }
                        }
                }
}

//@abi table supbuy i64
            struct supbuy{
        uint64_t _time;
        string farmern;
        string proname;
        uint64_t price;
        uint64_t qty;

        uint64_t primary_key() const{return _time;}

        EOSLIB_SERIALIZE(supbuy,(_time)(farmern)(proname)(price)(qty));
        };

typedef multi_index<N(supbuy),supbuy> _supbuy;
//@abi table fardash i64

        struct fardash{

        uint64_t _time;
        string _supname;
        string _cropm;
        uint64_t qty;
        uint64_t price;
        uint64_t primary_key() const{return _time;}

        EOSLIB_SERIALIZE(fardash,(_time)(_supname)(_cropm)(qty)(price));
        };      

        typedef multi_index<N(fardash),fardash> _fardash;
        


};

EOSIO_ABI(employee,(fareg)(addprobyfar)(supregis)(supbuypro))
}

