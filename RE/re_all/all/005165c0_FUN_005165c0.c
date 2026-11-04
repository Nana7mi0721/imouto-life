
undefined4 FUN_005165c0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (DAT_00ca39e8 != 0) {
    if (DAT_00ca39f4 != 0) {
      FUN_0057ae10(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    }
    DAT_00ca39e8 = 0;
  }
  if ((param_1 != (int *)0x0) && ((*param_1 < 0 || (param_1[1] < 0)))) {
    param_1 = (int *)0x0;
  }
  if (DAT_00a37d78 != 0) {
    FUN_00567da0(param_1);
    return 0;
  }
  if ((((DAT_00cc47d0 == 0) || ((int)DAT_00a38120 < 0)) ||
      ((DAT_00a38120 & 0x7c000000) != DAT_00cc47f8)) ||
     ((DAT_00cc4800 <= (int)(DAT_00a38120 & 0xffff) ||
      (iVar1 = *(int *)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4),
      puVar3 = (undefined *)(iVar1 + 0x88), iVar1 == 0)))) {
    puVar3 = &DAT_00a37df8;
  }
  uVar2 = FUN_005440f0(*(undefined4 *)(*(int *)(puVar3 + 0x14) + 0x14),DAT_00a37ed8,DAT_00a37edc,
                       DAT_00a37ee0,0);
  FUN_00581fb0(puVar3,param_1,uVar2);
  return 0;
}

