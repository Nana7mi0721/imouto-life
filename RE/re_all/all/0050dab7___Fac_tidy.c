
/* Library Function - Single Match
    __Fac_tidy
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __Fac_tidy(void)

{
  _Fac_node *this;
  undefined4 extraout_var;
  undefined4 uVar1;
  
  FUN_0050d92b(0);
  this = DAT_00a2014c;
  uVar1 = extraout_var;
  while (this != (_Fac_node *)0x0) {
    DAT_00a2014c = *(_Fac_node **)this;
    std::_Fac_node::~_Fac_node(this);
    _free(this);
    this = DAT_00a2014c;
  }
  DAT_00a2014c = this;
  FUN_0050d94e(uVar1);
  return;
}

