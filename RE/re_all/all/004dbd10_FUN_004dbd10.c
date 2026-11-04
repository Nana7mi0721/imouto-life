
basic_filebuf<char,std::char_traits<char>_> * __thiscall
FUN_004dbd10(basic_filebuf<char,std::char_traits<char>_> *param_1,char *param_2,int param_3,
            int param_4)

{
  undefined4 uVar1;
  undefined1 local_18 [4];
  _iobuf *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b19c8;
  local_10 = ExceptionList;
  if ((*(int *)(param_1 + 0x58) == 0) &&
     (ExceptionList = &local_10, local_14 = std::_Fiopen(param_2,param_3,param_4),
     local_14 != (_iobuf *)0x0)) {
    std::basic_filebuf<char,std::char_traits<char>_>::_Init(param_1,local_14,1);
    uVar1 = FUN_004e05b0(local_18);
    local_8 = 0;
    uVar1 = use_facet<>(uVar1);
    FUN_004dbfd0(uVar1);
    local_8 = 0xffffffff;
    FUN_004d3d00();
    ExceptionList = local_10;
    return param_1;
  }
  ExceptionList = local_10;
  return (basic_filebuf<char,std::char_traits<char>_> *)0x0;
}

