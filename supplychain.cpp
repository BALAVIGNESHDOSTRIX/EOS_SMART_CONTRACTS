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
        void fareg(uint64_t _tim,string _nam,uint64_t _cont,uint64_t time_,uint64_t _pass){

        _faregis faregs(_self,_self);

        auto iter = faregs.find(_tim);

        if(iter == faregs.end()){

                faregs.emplace(_self,[&](auto& reg){
                        reg._time = _tim;
                        reg._name = _nam;
                        reg.contact = _cont;
                        reg.password = _pass;
                });
        }else{
                print("The name is already exsists");   
        }
}


 //@abi table faregis i64
        struct faregis{
        uint64_t _time;
        string _name;
        uint64_t contact;
        uint64_t timeadd;
        uint64_t password;


        uint64_t primary_key() const{return _time;}
        EOSLIB_SERIALIZE(faregis,(_time)(_name)(contact)(timeadd)(password));


};

typedef multi_index<N(faregis),faregis> _faregis; //farmer Registration

 //@abi action
  void addprobyfar(uint64_t _time,string _farname,uint64_t _price,uint64_t _qty,string _cropname){

                _faregis regis(_self,_self);
                auto iter = regis.find(_time);


                if(iter == regis.end()){
                        print("The name you should have to create");
                }else{
                        
                        _farmer farmers(_self,_self);

                        auto iter = farmers.find(_time);

                        if(iter == farmers.end()){
                        farmers.emplace(_self,[&](auto& farm){

                                farm._time = _time;
                                farm._farmern = _farname;
                                farm.price = _price;
                                farm._qty = _qty;
                                farm._cropname = _cropname;
                        });
                        }else{
                                print(" The details are already exsists");
                        }

        
                }
}
  //@abi table farmerpro i64
        struct farmerpro{
        uint64_t _time;
        string _farmern;
        uint64_t price;
        uint64_t _qty;
        string _cropname;
    
        uint64_t primary_key() const{return _time;}
        EOSLIB_SERIALIZE(farmerpro,(_time)(_farmern)(price)(_qty)(_cropname));
        };

typedef multi_index<N(farmerpro),farmerpro> _farmer; //farmer product details


//@abi action
        void supregis(uint64_t _time,string _supn,uint64_t _pas,string _add){

        _supreg supregis(_self,_self);

        auto iter = supregis.find(_time);

        if(iter == supregis.end()){
                 supregis.emplace(_self,[&](auto& sup){

        sup._time = _time;
        sup._supname = _supn;
        sup.pass = _pas;
        sup._address = _add;
        });

        }else{
                print("The name is already exsists");
                }
} 


         //@abi table supreg i64
        struct supreg{
        uint64_t _time;
        string _supname;
        uint64_t pass;
        string _address;

        uint64_t primary_key() const{return _time;}

        EOSLIB_SERIALIZE(supreg,(_time)(_supname)(pass)(_address))


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

