
/* Library Function - Single Match
    public: __thiscall std::ctype<char>::ctype<char>(short const *,bool,unsigned int)
   
   Library: Visual Studio 2003 Debug */

ctype<char> * __thiscall
std::ctype<char>::ctype<char>(ctype<char> *this,short *param_1,bool param_2,uint param_3)

{
  _Locinfo *p_Var1;
  _Locinfo local_84 [116];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1a93;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ctype_base::ctype_base((ctype_base *)this,param_3);
  local_8 = 0;
  *(undefined ***)this = &PTR_FUN_007d2238;
  p_Var1 = (_Locinfo *)_Locinfo::_Locinfo(local_84,"C");
  local_8._0_1_ = 1;
  _Init(this,p_Var1);
  local_8 = (uint)local_8._1_3_ << 8;
  _Locinfo::~_Locinfo(local_84);
  if (param_1 != (short *)0x0) {
    _Tidy(this);
    *(short **)(this + 0x10) = param_1;
    *(uint *)(this + 0x14) = -(uint)param_2;
  }
  ExceptionList = local_10;
  return this;
}

