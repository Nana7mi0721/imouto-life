
undefined4 FUN_006ac420(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar1 = param_1 + 1;
  iVar5 = *(int *)(param_1[0x10] + 0x68);
  iVar2 = *(int *)(*(int *)(param_1[0x10] + 4) + 0x1c);
  FUN_006ac690(param_1);
  FUN_007976d0(puVar1,*param_2,param_2[1]);
  iVar4 = FUN_00797830(puVar1,1);
  if (iVar4 != 0) {
    return 0xffffff79;
  }
  iVar5 = FUN_00797830(puVar1,*(undefined4 *)(iVar5 + 0x2c));
  if (iVar5 == -1) {
    return 0xffffff78;
  }
  param_1[10] = iVar5;
  piVar3 = *(int **)(iVar2 + 0x20 + iVar5 * 4);
  if (piVar3 == (int *)0x0) {
    return 0xffffff78;
  }
  iVar5 = *piVar3;
  param_1[7] = iVar5;
  if (iVar5 == 0) {
    param_1[6] = 0;
    param_1[8] = 0;
  }
  else {
    uVar6 = FUN_00797830(puVar1,1);
    param_1[6] = uVar6;
    iVar5 = FUN_00797830(puVar1,1);
    param_1[8] = iVar5;
    if (iVar5 == -1) {
      return 0xffffff78;
    }
  }
  param_1[0xc] = param_2[4];
  param_1[0xd] = param_2[5];
  param_1[0xe] = param_2[6];
  param_1[0xf] = param_2[7];
  param_1[0xb] = param_2[3];
  param_1[9] = 0;
  *param_1 = 0;
  return 0;
}

