
int __thiscall FUN_00478270(int param_1,char param_2)

{
  int iVar1;
  int local_10;
  int local_8;
  
  iVar1 = (*(int *)(param_1 + 0x3c) - DAT_00a17ec0) +
          ((*(int *)(param_1 + 0x3c) - DAT_00a17ec0 < 0) - 1 & 3);
  if (*(int *)(param_1 + 0x68) < *(int *)(param_1 + 0x6c)) {
    local_8 = *(int *)(param_1 + 0x6c) - *(int *)(param_1 + 0x68);
  }
  else {
    local_8 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 0x6c);
  }
  for (local_10 = ((((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + DAT_0084b264) -
                  *(int *)(param_1 + 0xc4)) -
                  (*(int *)(param_1 + 0x6c) * *(int *)(param_1 + 0x6c) * 3 + local_8 * local_8 * -3)
                  / (int)(0xa0 / (longlong)DAT_0084b264);
      ((param_2 != '\0' && (DAT_00a180f5 != '\0')) && (local_10 < 0));
      local_10 = iVar1 * DAT_0084b264 + local_10) {
    iVar1 = FUN_0047a4b0();
  }
  if ((DAT_00a180f5 != '\0') && (iVar1 = FUN_0047a4b0(), iVar1 * DAT_0084b264 < local_10)) {
    iVar1 = FUN_0047a4b0();
    local_10 = local_10 - iVar1 * DAT_0084b264;
  }
  if ((DAT_00a180f5 != '\0') && (local_10 < 1)) {
    iVar1 = FUN_0047a4b0();
    local_10 = iVar1 * DAT_0084b264 + local_10;
  }
  return local_10 + *(int *)(param_1 + 0x104);
}

