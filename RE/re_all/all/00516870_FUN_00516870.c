
void FUN_00516870(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_00a37ef8 == 0) {
    iVar3 = FUN_00567fe0();
    uVar1 = DAT_0084c9ac;
    if (iVar3 < 0) {
      *param_1 = DAT_0084c9a8;
      uVar2 = DAT_0084c9b0;
      param_1[1] = uVar1;
      uVar1 = DAT_0084c9b4;
      param_1[2] = uVar2;
      param_1[3] = uVar1;
      return;
    }
  }
  uVar1 = DAT_0084c9ac;
  if ((-1 < param_3) && (param_3 < DAT_00a37ef4)) {
    iVar3 = DAT_00a37ef8 + param_3 * 0x130;
    if ((param_2 < *(int *)(iVar3 + 0x128)) && (-1 < param_2)) {
      iVar3 = *(int *)(iVar3 + 300);
      iVar4 = iVar3 + param_2 * 0x10;
      *param_1 = *(undefined4 *)(iVar3 + param_2 * 0x10);
      param_1[1] = *(undefined4 *)(iVar4 + 4);
      uVar1 = *(undefined4 *)(iVar4 + 0xc);
      param_1[2] = *(undefined4 *)(iVar4 + 8);
      param_1[3] = uVar1;
      return;
    }
  }
  *param_1 = DAT_0084c9a8;
  uVar2 = DAT_0084c9b0;
  param_1[1] = uVar1;
  uVar1 = DAT_0084c9b4;
  param_1[2] = uVar2;
  param_1[3] = uVar1;
  return;
}

