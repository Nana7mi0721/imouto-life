
undefined4 FUN_00570800(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  uint uVar16;
  bool bVar17;
  int local_824;
  undefined1 local_820 [16];
  undefined1 local_810 [16];
  undefined1 local_800 [2048];
  
  piVar1 = (int *)*param_1;
  iVar2 = piVar1[0x14];
  FUN_005764b0(&DAT_0084f3c8,0xffffffff,0x7ffd,local_820,0x10,piVar1[0xe]);
  FUN_005764b0(&DAT_0084f3cc,0xffffffff,0x7ffd,local_810,0x10,piVar1[0xe]);
  iVar7 = param_1[0x181];
  if (*piVar1 == 0) {
    uVar4 = *(uint *)(iVar7 + 0x14);
    uVar5 = *(uint *)(iVar7 + 0x10);
    uVar9 = 1;
    if ((*(uint *)(iVar7 + 8) & *(uint *)(iVar7 + 0xc)) != 0xffffffff) {
      uVar9 = 2;
    }
    uVar14 = param_1[0x182];
    if (uVar14 == uVar5 + uVar9) {
      return 0xffffffff;
    }
    piVar15 = (int *)(uVar14 * 0x40 + *(int *)(iVar7 + 0x18) + piVar1[0x12]);
    uVar16 = 0;
    uVar10 = uVar9 + uVar5;
    uVar9 = uVar4 + CARRY4(uVar9,uVar5);
    if ((uVar9 != 0) || (uVar14 < uVar10)) {
      do {
        if ((uVar16 < uVar4) || ((uVar16 <= uVar4 && (uVar14 < uVar5)))) {
          iVar7 = FUN_0056ff20(piVar1);
          if (iVar7 == 0) break;
          piVar15 = piVar15 + 0x10;
        }
        else if (((uVar14 == uVar5 && uVar16 - uVar4 == (uint)(uVar14 < uVar5)) ||
                 ((uVar14 - uVar5 == 1 && (uVar16 - uVar4 == (uint)(uVar14 < uVar5))))) &&
                (iVar7 = FUN_0056ff20(piVar1), iVar7 == 0)) break;
        bVar17 = 0xfffffffe < uVar14;
        uVar14 = uVar14 + 1;
        uVar16 = uVar16 + bVar17;
        if ((uVar9 <= uVar16) && ((uVar9 < uVar16 || (uVar10 <= uVar14)))) break;
      } while( true );
    }
    param_1[0x182] = uVar14;
    if ((uVar14 == uVar10) && (uVar16 == uVar9)) {
      return 0xffffffff;
    }
    if (param_2 == 0) {
      return 0;
    }
    if ((uVar16 < uVar4) || ((uVar16 <= uVar4 && (uVar14 < uVar5)))) {
      puVar8 = (ushort *)(*piVar15 + iVar2);
      FUN_00576f40(piVar1[0xe],local_800,0x800,puVar8 + (uint)*puVar8 * 2 + 2);
      *(uint *)(param_2 + 0x208) = (uint)((piVar15[2] & 0x10U) != 0);
      *(int *)(param_2 + 0x210) = piVar15[0xc];
      *(int *)(param_2 + 0x214) = piVar15[0xd];
      FUN_0050f690(piVar15 + 4,param_2 + 0x218);
      FUN_0050f690(piVar15 + 8,param_2 + 0x230);
    }
    else {
      if ((uVar14 - uVar5 == 1) && (uVar16 - uVar4 == (uint)(uVar14 < uVar5))) {
        puVar11 = local_810;
      }
      else {
        puVar11 = local_820;
      }
      FUN_00576f40(piVar1[0xe],local_800,0x800,puVar11);
      *(undefined4 *)(param_2 + 0x208) = 1;
      *(undefined4 *)(param_2 + 0x210) = 0;
      *(undefined4 *)(param_2 + 0x214) = 0;
      FUN_0056d380(param_2 + 0x218,0,0x18);
      FUN_0056d380(param_2 + 0x230,0,0x18);
    }
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
  }
  else {
    iVar3 = *(int *)(iVar7 + 8);
    iVar13 = param_1[0x182];
    iVar12 = (*(int *)(iVar7 + 4) != -1) + 1 + iVar3;
    iVar6 = (-(uint)(*(ushort *)((int)piVar1 + 10) < 2) & 0xfffffffc) + 0x2c;
    if (iVar13 == iVar12) {
      return 0xffffffff;
    }
    piVar15 = (int *)(iVar13 * iVar6 + *(int *)(iVar7 + 0xc) + piVar1[0x12]);
    if (iVar13 < iVar12) {
      local_824 = iVar13 - iVar3;
      do {
        if (iVar13 < iVar3) {
          iVar7 = FUN_0056ff20(piVar1);
          if (iVar7 == 0) break;
          piVar15 = (int *)((int)piVar15 + iVar6);
        }
        else if (((local_824 == 0) || (local_824 == 1)) &&
                (iVar7 = FUN_0056ff20(piVar1), iVar7 == 0)) break;
        iVar13 = iVar13 + 1;
        local_824 = local_824 + 1;
      } while (iVar13 < iVar12);
    }
    param_1[0x182] = iVar13;
    if (iVar13 == iVar12) {
      return 0xffffffff;
    }
    if (param_2 == 0) {
      return 0;
    }
    if (iVar13 < iVar3) {
      puVar8 = (ushort *)(*piVar15 + iVar2);
      FUN_00576f40(piVar1[0xe],local_800,0x800,puVar8 + (uint)*puVar8 * 2 + 2);
      *(uint *)(param_2 + 0x208) = (uint)piVar15[1] >> 4 & 1;
      *(int *)(param_2 + 0x210) = piVar15[9];
      *(undefined4 *)(param_2 + 0x214) = 0;
      FUN_0050f690(piVar15 + 2,param_2 + 0x218);
      FUN_0050f690(piVar15 + 6,param_2 + 0x230);
    }
    else {
      puVar11 = local_820;
      if (iVar13 - iVar3 == 1) {
        puVar11 = local_810;
      }
      FUN_00576f40(piVar1[0xe],local_800,0x800,puVar11);
      *(undefined4 *)(param_2 + 0x208) = 1;
      *(undefined4 *)(param_2 + 0x210) = 0;
      *(undefined4 *)(param_2 + 0x214) = 0;
      FUN_0056d380(param_2 + 0x218,0,0x18);
      FUN_0056d380(param_2 + 0x230,0,0x18);
    }
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
  }
  FUN_005764b0(local_800,0xffffffff,piVar1[0xe],param_2,0x208,DAT_00aba250);
  return 0;
}

