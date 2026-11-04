
void __thiscall FUN_00449f90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  
  if (*(char *)(param_1 + 0x1895) == '\0') {
    iVar2 = *(int *)(param_1 + 0x1660);
    iVar1 = FUN_0047a4b0();
    if (iVar2 + param_2 < iVar1 * DAT_0084b264 * 2 * 2 + *DAT_00a1671c * -4) {
      local_c = *(int *)(param_1 + 0x1660) + param_2;
    }
    else {
      iVar2 = FUN_0047a4b0();
      local_c = iVar2 * DAT_0084b264 * 2 * 2 + *DAT_00a1671c * -4;
    }
    if (local_c < 0) {
      local_10 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1660);
      iVar1 = FUN_0047a4b0();
      if (iVar2 + param_2 < iVar1 * DAT_0084b264 * 2 * 2 + *DAT_00a1671c * -4) {
        local_14 = *(int *)(param_1 + 0x1660) + param_2;
      }
      else {
        iVar2 = FUN_0047a4b0();
        local_14 = iVar2 * DAT_0084b264 * 2 * 2 + *DAT_00a1671c * -4;
      }
      local_10 = local_14;
    }
    *(int *)(param_1 + 0x1660) = local_10;
  }
  else {
    *(int *)(param_1 + 0x1660) = *(int *)(param_1 + 0x1660) + param_2;
  }
  return;
}

