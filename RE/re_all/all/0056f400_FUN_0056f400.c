
undefined4 FUN_0056f400(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  if ((param_1[0xf] != 0) || (param_1[0x10] != 0)) {
    return 0xffffffff;
  }
  psVar1 = (short *)(param_1 + 2);
  FUN_0056d380(psVar1,0,0x30);
  iVar7 = FUN_0052db80(param_2,0,1,0);
  param_1[0xf] = iVar7;
  if (iVar7 == 0) {
    return 0xffffffff;
  }
  FUN_0056cf70(param_1 + 0x16,0x800,param_2);
  puVar3 = param_1 + 0x216;
  FUN_0056e490(param_3);
  FUN_0056e720(psVar1,4,0,puVar3,0,0);
  if (*psVar1 != 0x5844) {
    FUN_0056d380(puVar3,0xff,0xc);
    FUN_0052dc20(param_1[0xf],0,0,0);
    FUN_0056e720(psVar1,4,0,puVar3,0,0);
    if (*psVar1 != 0x5844) goto LAB_0056f697;
  }
  uVar4 = *(ushort *)((int)param_1 + 10);
  if (5 < uVar4) {
    *param_1 = 0;
    if (6 < uVar4) goto LAB_0056f697;
    puVar2 = param_1 + 3;
    FUN_0056e720(puVar2,0x2c,0,puVar3,4,0);
    uVar5 = param_1[0xc];
    if ((param_1[0xd] == 0) && (uVar5 < 0xfdea)) {
      if (uVar5 < 0x4e5) {
        if (uVar5 != 0x4e4) {
          if (uVar5 < 0x3b7) {
            if ((uVar5 < 0x3b5) && (uVar5 != 0x3a4)) {
              bVar9 = uVar5 == 0x3a8;
              goto LAB_0056f53b;
            }
          }
          else if ((uVar5 < 0x4b0) || (0x4b1 < uVar5)) goto LAB_0056f541;
        }
      }
      else if (uVar5 < 0x8000) {
        if (uVar5 < 0x7ffe) {
          bVar9 = uVar5 == 0x7ffc;
LAB_0056f53b:
          if (!bVar9) goto LAB_0056f541;
        }
      }
      else if (uVar5 != 0xfde9) goto LAB_0056f541;
      param_1[0xe] = param_1[0xc];
    }
    else {
LAB_0056f541:
      param_1[0xe] = 0x3a4;
    }
    iVar7 = FUN_0056e030(*puVar2,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x6bf);
    param_1[0x11] = iVar7;
    if (iVar7 == 0) goto LAB_0056f697;
    FUN_0052dc20(param_1[0xf],param_1[6],param_1[7],0);
    FUN_0056e720(param_1[0x11],*puVar2,0,puVar3,0,0);
    iVar7 = param_1[8];
    iVar8 = param_1[10];
    goto LAB_0056f713;
  }
  *param_1 = 1;
  if (5 < uVar4) goto LAB_0056f697;
  puVar2 = param_1 + 3;
  if (uVar4 < 4) {
    FUN_0056e720(puVar2,0x14,0,puVar3,4,0);
    param_1[8] = 0x3a4;
LAB_0056f677:
    param_1[0xe] = 0x3a4;
  }
  else {
    FUN_0056e720(puVar2,0x18,0,puVar3,4,0);
    uVar5 = param_1[8];
    if (uVar5 < 0x4e5) {
      if (uVar5 != 0x4e4) {
        if (uVar5 < 0x3b7) {
          if ((uVar5 < 0x3b5) && (uVar5 != 0x3a4)) {
            bVar9 = uVar5 == 0x3a8;
            goto LAB_0056f65d;
          }
        }
        else if ((uVar5 < 0x4b0) || (0x4b1 < uVar5)) goto LAB_0056f677;
      }
    }
    else {
      if (uVar5 < 0x8000) {
        if (0x7ffd < uVar5) goto LAB_0056f65f;
        bVar9 = uVar5 == 0x7ffc;
      }
      else {
        bVar9 = uVar5 == 0xfde9;
      }
LAB_0056f65d:
      if (!bVar9) goto LAB_0056f677;
    }
LAB_0056f65f:
    param_1[0xe] = uVar5;
  }
  iVar7 = FUN_0056e030(*puVar2,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x6fc);
  param_1[0x11] = iVar7;
  if (iVar7 == 0) {
LAB_0056f697:
    if (param_1[0xf] != 0) {
      FUN_0052dbe0(param_1[0xf]);
      param_1[0xf] = 0;
    }
    if (param_1[0x11] != 0) {
      FUN_0056e1d0(param_1[0x11]);
      param_1[0x11] = 0;
    }
    return 0xffffffff;
  }
  FUN_0052dc20(param_1[0xf],param_1[5],0,0);
  if (*(ushort *)((int)param_1 + 10) < 5) {
    uVar11 = *puVar2;
    uVar10 = param_1[0x11];
    uVar13 = 0xffffffff;
    uVar12 = 0xffffffff;
  }
  else {
    uVar11 = *puVar2;
    uVar10 = param_1[0x11];
    uVar13 = 0;
    uVar12 = 0;
  }
  FUN_0056e720(uVar10,uVar11,0,puVar3,uVar12,uVar13);
  iVar7 = param_1[6];
  iVar8 = param_1[7];
LAB_0056f713:
  iVar6 = param_1[0x11];
  param_1[0x14] = iVar6;
  param_1[0x15] = iVar6 + iVar8;
  param_1[0x13] = iVar6 + iVar8;
  param_1[0x12] = iVar7 + iVar6;
  param_1[0x219] = 0;
  param_1[0x21a] = 0;
  param_1[0x21e] = 0;
  param_1[0x21f] = 0;
  return 0;
}

