
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00653210(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  FUN_00650810(param_1 + 6,0,0x100);
  *param_1 = (int)(param_1 + 0x46);
  iVar1 = 0;
  do {
    *(char *)(iVar1 + (int)(param_1 + 0x46)) = (char)iVar1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  FUN_00650810(param_1 + 0x86,0xff,0x200);
  param_1[1] = (int)(param_1 + 0x106);
  param_1[2] = (int)(param_1 + 0x206);
  param_1[3] = (int)(param_1 + 0x306);
  param_1[4] = (int)(param_1 + 0x406);
  param_1[5] = (int)(param_1 + 0x506);
  iVar2 = __ftol();
  iVar3 = __ftol();
  iVar4 = __ftol();
  iVar5 = __ftol();
  iVar9 = 0;
  iVar1 = -0x80;
  do {
    __ftol();
    iVar6 = __ftol();
    __ftol();
    iVar7 = __ftol();
    *(int *)(iVar9 + param_1[1]) = iVar6 * iVar2 + 0x8000 >> 0x10;
    *(int *)(iVar9 + param_1[2]) = iVar7 * iVar4 + 0x8000 >> 0x10;
    *(int *)(iVar9 + param_1[3]) = iVar6 * -iVar3;
    *(int *)(iVar9 + param_1[4]) = iVar7 * -iVar5 + 0x8000;
    __ftol();
    uVar8 = __ftol();
    *(undefined4 *)(iVar9 + param_1[5]) = uVar8;
    iVar6 = iVar1 + 0x81;
    iVar9 = iVar9 + 4;
    iVar1 = iVar1 + 1;
  } while (iVar6 < 0x100);
  return 0;
}

