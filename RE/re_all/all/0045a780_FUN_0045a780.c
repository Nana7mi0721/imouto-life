
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0045a780(int param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_8;
  
  piVar2 = (int *)FUN_004ce990(1);
  iVar5 = *piVar2;
  bVar1 = false;
  if (iVar5 == -0x2711) {
    local_8 = -0x2711;
  }
  else if (iVar5 == -2) {
    local_8 = -1;
  }
  else if (iVar5 == -1) {
    local_8 = -2;
  }
  else {
    puVar3 = (undefined4 *)FUN_004ce990(1);
    local_8 = FUN_00487080(*puVar3);
    if (local_8 < -999) {
      return 1;
    }
    bVar1 = true;
  }
  if ((local_8 == -2) || (local_8 == -0x2711)) {
    if ((DAT_00a14061 != '\0') || (DAT_00a14062 != '\0')) {
      return 0;
    }
    DAT_00a14061 = '\x01';
    if (local_8 == -2) {
      piVar2 = (int *)FUN_004ce990(4);
      if ((*piVar2 == -1) || (bVar1)) {
        DAT_00a14068 = DAT_00a17eb8;
      }
      else {
        puVar3 = (undefined4 *)FUN_004ce990(4);
        DAT_00a14068 = FUN_00487080(*puVar3);
      }
      uVar4 = FUN_004ce080();
      if (uVar4 < 6) {
        puVar3 = (undefined4 *)FUN_004ce990(2);
        iVar5 = FUN_00487080(*puVar3);
        DAT_00a1406c = iVar5 << 1;
        puVar3 = (undefined4 *)FUN_004ce990(3);
        iVar5 = FUN_00487080(*puVar3);
        DAT_00a14070 = iVar5 << 1;
      }
      else {
        puVar3 = (undefined4 *)FUN_004ce990(2);
        iVar5 = FUN_00487080(*puVar3);
        puVar6 = (uint *)FUN_004ce990(5);
        DAT_00a1406c = iVar5 * (2 - (*puVar6 & 1));
        puVar3 = (undefined4 *)FUN_004ce990(3);
        iVar5 = FUN_00487080(*puVar3);
        puVar6 = (uint *)FUN_004ce990(5);
        DAT_00a14070 = iVar5 * (2 - (*puVar6 & 1));
      }
    }
    else if (local_8 == -0x2711) {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      uVar7 = FUN_00487080(*puVar3);
      uVar8 = FUN_0046f7f0(7,uVar7,0,0);
      DAT_00a14068 = FUN_00487080(uVar8);
      uVar8 = FUN_0046f7f0(7,uVar7,1,0);
      iVar5 = FUN_00487080(uVar8);
      DAT_00a1406c = iVar5 << 1;
      uVar7 = FUN_0046f7f0(7,uVar7,2,0);
      iVar5 = FUN_00487080(uVar7);
      DAT_00a14070 = iVar5 << 1;
    }
    _DAT_00a14074 = (int)DAT_00a14480;
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  else {
    iVar5 = FUN_00452590(local_8);
    if (iVar5 == 0) {
      return 1;
    }
    uVar4 = FUN_004ce080();
    if (uVar4 < 6) {
      uVar9 = 0;
      puVar3 = (undefined4 *)FUN_004ce990(3);
      uVar7 = FUN_00487080(*puVar3);
      puVar3 = (undefined4 *)FUN_004ce990(2);
      uVar8 = FUN_00487080(*puVar3);
      FUN_00442fb0(uVar8,uVar7,uVar9);
    }
    else {
      puVar6 = (uint *)FUN_004ce990(5);
      uVar4 = *puVar6 & 1;
      puVar3 = (undefined4 *)FUN_004ce990(3);
      uVar7 = FUN_00487080(*puVar3);
      puVar3 = (undefined4 *)FUN_004ce990(2);
      uVar8 = FUN_00487080(*puVar3);
      FUN_00442fb0(uVar8,uVar7,uVar4);
    }
  }
  uVar4 = FUN_004ce080();
  if (5 < uVar4) {
    puVar6 = (uint *)FUN_004ce990(5);
    iVar5 = (int)(*puVar6 & 0xf0) >> 4;
    if (iVar5 != 1) {
      if (iVar5 != 2) {
        return 1;
      }
      DAT_00a140a8 = 1;
    }
    if ((DAT_00a1405c == '\0') && (DAT_00a14062 == '\0')) {
      FUN_00521db0(0,0,DAT_0084b230,DAT_0084b234,DAT_00a140a4,1);
      DAT_00a14092 = 0;
      DAT_00a14062 = '\x01';
      _DAT_00a14098 = DAT_00a1409c;
    }
  }
  return 1;
}

