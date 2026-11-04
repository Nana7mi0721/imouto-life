
void FUN_00620c20(float *param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float *pfVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float10 fVar11;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if (*param_1 == 0.0) {
    *param_1 = param_3;
    *(undefined4 *)((int)param_3 + 0x20) = 0;
    return;
  }
  if (*(int *)((int)param_2 + 0x28) != 0) {
    do {
      uVar1 = *(undefined4 *)((int)param_2 + 0x28);
      uVar4 = FUN_0060f480(local_20,*(int *)((int)param_2 + 0x24),
                           *(int *)((int)param_2 + 0x24) + 0x10);
      uVar4 = FUN_0060f480(local_10,param_3,(int)param_3 + 0x10,uVar4);
      FUN_005fc590(&local_30,uVar4);
      fVar2 = ABS(local_2c);
      fVar6 = ABS(local_28);
      fVar3 = ABS(local_30);
      fVar11 = (float10)FUN_00621aa0(param_3,uVar1);
      param_2 = *(float *)((int)param_2 + 0x24 +
                          (uint)(fVar11 <= (float10)(fVar3 + fVar6 + fVar2)) * 4);
    } while (*(int *)((int)param_2 + 0x28) != 0);
  }
  pfVar5 = (float *)param_1[1];
  pfVar10 = *(float **)((int)param_2 + 0x20);
  if (pfVar5 == (float *)0x0) {
    pfVar5 = (float *)FUN_00646b30(0x2c,0x10);
  }
  else {
    param_1[1] = 0.0;
  }
  pfVar5[8] = (float)pfVar10;
  pfVar5[9] = 0.0;
  pfVar5[10] = 0.0;
  FUN_006219f0(param_3,param_2,pfVar5);
  if (pfVar10 == (float *)0x0) {
    pfVar5[9] = param_2;
    *(float **)((int)param_2 + 0x20) = pfVar5;
    pfVar5[10] = param_3;
    *(float **)((int)param_3 + 0x20) = pfVar5;
    *param_1 = (float)pfVar5;
  }
  else {
    pfVar10[(*(float *)(*(int *)((int)param_2 + 0x20) + 0x28) == param_2) + 9] = (float)pfVar5;
    pfVar5[9] = param_2;
    *(float **)((int)param_2 + 0x20) = pfVar5;
    pfVar5[10] = param_3;
    *(float **)((int)param_3 + 0x20) = pfVar5;
    while ((((pfVar9 = pfVar10, *pfVar5 < *pfVar9 || (pfVar5[1] < pfVar9[1])) ||
            (pfVar5[2] < pfVar9[2])) ||
           (((pfVar9[4] < pfVar5[4] || (pfVar9[5] < pfVar5[5])) || (pfVar9[6] < pfVar5[6]))))) {
      fVar2 = pfVar9[10];
      iVar8 = (int)pfVar9[9] - (int)fVar2;
      pfVar5 = (float *)((int)fVar2 + 0x10);
      iVar7 = (int)pfVar9[9] - (int)pfVar9;
      param_1 = (float *)0x3;
      pfVar10 = pfVar9;
      do {
        if (pfVar5[-4] <= *(float *)(iVar7 + (int)pfVar10)) {
          fVar6 = pfVar5[-4];
        }
        else {
          fVar6 = *(float *)(iVar7 + (int)pfVar10);
        }
        *pfVar10 = fVar6;
        if (*(float *)(iVar8 + (int)pfVar5) <= *pfVar5) {
          fVar6 = *pfVar5;
        }
        else {
          fVar6 = *(float *)(iVar8 + (int)pfVar5);
        }
        *(float *)((int)pfVar5 + ((int)pfVar9 - (int)fVar2)) = fVar6;
        pfVar10 = pfVar10 + 1;
        pfVar5 = pfVar5 + 1;
        param_1 = (float *)((int)param_1 + -1);
      } while (param_1 != (float *)0x0);
      pfVar10 = (float *)pfVar9[8];
      pfVar5 = pfVar9;
      if ((float *)pfVar9[8] == (float *)0x0) {
        return;
      }
    }
  }
  return;
}

