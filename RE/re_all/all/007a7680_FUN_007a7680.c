
int FUN_007a7680(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar2 = FUN_007a20a0(param_1,0xf);
  uVar3 = 0;
  if (param_2 <= uVar2) {
    iVar5 = 1;
    uVar3 = FUN_007a7660(param_2,param_3);
    uVar4 = param_2;
    while (param_2 = uVar3 + 1, 1 < param_2) {
      iVar1 = param_2 * 2;
      if (uVar2 < iVar1 + uVar4) {
        if (1 < param_2) goto LAB_007a76e9;
        break;
      }
      uVar4 = uVar4 + iVar1;
      iVar5 = iVar5 + 1;
      uVar3 = (uint)((iVar1 + -2) * param_3) >> 0xf;
    }
    uVar3 = uVar2 - uVar4 >> 1;
    iVar5 = iVar5 + uVar3;
    uVar4 = uVar4 + uVar3 * 2;
LAB_007a76e9:
    uVar3 = uVar4 + param_2;
    if (uVar2 < uVar3) {
      iVar5 = -iVar5;
      uVar3 = uVar4;
    }
  }
  param_2 = param_2 + uVar3;
  if (0x7fff < param_2) {
    param_2 = 0x8000;
  }
  FUN_007a20e0(param_1,uVar3,param_2,0x8000);
  return iVar5;
}

