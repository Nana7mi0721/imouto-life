
void __fastcall FUN_0045d090(int param_1)

{
  int iVar1;
  char cVar2;
  wchar_t *pwVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int local_c;
  
  cVar2 = FUN_004ce0c0();
  if (cVar2 != '\0') {
LAB_0045d196:
    return;
  }
  pwVar3 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back
                     ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *)
                      (param_1 + 0x830));
  iVar1 = *(int *)pwVar3;
  local_c = *(int *)(param_1 + 8);
LAB_0045d0cf:
  do {
    local_c = local_c + 1;
    iVar4 = FUN_004cec90();
    if (iVar4 + -1 <= local_c) goto LAB_0045d196;
    uVar6 = 0;
    FUN_004cecd0(local_c);
    piVar5 = (int *)FUN_004ce990(uVar6);
    if (*piVar5 != 0x1f2) {
      uVar6 = 0;
      FUN_004cecd0(local_c);
      piVar5 = (int *)FUN_004ce990(uVar6);
      if (*piVar5 / 1000 != 0x1f2) goto LAB_0045d0cf;
    }
    iVar4 = FUN_004cecd0(local_c);
    if (*(char *)(iVar4 + 0x10) == iVar1) {
      *(int *)(param_1 + 8) = local_c;
      FUN_004ce1d0();
      FUN_004ce1d0();
      return;
    }
  } while( true );
}

