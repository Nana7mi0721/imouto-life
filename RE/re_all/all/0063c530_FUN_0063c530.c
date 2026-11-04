
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0063c530(int param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  float10 fVar3;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  if ((*(byte *)(param_1 + 200) & 3) == 0) {
    fVar2 = param_2 * *(float *)(param_1 + 0x150);
    pfVar1 = (float *)(param_1 + 0x1b4);
    local_20 = fVar2 * *(float *)(param_1 + 0x1a4);
    local_1c = fVar2 * *(float *)(param_1 + 0x1a8);
    *(float *)(param_1 + 0x130) = local_20 + *(float *)(param_1 + 0x130);
    *(float *)(param_1 + 0x134) = local_1c + *(float *)(param_1 + 0x134);
    *(float *)(param_1 + 0x138) = fVar2 * *(float *)(param_1 + 0x1ac) + *(float *)(param_1 + 0x138);
    local_2c = *(float *)(param_1 + 0x120) * *pfVar1 +
               *(float *)(param_1 + 0x124) * *(float *)(param_1 + 0x1b8) +
               *(float *)(param_1 + 0x128) * *(float *)(param_1 + 0x1bc);
    local_28 = *(float *)(param_1 + 0x110) * *pfVar1 +
               *(float *)(param_1 + 0x114) * *(float *)(param_1 + 0x1b8) +
               *(float *)(param_1 + 0x118) * *(float *)(param_1 + 0x1bc);
    fVar3 = (float10)FUN_005fcc30(pfVar1);
    local_24 = (float)fVar3;
    FUN_005fc500(&local_24,&local_28,&local_2c);
    *(float *)(param_1 + 0x140) = local_20 * param_2 + *(float *)(param_1 + 0x140);
    *(float *)(param_1 + 0x144) = local_1c * param_2 + *(float *)(param_1 + 0x144);
    *(float *)(param_1 + 0x148) = local_18 * param_2 + *(float *)(param_1 + 0x148);
    fVar2 = SQRT(*(float *)(param_1 + 0x148) * *(float *)(param_1 + 0x148) +
                 *(float *)(param_1 + 0x144) * *(float *)(param_1 + 0x144) +
                 *(float *)(param_1 + 0x140) * *(float *)(param_1 + 0x140));
    if (_DAT_00804864 < fVar2 * param_2) {
      fVar2 = (_DAT_00804864 / param_2) / fVar2;
      *(float *)(param_1 + 0x140) = fVar2 * *(float *)(param_1 + 0x140);
      *(float *)(param_1 + 0x144) = fVar2 * *(float *)(param_1 + 0x144);
      *(float *)(param_1 + 0x148) = fVar2 * *(float *)(param_1 + 0x148);
      return;
    }
  }
  return;
}

