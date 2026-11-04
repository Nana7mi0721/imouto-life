
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0063bca0(int param_1,float param_2)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_8;
  
  fVar3 = (float10)FUN_006c51d0();
  pfVar1 = (float *)(param_1 + 0x130);
  *pfVar1 = (float)(fVar3 * (float10)*pfVar1);
  *(float *)(param_1 + 0x134) = (float)(fVar3 * (float10)*(float *)(param_1 + 0x134));
  *(float *)(param_1 + 0x138) = (float)(fVar3 * (float10)*(float *)(param_1 + 0x138));
  fVar3 = (float10)FUN_006c51d0();
  pfVar2 = (float *)(param_1 + 0x140);
  *pfVar2 = (float)(fVar3 * (float10)*pfVar2);
  *(float *)(param_1 + 0x144) = (float)(fVar3 * (float10)*(float *)(param_1 + 0x144));
  *(float *)(param_1 + 0x148) = (float)(fVar3 * (float10)*(float *)(param_1 + 0x148));
  if (*(char *)(param_1 + 0x1cc) != '\0') {
    fVar3 = (float10)FUN_005fcc30(pfVar2);
    if ((fVar3 < (float10)*(float *)(param_1 + 0x1d8)) &&
       (*(float *)(param_1 + 0x138) * *(float *)(param_1 + 0x138) +
        *(float *)(param_1 + 0x134) * *(float *)(param_1 + 0x134) + *pfVar1 * *pfVar1 <
        *(float *)(param_1 + 0x1d4))) {
      *pfVar2 = *pfVar2 * *(float *)(param_1 + 0x1d0);
      *(float *)(param_1 + 0x144) = *(float *)(param_1 + 0x144) * *(float *)(param_1 + 0x1d0);
      *(float *)(param_1 + 0x148) = *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0x1d0);
      *pfVar1 = *(float *)(param_1 + 0x1d0) * *pfVar1;
      *(float *)(param_1 + 0x134) = *(float *)(param_1 + 0x134) * *(float *)(param_1 + 0x1d0);
      *(float *)(param_1 + 0x138) = *(float *)(param_1 + 0x138) * *(float *)(param_1 + 0x1d0);
    }
    fVar3 = (float10)FUN_005fcc30(pfVar1);
    if (SQRT(fVar3) < (float10)*(float *)(param_1 + 0x1c4)) {
      if (SQRT(fVar3) <= (float10)_DAT_00804c28) {
        *pfVar1 = 0.0;
        *(undefined4 *)(param_1 + 0x134) = 0;
        *(undefined4 *)(param_1 + 0x138) = 0;
        *(undefined4 *)(param_1 + 0x13c) = 0;
      }
      else {
        fVar3 = (float10)FUN_005fcc30(pfVar1);
        param_2 = (float)((float10)_DAT_00804108 / SQRT(fVar3));
        FUN_0060fe40(&local_20,pfVar1,&param_2);
        param_2 = local_18 * _DAT_00804c28;
        local_28 = local_1c * _DAT_00804c28;
        local_24 = local_20 * _DAT_00804c28;
        FUN_005fc500(&local_24,&local_28,&param_2);
        *pfVar1 = *pfVar1 - local_10;
        *(float *)(param_1 + 0x134) = *(float *)(param_1 + 0x134) - local_c;
        *(float *)(param_1 + 0x138) = *(float *)(param_1 + 0x138) - local_8;
      }
    }
    fVar3 = (float10)FUN_005fcc30(pfVar2);
    if (SQRT(fVar3) < (float10)*(float *)(param_1 + 0x1c8)) {
      if (SQRT(fVar3) <= (float10)_DAT_00804c28) {
        *pfVar2 = 0.0;
        *(undefined4 *)(param_1 + 0x144) = 0;
        *(undefined4 *)(param_1 + 0x148) = 0;
        *(undefined4 *)(param_1 + 0x14c) = 0;
        return;
      }
      fVar3 = (float10)FUN_005fcc30(pfVar2);
      param_2 = (float)((float10)_DAT_00804108 / SQRT(fVar3));
      FUN_0060fe40(&local_10,pfVar2,&param_2);
      local_c = local_c * _DAT_00804c28;
      local_8 = local_8 * _DAT_00804c28;
      *pfVar2 = *pfVar2 - local_10 * _DAT_00804c28;
      *(float *)(param_1 + 0x144) = *(float *)(param_1 + 0x144) - local_c;
      *(float *)(param_1 + 0x148) = *(float *)(param_1 + 0x148) - local_8;
      return;
    }
  }
  return;
}

