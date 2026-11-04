
void __thiscall FUN_0044a2b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_c;
  
  if (*(char *)(param_1 + 0x1895) == '\0') {
    if (*(int *)(param_1 + 0x1660) - param_2 < 1) {
      local_c = 0;
    }
    else {
      local_c = *(int *)(param_1 + 0x1660) - param_2;
    }
    *(int *)(param_1 + 0x1660) = local_c;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1660);
    iVar2 = FUN_0047a4b0();
    iVar4 = DAT_0084b264 * 2;
    iVar3 = FUN_0047a4b0();
    *(int *)(param_1 + 0x1660) =
         ((iVar1 - param_2) + iVar2 * iVar4 * 2) % (iVar3 * DAT_0084b264 * 2 * 2);
  }
  return;
}

