
void __fastcall FUN_004a6860(byte *param_1)

{
  uint local_c;
  byte local_5;
  
  if (*(int *)(param_1 + 4) != 0) {
    local_5 = param_1[4];
    FUN_004cd800(&local_5);
    local_c = (uint)*param_1;
    FUN_004ce160(&local_c);
  }
  *param_1 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}

