
void __fastcall FUN_0045cfe0(int param_1)

{
  int iVar1;
  char cVar2;
  wchar_t *pwVar3;
  int iVar4;
  int *piVar5;
  
  cVar2 = FUN_004ce0c0();
  if (cVar2 == '\0') {
    pwVar3 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back
                       ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *)
                        (param_1 + 0x830));
    iVar1 = *(int *)pwVar3;
    iVar4 = FUN_004ce080();
    piVar5 = (int *)FUN_004ce990(iVar4 + -1);
    *piVar5 = *piVar5 + -1;
    do {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      iVar4 = FUN_004cecd0(*(undefined4 *)(param_1 + 8));
    } while (*(char *)(iVar4 + 0x10) != iVar1);
  }
  return;
}

