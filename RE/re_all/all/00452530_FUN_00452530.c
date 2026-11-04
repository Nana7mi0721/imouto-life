
undefined4 __fastcall FUN_00452530(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x898) + 0x10);
  while (iVar2 = FUN_004cecd0(*(int *)(param_1 + 8) + 1), *(char *)(iVar2 + 0x10) != cVar1) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return 1;
}

