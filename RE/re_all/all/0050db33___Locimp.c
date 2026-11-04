
/* Library Function - Single Match
    protected: virtual __thiscall std::locale::_Locimp::~_Locimp(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::locale::_Locimp::~_Locimp(_Locimp *this)

{
  facet *pfVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  
  FUN_006c5130();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR__scalar_deleting_destructor__007d4850;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0050d92b(0);
  iVar2 = extraout_ECX[3];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    pfVar1 = *(facet **)(extraout_ECX[2] + iVar2 * 4);
    if (pfVar1 != (facet *)0x0) {
      pfVar1 = facet::_Decref(pfVar1);
      if (pfVar1 != (facet *)0x0) {
        (*(code *)**(undefined4 **)pfVar1)(1);
      }
    }
  }
  _free((void *)extraout_ECX[2]);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0050d94e();
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (extraout_ECX + 6),true,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_007d4848;
  return;
}

