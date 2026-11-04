
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0058e4a0(int param_1,float param_2,float *param_3,float *param_4,int param_5)

{
  byte bVar1;
  float fVar2;
  uint3 uVar3;
  uint3 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((param_3 == (float *)0x0) || (param_4 == (float *)0x0)) {
    return 0xffffffff;
  }
  if (DAT_00a37dc8 == 1) {
    FUN_005dba10(param_1,param_2,param_3,param_4,param_5);
    return 0;
  }
  fVar2 = (float)_DAT_007d9bb8;
  iVar5 = (int)ROUND(param_3[2] * (float)_DAT_0081ec30);
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (0xff < iVar5) {
    iVar5 = 0xff;
  }
  iVar6 = (int)ROUND(param_3[1] * (float)_DAT_0081ec30);
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  else if (0xff < iVar6) {
    iVar6 = 0xff;
  }
  uVar7 = (uint)ROUND(*param_3 * (float)_DAT_0081ec30);
  if ((int)uVar7 < 0) {
    uVar7 = 0;
  }
  else if (0xff < (int)uVar7) {
    uVar7 = 0xff;
  }
  uVar3 = CONCAT12((char)uVar7,CONCAT11((char)iVar6,(char)iVar5));
  uVar8 = (uint)ROUND(param_3[3] * (float)_DAT_0081ec30);
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  else if (0xff < (int)uVar8) {
    uVar8 = 0xff;
  }
  iVar5 = (int)ROUND(param_4[2] * (float)_DAT_0081ec30);
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (0xff < iVar5) {
    iVar5 = 0xff;
  }
  iVar6 = (int)ROUND(param_4[1] * (float)_DAT_0081ec30);
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  else if (0xff < iVar6) {
    iVar6 = 0xff;
  }
  uVar9 = (uint)ROUND(*param_4 * (float)_DAT_0081ec30);
  if ((int)uVar9 < 0) {
    uVar9 = 0;
  }
  else if (0xff < (int)uVar9) {
    uVar9 = 0xff;
  }
  uVar4 = CONCAT12((char)uVar9,CONCAT11((char)iVar6,(char)iVar5));
  uVar13 = (uint)ROUND(param_4[3] * (float)_DAT_0081ec30);
  if ((int)uVar13 < 0) {
    uVar13 = 0;
  }
  else if (0xff < (int)uVar13) {
    uVar13 = 0xff;
  }
  iVar5 = FUN_00586970(param_1,1);
  if (iVar5 < 0) {
    return 0xffffffff;
  }
  iVar5 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  pbVar10 = *(byte **)(param_1 + 0x48c);
  puVar11 = *(undefined4 **)(param_1 + 0xd0c);
  iVar6 = *(int *)(param_1 + 0x488) + iVar5 * -4;
  param_3 = (float *)(*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24));
  iVar14 = *(int *)(param_1 + 0xd08) + iVar5 * -4;
  if (param_5 == 0) {
    do {
      iVar16 = iVar5;
      do {
        uVar12 = CONCAT13((char)uVar8,uVar3);
        if ((int)ROUND(param_2 * fVar2) <=
            (int)((uint)pbVar10[1] * 0x964 + (uint)pbVar10[2] * 0x4c8 + (uint)*pbVar10 * 0x1d2)) {
          uVar12 = CONCAT13((char)uVar13,uVar4);
        }
        *puVar11 = uVar12;
        pbVar10 = pbVar10 + 4;
        puVar11 = puVar11 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      pbVar10 = pbVar10 + iVar6;
      puVar11 = (undefined4 *)((int)puVar11 + iVar14);
      param_3 = (float *)((int)param_3 + -1);
    } while (param_3 != (float *)0x0);
    FUN_00586b00();
    return 0;
  }
  uVar15 = uVar8 & 0xff;
  local_14 = CONCAT13((char)uVar8,
                      CONCAT12((&DAT_00a52a60)[uVar15 + (uVar7 & 0xff) * 0x100],
                               CONCAT11((&DAT_00a52a60)[uVar15 + (uVar3 & 0xff00)],
                                        (&DAT_00a52a60)[uVar15 + (uVar3 & 0xff) * 0x100])));
  uVar7 = uVar13 & 0xff;
  local_10 = CONCAT13((char)uVar13,
                      CONCAT12((&DAT_00a52a60)[uVar7 + (uVar9 & 0xff) * 0x100],
                               CONCAT11((&DAT_00a52a60)[uVar7 + (uVar4 & 0xff00)],
                                        (&DAT_00a52a60)[uVar7 + (uVar4 & 0xff) * 0x100])));
  do {
    iVar16 = iVar5;
    do {
      bVar1 = pbVar10[3];
      uVar12 = local_14;
      if ((int)ROUND(param_2 * fVar2) <=
          (int)((uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar10[1],bVar1)] * 0x964 +
                (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar10[2],bVar1)] * 0x4c8 +
               (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar10,bVar1)] * 0x1d2)) {
        uVar12 = local_10;
      }
      *puVar11 = uVar12;
      pbVar10 = pbVar10 + 4;
      puVar11 = puVar11 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    pbVar10 = pbVar10 + iVar6;
    puVar11 = (undefined4 *)((int)puVar11 + iVar14);
    param_3 = (float *)((int)param_3 + -1);
  } while (param_3 != (float *)0x0);
  FUN_00586b00();
  return 0;
}

