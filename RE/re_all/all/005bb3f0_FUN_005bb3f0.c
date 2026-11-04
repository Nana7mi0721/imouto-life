
undefined4 FUN_005bb3f0(float *param_1)

{
  float *pfVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  pfVar1 = *(float **)(DAT_00ef1ba0 + 8);
  if ((((*param_1 != *pfVar1) || (param_1[1] != pfVar1[1])) || (param_1[2] != pfVar1[2])) ||
     ((param_1[3] != pfVar1[3] || (DAT_00ef7324 != 0)))) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    *pfVar1 = *param_1;
    pfVar1[1] = param_1[1];
    pfVar1[2] = param_1[2];
    pfVar1[3] = param_1[3];
    *(undefined4 *)(DAT_00ef1ba0 + 0xc) = 1;
  }
  return 0;
}

