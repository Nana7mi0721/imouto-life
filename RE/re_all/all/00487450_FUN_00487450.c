
int FUN_00487450(char param_1,int param_2)

{
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1 == '\0') {
    local_10 = param_2;
  }
  else {
    if (param_2 < 999999) {
      local_8 = param_2;
    }
    else {
      local_8 = 999999;
    }
    if (local_8 < -0xf423e) {
      local_10 = -999999;
    }
    else {
      if (param_2 < 999999) {
        local_c = param_2;
      }
      else {
        local_c = 999999;
      }
      local_10 = local_c;
    }
  }
  return local_10;
}

