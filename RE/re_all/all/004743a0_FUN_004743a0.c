
undefined4 __thiscall FUN_004743a0(undefined4 param_1,int param_2)

{
  uint local_8;
  
  FUN_004cb840(param_2);
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    FUN_004cb840(param_2 + 0x1c + local_8 * 0x1c);
  }
  FUN_004cd5b0(param_2 + 0x1dc);
  FUN_004f09c0(param_2 + 0x1ec);
  return param_1;
}

