
undefined4 FUN_0056efd0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  if ((param_1[0xf] != 0) || (param_1[0x10] != 0)) {
    return 0xffffffff;
  }
  puVar3 = param_1 + 0x216;
  FUN_0056e490(param_3);
  param_1[0x222] = 0;
  param_1[0x10] = 0;
  iVar6 = FUN_0052db80(param_2,0,1,0);
  param_1[0x222] = iVar6;
  if (iVar6 == 0) {
    return 0xffffffff;
  }
  FUN_0056cf70(param_1 + 0x16,0x800,param_2);
  FUN_0052dc20(param_1[0x222],0,0,2);
  uVar9 = FUN_0052dc10(param_1[0x222]);
  *(undefined8 *)(param_1 + 0x21c) = uVar9;
  FUN_0052dc20(param_1[0x222],0,0,0);
  uVar7 = FUN_0056e030(param_1[0x21c],"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x5b6)
  ;
  psVar1 = (short *)(param_1 + 2);
  param_1[0x10] = uVar7;
  FUN_0056e720(psVar1,4,0,puVar3,0,0);
  if (*psVar1 != 0x5844) {
    FUN_0056d380(puVar3,0xff,0xc);
    FUN_0052dc20(param_1[0x222],0,0,0);
    FUN_0056e720(psVar1,4,0,puVar3,0,0);
    if (*psVar1 != 0x5844) goto LAB_0056f2d4;
  }
  uVar4 = *(ushort *)((int)param_1 + 10);
  if (5 < uVar4) {
    *param_1 = 0;
    if (6 < uVar4) goto LAB_0056f2d4;
    puVar2 = param_1 + 3;
    FUN_0056e720(puVar2,0x2c,0,puVar3,4,0);
    uVar5 = param_1[0xc];
    if ((param_1[0xd] == 0) && (uVar5 < 0xfdea)) {
      if (uVar5 < 0x4e5) {
        if (uVar5 != 0x4e4) {
          if (uVar5 < 0x3b7) {
            if ((uVar5 < 0x3b5) && (uVar5 != 0x3a4)) {
              bVar8 = uVar5 == 0x3a8;
              goto LAB_0056f165;
            }
          }
          else if ((uVar5 < 0x4b0) || (0x4b1 < uVar5)) goto LAB_0056f16b;
        }
      }
      else if (uVar5 < 0x8000) {
        if (uVar5 < 0x7ffe) {
          bVar8 = uVar5 == 0x7ffc;
LAB_0056f165:
          if (!bVar8) goto LAB_0056f16b;
        }
      }
      else if (uVar5 != 0xfde9) goto LAB_0056f16b;
      param_1[0xe] = param_1[0xc];
    }
    else {
LAB_0056f16b:
      param_1[0xe] = 0x3a4;
    }
    iVar6 = FUN_0056e030(*puVar2,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x5ee);
    param_1[0x11] = iVar6;
    if (iVar6 != 0) {
      FUN_0052dc20(param_1[0x222],param_1[6],param_1[7],0);
      FUN_0056e720(param_1[0x11],*puVar2,0,puVar3,0,0);
      iVar6 = param_1[0x11];
      param_1[0x14] = iVar6;
      param_1[0x12] = param_1[8] + iVar6;
      iVar6 = iVar6 + param_1[10];
      goto LAB_0056f36d;
    }
    goto LAB_0056f2d4;
  }
  *param_1 = 1;
  if (5 < uVar4) goto LAB_0056f2d4;
  puVar2 = param_1 + 3;
  if (uVar4 < 4) {
    FUN_0056e720(puVar2,0x14,0,puVar3,4,0);
    param_1[8] = 0x3a4;
LAB_0056f2b5:
    param_1[0xe] = 0x3a4;
  }
  else {
    FUN_0056e720(puVar2,0x18,0,puVar3,4,0);
    uVar5 = param_1[8];
    if (uVar5 < 0x4e5) {
      if (uVar5 != 0x4e4) {
        if (uVar5 < 0x3b7) {
          if ((uVar5 < 0x3b5) && (uVar5 != 0x3a4)) {
            bVar8 = uVar5 == 0x3a8;
            goto LAB_0056f29b;
          }
        }
        else if ((uVar5 < 0x4b0) || (0x4b1 < uVar5)) goto LAB_0056f2b5;
      }
    }
    else {
      if (uVar5 < 0x8000) {
        if (0x7ffd < uVar5) goto LAB_0056f29d;
        bVar8 = uVar5 == 0x7ffc;
      }
      else {
        bVar8 = uVar5 == 0xfde9;
      }
LAB_0056f29b:
      if (!bVar8) goto LAB_0056f2b5;
    }
LAB_0056f29d:
    param_1[0xe] = uVar5;
  }
  iVar6 = FUN_0056e030(*puVar2,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x62b);
  param_1[0x11] = iVar6;
  if (iVar6 != 0) {
    FUN_0052dc20(param_1[0x222],param_1[5],0,0);
    if (*(ushort *)((int)param_1 + 10) < 5) {
      uVar7 = *puVar2;
      uVar10 = param_1[0x11];
      uVar12 = 0xffffffff;
      uVar11 = 0xffffffff;
    }
    else {
      uVar7 = *puVar2;
      uVar10 = param_1[0x11];
      uVar12 = 0;
      uVar11 = 0;
    }
    FUN_0056e720(uVar10,uVar7,0,puVar3,uVar11,uVar12);
    iVar6 = param_1[0x11];
    param_1[0x14] = iVar6;
    param_1[0x12] = param_1[6] + iVar6;
    iVar6 = iVar6 + param_1[7];
LAB_0056f36d:
    param_1[0x15] = iVar6;
    param_1[0x13] = iVar6;
    FUN_0052dc20(param_1[0x222],0,0,0);
    FUN_0052dcb0(param_1[0x10],param_1[0x21c],1,param_1[0x222]);
    param_1[0x221] = 1;
    param_1[0x219] = 1;
    param_1[0x21a] = 0;
    param_1[0x21e] = 0;
    param_1[0x21f] = 0;
    if (param_4 == 0) {
      iVar6 = FUN_0056ef10(param_1);
      while (iVar6 == 0) {
        FUN_0056da20(0);
        iVar6 = FUN_0056ef10(param_1);
      }
    }
    return 0;
  }
LAB_0056f2d4:
  if (param_1[0x222] != 0) {
    FUN_0052dbe0(param_1[0x222]);
    param_1[0x222] = 0;
  }
  if (param_1[0x10] != 0) {
    FUN_0056e1d0(param_1[0x10]);
    param_1[0x10] = 0;
  }
  param_1[0x221] = 0;
  return 0xffffffff;
}

