
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005d86c0(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5,undefined4 param_6,
            undefined4 param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  bool bVar9;
  undefined *puVar10;
  int iVar11;
  
  iVar1 = param_1 + 0x74;
  uVar7 = 0;
  FUN_0056da60(iVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x6d3);
  if (param_2 == 0) {
    FUN_0056dac0(iVar1);
    return 0;
  }
  if (param_3 == 0) {
    param_3 = *(uint *)(param_1 + 0x20);
  }
  else if (param_3 < 0x10) {
    param_3 = 0x10;
  }
  uVar5 = ((param_2 + -1 + param_3) / param_3) * param_3;
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (param_4 == 0) {
      for (iVar6 = *(int *)(param_1 + 0x2318); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x3c)) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          uVar2 = ((iVar6 + 0x5b + param_3) / param_3) * param_3;
          uVar3 = (*(int *)(iVar6 + 0x20) - uVar2) + -0x10 + iVar6;
        }
        else {
          uVar2 = ((*(int *)(iVar6 + 0x24) + -1 + param_3) / param_3) * param_3;
          uVar3 = (*(int *)(iVar6 + 0x20) - uVar2) + *(int *)(iVar6 + 0x24);
        }
        if (uVar5 <= (uVar3 / param_3) * param_3) {
          param_4 = 0;
          goto LAB_005d89e0;
        }
      }
      uVar7 = FUN_005d8120(uVar5,param_3,0,param_5,param_6,param_7);
    }
    else {
      for (iVar6 = *(int *)(param_1 + 0x231c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x38)) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          if (uVar5 <= *(int *)(iVar6 + 0x20) - 0x6cU) {
            uVar2 = (((*(int *)(iVar6 + 0x20) - uVar5) + -0x10 + iVar6) / param_3) * param_3;
            bVar9 = uVar2 < iVar6 + 0x5cU;
            goto LAB_005d878d;
          }
        }
        else if (uVar5 <= *(uint *)(iVar6 + 0x20)) {
          uVar2 = (((*(uint *)(iVar6 + 0x24) - uVar5) + *(uint *)(iVar6 + 0x20)) / param_3) *
                  param_3;
          bVar9 = uVar2 < *(uint *)(iVar6 + 0x24);
LAB_005d878d:
          if (!bVar9) goto LAB_005d89e0;
        }
      }
      uVar7 = FUN_005d8120(uVar5,param_3,param_4,param_5,param_6,param_7);
    }
    goto LAB_005d89ec;
  }
  if (*(int *)(param_1 + 0x1c) != 1) goto LAB_005d89ec;
  iVar11 = *(int *)(param_1 + 0x2c);
  uVar2 = uVar5;
  if (iVar11 == 0) {
    uVar2 = uVar5 + 0x90;
  }
  iVar4 = FUN_005d68f0();
  uVar2 = ((1 << ((byte)iVar4 & 0x1f)) - 1U & (((uVar2 - 1) + param_3 * 2) / param_3) * param_3) >>
          ((byte)iVar4 - 5 & 0x1f);
  uVar3 = uVar2 + 1;
  if (0x1f < uVar3) {
    uVar3 = uVar2 - 0x1f;
    iVar4 = iVar4 + 1;
  }
  iVar8 = iVar4 * 0x20;
  iVar6 = *(int *)(param_1 + 0x318 + (iVar8 + uVar3) * 4);
  if (iVar6 == 0) {
    if ((*(uint *)(param_1 + 0x298 + iVar4 * 4) & -1 << ((byte)uVar3 & 0x1f)) == 0) {
      if ((-1 << ((char)iVar4 + 1U & 0x1f) & *(uint *)(param_1 + 0x294)) == 0) {
        uVar7 = FUN_005d8120(uVar5,param_3,param_4,param_5,param_6,param_7);
        FUN_0056dac0(iVar1);
        return uVar7;
      }
      iVar8 = FUN_005d6930();
      iVar4 = FUN_005d6930();
      iVar8 = iVar8 << 5;
    }
    else {
      iVar4 = FUN_005d6930();
    }
    iVar6 = *(int *)(param_1 + 0x318 + (iVar4 + iVar8) * 4);
  }
  if (iVar11 == 0) {
    iVar11 = *(int *)(iVar6 + 0x20);
    uVar2 = ((param_3 + 0x5b + iVar6) / param_3) * param_3;
    if ((iVar11 - uVar2) + iVar6 < uVar5 + 0x10) {
      puVar10 = &DAT_008017b0;
      goto LAB_005d89ae;
    }
  }
  else {
    iVar11 = *(int *)(iVar6 + 0x20);
    uVar2 = ((*(int *)(iVar6 + 0x24) + -1 + param_3) / param_3) * param_3;
    if ((iVar11 - uVar2) + *(int *)(iVar6 + 0x24) < uVar5) {
      puVar10 = &DAT_008017f8;
LAB_005d89ae:
      FUN_0056bca0(puVar10,iVar11);
      _DAT_00000000 = 0xffffffff;
    }
  }
LAB_005d89e0:
  uVar7 = FUN_005d6d90(iVar6,uVar2,param_2,uVar5,param_4,param_5,param_6,param_7);
LAB_005d89ec:
  FUN_0056dac0(iVar1);
  return uVar7;
}

