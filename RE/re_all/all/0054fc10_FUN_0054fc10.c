
undefined4 FUN_0054fc10(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = (param_1 & 0xffffefff) - 1;
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (DAT_00a72a60 == 0) {
    uVar1 = FUN_0056a010();
    return uVar1;
  }
  if ((iVar3 < 0) || (DAT_00a74b80 <= iVar3)) {
    FUN_0056d380(param_2,0,0x50);
    param_2[8] = 0xffffffff;
    param_2[9] = 0xffffffff;
    param_2[10] = 0xffffffff;
    param_2[0xb] = 0xffffffff;
    return 0xffffffff;
  }
  if (iVar3 < 0x10) {
    FUN_0056a470(iVar3);
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)(&DAT_00a74bcc + iVar3 * 0x4d4);
    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar4;
      puVar4 = puVar4 + 1;
      param_2 = param_2 + 1;
    }
  }
  return 0;
}

