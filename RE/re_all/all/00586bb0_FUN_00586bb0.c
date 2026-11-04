
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00586bb0(int param_1,float param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  byte *pbVar17;
  undefined1 *puVar18;
  
  param_2 = param_2 / (float)_DAT_007d58a0;
  if (_DAT_007d5550 <= param_2) {
    if (_DAT_007d589c < param_2) {
      param_2 = _DAT_007d589c;
    }
  }
  else {
    param_2 = _DAT_007d5550;
  }
  param_3 = param_3 / (float)_DAT_007d58a0;
  if (_DAT_007d5550 <= param_3) {
    if (_DAT_007d589c < param_3) {
      param_3 = _DAT_007d589c;
    }
  }
  else {
    param_3 = _DAT_007d5550;
  }
  if (DAT_00a37dc8 == 1) {
    FUN_005db770(param_1,param_2,param_3);
    return 0;
  }
  fVar2 = param_3 * (float)_DAT_007d9bc0;
  fVar4 = (float)_DAT_0081ec30;
  fVar3 = (float)_DAT_007d9bb8;
  fVar5 = param_2 * (float)_DAT_007d9bb0;
  fVar8 = param_3 * (float)_DAT_007d9ba8;
  fVar7 = (float)_DAT_0081ec30;
  fVar6 = (float)_DAT_007d9bb8;
  fVar9 = param_2 * (float)_DAT_007d9ba0;
  fVar11 = (float)_DAT_0081ec30;
  fVar10 = (float)_DAT_007d9bb8;
  iVar12 = FUN_00586970(param_1,1);
  if (iVar12 < 0) {
    return 0xffffffff;
  }
  param_2 = (float)(*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24));
  iVar14 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  iVar12 = *(int *)(param_1 + 0x488);
  iVar1 = *(int *)(param_1 + 0xd08);
  pbVar17 = *(byte **)(param_1 + 0x48c);
  puVar18 = *(undefined1 **)(param_1 + 0xd0c);
  do {
    param_3 = (float)iVar14;
    do {
      iVar13 = (uint)pbVar17[1] * 0x964 + (uint)pbVar17[2] * 0x4c8 + (uint)*pbVar17 * 0x1d2;
      iVar15 = (int)ROUND(fVar9 * fVar11 * fVar10) + iVar13 >> 0xc;
      iVar16 = (int)ROUND((fVar5 - fVar8) * fVar7 * fVar6) + iVar13 >> 0xc;
      iVar13 = iVar13 + (int)ROUND(fVar2 * fVar4 * fVar3) >> 0xc;
      if (iVar15 < 0) {
        iVar15 = 0;
      }
      else if (0xff < iVar15) {
        iVar15 = 0xff;
      }
      if (iVar16 < 0) {
        iVar16 = 0;
      }
      else if (0xff < iVar16) {
        iVar16 = 0xff;
      }
      if (iVar13 < 0) {
        iVar13 = 0;
      }
      else if (0xff < iVar13) {
        iVar13 = 0xff;
      }
      puVar18[2] = (char)iVar13;
      *puVar18 = (char)iVar15;
      puVar18[1] = (char)iVar16;
      puVar18[3] = pbVar17[3];
      pbVar17 = pbVar17 + 4;
      puVar18 = puVar18 + 4;
      param_3 = (float)((int)param_3 + -1);
    } while (param_3 != 0.0);
    pbVar17 = pbVar17 + iVar12 + iVar14 * -4;
    puVar18 = puVar18 + iVar1 + iVar14 * -4;
    param_2 = (float)((int)param_2 + -1);
  } while (param_2 != 0.0);
  FUN_00586b00();
  return 0;
}

