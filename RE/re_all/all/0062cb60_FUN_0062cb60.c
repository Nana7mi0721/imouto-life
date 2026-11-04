
uint __thiscall FUN_0062cb60(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  ushort uVar5;
  int iVar3;
  undefined2 uVar6;
  uint uVar4;
  float *pfVar7;
  undefined1 uVar8;
  int iVar9;
  
  iVar3 = *param_1;
  uVar8 = 0;
  if (0 < iVar3) {
    pfVar7 = (float *)(param_1 + 3);
    iVar9 = iVar3;
    uVar8 = 0;
    do {
      uVar5 = (ushort)((uint)iVar3 >> 0x10);
      iVar3 = (uint)uVar5 << 0x10;
      if ((((pfVar7[1] == param_2[3]) && (iVar3 = (uint)uVar5 << 0x10, *pfVar7 == param_2[2])) &&
          (iVar3 = (uint)uVar5 << 0x10, pfVar7[-1] == param_2[1])) &&
         (iVar3 = (uint)uVar5 << 0x10, pfVar7[-2] == *param_2)) {
        uVar8 = 1;
      }
      pfVar7 = pfVar7 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  fVar1 = param_2[3];
  fVar2 = (float)param_1[0x4c];
  uVar6 = (undefined2)((uint)iVar3 >> 0x10);
  uVar4 = CONCAT22(uVar6,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                         (ushort)(fVar1 == fVar2) << 0xe);
  if ((fVar1 == fVar2) != 0) {
    fVar1 = param_2[2];
    fVar2 = (float)param_1[0x4b];
    uVar4 = CONCAT22(uVar6,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                           (ushort)(fVar1 == fVar2) << 0xe);
    if ((fVar1 == fVar2) != 0) {
      fVar1 = param_2[1];
      fVar2 = (float)param_1[0x4a];
      uVar4 = CONCAT22(uVar6,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10
                             | (ushort)(fVar1 == fVar2) << 0xe);
      if ((fVar1 == fVar2) != 0) {
        fVar1 = *param_2;
        fVar2 = (float)param_1[0x49];
        uVar4 = CONCAT31((int3)(CONCAT22(uVar6,(ushort)(fVar1 < fVar2) << 8 |
                                               (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                               (ushort)(fVar1 == fVar2) << 0xe) >> 8),1);
        if ((uVar4 & 0x4000) != 0) {
          return uVar4;
        }
      }
    }
  }
  return CONCAT31((int3)(uVar4 >> 8),uVar8);
}

