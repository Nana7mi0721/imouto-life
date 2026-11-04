
int __thiscall FUN_00478140(int param_1,char param_2)

{
  int iVar1;
  int local_14;
  int local_8;
  
  iVar1 = (*(int *)(param_1 + 0x38) - DAT_00a17ebc) +
          ((*(int *)(param_1 + 0x38) - DAT_00a17ebc < 0) - 1 & 3);
  for (local_8 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + DAT_0084b264 / 2;
      ((param_2 != '\0' && (DAT_00a180f4 != '\0')) && (local_8 < 0));
      local_8 = iVar1 * DAT_0084b264 + local_8) {
    iVar1 = FUN_0047a490();
  }
  iVar1 = FUN_0047a490();
  if ((iVar1 * DAT_0084b264 - (int)*DAT_00a16718) / 2 < 0) {
    local_14 = 0;
  }
  else {
    iVar1 = FUN_0047a490();
    local_14 = (iVar1 * DAT_0084b264 - (int)*DAT_00a16718) / 2;
  }
  if ((DAT_00a180f4 != '\0') && (*DAT_00a16718 + local_14 < local_8)) {
    iVar1 = FUN_0047a490();
    local_8 = local_8 - iVar1 * DAT_0084b264;
  }
  return local_8 + *(int *)(param_1 + 0x100);
}

