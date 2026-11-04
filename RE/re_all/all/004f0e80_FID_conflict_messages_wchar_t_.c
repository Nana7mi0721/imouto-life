
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::codecvt<char,char,int>::codecvt<char,char,int>(unsigned int)
    public: __thiscall std::messages<char>::messages<char>(unsigned int)
    public: __thiscall std::messages<unsigned short>::messages<unsigned short>(unsigned int)
    public: __thiscall std::messages<wchar_t>::messages<wchar_t>(unsigned int)
   
   Library: Visual Studio 2003 Debug */

void * __thiscall FID_conflict_messages<wchar_t>(void *this,uint param_1)

{
  undefined4 uVar1;
  _Locinfo local_84 [116];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1b93;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FID_conflict_codecvt_base(this,param_1);
  local_8 = 0;
  *(undefined ***)this = &PTR_FUN_007d2260;
  uVar1 = std::_Locinfo::_Locinfo(local_84,"C");
  local_8._0_1_ = 1;
  FUN_004d13c0(uVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  std::_Locinfo::~_Locinfo(local_84);
  ExceptionList = local_10;
  return this;
}

