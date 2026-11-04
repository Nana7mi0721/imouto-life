
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c2e40(int param_1)

{
  char cVar1;
  
  *(double *)(param_1 + 0x80) = (double)_DAT_00a18ad8;
  cVar1 = operator!=<>(&DAT_00a13fc0);
  if (cVar1 != '\0') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x38),
               "");
    FUN_004cb840();
  }
  *(undefined4 *)(param_1 + 0x270) = DAT_00a18ae0;
  FUN_00494480(0,_DAT_00802e18,_DAT_00802e18,_DAT_007d0a60);
  return;
}

