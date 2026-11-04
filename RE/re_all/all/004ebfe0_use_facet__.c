
/* Library Function - Multiple Matches With Same Base Name
    class std::ctype<char> const & __cdecl std::use_facet<class std::ctype<char> >(class std::locale
   const &)
    class std::ctype<unsigned short> const & __cdecl std::use_facet<class std::ctype<unsigned short>
   >(class std::locale const &)
    class std::ctype<wchar_t> const & __cdecl std::use_facet<class std::ctype<wchar_t> >(class
   std::locale const &)
   
   Library: Visual Studio 2003 Debug */

facet * use_facet<>(locale *param_1)

{
  facet *pfVar1;
  int iVar2;
  undefined1 local_30 [12];
  facet *local_24;
  facet *local_20 [2];
  uint local_18;
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1b68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0050d92b(0);
  local_8 = 0;
  local_20[0] = DAT_00a1fbac;
  local_18 = std::locale::id::operator_unsigned_int((id *)&DAT_00a20160);
  local_14 = std::locale::_Getfacet(param_1,local_18);
  if (local_14 == (facet *)0x0) {
    if (local_20[0] == (facet *)0x0) {
      iVar2 = FUN_004ec110(local_20);
      if (iVar2 == -1) {
        FUN_004ff6d8("bad cast");
        __CxxThrowException_8(local_30,&DAT_00847388);
      }
      local_14 = local_20[0];
      DAT_00a1fbac = local_20[0];
      local_24 = local_20[0];
      std::locale::facet::_Incref(local_20[0]);
      std::locale::facet::_Register(local_24);
    }
    else {
      local_14 = local_20[0];
    }
  }
  pfVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_0050d94e();
  ExceptionList = local_10;
  return pfVar1;
}

