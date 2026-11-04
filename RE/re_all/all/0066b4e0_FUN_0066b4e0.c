
void FUN_0066b4e0(uint param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bVar6;
  
  iVar3 = param_1;
  if ((*(int *)(param_1 + 400) != 0) || (*(int *)(param_1 + 0x194) != 0)) {
    FUN_006687b0(param_1,s_gamma_table_being_rebuilt_00a0c458);
    FUN_0066b390(param_1);
  }
  if (param_2 < 9) {
    if (*(int *)(param_1 + 0x18c) < 1) {
      uVar4 = 100000;
    }
    else {
      uVar4 = FUN_0066b240(*(undefined4 *)(param_1 + 0x2dc),*(int *)(param_1 + 0x18c));
    }
    FUN_0066b9f0(param_1,param_1 + 400,uVar4);
    if ((*(uint *)(param_1 + 0x7c) & 0x600080) != 0) {
      uVar4 = FUN_0066b1d0(*(undefined4 *)(param_1 + 0x2dc));
      FUN_0066b9f0(param_1,param_1 + 0x19c,uVar4);
      if (*(int *)(param_1 + 0x18c) < 1) {
        uVar4 = *(undefined4 *)(param_1 + 0x2dc);
      }
      else {
        uVar4 = FUN_0066b1d0(*(int *)(param_1 + 0x18c));
      }
      FUN_0066b9f0(param_1,param_1 + 0x198,uVar4);
      return;
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x157) & 2) == 0) {
      bVar6 = *(byte *)(param_1 + 0x1ab);
    }
    else {
      bVar6 = *(byte *)(param_1 + 0x1a8);
      if (*(byte *)(param_1 + 0x1a8) < *(byte *)(param_1 + 0x1a9)) {
        bVar6 = *(byte *)(param_1 + 0x1a9);
      }
      if (bVar6 < *(byte *)(param_1 + 0x1aa)) {
        bVar6 = *(byte *)(param_1 + 0x1aa);
      }
    }
    if ((bVar6 == 0) || (0xf < bVar6)) {
      bVar6 = 0;
    }
    else {
      bVar6 = 0x10 - bVar6;
    }
    puVar1 = (uint *)(param_1 + 0x7c);
    param_1 = (uint)bVar6;
    uVar5 = *puVar1 & 0x4000400;
    if ((uVar5 == 0) || (4 < bVar6)) {
      if (8 < bVar6) {
        param_1 = 8;
      }
    }
    else {
      param_1 = 5;
    }
    iVar2 = *(int *)(iVar3 + 0x18c);
    *(uint *)(iVar3 + 0x188) = param_1;
    if (uVar5 == 0) {
      if (iVar2 < 1) {
        uVar4 = 100000;
      }
      else {
        uVar4 = FUN_0066b240(*(undefined4 *)(iVar3 + 0x2dc),iVar2);
      }
      FUN_0066b740(iVar3,iVar3 + 0x194,param_1,uVar4);
    }
    else if (iVar2 < 1) {
      FUN_0066b8b0(iVar3,iVar3 + 0x194,param_1,100000);
    }
    else {
      uVar4 = FUN_0066b6f0(*(undefined4 *)(iVar3 + 0x2dc),iVar2);
      FUN_0066b8b0(iVar3,iVar3 + 0x194,param_1,uVar4);
    }
    if ((*(uint *)(iVar3 + 0x7c) & 0x600080) != 0) {
      uVar4 = FUN_0066b1d0(*(undefined4 *)(iVar3 + 0x2dc));
      FUN_0066b740(iVar3,iVar3 + 0x1a4,param_1,uVar4);
      if (*(int *)(iVar3 + 0x18c) < 1) {
        uVar4 = *(undefined4 *)(iVar3 + 0x2dc);
      }
      else {
        uVar4 = FUN_0066b1d0(*(int *)(iVar3 + 0x18c));
      }
      FUN_0066b740(iVar3,iVar3 + 0x1a0,param_1,uVar4);
    }
  }
  return;
}

