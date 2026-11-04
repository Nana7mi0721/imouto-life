
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056d840(void)

{
  float10 fVar1;
  int local_8;
  
  local_8 = 0;
  do {
    fVar1 = (float10)(((float)local_8 * (float)_DAT_007d56c0 + (float)local_8 * (float)_DAT_007d56c0
                      ) * (float)_DAT_007d62c8);
    fcos(fVar1);
    fVar1 = (float10)fsin(fVar1);
    local_8 = local_8 + 1;
    (&DAT_00aba250)[local_8] = (float)fVar1;
  } while (local_8 < 0x10000);
  return 0;
}

