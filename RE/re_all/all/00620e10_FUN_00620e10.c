
float * FUN_00620e10(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float local_20 [4];
  float local_10;
  float local_c;
  float local_8;
  
  if (param_2 == *param_1) {
    *param_1 = 0.0;
    return (float *)0x0;
  }
  fVar2 = *(float *)((int)param_2 + 0x20);
  pfVar5 = *(float **)((int)fVar2 + 0x20);
  fVar1 = *(float *)((int)fVar2 + (10 - (uint)(*(float *)((int)fVar2 + 0x28) == param_2)) * 4);
  if (pfVar5 == (float *)0x0) {
    *param_1 = fVar1;
    *(undefined4 *)((int)fVar1 + 0x20) = 0;
    FUN_00646b80(param_1[1]);
    param_1[1] = fVar2;
    return (float *)*param_1;
  }
  pfVar5[(pfVar5[10] == fVar2) + 9] = fVar1;
  *(float **)((int)fVar1 + 0x20) = pfVar5;
  FUN_00646b80(param_1[1]);
  param_1[1] = fVar2;
  while( true ) {
    fVar2 = pfVar5[9];
    fVar1 = pfVar5[10];
    pfVar4 = pfVar5;
    pfVar6 = local_20;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar6 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar6 = pfVar6 + 1;
    }
    iVar7 = (int)fVar2 - (int)fVar1;
    pfVar4 = (float *)((int)fVar1 + 0x10);
    iVar3 = (int)fVar2 - (int)pfVar5;
    param_2 = 4.2039e-45;
    pfVar6 = pfVar5;
    do {
      if (pfVar4[-4] <= *(float *)(iVar3 + (int)pfVar6)) {
        fVar2 = pfVar4[-4];
      }
      else {
        fVar2 = *(float *)(iVar3 + (int)pfVar6);
      }
      *pfVar6 = fVar2;
      if (*(float *)(iVar7 + (int)pfVar4) <= *pfVar4) {
        fVar2 = *pfVar4;
      }
      else {
        fVar2 = *(float *)(iVar7 + (int)pfVar4);
      }
      *(float *)((int)pfVar4 + ((int)pfVar5 - (int)fVar1)) = fVar2;
      pfVar6 = pfVar6 + 1;
      pfVar4 = pfVar4 + 1;
      param_2 = (float)((int)param_2 + -1);
    } while (param_2 != 0.0);
    if ((((local_20[0] == *pfVar5) && (local_20[1] == pfVar5[1])) && (local_20[2] == pfVar5[2])) &&
       (((local_10 == pfVar5[4] && (local_c == pfVar5[5])) && (local_8 == pfVar5[6])))) break;
    pfVar5 = (float *)pfVar5[8];
    if (pfVar5 == (float *)0x0) {
LAB_00620f49:
      return (float *)*param_1;
    }
  }
  if (pfVar5 != (float *)0x0) {
    return pfVar5;
  }
  goto LAB_00620f49;
}

