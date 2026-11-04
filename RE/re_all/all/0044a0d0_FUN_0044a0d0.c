
void __thiscall FUN_0044a0d0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_c;
  
  if (*(char *)(param_1 + 0x1894) == '\0') {
    if (*(int *)(param_1 + 0x165c) - param_2 < 1) {
      local_c = 0;
    }
    else {
      local_c = *(int *)(param_1 + 0x165c) - param_2;
    }
    *(int *)(param_1 + 0x165c) = local_c;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x165c);
    iVar2 = FUN_0047a490();
    iVar4 = DAT_0084b264 * 2;
    iVar3 = FUN_0047a490();
    *(int *)(param_1 + 0x165c) =
         ((iVar1 - param_2) + iVar2 * iVar4 * 2) % (iVar3 * DAT_0084b264 * 2 * 2);
  }
  return;
}

