
undefined4
FUN_00614950(float *param_1,float *param_2,int *param_3,int param_4,float *param_5,float param_6,
            float param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar8;
  undefined4 uVar7;
  
  piVar5 = param_3;
  fVar1 = (*(float *)(*param_3 * 0x10 + param_4) - *param_1) * *param_2;
  *param_5 = fVar1;
  iVar6 = param_3[1] * 0x10;
  fVar2 = (*(float *)(param_4 + *param_3 * -0x10 + 0x10) - *param_1) * *param_2;
  fVar3 = (*(float *)(iVar6 + 4 + param_4) - param_1[1]) * param_2[1];
  fVar4 = (*(float *)(param_4 + param_3[1] * -0x10 + 0x14) - param_1[1]) * param_2[1];
  uVar8 = (undefined2)((uint)iVar6 >> 0x10);
  uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar4) << 8 | (ushort)(NAN(fVar1) || NAN(fVar4)) << 10 |
                         (ushort)(fVar1 == fVar4) << 0xe);
  if (fVar1 < fVar4 || (fVar1 == fVar4) != 0) {
    uVar7 = CONCAT22(uVar8,(ushort)(fVar3 < fVar2) << 8 | (ushort)(NAN(fVar3) || NAN(fVar2)) << 10 |
                           (ushort)(fVar3 == fVar2) << 0xe);
    if (fVar3 < fVar2 || (fVar3 == fVar2) != 0) {
      if (fVar1 < fVar3) {
        *param_5 = fVar3;
      }
      param_3 = (int *)fVar2;
      if (fVar4 < fVar2) {
        param_3 = (int *)fVar4;
      }
      iVar6 = piVar5[2] * 0x10;
      fVar2 = (*(float *)(iVar6 + 8 + param_4) - param_1[2]) * param_2[2];
      fVar3 = (*(float *)(param_4 + piVar5[2] * -0x10 + 0x18) - param_1[2]) * param_2[2];
      fVar1 = *param_5;
      uVar8 = (undefined2)((uint)iVar6 >> 0x10);
      uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar3) << 8 | (ushort)(NAN(fVar1) || NAN(fVar3)) << 10
                             | (ushort)(fVar1 == fVar3) << 0xe);
      if (fVar1 < fVar3 || (fVar1 == fVar3) != 0) {
        uVar7 = CONCAT22(uVar8,(ushort)(fVar2 < (float)param_3) << 8 |
                               (ushort)(NAN(fVar2) || NAN((float)param_3)) << 10 |
                               (ushort)(fVar2 == (float)param_3) << 0xe);
        if (fVar2 < (float)param_3 || (fVar2 == (float)param_3) != 0) {
          if (*param_5 < fVar2) {
            *param_5 = fVar2;
          }
          if (fVar3 < (float)param_3) {
            param_3 = (int *)fVar3;
          }
          if ((*param_5 < param_7) && (param_6 < (float)param_3)) {
            return 1;
          }
          return 0;
        }
      }
    }
  }
  return uVar7;
}

