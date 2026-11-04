
undefined4 FUN_00691580(int *param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = FUN_00691640(param_1);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  *(undefined1 *)*param_1 = 0xff;
  iVar2 = param_1[1];
  *param_1 = *param_1 + 1;
  param_1[1] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    uVar1 = FUN_00691610(param_1);
    if ((char)uVar1 == '\0') {
      return uVar1;
    }
  }
  *(char *)*param_1 = param_2 + -0x30;
  iVar2 = param_1[1];
  *param_1 = *param_1 + 1;
  param_1[1] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    uVar1 = FUN_00691610(param_1);
    if ((char)uVar1 == '\0') {
      return uVar1;
    }
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1[8] + 0x114)) {
    piVar3 = param_1 + 4;
    do {
      *piVar3 = 0;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < *(int *)(param_1[8] + 0x114));
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

