
void FUN_006bd9a0(int param_1,int param_2,int param_3,short *param_4,int param_5,ushort param_6)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  int iVar7;
  int local_8;
  int local_4;
  
  if (param_5 < 2) {
    uVar2 = (undefined2)((int)((int)*param_4 * (uint)param_6 + 0xf) >> 5);
    psVar6 = param_4 + 0x40;
    for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(uint *)psVar6 = CONCAT22(uVar2,uVar2);
      psVar6 = psVar6 + 2;
    }
  }
  else {
    *param_4 = *param_4 * param_6;
    FUN_006bf370(param_4 + 0x40,param_4,param_5);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x240 + param_3 * 4);
  iVar4 = *(int *)(*(int *)(param_1 + 0xac) + param_2 * 4);
  iVar7 = *(int *)(param_1 + 0x22c) + iVar4;
  uVar5 = *(uint *)(*(int *)(param_1 + 0xa8) + param_2 * 4) >> 6 & 3;
  if (uVar5 == 2) {
    FUN_006bf1d0(iVar7,uVar1,param_4 + 0x40);
    return;
  }
  iVar4 = *(int *)(param_1 + 0x224 + uVar5 * 4) + iVar4;
  iVar3 = FUN_006bd8f0(param_1,&local_8,param_3,
                       *(undefined2 *)(*(int *)(param_1 + 0xb0) + param_2 * 2));
  if (iVar3 < 2) {
    FUN_006bf230(iVar7,local_8 + iVar4,uVar1,param_4 + 0x40);
    return;
  }
  FUN_006bf2c0(iVar7,local_8 + iVar4,local_4 + iVar4);
  return;
}

