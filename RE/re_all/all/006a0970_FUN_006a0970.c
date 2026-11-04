
void FUN_006a0970(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  piVar7 = param_1;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  uVar5 = (uint)((byte *)(*param_2 + param_3))[1];
  uVar3 = (uint)*(byte *)(*param_2 + param_3);
  iVar2 = uVar3 + uVar5;
  iVar4 = uVar3 - uVar5;
  uVar3 = (uint)((byte *)(param_2[1] + param_3))[1];
  uVar5 = (uint)*(byte *)(param_2[1] + param_3);
  iVar1 = uVar5 + uVar3;
  iVar6 = uVar5 - uVar3;
  param_1[8] = (iVar2 - iVar1) * 0x10;
  *param_1 = (iVar1 + -0x200 + iVar2) * 0x10;
  param_1[1] = (iVar6 + iVar4) * 0x10;
  param_1[9] = (iVar4 - iVar6) * 0x10;
  return;
}

