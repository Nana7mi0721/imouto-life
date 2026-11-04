
uint FUN_006736c0(int param_1,undefined1 *param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]);
  if (0x7fffffff < uVar1) {
    if (param_1 != 0) {
      FUN_006687b0(param_1,s_PNG_fixed_point_integer_out_of_r_00a0ce2c);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

