
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0047cda0(int param_1)

{
  int iVar1;
  int local_8;
  
  FUN_004ce950();
  iVar1 = FUN_004717c0(1);
  FUN_004ce970(iVar1 + 0x14);
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    FUN_004ce950();
    iVar1 = FUN_004717c0(local_8 + 1);
    FUN_004ce970(iVar1 + 0x14);
  }
  *(undefined8 *)(param_1 + 0x170) = _DAT_007d07d0;
  return 1;
}

