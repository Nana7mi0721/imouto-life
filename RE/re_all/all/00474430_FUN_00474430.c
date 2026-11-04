
int __thiscall FUN_00474430(int param_1,int param_2)

{
  uint local_8;
  
  for (local_8 = 0; local_8 < 0x1400; local_8 = local_8 + 1) {
    *(undefined1 *)(param_1 + local_8) = *(undefined1 *)(param_2 + local_8);
  }
  FUN_0046f4c0(param_2 + 0x1400);
  FUN_004cda30(param_2 + 0x142c);
  FUN_004cf3c0(param_2 + 0x143c);
  return param_1;
}

