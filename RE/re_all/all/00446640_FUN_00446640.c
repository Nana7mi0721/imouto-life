
void __fastcall FUN_00446640(int param_1)

{
  int iVar1;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_004d25e0();
    if (iVar1 <= local_8) break;
    iVar1 = FUN_004d2620(local_8);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
    iVar1 = FUN_004d2620(local_8);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    iVar1 = FUN_004d2620(local_8);
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_1 + 0x38);
    iVar1 = FUN_004d2620(local_8);
    *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
    local_8 = local_8 + 1;
  }
  FUN_004ce950();
  for (local_c = 0; local_c < 100; local_c = local_c + 1) {
    local_10 = 0;
    FUN_004ce160(&local_10);
  }
  return;
}

