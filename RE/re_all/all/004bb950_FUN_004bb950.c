
int FUN_004bb950(int param_1,int param_2)

{
  int local_c;
  
  if (*DAT_00a16714 < 0xd3) {
    if (param_1 <= param_2) {
      param_1 = param_1 / 2;
    }
  }
  else {
    if (param_1 < -0x6e) {
      local_c = (-0x6e - param_1) / 2 + param_1;
    }
    else {
      local_c = param_1;
    }
    param_1 = local_c;
  }
  return param_1;
}

