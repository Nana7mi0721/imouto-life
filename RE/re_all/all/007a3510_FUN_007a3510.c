
uint FUN_007a3510(int *param_1,int param_2,uint param_3,undefined4 param_4,uint param_5,
                 undefined4 *param_6,undefined4 param_7,float *param_8,undefined4 param_9,
                 undefined4 *param_10,uint param_11)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  float *pfVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  int local_14;
  int local_8;
  
  puVar8 = param_6;
  iVar10 = *param_1;
  bVar11 = param_5 == 1;
  local_8 = 0;
  local_14 = 0;
  iVar7 = param_1[5];
  if (param_3 == 1) {
    uVar2 = FUN_007a39f0(param_1,param_2,0,param_4,param_8);
    return uVar2;
  }
  if (0 < iVar7) {
    local_14 = iVar7;
  }
  if (((param_10 != (undefined4 *)0x0) && (param_6 != (undefined4 *)0x0)) &&
     ((local_14 != 0 || ((((param_3 / param_5 & 1) == 0 && (iVar7 < 0)) || (1 < (int)param_5)))))) {
    param_6 = param_10;
    for (uVar2 = param_3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_10 = *puVar8;
      puVar8 = puVar8 + 1;
      param_10 = param_10 + 1;
    }
  }
  iVar9 = 0;
  if (0 < local_14) {
    do {
      bVar5 = (byte)iVar9;
      if (iVar10 != 0) {
        FUN_007a2ef0(param_2,(int)param_3 >> (bVar5 & 0x1f),1 << (bVar5 & 0x1f));
      }
      if (param_6 != (undefined4 *)0x0) {
        FUN_007a2ef0(param_6,(int)param_3 >> (bVar5 & 0x1f),1 << (bVar5 & 0x1f));
      }
      param_11 = (uint)(byte)(&DAT_0083c58c)[(int)param_11 >> 4] << 2 |
                 (uint)(byte)(&DAT_0083c58c)[param_11 & 0xf];
      iVar9 = iVar9 + 1;
    } while (iVar9 < local_14);
  }
  bVar5 = (byte)local_14;
  uVar2 = param_3 / param_5 << (bVar5 & 0x1f);
  iVar9 = (int)param_5 >> (bVar5 & 0x1f);
  for (; ((uVar2 & 1) == 0 && (iVar7 < 0)); iVar7 = iVar7 + 1) {
    if (iVar10 != 0) {
      FUN_007a2ef0(param_2,uVar2,iVar9);
    }
    if (param_6 != (undefined4 *)0x0) {
      FUN_007a2ef0(param_6,uVar2,iVar9);
    }
    bVar6 = (byte)iVar9;
    iVar9 = iVar9 << 1;
    uVar2 = (int)uVar2 >> 1;
    param_11 = param_11 | param_11 << (bVar6 & 0x1f);
    local_8 = local_8 + 1;
  }
  if (1 < iVar9) {
    if (iVar10 != 0) {
      FUN_007a3800(param_2,(int)uVar2 >> (bVar5 & 0x1f),iVar9 << (bVar5 & 0x1f),bVar11);
    }
    if (param_6 != (undefined4 *)0x0) {
      FUN_007a3800(param_6,(int)uVar2 >> (bVar5 & 0x1f),iVar9 << (bVar5 & 0x1f),bVar11);
    }
  }
  uVar3 = FUN_007a3ae0(param_1,param_2,param_3,param_4,iVar9,param_6,param_7,param_9,param_11);
  if (iVar10 == 0) {
    if (1 < iVar9) {
      FUN_007a3900(param_2,(int)uVar2 >> (bVar5 & 0x1f),iVar9 << (bVar5 & 0x1f),bVar11);
    }
    if (0 < local_8) {
      param_6 = (undefined4 *)local_8;
      do {
        iVar9 = iVar9 >> 1;
        uVar2 = uVar2 << 1;
        uVar3 = uVar3 | uVar3 >> ((byte)iVar9 & 0x1f);
        FUN_007a2ef0(param_2,uVar2,iVar9);
        param_6 = (undefined4 *)((int)param_6 + -1);
      } while (param_6 != (undefined4 *)0x0);
    }
    iVar10 = 0;
    if (0 < local_14) {
      do {
        uVar3 = (uint)(byte)(&DAT_0083c59c)[uVar3];
        FUN_007a2ef0(param_2,(int)param_3 >> ((byte)iVar10 & 0x1f),1 << ((byte)iVar10 & 0x1f));
        iVar10 = iVar10 + 1;
      } while (iVar10 < local_14);
    }
    if ((param_8 != (float *)0x0) && (fVar1 = (float)(int)param_3, 0 < (int)param_3)) {
      pfVar4 = param_8;
      do {
        param_3 = param_3 - 1;
        *pfVar4 = *(float *)((param_2 - (int)param_8) + (int)pfVar4) * SQRT(fVar1);
        pfVar4 = pfVar4 + 1;
      } while (param_3 != 0);
    }
    uVar3 = uVar3 & (1 << ((byte)(iVar9 << (bVar5 & 0x1f)) & 0x1f)) - 1U;
  }
  return uVar3;
}

