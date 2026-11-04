
/* WARNING: Removing unreachable block (ram,0x005f324f) */
/* WARNING: Removing unreachable block (ram,0x005f32aa) */
/* WARNING: Removing unreachable block (ram,0x005f322d) */
/* WARNING: Removing unreachable block (ram,0x005f328c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f2fb0(int param_1,int param_2)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  uint uVar12;
  int *piVar13;
  uint local_98;
  int local_8c;
  int *local_88;
  int local_84;
  undefined1 local_80 [128];
  
  iVar10 = 0;
  local_98 = 0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc47d0 == 0) || (uVar8 = *(uint *)(param_1 + 8), (int)uVar8 < 0)) ||
      ((uVar8 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(uVar8 & 0xffff) ||
       (piVar13 = *(int **)(DAT_00cc47d4 + (uVar8 & 0xffff) * 4), piVar13 == (int *)0x0)) ||
      ((*piVar13 * 0x10000 != (uVar8 & 0x3ff0000) || (piVar13[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_2 == 2) {
    iVar10 = 0;
  }
  else if (param_2 == 4) {
    iVar10 = 1;
  }
  else if (param_2 == 8) {
    iVar10 = 2;
  }
  piVar13 = &DAT_00dda4ac + iVar10;
  local_88 = piVar13;
  if ((int)(&DAT_00dda4ac)[iVar10] < 0) {
    iVar7 = FUN_005f2360(0);
    *piVar13 = iVar7;
    if (iVar7 < 0) {
      FUN_005764b0((&PTR_s_DownScaleX2_pso_00a057c0)[iVar10],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar7,piVar13);
  }
  uVar6 = _DAT_00802734;
  uVar4 = _DAT_007d5340;
  puVar1 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  if (param_2 == 2) {
    local_98 = 1;
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  else if (param_2 == 4) {
    local_98 = 4;
    *puVar1 = _DAT_007d5340;
    puVar1[1] = uVar4;
    puVar1[2] = 0x3f800000;
    puVar1[5] = 0x3f800000;
    puVar1[6] = 0x3f800000;
    puVar1[7] = 0x3f800000;
    puVar1[3] = uVar4;
    puVar1[4] = uVar4;
  }
  else if (param_2 == 8) {
    local_98 = 0x10;
    *puVar1 = _DAT_00802734;
    puVar1[1] = uVar6;
    uVar4 = _DAT_007d5340;
    puVar1[2] = _DAT_007d5340;
    puVar1[3] = uVar6;
    puVar1[4] = 0x3f800000;
    puVar1[5] = uVar6;
    uVar5 = _DAT_00802730;
    puVar1[6] = _DAT_00802730;
    puVar1[0xe] = uVar5;
    puVar1[0x16] = uVar5;
    puVar1[0x19] = uVar5;
    puVar1[0x1b] = uVar5;
    puVar1[0x1d] = uVar5;
    puVar1[0x1e] = uVar5;
    puVar1[0x1f] = uVar5;
    puVar1[7] = uVar6;
    puVar1[8] = uVar6;
    puVar1[0x10] = uVar6;
    puVar1[0x18] = uVar6;
    puVar1[9] = uVar4;
    puVar1[10] = uVar4;
    puVar1[0xb] = uVar4;
    puVar1[0xd] = uVar4;
    puVar1[0xf] = uVar4;
    puVar1[0x12] = uVar4;
    puVar1[0x1a] = uVar4;
    puVar1[0xc] = 0x3f800000;
    puVar1[0x11] = 0x3f800000;
    puVar1[0x13] = 0x3f800000;
    puVar1[0x14] = 0x3f800000;
    puVar1[0x15] = 0x3f800000;
    puVar1[0x17] = 0x3f800000;
    puVar1[0x1c] = 0x3f800000;
  }
  FUN_005159a0(*(undefined4 *)(param_1 + 8),&local_84,&local_8c);
  fVar2 = (float)local_84;
  uVar8 = 0;
  fVar3 = (float)local_8c;
  if (3 < local_98) {
    uVar9 = 2;
    do {
      pfVar11 = (float *)(puVar1 + (uVar8 >> 1) * 4);
      *pfVar11 = *pfVar11 / fVar2;
      pfVar11[1] = pfVar11[1] / fVar3;
      uVar12 = uVar9 - 1 >> 1;
      puVar1[uVar12 * 4 + 2] = (float)puVar1[uVar12 * 4 + 2] / fVar2;
      puVar1[uVar12 * 4 + 3] = (float)puVar1[uVar12 * 4 + 3] / fVar3;
      pfVar11 = (float *)(puVar1 + (uVar9 >> 1) * 4);
      *pfVar11 = *pfVar11 / fVar2;
      pfVar11[1] = pfVar11[1] / fVar3;
      uVar12 = uVar9 + 1 >> 1;
      puVar1[uVar12 * 4 + 2] = (float)puVar1[uVar12 * 4 + 2] / fVar2;
      puVar1[uVar12 * 4 + 3] = (float)puVar1[uVar12 * 4 + 3] / fVar3;
      uVar8 = uVar8 + 4;
      uVar9 = uVar9 + 4;
      piVar13 = local_88;
    } while ((int)uVar8 < (int)(local_98 - 3));
  }
  for (; (int)uVar8 < (int)local_98; uVar8 = uVar8 + 1) {
    if ((uVar8 & 1) == 0) {
      pfVar11 = (float *)(puVar1 + (uVar8 >> 1) * 4);
      *pfVar11 = (float)puVar1[(uVar8 >> 1) * 4] / fVar2;
      pfVar11[1] = pfVar11[1] / fVar3;
    }
    else {
      uVar9 = uVar8 >> 1;
      puVar1[uVar9 * 4 + 2] = (float)puVar1[uVar9 * 4 + 2] / fVar2;
      puVar1[uVar9 * 4 + 3] = (float)puVar1[uVar9 * 4 + 3] / fVar3;
    }
  }
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar13,1,param_2,0xffffffff,0);
  return 0;
}

