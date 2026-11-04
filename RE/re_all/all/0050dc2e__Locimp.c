
/* Library Function - Single Match
    private: __thiscall std::locale::_Locimp::_Locimp(bool)
   
   Library: Visual Studio 2003 Release */

undefined4 * __thiscall std::locale::_Locimp::_Locimp(_Locimp *this,bool param_1)

{
  undefined1 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_006c5130();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  uVar1 = *(undefined1 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR__scalar_deleting_destructor__007d4850;
  *(undefined1 *)(extraout_ECX + 5) = uVar1;
  basic_string<>(&DAT_007d4854);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

