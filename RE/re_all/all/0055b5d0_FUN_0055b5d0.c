
undefined4 FUN_0055b5d0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int unaff_ESI;
  undefined4 uVar6;
  undefined4 local_34;
  uint local_30;
  int local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  uint local_4;
  
  iVar5 = 0;
  local_34 = 0xffffffff;
  if (DAT_00a834f0 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(unaff_ESI + 0x24c) == 0) {
    return 0;
  }
  FUN_0056da60(&DAT_00cc50e4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x3c0a);
  FUN_00551ca0(unaff_ESI + 0x78,&local_30,local_28);
  uVar4 = *(uint *)(unaff_ESI + 0x238);
  if ((uVar4 != 0xffffffff) && (*(int *)(unaff_ESI + 0x240) == 0)) {
    uVar1 = *(uint *)(unaff_ESI + 0x23c);
    if (((uVar1 < local_30) && ((uVar1 <= uVar4 && (uVar4 <= local_30)))) ||
       ((local_30 < uVar1 && ((uVar1 <= uVar4 || (uVar4 <= local_30)))))) {
      *(undefined4 *)(unaff_ESI + 0x240) = 1;
    }
    else {
      *(uint *)(unaff_ESI + 0x23c) = local_30;
    }
  }
  uVar4 = *(uint *)(unaff_ESI + 0x234);
  uVar1 = uVar4 - *(int *)(unaff_ESI + 0x248);
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + *(int *)(unaff_ESI + 0x230);
  }
  if ((((uVar1 <= uVar4) || (uVar1 <= local_30)) || (local_30 <= uVar4)) &&
     ((uVar4 <= uVar1 || ((uVar1 <= local_30 && (local_30 <= uVar4)))))) {
    if ((uVar4 < uVar1) && (local_30 <= uVar1)) {
      iVar3 = *(int *)(unaff_ESI + 0x230) - uVar1;
    }
    else {
      iVar3 = -uVar1;
    }
    iVar3 = (int)(*(int *)(unaff_ESI + 0x248) + iVar3 + local_30) /
            (int)(uint)*(ushort *)(unaff_ESI + 0x40);
    if (-1 < iVar3) {
      iVar2 = *(int *)(unaff_ESI + 0x58);
      if (iVar2 < iVar3) {
        if (iVar2 < 1) {
          iVar5 = iVar3;
          iVar3 = 0;
        }
        else {
          iVar3 = iVar2;
        }
      }
      local_2c = (iVar3 + iVar5) * (uint)*(ushort *)(unaff_ESI + 0x40);
      iVar2 = FUN_005518a0(unaff_ESI + 0x78,*(undefined4 *)(unaff_ESI + 0x234),local_2c,&local_20,
                           &local_18,&local_1c,&local_14);
      if (iVar2 != 0) goto LAB_0055b924;
      if ((iVar5 != 0) && (*(int *)(unaff_ESI + 0x238) == -1)) {
        iVar2 = (uint)*(ushort *)(unaff_ESI + 0x40) * iVar3 + *(int *)(unaff_ESI + 0x234);
        *(int *)(unaff_ESI + 0x238) = iVar2;
        if (*(int *)(unaff_ESI + 0x230) < iVar2) {
          *(int *)(unaff_ESI + 0x238) = iVar2 - *(int *)(unaff_ESI + 0x230);
        }
        *(uint *)(unaff_ESI + 0x23c) = local_30;
        *(undefined4 *)(unaff_ESI + 0x240) = 0;
      }
      if ((*(int *)(unaff_ESI + 0x240) != 0) && (iVar3 != 0)) {
        *(undefined4 *)(unaff_ESI + 0x240) = 0;
        *(undefined4 *)(unaff_ESI + 0x23c) = 0;
        *(undefined4 *)(unaff_ESI + 0x238) = 0xffffffff;
      }
      local_24 = *(undefined4 *)(unaff_ESI + 0x234);
      *(int *)(unaff_ESI + 0x58) = *(int *)(unaff_ESI + 0x58) - iVar3;
      local_10 = 0;
      local_c = 0;
      local_8 = local_18;
      local_4 = local_14;
      if ((local_18 != 0) && (iVar3 != 0)) {
        uVar4 = (uint)*(ushort *)(unaff_ESI + 0x40) * iVar3;
        if (local_18 < uVar4) {
          uVar4 = local_18;
        }
        FUN_005973e0(unaff_ESI + 0x5c,local_20,uVar4,0);
        local_10 = local_10 + uVar4;
        local_8 = local_8 - uVar4;
        iVar3 = iVar3 - uVar4 / *(ushort *)(unaff_ESI + 0x40);
      }
      if ((local_4 != 0) && (iVar3 != 0)) {
        uVar4 = (uint)*(ushort *)(unaff_ESI + 0x40) * iVar3;
        if (local_4 < uVar4) {
          uVar4 = local_4;
        }
        FUN_005973e0(unaff_ESI + 0x5c,local_1c + local_c,uVar4,0);
        local_c = local_c + uVar4;
        local_4 = local_4 - uVar4;
      }
      if ((local_8 != 0) && (iVar5 != 0)) {
        uVar4 = (uint)*(ushort *)(unaff_ESI + 0x40) * iVar5;
        if (local_8 < uVar4) {
          uVar4 = local_8;
        }
        if (*(short *)(unaff_ESI + 0x42) == 8) {
          uVar6 = 0x7f;
LAB_0055b86e:
          FUN_0056d380(local_20 + local_10,uVar6,uVar4);
        }
        else if (*(short *)(unaff_ESI + 0x42) == 0x10) {
          uVar6 = 0;
          goto LAB_0055b86e;
        }
        local_10 = local_10 + uVar4;
        local_8 = local_8 - uVar4;
        iVar5 = iVar5 - uVar4 / *(ushort *)(unaff_ESI + 0x40);
      }
      if ((local_4 != 0) && (iVar5 != 0)) {
        uVar4 = (uint)*(ushort *)(unaff_ESI + 0x40) * iVar5;
        if (local_4 < uVar4) {
          uVar4 = local_4;
        }
        if (*(short *)(unaff_ESI + 0x42) == 8) {
          uVar6 = 0x7f;
LAB_0055b8ce:
          FUN_0056d380(local_1c + local_c,uVar6,uVar4);
        }
        else if (*(short *)(unaff_ESI + 0x42) == 0x10) {
          uVar6 = 0;
          goto LAB_0055b8ce;
        }
        local_c = local_c + uVar4;
        local_4 = local_4 - uVar4;
      }
      FUN_00551980(unaff_ESI + 0x78,local_20,local_18,local_1c,local_14);
      *(int *)(unaff_ESI + 0x234) = *(int *)(unaff_ESI + 0x234) + local_2c;
      if (*(int *)(unaff_ESI + 0x230) <= *(int *)(unaff_ESI + 0x234)) {
        *(int *)(unaff_ESI + 0x234) = *(int *)(unaff_ESI + 0x234) - *(int *)(unaff_ESI + 0x230);
      }
      local_34 = 0;
      goto LAB_0055b924;
    }
  }
  local_34 = 0;
LAB_0055b924:
  FUN_0056dac0(&DAT_00cc50e4);
  return local_34;
}

