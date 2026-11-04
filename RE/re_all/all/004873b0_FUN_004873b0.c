
uint FUN_004873b0(uint param_1,uint param_2)

{
  uint local_1c;
  uint local_14;
  uint local_c;
  uint local_8;
  
  if ((param_2 < 0x80000000) || ((-2 < (int)param_2 && (0x88ca6bff < param_1)))) {
    local_c = param_1;
    local_8 = param_2;
  }
  else {
    local_c = 0x88ca6c00;
    local_8 = 0xffffffff;
  }
  if (((int)local_8 < 0) || (((int)local_8 < 1 && (local_c < 0x77359401)))) {
    if ((param_2 < 0x80000000) || ((-2 < (int)param_2 && (0x88ca6bff < param_1)))) {
      local_1c = param_1;
    }
    else {
      local_1c = 0x88ca6c00;
    }
    local_14 = local_1c;
  }
  else {
    local_14 = 2000000000;
  }
  return local_14;
}

