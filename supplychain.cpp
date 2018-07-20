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


                                 _farmer mers(_self,_self);

                                auto imr = mers.find(proid);

                                if(imr == mers.end()){

                                        print("The details you have to create");
                                        }else{

                                                mers.modify(imr,_self,[&](auto& rs){

                                                rs._qty = rs._qty - _qty;
                                                });
                                        }
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
 //supplier aprove to sale the product
        //@abi action
        void supsaadd(account_name _proid,string pron_,uint64_t _pric,uint64_t _qty){

        _supsale salesup(_self,_self);

        auto iter = salesup.find(_proid);

        if(iter == salesup.end()){


                salesup.emplace(_self,[&](auto& sup){

                sup.proid = _proid;
                sup._proname = pron_;
                sup.price = _pric;
                sup._qty = _qty;
                });
                }else{print(" The details are already exsists");}

        }
//@abi table supsale i64

        struct supsale{

        account_name proid;
        string _proname;
        uint64_t price;
        uint64_t _qty;

        uint64_t primary_key() const{return proid;}

        EOSLIB_SERIALIZE(supsale,(proid)(_proname)(price)(_qty))
        };
        typedef multi_index<N(supasale),supsale> _supsale;



        //Shop Phase

        //@abi table shopbuy i64

        struct shopbuy{

        account_name proid;
        account_name supid_;
        string supname_;
        string cropn_;

        uint64_t primary_key() const{return proid;}

        EOSLIB_SERIALIZE(shopbuy, (proid)(supid_)(supname_)(cropn_))
        };

        typedef multi_index<N(shopbuy),shopbuy> _shopbuy;

//@abi table shopget i64

        struct shopget{
        account_name proid;
        uint64_t _qty;
        uint64_t price;
        uint64_t totpri;

        uint64_t primary_key() const{return proid;}
        EOSLIB_SERIALIZE(shopget,(proid)(_qty)(price)(totpri))
        };

        typedef multi_index<N(shopget),shopget> _shopget;

 //@abi action
        void shopbuypro(account_name _shopid,account_name supid,account_name proid_,string _supn,string cropn_,string _dat,uint64_t _qty,uint64_t _pric,account_name _uid,string $



                _shopreg shopregs(_self,_self);

                auto iter = shopregs.find(_shopid);

                if(iter == shopregs.end()){

                    print("You have to create a shopkeeper");

                }  else{

                        _supreg supregs(_self,_self);


                        auto imr = supregs.find(supid);

                        if(imr == supregs.end()){

                                print("You have to first create the supplier");
                        }else{

                                _supsale sales(_self,_self);


                                auto opr = sales.find(proid_);

                                if(opr == sales.end()){
                                                print("You have to choose the available product");
                                        }else{

                                                _shopbuy buys(_self,_self);

                                                auto iqr = buys.find(proid_);

                                                if(iqr == buys.end()){


                                                                buys.emplace(_self,[&](auto& bys){

                                                                        bys.proid = proid_;
                                                                        bys.supid_ = supid;
                                                                        bys.supname_ = _supn;
                                                                        bys.cropn_ = cropn_;
                                                                        });
                                                        }else{print("The Details are already available");}
					_shopget getshop(_self,_self);

                                                auto kbl = getshop.find(proid_);

                                                        if(kbl == getshop.end()){

                                                                getshop.emplace(_self,[&](auto& shop){

                                                                shop.proid = proid_;
                                                                shop._qty = _qty;
                                                                shop.price = _pric;
                                                                shop.totpri = _qty * _pric;
                                                                });
                                                                }else{print("The details are already available");}

							_supsale sales(_self,_self);

                                                        auto les = sales.find(proid_);

                                                        if(les == sales.end()){

                                                                print("You have to create the details");
                                                                }else{
                                                                                sales.modify(les,_self,[&](auto& less){

                                                                                        less._qty = less._qty - _qty;
                                                                                });
                                                                        }

                                                                _dashb ashbbs(_self,_self);

                                                                auto ipo = ashbbs.find(_uid);

                                                                if(ipo == ashbbs.end()){

                                                                        ashbbs.emplace(_self,[&](auto& bbs){

                                                                                bbs.uid = _uid;
                                                                                bbs.supnam = _supn;
                                                                                bbs.shopname = _shopn;
                                                                                bbs.cropn = cropn_;
                                                                        });
                                                                        }else{print("The details are already available");}

 								_dashsupk supks(_self,_self);

                                                                auto imol = supks.find(_uid);

                                                                if(imol == supks.end()){

                                                                        supks.emplace(_self,[&](auto& pkss){

                                                                                pkss.uid = _uid;
                                                                                pkss._qty = _qty;
                                                                                pkss._date = _dat;
                                                                                pkss._pric = _pric;
                                                                                });
                                                                        }else{print("The details are already available");}
                                                }
                                }
                }




        }


//Shop registration
 //@abi table shopreg i64

        struct shopreg{
        account_name shop_id;
        string shopna;
        uint64_t contact;
        uint64_t pass;

        uint64_t primary_key() const{return shop_id;}

        EOSLIB_SERIALIZE(shopreg,(shop_id)(shopna)(contact)(pass))
        };

        typedef multi_index<N(shopreg),shopreg> _shopreg;

//@abi action
        void shopregis(account_name _shopid,string _shopn,uint64_t cont,uint64_t _pass){

        _shopreg regis(_self,_self);

        auto ilg = regis.find(_shopid);

                if(ilg == regis.end()){

                        regis.emplace(_self,[&](auto& gis){

                        gis.shop_id = _shopid;
                        gis.shopna = _shopn;
                        gis.contact = cont;
                        gis.pass = _pass;
                        });
                }else{print("The details are already exsists");}
        }


        //@abi table supdashb i64
        struct supdashb{

        account_name uid; //proid + shopid
        string supnam;
        string shopname;
        string cropn;

        uint64_t primary_key() const{return uid;}

        EOSLIB_SERIALIZE(supdashb,(uid)(supnam)(shopname)(cropn))

        };

        typedef multi_index<N(supdashb),supdashb> _dashb;


 //@abi table supbdash i64

        struct supbdash{

        account_name uid; //proid + shopid
        uint64_t _qty;
        string _date;
        uint64_t _pric;

        uint64_t primary_key() const{return uid;}
        EOSLIB_SERIALIZE(supbdash,(uid)(_qty)(_date)(_pric))
        };

        typedef multi_index<N(supbdash),supbdash> _dashsupk;


        //@abi table customerreg i64

        struct customerreg{

        account_name customerid;
        string _name;
        uint64_t pass_;
        string address_;

        uint64_t primary_key() const{return customerid;}

        EOSLIB_SERIALIZE(customerreg,(customerid)(_name)(_name)(pass_)(address_))



        };

        typedef multi_index<N(customerreg),customerreg> _customers;
	
	//@abi action
        void custregis(account_name _customerid,string _nam,uint64_t passt_,string _add){

                _customers merss(_self,_self);

                auto ium = merss.find(_customerid);

                if(ium == merss.end()){

                        merss.emplace(_self,[&](auto& sss){

                                        sss.customerid = _customerid;
                                        sss._name = _nam;
                                        sss.pass_ = passt_;
                                        sss.address_ = _add;
                                });
                        }else{print("The details are already available");}

        }
//@abi table shopadsale i64

        struct shopadsale {

        account_name proid;
        string crop_name;
        uint64_t _qty;
        uint64_t _pricd;

        uint64_t primary_key() const{return proid;}

        EOSLIB_SERIALIZE(shopadsale,(proid)(crop_name)(_qty)(_pricd))
        };

        typedef multi_index<N(shopadsale),shopadsale> _shopaddsal;
        //@abi action
        void addprobysh(account_name cropid,string pron_,uint64_t _qty,uint64_t pric){

        _shopaddsal shopsales(_self,_self);

        auto upr = shopsales.find(cropid);

                if(upr == shopsales.end()){

                        shopsales.emplace(_self,[&](auto& less){

                                less.proid = cropid;
                                less.crop_name = pron_;
                                less._qty = _qty;
                                less._pricd = pric;
                                });
                        }else{print("the details are already available");}
        }

//@abi table buyprocus i64

        struct buyprocus{

        account_name proid;
        string proname;
        uint64_t count_;
        uint64_t pric;

        uint64_t primary_key() const{return proid;}

        EOSLIB_SERIALIZE(buyprocus,(proid)(proname)(count_)(pric))

        };

        typedef multi_index<N(buyprocus),buyprocus> buyprocus_;

        //@abi table cusbuypro i64
        struct cusbuypro{

        account_name proid;
        account_name cusid;
        string cusname;

        uint64_t primary_key() const{return proid;}

        EOSLIB_SERIALIZE(cusbuypro,(proid)(cusid)(cusname))
        };

        typedef multi_index<N(cusbuypro),cusbuypro>  _cusbuypro;

        //@abi table cuspro i64
        struct cuspro{

        account_name proid;
        account_name shopid;
        string shopname;

        uint64_t primary_key() const{return proid;}

        EOSLIB_SERIALIZE(cuspro,(proid)(shopid)(shopname))
        };
  typedef multi_index<N(cuspro),cuspro> _cuspros;


 //@abi action

        void cusbuysro(account_name proid,account_name shopid,account_name cusid,string cropn_,string shopn_,string cusn_,uint64_t qty_,uint64_t pri,account_name uid_){

        _customers custss(_self,_self);

        auto iter = custss.find(cusid);

                if(iter == custss.end()){
                        print("You have to create the customer");
                        }else{
                                _shopreg sopss(_self,_self);

                                auto klm = sopss.find(shopid);

                                        if(klm == sopss.end()){

                                                print("You have to create the shopkeeper");
                                                }else{

                                                        _shopaddsal adds(_self,_self);

                                                        auto iop = adds.find(proid);

                                                                if(iop == adds.end()){

                                                                                print("the product is not available in shop");
											}else{

                                                                                buyprocus_ procuss(_self,_self);

                                                                                auto ilp = procuss.find(proid);
                                                                                        if(ilp == procuss.end()){

                                                                                                procuss.emplace(_self,[&](auto& uss ){

                                                                                                        uss.proid = proid;
                                                                                                        uss.proname = cropn_;
                                                                                                        uss.count_ = qty_;
                                                                                                        uss.pric = pri;


                                                                                                        });
                                                                                                }else{print("The details are already available");}

                                                                                        _cusbuypro buyss(_self,_self);

                                                                                        auto ghj = buyss.find(proid);

                                                                                                if(ghj == buyss.end()){

                                                                                                        buyss.emplace(_self,[&](auto& yss){

                                                                                                                yss.proid = proid;
														yss.cusid = cusid;
                                                                                                                yss.cusname = cusn_;
                                                                                                                });
                                                                                                        }else{print("the details are already available");}

                                                                                        _cuspros mumm(_self,_self);

                                                                                        auto irc = mumm.find(proid);

                                                                                        if(irc == mumm.end()){

                                                                                                mumm.emplace(_self,[&](auto& mms){

                                                                                                        mms.proid = proid;
                                                                                                        mms.shopid = shopid;
                                                                                                        mms.shopname = shopn_;
                                                                                                        });
                                                                                        }else{print("The datas are already available");}


                                                                                _shopaddsal salese(_self,_self);

                                                                                auto uio = salese.find(proid);


                                                                                        if(uio == salese.end()){
                                                                                                print("The rqeuired details are not vailable ");
											}else{


                                                                                                salese.modify(uio,_self,[&](auto& sess){

                                                                                                  sess._qty = sess._qty - qty_;

                                                                                                });
                                                                                        }



                                                                                        _shopdss dsshop(_self,_self);


                                                                                        auto ity = dsshop.find(uid_);

                                                                                                if(ity == dsshop.end()){

                                                                                                        dsshop.emplace(_self,[&](auto& dss){

                                                                                                                dss.uid = uid_;
                                                                                                                dss.cusn_ = cusn_;
                                                                                                                dss.cusid = cusid;
                                                                                                                });
                                                                                                        }else{print("The datas are already available");}
													_boardshop dshop(_self,_self);


                                                                                                auto kbl = dshop.find(uid_);

                                                                                                if(kbl == dshop.end()){

                                                                                                        dshop.emplace(_self,[&](auto& jkl){


                                                                                                                jkl.uid = uid_;
                                                                                                                jkl.proid = proid;
                                                                                                                jkl.cropname = cropn_;

                                                                                                                });
                                                                                                        }else{print("The details are already available");}


                                                                                                ardss_ rdsk(_self,_self);

                                                                                                auto sdf = rdsk.find(uid_);


                                                                                                if(sdf == rdsk.end()){
                                                                                                        rdsk.em
                                                                                                }
                                                                                        }



                                                        }
                                }


        }
 //@abi table shopdash i64

        struct shopdash{

        account_name uid; //cusid + proid
        string cusn_;
        account_name cusid;

        uint64_t primary_key() const{return uid;}

        EOSLIB_SERIALIZE(shopdash,(uid)(cusn_)(cusid))
        };

        typedef multi_index<N(shopdash),shopdash> _shopdss;


        //@abi table shopboard i64

        struct shopboard{

        account_name uid;
        account_name proid;
        string cropname;

        uint64_t primary_key() const{return uid;}

        EOSLIB_SERIALZIE(shopboard,(uid)(proid)(cropname))

        };

        typedef multi_index<N(shopboard),shopboard> _boardshop;


//@abi table shopdboard i64

        struct shopdboard{

                account_name uid;
                uint64_t crqty;
                uint64_t price;
                string date;

                uint64_t primary_key() const{return uid;}
        };

        typedef multi_index<N(shopdboard),shopdboard> ardss_;




};





EOSIO_ABI(employee,(fareg)(addprobyfar)(supregis)(supproby)(shopregis)(supsaadd)(shopbuypro)(custregis)(addprobysh)(cusbuysro))
}








