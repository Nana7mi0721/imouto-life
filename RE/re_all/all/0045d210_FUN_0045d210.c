
undefined4 __fastcall FUN_0045d210(int param_1)

{
  char cVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined3 uVar6;
  int iVar4;
  int *piVar5;
  
  pwVar2 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back
                     ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *)
                      (param_1 + 0x840));
  if (*(int *)pwVar2 < 1) {
    FUN_004ce1d0();
    uVar3 = FUN_004ce1d0();
    uVar6 = (undefined3)((uint)uVar3 >> 8);
  }
  else {
    iVar4 = FUN_004ce080();
    piVar5 = (int *)FUN_004ce990(iVar4 + -1);
    *piVar5 = *piVar5 + -1;
    cVar1 = *(char *)(*(int *)(param_1 + 0x898) + 0x10);
    do {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      iVar4 = FUN_004cecd0(*(undefined4 *)(param_1 + 8));
    } while (*(char *)(iVar4 + 0x10) != cVar1);
    uVar6 = (undefined3)((uint)iVar4 >> 8);
  }
  return CONCAT31(uVar6,1);
}

