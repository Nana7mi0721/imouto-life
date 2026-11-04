
int FUN_007a0320(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_007a2640(48000,0x3c0,0);
  if ((param_3 < 0) || (2 < param_3)) {
    return -1;
  }
  if (param_1 == (int *)0x0) {
    return -7;
  }
  piVar4 = param_1;
  for (uVar2 = ((*(int *)(iVar1 + 4) + 0x818) * param_3 + *(int *)(iVar1 + 8) * 8) * 4 + 0x54U >> 2;
      uVar2 != 0; uVar2 = uVar2 - 1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)piVar4 = 0;
    piVar4 = (int *)((int)piVar4 + 1);
  }
  *param_1 = iVar1;
  param_1[1] = *(int *)(iVar1 + 4);
  param_1[2] = param_3;
  param_1[3] = param_3;
  param_1[4] = 1;
  param_1[5] = 0;
  param_1[6] = *(int *)(iVar1 + 0xc);
  param_1[7] = 1;
  param_1[8] = 0;
  param_1[0xc] = 0;
  FUN_007a1d70(param_1,0xfbc);
  iVar1 = FUN_007a26c0(param_2);
  param_1[4] = iVar1;
  return (iVar1 != 0) - 1;
}

