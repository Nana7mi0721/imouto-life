
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0065f090(float *param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  double local_18;
  undefined8 local_10;
  
  iVar2 = FUN_0065ead0((double)param_1[1],param_2);
  fVar1 = param_1[1] * (float)_DAT_008053e8 + param_1[2] * (float)_DAT_008053f0 + *param_1;
  if ((iVar2 == 0) || (fVar1 <= (float)_DAT_007d0a60)) {
    local_10 = 0.210526316;
    local_18 = 0.473684211;
  }
  else {
    local_10 = (double)((*param_1 * (float)_DAT_008053c8) / fVar1);
    local_18 = (double)((param_1[1] * (float)_DAT_008053d0) / fVar1);
  }
  uVar3 = FUN_0065eb60((undefined4)local_10,local_10._4_4_,local_18._0_4_,
                       (int)((ulonglong)local_18 >> 0x20),param_2);
  if ((int)uVar3 < 0) {
    uVar3 = FUN_0065eb60(0xbd156c1a,0x3fcaf286,0x94b8199e,0x3fde50d7,0);
  }
  return iVar2 << 0xe | uVar3;
}

