
undefined4
FUN_00522dc0(undefined4 *param_1,uint param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  undefined4 uVar15;
  short *psVar16;
  int local_8b8;
  int local_8ac;
  int local_8a8;
  int local_8a4;
  undefined4 local_894;
  undefined4 local_890;
  uint local_88c;
  undefined4 local_888;
  undefined2 local_884;
  undefined1 local_882;
  short local_880 [32];
  short local_840 [32];
  short asStack_800 [256];
  short asStack_600 [256];
  short asStack_400 [256];
  short asStack_200 [256];
  
  iVar11 = DAT_00a37d78;
  if (((((DAT_00cc47d0 == 0) || ((int)param_2 < 0)) || ((param_2 & 0x7c000000) != DAT_00cc47f8)) ||
      ((DAT_00cc4800 <= (int)(param_2 & 0xffff) ||
       (piVar9 = *(int **)(DAT_00cc47d4 + (param_2 & 0xffff) * 4), piVar9 == (int *)0x0)))) ||
     (*piVar9 * 0x10000 != (param_2 & 0x3ff0000))) {
    return 0xffffffff;
  }
  FUN_00517450(&local_894,param_1,param_3,param_4,param_6,param_7,param_8,param_9,param_10);
  if ((((char)local_88c == '\x01') || ((char)local_88c == '\x02')) ||
     (((char)local_88c == '\x03' || (((char)local_88c == '\x04' || ((char)local_88c == '\x05'))))))
  {
    uVar15 = 1;
  }
  else {
    uVar15 = 0;
  }
  if (iVar11 == 0) {
    iVar6 = 0x1c;
  }
  else {
    uVar4 = param_1[0x16];
    uVar5 = FUN_00517710(param_3,local_840,1,0,uVar4,uVar15);
    iVar6 = FUN_00517710(param_4,local_880,1,0,uVar4,uVar15);
    iVar12 = iVar6 * uVar5;
    if ((local_894._3_1_ != '\0') && (1 < iVar12)) {
      return 0xffffffff;
    }
    sVar3 = 0;
    local_8ac = 0;
    if (0 < iVar6) {
      local_8b8 = 0;
      do {
        sVar14 = 0;
        iVar13 = 0;
        if (0 < (int)uVar5) {
          sVar2 = local_880[local_8ac];
          psVar16 = (short *)((int)asStack_200 + local_8b8);
          for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(uint *)psVar16 = CONCAT22(sVar2,sVar2);
            psVar16 = psVar16 + 2;
          }
          for (uVar10 = (uint)((uVar5 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
            *psVar16 = sVar2;
            psVar16 = psVar16 + 1;
          }
          psVar16 = (short *)((int)asStack_800 + local_8b8);
          for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(uint *)psVar16 = CONCAT22(sVar3,sVar3);
            psVar16 = psVar16 + 2;
          }
          for (uVar10 = (uint)((uVar5 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
            *psVar16 = sVar3;
            psVar16 = psVar16 + 1;
          }
          iVar7 = local_8b8;
          do {
            sVar2 = local_840[iVar13];
            *(short *)((int)asStack_400 + iVar7) = sVar2;
            *(short *)((int)asStack_600 + iVar7) = sVar14;
            iVar13 = iVar13 + 1;
            sVar14 = sVar14 + sVar2;
            iVar7 = iVar7 + 2;
          } while (iVar13 < (int)uVar5);
        }
        sVar3 = sVar3 + local_880[local_8ac];
        local_8ac = local_8ac + 1;
        local_8b8 = local_8b8 + uVar5 * 2;
      } while (local_8ac < iVar6);
    }
    iVar13 = iVar12;
    if ((DAT_00a37da4 != 0) && (local_8ac = 0, local_8a8 = iVar12, 0 < iVar12)) {
      do {
        sVar3 = asStack_400[local_8ac];
        sVar14 = asStack_200[local_8ac];
        if (sVar3 != sVar14) {
          if (sVar3 < sVar14) {
            local_8a4 = (int)sVar14 / (int)sVar3;
            sVar14 = asStack_600[local_8ac];
            sVar2 = asStack_800[local_8ac];
            iVar6 = 0;
            asStack_200[local_8ac] = sVar3;
            uVar5 = local_8a4 - 1;
            if (0 < (int)uVar5) {
              iVar7 = iVar13 * 2;
              psVar16 = asStack_600 + iVar13;
              for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(uint *)psVar16 = CONCAT22(sVar14,sVar14);
                psVar16 = psVar16 + 2;
              }
              for (uVar10 = (uint)((uVar5 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
                *psVar16 = sVar14;
                psVar16 = psVar16 + 1;
              }
              psVar16 = asStack_200 + iVar13;
              for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(uint *)psVar16 = CONCAT22(sVar3,sVar3);
                psVar16 = psVar16 + 2;
              }
              for (uVar10 = (uint)((uVar5 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
                *psVar16 = sVar3;
                psVar16 = psVar16 + 1;
              }
              psVar16 = asStack_400 + iVar13;
              for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(uint *)psVar16 = CONCAT22(sVar3,sVar3);
                psVar16 = psVar16 + 2;
              }
              for (uVar5 = (uint)((uVar5 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
                *psVar16 = sVar3;
                psVar16 = psVar16 + 1;
              }
              do {
                *(short *)((int)asStack_800 + iVar7) = ((short)iVar6 + 1) * sVar3 + sVar2;
                iVar6 = iVar6 + 1;
                iVar7 = iVar7 + 2;
              } while (iVar6 < local_8a4 + -1);
LAB_005231dd:
              iVar13 = local_8a8;
            }
          }
          else {
            local_8a4 = (int)sVar3 / (int)sVar14;
            sVar3 = asStack_600[local_8ac];
            sVar2 = asStack_800[local_8ac];
            iVar6 = 0;
            asStack_400[local_8ac] = sVar14;
            uVar5 = local_8a4 - 1;
            if (0 < (int)uVar5) {
              iVar7 = iVar13 * 2;
              psVar16 = asStack_800 + iVar13;
              for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(uint *)psVar16 = CONCAT22(sVar2,sVar2);
                psVar16 = psVar16 + 2;
              }
              for (uVar10 = (uint)((uVar5 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
                *psVar16 = sVar2;
                psVar16 = psVar16 + 1;
              }
              psVar16 = asStack_400 + iVar13;
              for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(uint *)psVar16 = CONCAT22(sVar14,sVar14);
                psVar16 = psVar16 + 2;
              }
              for (uVar10 = (uint)((uVar5 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
                *psVar16 = sVar14;
                psVar16 = psVar16 + 1;
              }
              psVar16 = asStack_200 + iVar13;
              for (uVar10 = (uVar5 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(uint *)psVar16 = CONCAT22(sVar14,sVar14);
                psVar16 = psVar16 + 2;
              }
              for (uVar5 = (uint)((uVar5 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
                *psVar16 = sVar14;
                psVar16 = psVar16 + 1;
              }
              do {
                *(short *)((int)asStack_600 + iVar7) = ((short)iVar6 + 1) * sVar14 + sVar3;
                iVar6 = iVar6 + 1;
                iVar7 = iVar7 + 2;
              } while (iVar6 < local_8a4 + -1);
              goto LAB_005231dd;
            }
          }
          iVar13 = iVar13 + -1 + local_8a4;
          local_8a8 = iVar13;
        }
        local_8ac = local_8ac + 1;
      } while (local_8ac < iVar12);
    }
    iVar6 = iVar13 * 0x40 + 8;
    local_8a8 = iVar13;
  }
  iVar6 = FUN_0056e050(iVar6 + 0x34,"..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x62e4);
  piVar9[0x13] = iVar6;
  if (iVar6 == 0) {
    FUN_0056bb10(&DAT_007d55c8);
    return 0xffffffff;
  }
  if (iVar11 != 0) {
    iVar11 = iVar6 + 0x3c + local_8a8 * 0x1c;
    piVar8 = (int *)(iVar6 + 0x3c);
    if (0 < local_8a8) {
      iVar12 = local_8a8;
      do {
        *piVar8 = iVar11;
        piVar8 = piVar8 + 7;
        iVar11 = iVar11 + 0x24;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
  }
  *(undefined4 *)(iVar6 + 8) = local_894;
  *(undefined4 *)(iVar6 + 0xc) = local_890;
  *(uint *)(iVar6 + 0x10) = local_88c;
  *(undefined4 *)(iVar6 + 0x14) = local_888;
  *(undefined2 *)(iVar6 + 0x18) = local_884;
  *(undefined1 *)(iVar6 + 0x1a) = local_882;
  *(undefined4 *)(iVar6 + 0x1c) = *param_1;
  iVar11 = param_1[0x1a];
  piVar9[0x16] = 0;
  piVar9[0x17] = 0;
  piVar9[0x14] = 0;
  piVar9[0x15] = 0;
  piVar9[0x20] = iVar11;
  piVar9[0x1a] = (int)(float)param_3;
  piVar9[0x19] = param_4;
  piVar9[0x18] = param_3;
  piVar9[0x1b] = (int)(float)param_4;
  *(int *)(piVar9[0x13] + 0x20) = param_3;
  *(int *)(piVar9[0x13] + 0x24) = param_4;
  *(undefined4 *)piVar9[0x13] = 1;
  if (*(char *)(iVar6 + 8) == '\0') {
    if (*(char *)(iVar6 + 0x17) == '\x01') {
      iVar11 = FUN_005820e0(iVar6 + 0x34,*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x24)
                            ,0xffffffff,0,2,0,0,0,0);
      if (iVar11 < 0) {
        FUN_0056bb10(&DAT_007d5590);
        return 0xffffffff;
      }
    }
    else {
      cVar1 = *(char *)(iVar6 + 10);
      if (*(char *)(iVar6 + 0x14) == '\x10') {
        iVar11 = (cVar1 != '\0') + 0x31;
      }
      else {
        iVar11 = (cVar1 != '\0') + 0x33;
      }
      *(int *)(iVar6 + 4) = iVar11;
      if (*(char *)(iVar6 + 0x18) == '\x01') {
        uVar15 = 0xffff;
      }
      else {
        uVar15 = FUN_00581c90(*(char *)(iVar6 + 0x14) != '\x10',cVar1,0,DAT_00a37f50 >> 0x10 & 0xff,
                              DAT_00a37f50 >> 8 & 0xff,DAT_00a37f50 & 0xff,0xff);
        uVar15 = FUN_005440f0(uVar15);
      }
      iVar11 = FUN_005820e0(iVar6 + 0x34,*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x24)
                            ,0xffffffff,uVar15,*(char *)(iVar6 + 0x14) != '\x10',
                            *(undefined1 *)(iVar6 + 0x18),*(undefined1 *)(iVar6 + 10),0,0);
      if (iVar11 < 0) {
        FUN_0056bb10(&DAT_007d5568);
        return 0xffffffff;
      }
    }
  }
  else {
    uVar15 = FUN_00516f10((char *)(iVar6 + 8));
    *(undefined4 *)(iVar6 + 4) = uVar15;
    *(int *)(iVar6 + 0x38) = local_8a8;
    *(uint *)(iVar6 + 0x34) = local_88c >> 8 & 0xff;
    if (0 < local_8a8) {
      piVar9 = (int *)(iVar6 + 0x4c);
      iVar11 = 0;
      do {
        sVar3 = asStack_600[iVar11];
        piVar9[-1] = *(int *)(iVar6 + 0x20) - (int)sVar3;
        iVar12 = (int)asStack_400[iVar11];
        *piVar9 = *(int *)(iVar6 + 0x24) - (int)asStack_800[iVar11];
        if (iVar12 < piVar9[-1]) {
          piVar9[-1] = iVar12;
        }
        iVar13 = (int)asStack_200[iVar11];
        if (iVar13 < *piVar9) {
          *piVar9 = iVar13;
        }
        piVar9[-3] = (int)sVar3;
        piVar9[-2] = (int)asStack_800[iVar11];
        piVar9[1] = iVar12;
        piVar9[2] = iVar13;
        iVar11 = iVar11 + 1;
        piVar9 = piVar9 + 7;
      } while (iVar11 < local_8a8);
    }
    if ((*(char *)(iVar6 + 0xb) != '\0') && (param_1[0xf] != 0)) {
      uVar5 = 1;
      *(undefined4 *)(iVar6 + 0x28) = 1;
      if (param_1[0x12] != 0x18) {
        uVar5 = (param_1[0x12] != 0x20) - 1 & 2;
      }
      *(uint *)(iVar6 + 0x2c) = uVar5;
    }
    iVar11 = FUN_00568a80(iVar6,param_11);
    if (iVar11 == -1) {
      return 0xffffffff;
    }
  }
  iVar11 = FUN_00517880(param_2,0,param_11);
  if (iVar11 < 0) {
    return 0xffffffff;
  }
  return 0;
}

