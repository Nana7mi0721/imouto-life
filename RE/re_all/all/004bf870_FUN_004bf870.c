
int __thiscall FUN_004bf870(int param_1,char param_2)

{
  int iVar1;
  int local_8;
  
  iVar1 = (*(int *)(param_1 + 0x3c) - DAT_00a17ec0) +
          ((*(int *)(param_1 + 0x3c) - DAT_00a17ec0 < 0) - 1 & 3);
  for (local_8 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + DAT_0084b264;
      ((param_2 != '\0' && (DAT_00a180f5 != '\0')) && (local_8 < 0));
      local_8 = iVar1 * DAT_0084b264 + local_8) {
    iVar1 = FUN_0047a4b0();
  }
  if ((DAT_00a180f5 != '\0') && (iVar1 = FUN_0047a4b0(), iVar1 * DAT_0084b264 < local_8)) {
    iVar1 = FUN_0047a4b0();
    local_8 = local_8 - iVar1 * DAT_0084b264;
  }
  if ((DAT_00a180f5 != '\0') && (local_8 < 1)) {
    iVar1 = FUN_0047a4b0();
    local_8 = iVar1 * DAT_0084b264 + local_8;
  }
  return local_8 + *(int *)(param_1 + 0x104);
}

