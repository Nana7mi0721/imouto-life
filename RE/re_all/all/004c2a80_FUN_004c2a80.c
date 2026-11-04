
void __fastcall FUN_004c2a80(int param_1)

{
  int iVar1;
  int local_c;
  
  if (*(int *)(param_1 + 0xf8) - DAT_0084b244 < -9) {
    local_c = -10;
  }
  else {
    local_c = *(int *)(param_1 + 0xf8) - DAT_0084b244;
  }
  *(int *)(param_1 + 0xf8) = local_c;
  iVar1 = FUN_0050e880();
  if (iVar1 != 0) {
    FUN_00475460(0xffffffff);
  }
  return;
}

