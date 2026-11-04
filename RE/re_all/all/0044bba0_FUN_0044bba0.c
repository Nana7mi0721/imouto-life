
uint __fastcall FUN_0044bba0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_004174a0(0,0);
  uVar2 = uVar1 / 6;
  uVar1 = uVar1 % 6;
  if (uVar1 < 4) {
    uVar2 = FUN_0044e2e0();
  }
  else if (uVar1 == 4) {
    uVar2 = FUN_00486b30();
  }
  else if (uVar1 == 5) {
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return uVar2;
}

