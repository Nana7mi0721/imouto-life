
basic_ostream<char,std::char_traits<char>_> * __thiscall
FUN_004d0de0(basic_ostream<char,std::char_traits<char>_> *param_1,undefined4 param_2,uint param_3,
            undefined4 param_4,int param_5)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1082;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_5 != 0) {
    ExceptionList = &local_10;
    *(undefined **)param_1 = &DAT_007d2168;
    basic_ios<>(param_1,0);
    local_8 = 0;
  }
  std::basic_ostream<char,std::char_traits<char>_>::basic_ostream<char,std::char_traits<char>_>
            (param_1,(basic_streambuf<char,std::char_traits<char>_> *)(param_1 + 4),false);
  local_8 = 1;
  *(undefined ***)(param_1 + *(int *)(*(int *)param_1 + 4)) =
       &PTR__scalar_deleting_destructor__007d2164;
  std::basic_filebuf<char,std::char_traits<char>_>::basic_filebuf<char,std::char_traits<char>_>
            ((basic_filebuf<char,std::char_traits<char>_> *)(param_1 + 4),(_iobuf *)0x0);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_004dbd10(param_2,param_3 | 2,param_4);
  if (iVar1 == 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)(param_1 + *(int *)(*(int *)param_1 + 4)),
               2,false);
  }
  ExceptionList = local_10;
  return param_1;
}

