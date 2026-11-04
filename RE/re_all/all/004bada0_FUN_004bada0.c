
void __fastcall FUN_004bada0(int param_1)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    iVar1 = FUN_004717c0(local_8 + 1);
    *(int *)(param_1 + 0x388 + local_8 * 4) = iVar1 + -10;
    *(undefined4 *)(param_1 + 0x394 + local_8 * 4) = 0;
  }
  return;
}

