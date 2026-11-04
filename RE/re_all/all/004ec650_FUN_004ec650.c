
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004ec650(double param_1,uint param_2)

{
  double local_1c;
  double local_14;
  uint local_8;
  
  if ((int)param_2 < 0) {
    local_8 = -param_2;
  }
  else {
    local_8 = param_2;
  }
  local_14 = _DAT_00802e18;
  while( true ) {
    if ((local_8 & 1) != 0) {
      local_14 = local_14 * param_1;
    }
    local_8 = local_8 >> 1;
    if (local_8 == 0) break;
    param_1 = param_1 * param_1;
  }
  if ((int)param_2 < 0) {
    local_1c = _DAT_00802e18 / local_14;
  }
  else {
    local_1c = local_14;
  }
  return (float10)local_1c;
}

