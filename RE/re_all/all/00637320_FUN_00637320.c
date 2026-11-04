
void FUN_00637320(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 0xb4) != '\0')) {
    fVar1 = *(float *)(param_1 + 0x2c);
    fVar2 = param_2[2];
    fVar3 = *(float *)(param_1 + 0x1c);
    fVar4 = param_2[1];
    fVar5 = *(float *)(param_1 + 0xc);
    fVar6 = *param_2;
    fVar7 = (float10)FUN_005fccd0(param_2);
    fVar8 = (float10)FUN_005fccb0(param_2);
    fVar8 = fVar8 * (float10)*(float *)(param_1 + 0xa4);
    fVar7 = (float10)(float)fVar7 * (float10)*(float *)(param_1 + 0xa8);
    fVar9 = (float10)(fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2) *
            (float10)*(float *)(param_1 + 0xac);
    fVar1 = *(float *)(param_1 + 0x1c);
    fVar2 = *(float *)(param_1 + 0x18);
    fVar3 = *(float *)(param_1 + 0x14);
    fVar4 = *(float *)(param_1 + 0x2c);
    fVar5 = *(float *)(param_1 + 0x28);
    fVar6 = *(float *)(param_1 + 0x24);
    *param_2 = (float)(fVar8 * (float10)*(float *)(param_1 + 4) +
                      fVar7 * (float10)*(float *)(param_1 + 8) +
                      fVar9 * (float10)*(float *)(param_1 + 0xc));
    param_2[1] = (float)(fVar8 * (float10)fVar3 + fVar7 * (float10)fVar2 + fVar9 * (float10)fVar1);
    param_2[2] = (float)(fVar8 * (float10)fVar6 + fVar7 * (float10)fVar5 + fVar9 * (float10)fVar4);
    param_2[3] = 0.0;
  }
  return;
}

