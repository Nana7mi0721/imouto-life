
void FUN_0066abe0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  int local_4;
  
  iVar1 = param_1;
  if (*(char *)(param_1 + 0x261) != '\0') {
    return;
  }
  if ((*(byte *)(param_1 + 0x326) & 2) == 0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x310);
  local_4 = *(int *)(param_1 + 0x31c);
  local_8 = *(int *)(param_1 + 0x304);
  iVar3 = local_4 + iVar2 + local_8;
  param_1 = iVar2;
  if (((((iVar3 < 1) || (local_8 < 0)) ||
       (iVar2 = FUN_0066b150(&local_8,local_8,0x8000,iVar3), iVar2 == 0)) ||
      ((((local_8 < 0 || (0x8000 < local_8)) ||
        ((param_1 < 0 ||
         ((iVar2 = FUN_0066b150(&param_1,param_1,0x8000,iVar3), iVar2 == 0 || (param_1 < 0)))))) ||
       (0x8000 < param_1)))) ||
     ((((local_4 < 0 || (iVar2 = FUN_0066b150(&local_4,local_4,0x8000,iVar3), iVar2 == 0)) ||
       (local_4 < 0)) ||
      ((0x8000 < local_4 || (iVar2 = local_4 + param_1 + local_8, 0x8001 < iVar2)))))) {
    FUN_00668620(iVar1,s_internal_error_handling_cHRM_>XY_00a0c204);
    return;
  }
  if (iVar2 < 0x8001) {
    if (0x7fff < iVar2) goto LAB_0066ad38;
    iVar2 = 1;
  }
  else {
    iVar2 = -1;
  }
  if (param_1 < local_8) {
LAB_0066ad26:
    if (local_4 <= local_8) {
      local_8 = local_8 + iVar2;
      goto LAB_0066ad38;
    }
  }
  else {
    if (local_4 <= param_1) {
      param_1 = param_1 + iVar2;
      goto LAB_0066ad38;
    }
    if (param_1 <= local_8) goto LAB_0066ad26;
  }
  local_4 = local_4 + iVar2;
LAB_0066ad38:
  if (local_4 + param_1 + local_8 == 0x8000) {
    *(short *)(iVar1 + 0x262) = (short)local_8;
    *(short *)(iVar1 + 0x264) = (short)param_1;
    return;
  }
  FUN_00668620(iVar1,s_internal_error_handling_cHRM_coe_00a0c228);
  return;
}

