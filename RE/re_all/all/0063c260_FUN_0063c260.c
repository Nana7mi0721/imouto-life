
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0063c260(int param_1,float param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if (param_2 == _DAT_007d5344) {
    *(undefined4 *)(param_1 + 0x150) = 0;
    *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) | 1;
  }
  else {
    param_2 = _DAT_00804108 / param_2;
    *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) & 0xfffffffe;
    *(float *)(param_1 + 0x150) = param_2;
  }
  if (param_3[2] == _DAT_007d5344) {
    fVar1 = _DAT_007d5344;
  }
  else {
    fVar1 = _DAT_00804108 / param_3[2];
  }
  if (param_3[1] == _DAT_007d5344) {
    fVar2 = _DAT_007d5344;
  }
  else {
    fVar2 = _DAT_00804108 / param_3[1];
  }
  if (*param_3 == _DAT_007d5344) {
    fVar3 = _DAT_007d5344;
  }
  else {
    fVar3 = _DAT_00804108 / *param_3;
  }
  *(float *)(param_1 + 0x194) = fVar3;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(float *)(param_1 + 0x198) = fVar2;
  *(float *)(param_1 + 0x19c) = fVar1;
  return;
}

