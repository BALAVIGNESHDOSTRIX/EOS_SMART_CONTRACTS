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
        void fareg(account_name _id,string _nam,uint64_t _cont,uint64_t _pass){


        _faregis faregs(_self,_self);


        auto iter = faregs.find(_id);


        if(iter == faregs.end()){



                faregs.emplace(_self,[&](auto& reg){
                        reg._id = _id;
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
        account_name _id;
        string _name;
        uint64_t contact;
        uint64_t password;



        uint64_t primary_key() const{return _id;}
        EOSLIB_SERIALIZE(faregis,(_id)(_name)(contact)(password));


};
typedef multi_index<N(faregis),faregis> _faregis; //farmer Registration

//add a product by the farmer

//@abi action
  void addprobyfar(account_name _farmid,account_name proid,string far_n,uint64_t _price,uint64_t _qty,string _cropname){

                _faregis regis(_self,_self);
                auto iter = regis.find(_farmid);


                if(iter == regis.end()){
                        print("The name you should have to create");
                }else{

                        _farmer farmers(_self,_self);

                        auto iter = farmers.find(proid);

                        if(iter == farmers.end()){
                        farmers.emplace(_self,[&](auto& farm){

                                farm._proid = proid ;
                                farm.price = _price;
                                farm._qty = _qty;
                                farm._cropname = _cropname;
                                farm._farmernm = far_n;
                        });
                        }else{
                                print(" The details are already exsists");
                        }


                }
}


//@abi table farmerpro i64
        struct farmerpro{
        account_name _proid;
        string _farmernm;
        uint64_t price;
        uint64_t _qty;
        string _cropname;
    
        uint64_t primary_key() const{return _proid;}
        EOSLIB_SERIALIZE(farmerpro,(_proid)(_farmernm)(price)(_qty)(_cropname));
        };

typedef multi_index<N(farmerpro),farmerpro> _farmer; //farmer product details



//@abi action
        void supregis(account_name _supid,string _supn,uint64_t _pas,string _add){

        _supreg supregis(_self,_self);

        auto iter = supregis.find(_supid);

        if(iter == supregis.end()){
                 supregis.emplace(_self,[&](auto& sup){

        sup._supid = _supid;
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
        account_name _supid;
        string _supname;
        uint64_t pass;
        string _address;

        uint64_t primary_key() const{return _supid;}

        EOSLIB_SERIALIZE(supreg,(_supid)(_supname)(pass)(_address))


        };
typedef multi_index<N(supreg),supreg> _supreg; //Supplier Registration


//@abi action
        void supproby(account_name _supid,account_name farid,account_name proid,
                        string sup_n,string fanam,string pro_n,uint64_t _qty,uint64_t _price,string dat_,account_name unid,string cropn_,uint64_t pay,uint64_t _balance){

        _supreg sups(_self,_self);

        auto iter = sups.find(_supid);
        if(iter == sups.end()){

        print("The suplier is not exsists");    
        }else{

                _faregis farss(_self,_self);
                auto itr = farss.find(farid);

                if(itr == farss.end()){
                        print("The required former is not available");
                }else{
                        _farmer farpros(_self,_self);

                        auto itrr = farpros.find(proid);

                        if(itrr == farpros.end()){

                                print("the required crop is not available");
                        }else{

                                _supbuy subss(_self,_self);

                                auto itk = subss.find(proid);

                                if(itk == subss.end()){

                                        subss.emplace(_self,[&](auto& sub){
					sub.supid = _supid;
                                        sub.cropid = proid;
                                        sub.farmern = fanam;
                                        sub.proname = pro_n;
                                        });



                                }

                                _subuy buys(_self,_self);

                                auto itkk = buys.find(proid);

                                if(itkk == buys.end()){

                                        buys.emplace(_self,[&](auto& by){

                                                by._supid = _supid;
                                                by.cropid = proid;
                                                by._qty = _qty;
                                                by._price = _price;
                                                });
                                        }else{ print("The details are already exsists");}

                                _farmdss dash(_self,_self);


 				//account_name comp= _supid +  proid;
                                auto uinq = dash.find(unid); //unique id is generated by using proid with supplier id

                                        if(uinq == dash.end()){

                                                dash.emplace(_self,[&](auto& sh){

                                                        sh.unid = unid;
                                                        sh.supid= _supid;
                                                        sh.balance = _balance;
                                                        });
                                        }else{print("The details are already exsists");}


                                _ashfarm farmss(_self,_self);

                                auto ktr = farmss.find(unid);

                                if(ktr == farmss.end()){

                                        farmss.emplace(_self,[&](auto& mss){

                                                mss.unid = unid;
                                                mss.farnm = fanam;
                                                mss.date_ = dat_;
                                                mss.cropn = cropn_;
					 });
                                        }else{print("The details are already exsists");}


                                _datafar datass(_self,_self);

                                auto kms= datass.find(unid);

                                if(kms == datass.end()){

                                        datass.emplace(_self,[&](auto& ass){

                                                ass.unid = unid;
                                                ass.qty = _qty;
                                                ass.price = _price;
                                                ass.totalpr = _qty * _price;
                                                });
                                        }else{print("The details are already exsists");}

                                _farmsh mshs(_self,_self);

                                auto ssh = mshs.find(unid);

                                if(ssh == mshs.end()){

                                        mshs.emplace(_self,[&](auto& shs){
  						shs.unid =unid;
                                                shs.proid = proid;
                                                shs.paid = pay;
                                                });
                                        }else{print("The details are already exsists");}
                                }

                }
        }
        }
//@abi table supbuy i64
      struct supbuy{
        account_name supid;
        account_name cropid;
        string farmern;
        string proname;


        uint64_t primary_key() const{return cropid;}

        EOSLIB_SERIALIZE(supbuy,(supid)(cropid)(farmern)(proname));
        };

typedef multi_index<N(supbuy),supbuy> _supbuy;


//@abi table subuy i64

        struct subuy{

        account_name _supid;
        account_name cropid;
        uint64_t _qty;
        uint64_t _price;


        uint64_t primary_key() const{return cropid;}

        EOSLIB_SERIALIZE(subuy,(_supid)(cropid)(_qty)(_price))

        };
        typedef multi_index<N(subuy),subuy> _subuy;
//Farmer Dashboard


        //@abi table farmdash i64

        struct farmdash{

        account_name unid;
        account_name supid;
        uint64_t balance;

        uint64_t primary_key() const{return unid;}
        EOSLIB_SERIALIZE(farmdash,(unid)(supid)(balance))

        };

        typedef multi_index<N(farmdash),farmdash> _farmdss;

        //@abi table farmsh i64

        struct farmsh{
        account_name unid;
        account_name proid;
        uint64_t paid;
        uint64_t primary_key() const{return unid;}

        EOSLIB_SERIALIZE(farmsh,(unid)(proid)(paid))
        };

        typedef multi_index<N(farmsh),farmsh> _farmsh;
 //@abi table dashfarm i64

        struct dashfarm{
        account_name unid;
        string farnm;
        string date_;
        string cropn;

        uint64_t primary_key() const{return unid;}

        EOSLIB_SERIALIZE(dashfarm,(unid)(farnm)(date_)(cropn))
        };

        typedef multi_index<N(dashfarm),dashfarm> _ashfarm;

        //@abi table datafar i64

        struct datafar{
        account_name unid;
        uint64_t qty;
        uint64_t price;
        uint64_t totalpr;

        uint64_t primary_key() const{return unid;}

        EOSLIB_SERIALIZE(datafar,(unid)(qty)(price)(totalpr))
        };

        typedef multi_index<N(datafar),datafar> _datafar;


};

EOSIO_ABI(employee,(fareg)(addprobyfar)(supregis)(supproby))
}


