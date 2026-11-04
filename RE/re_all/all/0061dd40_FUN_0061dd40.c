
ushort FUN_0061dd40(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  undefined1 uVar3;
  ushort uVar4;
  
  uVar3 = 1;
  if ((*param_4 < *param_1) || (*param_2 < *param_3)) {
    uVar3 = 0;
  }
  if ((param_4[2] < param_1[2]) || (param_2[2] < param_3[2])) {
    uVar3 = 0;
  }
  fVar1 = param_1[1];
  fVar2 = param_4[1];
  uVar4 = (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
          (ushort)(fVar1 == fVar2) << 0xe;
  if (fVar1 < fVar2 || (fVar1 == fVar2) != 0) {
    fVar1 = param_2[1];
    fVar2 = param_3[1];
    uVar4 = (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
            (ushort)(fVar1 == fVar2) << 0xe;
    if (fVar1 >= fVar2) {
      return CONCAT11((char)(uVar4 >> 8),uVar3);
    }
  }
  return uVar4;
}

